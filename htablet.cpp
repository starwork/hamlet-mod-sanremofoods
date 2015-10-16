#include "htablet.h"
#include "ui_htablet.h"

Htablet::Htablet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Htablet)
{
    ui->setupUi(this);
}

Htablet::~Htablet()
{
    delete ui;
}
