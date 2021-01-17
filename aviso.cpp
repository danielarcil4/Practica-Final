#include "aviso.h"
#include "ui_aviso.h"

Aviso::Aviso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aviso)
{
    ui->setupUi(this);
}

Aviso::~Aviso()
{
    delete ui;
}

void Aviso::on_pushButton_clicked()
{
    this->close();
}
