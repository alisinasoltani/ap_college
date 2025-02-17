#include "../include/UserProfile.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMainWindow>

Profile::Profile(QWidget* parent): QWidget(parent) {
    this->layout = new QGridLayout;
    this->sideBar = new QWidget;

    this->setLayout(this->layout);
    this->layout->addWidget(sideBar);

    this->sideBar->setStyleSheet(
    ""
        );
}

Profile::~Profile() {
    delete this->layout;
    delete this->sideBar;
}
