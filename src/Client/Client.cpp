#include "Client.h"
#include <exception>
#include <cstdlib>
#include <filesystem>

void ClientAuthHandler::pskRequired(QSslPreSharedKeyAuthenticator *auth) {
    QTextStream u(stdout);
    auth->setPreSharedKey(QByteArrayLiteral("\x1a\x2b\x3c\x4d\x5e\x6f"));
}

struct BadConnection : public std::exception
{

};


void Client::to_console(const QString& msg) {
    QTextStream out(stdout);
    out << msg;
//    out_stream << msg;
//    std::cout << msg.toStdString();
}



Client::Client(): server_dtls(QSslSocket::SslClientMode),
                                    in_stream(stdin), out_stream(stdout) {
    stages = std::vector<bool>(11);
    client_config = QSslConfiguration::defaultDtlsConfiguration();
    client_config.setDtlsCookieVerificationEnabled(false);
    client_config.setPeerVerifyMode(QSslSocket::VerifyNone);
    server_dtls.setDtlsConfiguration(client_config);
    ClientAuthHandler handler;
    QDtls::connect(&server_dtls, &QDtls::pskRequired, &handler, &ClientAuthHandler::pskRequired);
}


void Client::connect(const QHostAddress& server_address, quint16 s_port) {
    this->server_port = s_port;
    this->server_addr = server_address;
    bool res;
    res = server_dtls.setPeer(server_addr, server_port);
    client_socket.connectToHost(server_addr, server_port);

//    if (client_socket.errorString().size() != 0) {
//        std::cout << client_socket.errorString().toStdString();
//        throw BadConnection();
//    }

    quint16 port;
    QHostAddress address;
    QByteArray server_hello;

    //while (!client_socket.hasPendingDatagrams()) {
<<<<<<< HEAD
=======
//    QDtls::connect(&server_dtls, &QDtls::handshakeTimeout, this, &Client::timeout);
//    connect(&client_socket, &QAbstractSocket::connected, this, &DtlsAssociation::udpSocketConnected);
//    connect(&pingTimer, &QTimer::timeout, this, &DtlsAssociation::pingTimeout);
>>>>>>> dev_2
        server_dtls.doHandshake(&client_socket);
        //usleep(5000000);
    //}
    ClientAuthHandler h;
<<<<<<< HEAD
=======

>>>>>>> dev_2
    QDtls::connect(&server_dtls, &QDtls::pskRequired, &h, &ClientAuthHandler::pskRequired);
    while (server_dtls.handshakeState() != QDtls::HandshakeComplete) {
        while (client_socket.hasPendingDatagrams()) {
            server_hello = QByteArray(client_socket.pendingDatagramSize(), Qt::Uninitialized);
            client_socket.readDatagram(server_hello.data(), server_hello.size(), &address, &port);
            if (server_dtls.handshakeState() != QDtls::HandshakeComplete) {
                server_dtls.doHandshake(&client_socket, server_hello);
            }
        }
    }
    to_console("connection established.\n");
}

<<<<<<< HEAD
QString Client::from_console() {
    std::string result;
    std::cin >> result;
    std::string without_spaces;
    for (auto && i : result) {
        if (i != ' ')
            without_spaces += i;
    }
    return without_spaces.c_str();
}

void Client::send(const QString& msg) {
    QByteArray in_byte = msg.toUtf8();
=======
void Client::timeout() {
    to_console("Timeout.");
    throw std::invalid_argument("timeout");
}

QString Client::from_console() {
    std::string result;
    std::getline( std::cin, result);
//    std::string without_spaces;
//    for (auto && i : result) {
//        if (i != ' ')
//            without_spaces += i;
//    }
    return result.c_str();
}

QString remove_spaces(const QString& obj) {
    QString result = "";
    for (auto el: obj) {
        if (el != ' ')
            result += el;
        else
            result += ';';
    }
    return result;
}

void Client::send(const QString& msg) {
//    to_console(msg);
//    std::string res = msg.toStdString();
    QByteArray in_byte = remove_spaces(msg).toUtf8();
>>>>>>> dev_2
    server_dtls.writeDatagramEncrypted(&client_socket, in_byte);
}

QString Client::get_from_server() {
    quint16 port;
    QHostAddress address;
    QByteArray server_hello;
    client_socket.waitForReadyRead(-1);
    server_hello = QByteArray(client_socket.pendingDatagramSize(), Qt::Uninitialized);
    client_socket.readDatagram(server_hello.data(), server_hello.size(), &address, &port);
    std::string f = server_hello.toStdString();
    return server_dtls.decryptDatagram(&client_socket, server_hello);
}

void Client::disconnect() {
    running = false;
}

void Client::handle_message(const QString& msg) {
    std::string f = msg.toStdString();
    if (msg == "shutdown") {
        disconnect();
    }
    else if (msg == "successful connection.") {
        to_console("the second player is in. Game starts\n");
    }
    else {
        to_console(msg);
        to_console("\n");
    }
}

void Client::start_game() {
    running = true;
    QString client_msg;
    QString server_msg;
    while (running) {
        if (client_socket.hasPendingDatagrams()) {
            while (client_socket.hasPendingDatagrams()) {
                server_msg = get_from_server();
                handle_message(server_msg);
            }
            client_msg = from_console();
            send(client_msg);
        }
        usleep(1000);
    }
}

void Client::typo() {
    to_console("Guess you have typed something wrong, try again\n");
}

bool Client::check_for_emergency_message(QString msg) {
    if (msg == "return") {
        stages.assign(11, false);
        return true;
    }
    return false;
}

int Client::stage_1() {
    if (!stages[1]) {
        to_console("Hello! You are about to play the greatest game of all time.\n"
                   "At first, choose whether you want to connect to the existing game\n"
                   "in the local network or you want to create one by yourself. (type 'connect' or 'create')\n");
        stages[1] = true;
    }
    else {
        to_console("create or connect?\n");
    }
    QString response = from_console();
    if (check_for_emergency_message(response))
        return 1;
    if (response == "connect") {
        return 2;
    }
    else if (response == "create") {
        return 10;
    }
    else {
        typo();
        return 1;
    }
}

int Client::stage_2() {
    if (!stages[2]) {
        to_console("Alright, so now input IP address and port of your opponent\n");
        to_console("You should type them in two separate messages, like this:\n127.0.0.1\n4433\n");
        stages[2] = true;
    }
    else {
        to_console("again: IP\nPORT\nTry:\n");
    }
    QString ip = from_console();
    if (check_for_emergency_message(ip))
        return 1;
    QString port = from_console();
    if (check_for_emergency_message(port))
        return 1;
    try {
        server_addr = QHostAddress(ip);
        server_port = quint16(port.toInt());
    } catch (...) {
        typo();
        return 2;
    }
    return 5;
}


int Client::stage_5() {
    to_console("So now I will try to connect to the server with the provided address\n");
    try {
        usleep(5000000); // 5 secs to raise server
        connect(server_addr, server_port);
    } catch (const BadConnection&) {
<<<<<<< HEAD
=======
        client_socket.disconnectFromHost();
>>>>>>> dev_2
        to_console("so connection was not successful, probably you have missed something, try again\n");
        return 2;
    }
    return 0;
}

void create_server(const QHostAddress& addr, quint16 port) {
    std::string cur_dir = std::filesystem::current_path().string();
    std::string port_str = QString::number(port).toStdString();
    std::string addr_str = addr.toString().toStdString();
    std::string ans = cur_dir + std::string("/Ravinagar ") + addr_str + std::string(" ") + port_str + " &";
    system(ans.c_str());
}

bool check_address(const QHostAddress& addr, quint16 port) {
    return true;
}

int Client::stage_10() {
    if (!stages[2]) {
        to_console("Alright, so now input your public IP address and port\n");
        to_console("You should type them in two separate messages, like this:\n127.0.0.1\n4433\n");
        stages[2] = true;
    }
    QString ip = from_console();
    if (check_for_emergency_message(ip))
        return 1;
    QString port = from_console();
    if (check_for_emergency_message(port))
        return 1;
    try {
        server_addr = QHostAddress(ip);
        server_port = quint16(port.toInt());
    } catch (...) {
        typo();
        return 2;
    }
    bool started = check_address(server_addr, server_port);
    if (!started) {
        to_console("server could not be created, try to check ip and port and try again:\n");
        return 10;
    }
    else {
        create_server(server_addr, server_port);
        to_console("Probably server is created successfully.\n");
    }
    return 5;
}

void Client::default_error_message() {
    to_console("Something went wrong.");
}

void Client::run() {
    QString client_msg;
    int stage = 1;
    // stage 1 - choose whether you want to connect or create your own game
    // if own - run server -> stage 10, if connect - stage 2:
    // stage 2 - choose IP-address and port of your opponent -> stage 5
    // stage 10 - choose IP and port of your server -> stage 5
    // stage 5 - connect to server
    // start_game()
    // if stage == 0, game can be started
    // if stage == -1, something went wrong
    while (stage) {
        switch (stage) {
            case 1:
                stage = stage_1();
                break;
            case 2:
                stage = stage_2();
                break;
            case 5:
                stage = stage_5();
                break;
            case 10:
                stage = stage_10();
                break;
            default:
                default_error_message();
                stage = 1;
                stages.assign(11, false);
                break;
            }
    }
    start_game();
}
