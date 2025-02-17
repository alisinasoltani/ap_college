#include "cobitex.h"
#include "./ui_cobitex.h"

Cobitex::Cobitex(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cobitex)
{
    ui->setupUi(this);
}

Cobitex::~Cobitex()
{
    delete ui;
}
