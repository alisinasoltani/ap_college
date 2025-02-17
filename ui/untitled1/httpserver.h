#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class HttpServer : public QTcpServer {
    Q_OBJECT
public:
    explicit HttpServer(QObject *parent = nullptr);
    void startServer();

private slots:
    void handleNewConnection();
    void readRequest();

private:
    QByteArray buildResponse();
};

#endif // HTTPSERVER_H
