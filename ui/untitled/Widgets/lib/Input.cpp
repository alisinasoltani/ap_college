#include "../include/Input.h"
#include <QWidget>
#include <QGroupBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QLabel>
#include <QGridLayout>

Input::Input(QWidget* parent)
    : QWidget(parent) {
    this->row = new QHBoxLayout;
    this->container = new QGroupBox("Grid Layout");
    this->inputLayout = new QGridLayout;
    this->line1 = new QLineEdit;
    this->line2 = new QLineEdit;
    this->line3 = new QLineEdit;
    this->lineLabel1 = new QLabel("Line 1");
    this->lineLabel2 = new QLabel("Line 2");
    this->lineLabel3 = new QLabel("Line 3");
    this->textBox = new QTextEdit;

    this->inputLayout->addWidget(this->lineLabel1, 2,0,1,1);
    this->inputLayout->addWidget(this->lineLabel2, 3,0,1,1);
    this->inputLayout->addWidget(this->lineLabel3, 4,0,1,1);

    this->inputLayout->addWidget(this->line1, 2,1,1,2);
    this->inputLayout->addWidget(this->line2, 3,1,1,2);
    this->inputLayout->addWidget(this->line3, 4,1,1,2);

    this->inputLayout->addWidget(this->textBox, 0,3,5,3);

    this->inputLayout->setSizeConstraint(QLayout::SetFixedSize);
    this->container->setLayout(inputLayout);
    this->row->addWidget(this->container);
    this->row->setSizeConstraint(QLayout::SetFixedSize);
    this->setLayout(row);
}

Input::~Input() {
    delete this->row;
    delete this->container;
    delete this->inputLayout;
    delete this->line1;
    delete this->line2;
    delete this->line3;
    delete this->lineLabel1;
    delete this->lineLabel2;
    delete this->lineLabel3;
    delete this->textBox;
}
