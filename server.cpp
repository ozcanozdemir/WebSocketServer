#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    server= new QWebSocketServer(QStringLiteral("server"), QWebSocketServer::NonSecureMode,this);

    connect(server,&QWebSocketServer::newConnection,this,&Server::newConnection);

    if(!server->listen(QHostAddress("172.16.50.155"),1234))
    {
        qDebug()<<"server could not start";
    }
    else
    {
        qDebug()<<"server started";
    }
}

Server::~Server()
{
    server->close();
}

void Server::newConnection()
{
    qDebug()<<"acıldı";
    QWebSocket *socket= server->nextPendingConnection();

    socket->sendTextMessage("piton client geldi");
    //socket->close();
}
