#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QVBoxLayout mainLayout;
    QLabel nameLabel("HELLO?");
    QLabel nameLabel2("HELLO??");
    QLineEdit input1;
    QPushButton button("Submit");

    mainLayout.addWidget(&nameLabel);
    mainLayout.addWidget(&nameLabel2);
    mainLayout.addWidget(&input1);
    mainLayout.addWidget(&button);

    w.show();
    return a.exec();
}
