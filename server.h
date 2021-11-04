#ifndef SERVER_H
#define SERVER_H
#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <QObject>
#include<QWebSocket>
#include<QWebSocketServer>
#include<QDebug>
#include<qwebsocketserver.h>
#include<qwebsocket.h>


class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
    QWebSocketServer *server;


public slots:
    void newConnection();
private:



};

#endif // SERVER_H
