#include <QCoreApplication>
#include "server/HttpServer.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    HttpServer server;
    if (!server.listen(QHostAddress::Any, 8080)) {
        qCritical() << "Unable to start the server:" << server.errorString();
        return 1;
    }

    qDebug() << "Multithreaded server is running on port 8080...";
    return app.exec();
}
