#include "HttpServer.h"
#include <QDebug>
#include "../database/DatabaseManager.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QRegularExpression>

HttpServer::HttpServer(QObject *parent) : QTcpServer(parent) {}

void HttpServer::incomingConnection(qintptr socketDescriptor) {
    ConnectionHandler *handler = new ConnectionHandler(socketDescriptor, this);
    connect(handler, &QThread::finished, handler, &QObject::deleteLater);
    handler->start();
}

ConnectionHandler::ConnectionHandler(qintptr socketDescriptor, QObject *parent)
    : QThread(parent), m_socketDescriptor(socketDescriptor) {
}

void ConnectionHandler::run() {
    QTcpSocket socket;
    if (!socket.setSocketDescriptor(m_socketDescriptor)) {
        qCritical() << "Failed to set socket descriptor";
        return;
    }

    connect(&socket, &QTcpSocket::stateChanged, [](QAbstractSocket::SocketState state) {
        qDebug() << "Socket state changed to:" << state;
    });

    if (socket.waitForReadyRead(10000)) {
        QByteArray request = socket.readAll();
        qDebug() << "Request received:\n" << request;

        QList<QByteArray> requestLines = request.split('\n');
        for (QByteArray &line : requestLines) {
            line = line.trimmed();
        }
        QByteArray requestLine = requestLines[0];
        QList<QByteArray> parts = requestLine.split(' ');
        QByteArray method = parts[0];
        QByteArray path = parts[1];
        qDebug() << "Raw request line:" << requestLine;
        qDebug() << "Split parts:" << parts;
        qDebug() << "Method:" << method << "Path:" << path;

        DatabaseManager dbManager;
        if(!dbManager.initializeDatabase()) {
            sendResponse(socket, 500, "Database initialization failed");
            return;
        }

        QByteArray response;
        if (path.startsWith("/users")) {
            QRegularExpressionMatch match = QRegularExpression("^\\/users\\/(\\d+)\\/?$", QRegularExpression::CaseInsensitiveOption).match(path);

            int userId = match.hasMatch() ? match.captured(1).toInt() : -1;

            if (method == "POST") {
                QJsonDocument doc = QJsonDocument::fromJson(getRequestBody(requestLines));
                QJsonObject result = dbManager.createUser(doc.object());
                response = QJsonDocument(result).toJson();
            }
            else if (method == "GET" && userId != -1) {
                QJsonObject result = dbManager.getUser(userId);
                response = QJsonDocument(result).toJson();
            }
            else if (method == "PUT" && userId != -1) {
                QJsonDocument doc = QJsonDocument::fromJson(getRequestBody(requestLines));
                QJsonObject result = dbManager.updateUser(userId, doc.object());
                response = QJsonDocument(result).toJson();
            }
            else if (method == "DELETE" && userId != -1) {
                bool success = dbManager.deleteUser(userId);
                response = QJsonDocument(QJsonObject{{"success", success}}).toJson();
            }
            else {
                sendResponse(socket, 400, "Invalid request");
                return;
            }
        } else if (path.startsWith("/orders")) {
            QRegularExpressionMatch orderMatch = QRegularExpression("^/orders/(\\d+)$").match(path);
            int orderId = orderMatch.hasMatch() ? orderMatch.captured(1).toInt() : -1;
            if (method == "POST") {
                QJsonDocument doc = QJsonDocument::fromJson(getRequestBody(requestLines));
                QJsonObject result = dbManager.createOrder(doc.object());
                response = QJsonDocument(result).toJson();
            }
            else if (method == "GET" && orderId != -1) {
                QJsonObject result = dbManager.getOrder(orderId);
                response = QJsonDocument(result).toJson();
            }
            else if (method == "DELETE" && orderId != -1) {
                bool success = dbManager.deleteOrder(orderId);
                response = QJsonDocument(QJsonObject{{"success", success}}).toJson();
            }
            else {
                sendResponse(socket, 400, "Invalid request");
                return;
            }
        } else if (path.startsWith("/requests")) {
            QRegularExpressionMatch requestMatch = QRegularExpression("^/requests/(\\d+)$").match(path);
            int requestId = requestMatch.hasMatch() ? requestMatch.captured(1).toInt() : -1;
            if (method == "POST") {
                QJsonDocument doc = QJsonDocument::fromJson(getRequestBody(requestLines));
                QJsonObject result = dbManager.createRequest(doc.object());
                response = QJsonDocument(result).toJson();
            }
            else if (method == "GET" && requestId != -1) {
                QJsonObject result = dbManager.getRequest(requestId);
                response = QJsonDocument(result).toJson();
            }
            else if (method == "DELETE" && requestId != -1) {
                bool success = dbManager.deleteRequest(requestId);
                response = QJsonDocument(QJsonObject{{"success", success}}).toJson();
            }
            else {
                sendResponse(socket, 400, "Invalid request");
                return;
            }
        } else if (path.startsWith("/wallets")) {
            QRegularExpressionMatch walletMatch = QRegularExpression("^/wallets/(\\d+)$").match(path);
            int walletId = walletMatch.hasMatch() ? walletMatch.captured(1).toInt() : -1;
            if (method == "POST") {
                QJsonDocument doc = QJsonDocument::fromJson(getRequestBody(requestLines));
                QJsonObject result = dbManager.createUser(doc.object());
                response = QJsonDocument(result).toJson();
            }
            else if (method == "GET" && walletId != -1) {
                QJsonObject result = dbManager.getWallet(walletId);
                response = QJsonDocument(result).toJson();
            }
            else if (method == "PUT" && walletId != -1) {
                QJsonDocument doc = QJsonDocument::fromJson(getRequestBody(requestLines));
                QJsonObject result = dbManager.updateWallet(walletId, doc.object());
                response = QJsonDocument(result).toJson();
            }
            else if (method == "DELETE" && walletId != -1) {
                bool success = dbManager.deleteWallet(walletId);
                response = QJsonDocument(QJsonObject{{"success", success}}).toJson();
            }
            else {
                sendResponse(socket, 400, "Invalid request");
                return;
            }
        } else {
            sendResponse(socket, 404, "Not Found");
            return;
        }

        sendResponse(socket, 200, response);
    }

    // Gracefully close the connection
    if (socket.state() == QAbstractSocket::ConnectedState) {
        socket.disconnectFromHost();
        if (socket.state() != QAbstractSocket::UnconnectedState) {
            if (!socket.waitForDisconnected(10000)) {
                qWarning() << "Socket did not disconnect cleanly.";
            }
        }
    } else {
        qDebug() << "Socket already disconnected.";
    }
}
