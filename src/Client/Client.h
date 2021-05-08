#pragma once
#include <QtNetwork>
#include <QDtls>
#include <iostream>
#include <unistd.h>
#include <thread>


class ClientAuthHandler: public QObject {
public slots:
    void pskRequired(QSslPreSharedKeyAuthenticator *auth);
};

<<<<<<< HEAD
class Client: public QObject {
=======
class Client {
>>>>>>> dev_2
    std::thread game_thread;
    QHostAddress server_addr;
    quint16 server_port = 0;
    bool running = false;
    bool connected_to_host = false;
    QSslConfiguration client_config;
    std::vector<bool> stages;
    QUdpSocket client_socket;
    QDtls server_dtls;
    QTextStream out_stream;
    QTextStream in_stream;
    void send(const QString& msg);
    QString get_from_server();
    void to_console(const QString& msg);
    void default_error_message();
    QString from_console();
    void typo();
    int stage_1();
    int stage_2();
    int stage_5();
    int stage_10();
    void connect(const QHostAddress& server_address, quint16 s_port);
    void start_game();
    bool check_for_emergency_message(QString msg);
    void disconnect();
    void handle_message(const QString& msg);

public:
    Client();
    void run();
<<<<<<< HEAD
=======
public slots:
    void timeout();
>>>>>>> dev_2
};
