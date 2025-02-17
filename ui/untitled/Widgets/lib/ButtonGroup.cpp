#include "../include/ButtonGroup.h"
// #include "./ui_mainwindow.h"
#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>


ButtonGroup::ButtonGroup(QWidget *parent)
    : QWidget(parent)
{
    this->body = new QVBoxLayout;
    this->buttonLayout = new QHBoxLayout;
    this->buttonContainer = new QGroupBox("Horizontal Layout");

    this->btn1 = new QPushButton("button 1");
    this->btn2 = new QPushButton("button 2");
    this->btn3 = new QPushButton("button 3");
    this->btn4 = new QPushButton("button 4");

    this->buttonContainer->setLayout(buttonLayout);
    this->buttonLayout->addWidget(btn1);
    this->buttonLayout->addWidget(btn2);
    this->buttonLayout->addWidget(btn3);
    this->buttonLayout->addWidget(btn4);

    this->buttonLayout->setSizeConstraint(QLayout::SetFixedSize);
    this->body->addWidget(buttonContainer);
    this->body->setSizeConstraint(QLayout::SetFixedSize);
    this->setLayout(body);
}

ButtonGroup::~ButtonGroup() {
    delete this->body;
    delete this->buttonContainer;
    delete this->buttonLayout;
    delete this->btn1;
    delete this->btn2;
    delete this->btn3;
    delete this->btn4;
}
