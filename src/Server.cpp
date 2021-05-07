#include "Server.h"

#include <utility>

void AuthHandler::pskRequired(QSslPreSharedKeyAuthenticator *auth) {
    auth->setPreSharedKey(QByteArrayLiteral("\x1a\x2b\x3c\x4d\x5e\x6f"));
}

Server* Server::instance = nullptr;

QDtls* Server::get_client(const QHostAddress& addr, quint16 port) {
    if (!client_1)
        return nullptr;
    if (addr == client_1->peerAddress() && port == client_1->peerPort())
        return client_1;
    if (!client_2)
        return nullptr;
    if (addr == client_2->peerAddress() && port == client_2->peerPort())
        return client_2;
    return nullptr;
}

void Server::set_client(QHostAddress addr, quint16 port) {
    if (!client_1) {
        client_1 = new QDtls(QSslSocket::SslServerMode);
        client_1->setDtlsConfiguration(server_config);
        client_1->setPeer(addr, port);
        QDtls::connect(client_1, &QDtls::pskRequired, &handler, &AuthHandler::pskRequired);
    }
    else {
        client_2 = new QDtls(QSslSocket::SslServerMode);
        client_2->setDtlsConfiguration(server_config);
        client_2->setPeer(addr, port);
        QDtls::connect(client_2, &QDtls::pskRequired, &handler, &AuthHandler::pskRequired);
    }
}

std::string Server::get_response() {
    udpSocket->waitForReadyRead(-1);
    QByteArray datagram;
    datagram.resize(udpSocket->pendingDatagramSize());
    QHostAddress sender;
    quint16 senderPort;
    udpSocket->readDatagram(datagram.data(), datagram.size(),
                            &sender, &senderPort);
    return datagram.toStdString();
}

quint16 Server::choose_port() {
    return server_port;
}

QHostAddress Server::get_public_ip() {
    return server_addr;
}

void Server::write_message(QDtls* client, const QByteArray& msg) {
    std::string f = QString(msg).toStdString();
    client->writeDatagramEncrypted(udpSocket, msg);
}

bool Server::completed() {
    return (client_1 && client_2) && (client_1->handshakeState() == QDtls::HandshakeComplete &&
                                      client_2->handshakeState() == QDtls::HandshakeComplete);
}

bool Server::is_running() {
    return running;
}

Server::Server(): udpSocket(new QUdpSocket(nullptr)), server_config(QSslConfiguration::defaultDtlsConfiguration()){
    running = udpSocket->bind(get_public_ip(), choose_port());
}

void Server::write(int player_num, QString msg) {
    std::string f = msg.toStdString();
    std::string g = QString(msg.toUtf8()).toStdString();
    QDtls* cur_client;
    if (player_num == 1)
        cur_client = client_1;
    else
        cur_client = client_2;
    cur_client->writeDatagramEncrypted(udpSocket, msg.toUtf8());
}

void Server::start() {
    server_config.setDtlsCookieVerificationEnabled(false);
    wait_two_connections();
}

void Server::timeout() {

}

void Server::wait_two_connections() {
    QByteArray datagram;
    QHostAddress addr;
    quint16 port = 0;
    QDtls* cur_client;
    while(udpSocket->waitForReadyRead(-1)) {
        while (udpSocket->hasPendingDatagrams()) {
            datagram = QByteArray(udpSocket->pendingDatagramSize(), Qt::Uninitialized);
            udpSocket->readDatagram(datagram.data(), datagram.size(), &addr, &port);
            cur_client = get_client(addr, port);
            if (!cur_client){
                set_client(addr, port);
            }
            cur_client = get_client(addr, port);
            if (cur_client->handshakeState() != QDtls::HandshakeComplete) {
                cur_client->doHandshake(udpSocket, datagram);
            }
        }
        usleep(2000000);
        if (completed()) {
            write_message(client_1, "successful connection.");
            write_message(client_2, "successful connection.");
            break;
        }
    }
}

void Server::set_addr(QHostAddress addr, quint16 port) {
    server_addr = std::move(addr);
    server_port = port;
}

int Server::get_player_number(const QHostAddress& addr, quint16 port) {
    QDtls* cur_p = get_client(addr, port);
    return cur_p==client_1?1:2;
}

RawCommand Server::get() {
    udpSocket->waitForReadyRead(-1);
    QByteArray datagram;
    datagram.resize(udpSocket->pendingDatagramSize());
    QHostAddress sender;
    quint16 senderPort;
    udpSocket->readDatagram(datagram.data(), datagram.size(),
                            &sender, &senderPort);
    QDtls* p = get_client(sender, senderPort);
    if (p)
        return RawCommand((p->decryptDatagram(udpSocket, datagram)).toStdString(), get_player_number(sender, senderPort));
    return RawCommand("", -1);
}

Server* Server::get_instance() {
    if (!instance)
        instance = new Server();
    return instance;
}
