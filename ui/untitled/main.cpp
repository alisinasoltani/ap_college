#include <QApplication>
#include <QCoreApplication>
// #include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QsqlDatabase>

// int main(int argc, char *argv[]) {
//     QApplication app(argc, argv);

//     QMainWindow mainWindow;
//     mainWindow.setWindowTitle("Navbar with Logo Example");
//     mainWindow.resize(1920, 1080);

//     QWidget *centralWidget = new QWidget;

//     QWidget *navbar = new QWidget;
//     navbar->setFixedHeight(60);
//     navbar->setStyleSheet("background-color: #000000;");

//     QLabel *logoLabel = new QLabel(navbar);
//     QPixmap logoPixmap("D:/GitHub/ap_college/ui/untitled/Widgets/pictures/logo.png");
//     if (!logoPixmap.isNull()) {
//         logoLabel->setPixmap(logoPixmap.scaled(120, 34, Qt::KeepAspectRatio, Qt::SmoothTransformation));
//     } else {
//         logoLabel->setText("Logo Missing");
//         logoLabel->setStyleSheet("color: white; font-size: 14px;");
//     }
//     logoLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

//     QHBoxLayout *navbarLayout = new QHBoxLayout(navbar);
//     navbarLayout->setContentsMargins(20, 10, 20, 10);
//     navbarLayout->addWidget(logoLabel);

//     QWidget *sidebar = new QWidget;
//     sidebar->setFixedWidth(250);
//     sidebar->setStyleSheet("background-color: #0B0B0B;");

//     QWidget *contentArea = new QWidget;
//     contentArea->setStyleSheet("background-color: #101010;");

//     QLabel *contentLabel = new QLabel("Main Content Area", contentArea);
//     contentLabel->setAlignment(Qt::AlignCenter);

//     QHBoxLayout *contentLayout = new QHBoxLayout;
//     contentLayout->setContentsMargins(0, 0, 0, 0);
//     contentLayout->setSpacing(0);
//     contentLayout->addWidget(sidebar);
//     contentLayout->addWidget(contentArea);

//     QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
//     mainLayout->setContentsMargins(0, 0, 0, 0);
//     mainLayout->setSpacing(0);
//     mainLayout->addWidget(navbar);
//     mainLayout->addLayout(contentLayout);

//     mainWindow.setCentralWidget(centralWidget);

//     mainWindow.show();

//     return app.exec();
// }
int main(int argc, char *argv[]) {
    qdebug() << QsqlDatabase::drivers();
}
