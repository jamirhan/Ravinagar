#pragma once
#include <string>
#include <queue>
#include "../Message.h"
#include <QUdpSocket>
#include <QDtls>
#include <QtNetwork>
#include <iostream>

struct AuthHandler: public QObject {
public slots:
    void pskRequired(QSslPreSharedKeyAuthenticator *auth);
};

struct RawCommand;


class Server {
    QUdpSocket* udpSocket;
    QDtls* client_1 = nullptr;
    QDtls* client_2 = nullptr;
    inline static QHostAddress server_addr;
    inline static quint16 server_port;
    bool running = false;
    QSslConfiguration server_config;
    AuthHandler handler;
    static Server* instance;
    QDtls* get_client(const QHostAddress& addr, quint16 port);
    void set_client(QHostAddress addr, quint16 port);
    std::string get_response();
    static quint16 choose_port();
    static QHostAddress get_public_ip();
    void write_message(QDtls* client, const QByteArray& msg);
    bool completed();
    void wait_two_connections();
    int get_player_number(const QHostAddress& addr, quint16 port);
    Server();
public:
    static Server* get_instance();
    void start();
    static void set_addr(QHostAddress addr, quint16 port);
    RawCommand get();
    bool is_running();
    void write(int player_num, QString msg);
};
