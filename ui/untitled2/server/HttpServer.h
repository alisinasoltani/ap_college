#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>

class HttpServer : public QTcpServer {
    Q_OBJECT

public:
    explicit HttpServer(QObject *parent = nullptr);

protected:
    void incomingConnection(qintptr socketDescriptor) override;
};

class ConnectionHandler : public QThread {
    Q_OBJECT

public:
    explicit ConnectionHandler(qintptr socketDescriptor, QObject *parent = nullptr);
    void run() override;

private:
    qintptr m_socketDescriptor;
    QByteArray getRequestBody(const QList<QByteArray> &requestLines) {
        for(int i=1; i<requestLines.size(); i++) {
            if(requestLines[i].isEmpty()) {
                return requestLines.mid(i+1).join("\r\n");
            }
        }
        return "";
    }

    void sendResponse(QTcpSocket &socket, int statusCode, const QByteArray &body) {
        QByteArray response = QString("HTTP/1.1 %1 %2\r\n"
                                      "Content-Type: application/json\r\n"
                                      "Content-Length: %3\r\n\r\n")
                                  .arg(statusCode)
                                  .arg(getStatusText(statusCode))
                                  .arg(body.size())
                                  .toUtf8();
        response += body;
        socket.write(response);
        socket.flush();
    }

    QString getStatusText(int statusCode) {
        switch(statusCode) {
        case 200: return "OK";
        case 201: return "Created";
        case 400: return "Bad Request";
        case 404: return "Not Found";
        case 500: return "Internal Server Error";
        default: return "Unknown";
        }
    }
};

#endif // HTTPSERVER_H
