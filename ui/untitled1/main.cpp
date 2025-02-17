#include <QCoreApplication>
#include "httpserver.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    HttpServer server;
    server.startServer();
    return a.exec();
}
