#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include "../include/Navbar.h"

Navbar::Navbar(QWidget* parent): QWidget(parent) {
    this->navbar = new QWidget;
    this->navbarLayout = new QHBoxLayout;

    navbar->setFixedHeight(60);
    navbar->setStyleSheet("background-color: #000000;");

    QLabel *logoLabel = new QLabel(navbar);
    QPixmap logoPixmap("D:/GitHub/ap_college/ui/untitled/Widgets/pictures/logo.png");
    if (!logoPixmap.isNull()) {
        logoLabel->setPixmap(logoPixmap.scaled(120, 34, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        logoLabel->setText("Logo Missing");
        logoLabel->setStyleSheet("color: white; font-size: 14px;");
    }
    logoLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    QHBoxLayout *navbarLayout = new QHBoxLayout(navbar);
    navbarLayout->setContentsMargins(20, 10, 20, 10);
    navbarLayout->addWidget(logoLabel);
}

Navbar::~Navbar() {
    delete this->navbar;
    delete this->navbarLayout;
}
