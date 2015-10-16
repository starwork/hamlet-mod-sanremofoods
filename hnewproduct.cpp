#include "hnewproduct.h"
#include "ui_hnewproduct.h"
#include "hnuovaricetta.h"

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

HNewProduct::HNewProduct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HNewProduct)
{
    ui->setupUi(this);
}

HNewProduct::~HNewProduct()
{
    delete ui;
}


void HNewProduct::on_pushButton_2_clicked()
{
    this->close();
}

void HNewProduct::init(QString conn)
{
    sConn=conn;
    db=QSqlDatabase::database(sConn);

    tmTipo=new QSqlTableModel(0,db);
    tmTipo->setTable("tipi_prodotto");
    tmTipo->setSort(1,Qt::AscendingOrder);
    tmTipo->select();

    ui->comboBox->setModel(tmTipo);
    ui->comboBox->setModelColumn(1);

    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(tipoSelected()));




}

void HNewProduct::tipoSelected()
{
    int tipo=ui->comboBox->model()->index(ui->comboBox->currentIndex(),0).data(0).toInt();

    if (tipo==1)
    {
        ui->pbSaveAndCreate->setVisible(true);
    }
    else
    {
         ui->pbSaveAndCreate->setVisible(false);
    }

}

void HNewProduct::addNewProduct()
{
    QSqlQuery q(db);
    QString query;
    QVariant descrizione,tipo,allergenico,attivo;

    descrizione=ui->leDescrizione->text().toUpper();
    tipo=ui->comboBox->model()->index(ui->comboBox->currentIndex(),0).data(0).toString();
   /* if (ui->cbAllergenico->isChecked())
    {
       allergenico="1";
    }
    else
    {
        allergenico="0";
    }*/

    attivo="1";
    allergenico=0;


    query="INSERT INTO prodotti (descrizione,tipo,attivo) VALUES(:desc,:tipo,:attivo)";
    q.prepare(query);
    q.bindValue(":desc",QVariant(descrizione));
    q.bindValue(":tipo",QVariant(tipo));
    q.bindValue(":allerg",QVariant(allergenico));
    q.bindValue(":attivo",QVariant(attivo));


    if(q.exec())
    {
        ui->leDescrizione->setText("");

    }
    else
    {
        QMessageBox::warning(this, QApplication::applicationName(),"Errore salvando il prodotto\n"+q.lastError().text(),QMessageBox::Ok);
    }
}



void HNewProduct::on_pushButton_clicked()
{
    addNewProduct();
}
