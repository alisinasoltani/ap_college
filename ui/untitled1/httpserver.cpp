#include "httpserver.h"
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

HttpServer::HttpServer(QObject *parent) : QTcpServer(parent) {}

void HttpServer::startServer() {
    if (!listen(QHostAddress::Any, 3000)) {
        qDebug() << "Error starting server:" << errorString();
        exit(EXIT_FAILURE);
    }
    qDebug() << "Server listening on port 3000...";
}

void HttpServer::handleNewConnection() {
    QTcpSocket *clientSocket = nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &HttpServer::readRequest);
    connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);
}

void HttpServer::readRequest() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) return;

    // Read the request (optional, since we're sending a fixed response)
    clientSocket->readAll();

    // Send response
    QByteArray response = buildResponse();
    clientSocket->write(response);

    // Wait for data to be written before closing
    if (clientSocket->waitForBytesWritten()) {
        clientSocket->disconnectFromHost();
    }
}

QByteArray HttpServer::buildResponse() {
    return QByteArray(
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html; charset=utf-8\r\n"
        "Connection: close\r\n"
        "\r\n"
        "<h1>Hello from Qt HTTP Server!</h1>"
        );
}
