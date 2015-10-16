#include "hscheda.h"
#include "ui_hscheda.h"
#include "huser.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QImage>
#include <QDebug>
#include <QGraphicsScene>
#include <QTextDocument>
#include <QFileDialog>
#include <QImageReader>
#include "hmodificascheda.h"
#include <QTextDocumentFragment>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QByteArray>
#include <QTextCodec>

#include <QSqlError>


HScheda::HScheda(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HScheda)
{
    ui->setupUi(this);
}

HScheda::~HScheda()
{
    delete ui;

}


void HScheda::init(QString conn,HUser* usr)
{
  db=QSqlDatabase::database(conn);
  user=usr;
  if(!user->getCanUpdate())
  {
      ui->pushButton_2->setVisible(false);
  }
  QSqlTableModel *mod=new QSqlTableModel(0,db);
  mod->setTable("anagrafica");
  mod->setFilter("cliente=1");
  mod->setSort(1,Qt::AscendingOrder);
  mod->select();
  ui->cbClienti->setModel(mod);
  ui->cbClienti->setModelColumn(1);




  connect (ui->cbClienti,SIGNAL(currentIndexChanged(int)),this,SLOT(getSubclients()));
  connect (ui->cbClienti,SIGNAL(currentIndexChanged(int)),this,SLOT(getRecipesForClient()));
//  connect(ui->textEdit,SIGNAL())
  ui->textEdit->setAcceptDrops(true);



}

void HScheda::loadScheda()
{
    QString sql;
    QSqlQuery q(db);
    QString htm;

   // bool newformat=true;



    sql="SELECT scheda from schede where cliente=:idcliente and prodotto=:idprodotto";


    q.prepare(sql);
    q.bindValue(":idcliente",QVariant(idcliente));
    q.bindValue(":idprodotto",QVariant(idprodotto));
    q.exec();
    q.first();



    QString scheda=q.value(0).toString();
    htm.append(scheda);


    ui->textEdit->setHtml(htm);

    }

void HScheda::loadSchedaOld()
{
    QString sql;
    QSqlQuery q(db);
    QString htm;





    sql="SELECT olio,vaso,tappo,etichette,scatole,note,immagine from schede where cliente=:idcliente and prodotto=:idprodotto";


    q.prepare(sql);
    q.bindValue(":idcliente",QVariant(idcliente));
    q.bindValue(":idprodotto",QVariant(idprodotto));
    q.exec();
    q.first();



    htm="<p align='center'><h1>"+ ui->listView->currentIndex().data(0).toString() + " -" + ui->cbClienti->model()->index(ui->cbClienti->currentIndex(),1).data(0).toString() +  "</h1></p>";

    htm.append("<br><br>");
    htm.append("<table width=100% align=center>");
    htm.append("<tr>");
    htm.append("<td>");
    htm.append("<h2>OLIO:</h2>");
    htm.append("</td>");
    htm.append("<td>");
    htm.append(q.value(0).toString());
    htm.append("</td>");
    htm.append("</tr>");


    htm.append("<tr>");
    htm.append("<td>");
    htm.append("<h2>VASO:</h2>");
    htm.append("</td>");
    htm.append("<td>");
    htm.append(q.value(1).toString());
    htm.append("</td>");
    htm.append("</tr>");

    htm.append("<tr>");
    htm.append("<td>");
    htm.append("<h2>TAPPO:</h2>");
    htm.append("</td>");
    htm.append("<td>");
    htm.append(q.value(2).toString());
    htm.append("</td>");
    htm.append("</tr>");

    htm.append("<tr>");
    htm.append("<td>");
    htm.append("<h2>ETICHETTE:</h2>");
    htm.append("</td>");
    htm.append("<td>");
    htm.append(q.value(3).toString());
    htm.append("</td>");
    htm.append("</tr>");

    htm.append("<tr>");
    htm.append("<td>");
    htm.append("<h2>SCATOLE:</h2>");
    htm.append("</td>");
    htm.append("<td>");
    htm.append(q.value(4).toString());
    htm.append("</td>");
    htm.append("</tr>");

    htm.append("<tr>");
    htm.append("<td>");
    htm.append("<h2>NOTE:</h2>");
    htm.append("</td>");
    htm.append("<td>");
    htm.append(q.value(5).toString());
    htm.append("</td>");
    htm.append("</tr>");

    htm.append("<tr>");
    htm.append("<td>");
    htm.append("<h2>IMMAGINE:</h2>");
    htm.append("</td>");
    htm.append("<td>");
  //  htm.append("<div width=300px height=100px>");
  //  htm.append(q.value(6).toString());
  //  htm.append("</div>");
    htm.append("</td>");
    htm.append("</tr>");
    htm.append("</table>");

    ui->textEdit->setHtml(htm);
}

void HScheda::getRecipesForClient()
{


   QString query="SELECT ricette.ID_prodotto, prodotti.descrizione FROM ricette, prodotti WHERE prodotti.ID=ricette.ID_prodotto AND ricette.ID IN (SELECT ID_ricetta FROM associazioni WHERE ID_cliente=:id)";
   QSqlQuery q(db);
   q.prepare(query);
   q.bindValue(":id",QVariant(idcliente));
   q.exec();

   QSqlQueryModel *qrm=new QSqlQueryModel();


   qrm->setQuery(q);


   QModelIndex index=qrm->index(0,0);

   ui->listView->setModel(qrm);
   ui->listView->setModelColumn(1);
   ui->listView->setCurrentIndex(index);

   idprodotto=ui->listView->model()->index(ui->listView->selectionModel()->currentIndex().row(),0).data().toInt();
   connect (ui->listView->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(setIDCLiente()));
   connect(ui->listView->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(loadScheda()));

   setIDCLiente();


}
void HScheda::on_pushButton_clicked()
{
    close();
}

void HScheda::getSubclients()
{
    idcliente= ui->cbClienti->model()->index(ui->cbClienti->currentIndex(),0).data(0).toInt();
    QSqlQueryModel *subclients=new QSqlQueryModel();
    QSqlQuery q(db);
    QString sql="SELECT ID, ragione_sociale FROM anagrafica WHERE IDCliente=:id and subcliente=1";
    q.prepare(sql);
    q.bindValue(":id",QVariant(idcliente));
    q.exec();
    subclients->setQuery(q);
    ui->lvSubclients->setModel(subclients);
    ui->lvSubclients->setModelColumn(1);

    if(subclients->rowCount() > 0)
    {
        disconnect (ui->cbClienti,SIGNAL(currentIndexChanged(int)),this,SLOT(getSubclients()));
        disconnect (ui->cbClienti,SIGNAL(currentIndexChanged(int)),this,SLOT(getRecipesForClient()));

        connect (ui->lvSubclients->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(getRecipesForClient()));
    }
    else
    {
        disconnect (ui->lvSubclients->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(getRecipesForClient()));
        connect (ui->cbClienti,SIGNAL(currentIndexChanged(int)),this,SLOT(getSubclients()));
        connect (ui->cbClienti,SIGNAL(currentIndexChanged(int)),this,SLOT(getRecipesForClient()));
    }

   connect (ui->cbClienti,SIGNAL(currentIndexChanged(int)),this,SLOT(setIDCLiente()));

}

void HScheda::on_checkBox_toggled(bool checked)
{

    if (checked)
    {
        ui->lvSubclients->setVisible(true);
        connect (ui->cbClienti,SIGNAL(currentIndexChanged(int)),this,SLOT(getSubclients()));
        connect (ui->lvSubclients,SIGNAL(currentIndexChanged(int)),this,SLOT(getRecipesForClient()));


    }else{

        ui->lvSubclients->setVisible(false);
        disconnect (ui->cbClienti,SIGNAL(currentIndexChanged(int)),this,SLOT(getRecipesForClient()));
    }
}

void HScheda::setIDCLiente()
{
    if (ui->checkBox->isChecked())
    {
        idcliente=ui->lvSubclients->model()->index(ui->lvSubclients->selectionModel()->currentIndex().row(),0).data(0).toInt();
    }
    else
    {
        idcliente=ui->cbClienti->model()->index(ui->cbClienti->currentIndex(),0).data(0).toInt();
    }

    idprodotto=ui->listView->model()->index(ui->listView->selectionModel()->currentIndex().row(),0).data(0).toInt();
}

void HScheda::on_cbClienti_currentIndexChanged(int index)
{
    idcliente=ui->cbClienti->model()->index(ui->cbClienti->currentIndex(),0).data(0).toInt();
}



void HScheda::on_pushButton_3_clicked()
{
    HModificaScheda *f =new HModificaScheda();
    f->init(sConn,idcliente,idprodotto,"pippo");

    f->show();
}

void HScheda::on_pushButton_4_clicked()
{

    QTextDocument* doc= ui->textEdit->document();
    QString htm=doc->toHtml();
    QByteArray ba = htm.toUtf8();



}

bool HScheda::save()
{
    QTextDocument* doc= ui->textEdit->document();
    QString htm=doc->toHtml();

   // //qDebug()<<htm;

   // QByteArray ba = htm.toUtf8();

    QSqlQuery q(db);
    QString sql;

    bool b;



    sql="SELECT COUNT(ID) FROM schede where cliente=:cliente and prodotto=:prodotto";
    q.prepare(sql);
    q.bindValue(":cliente",QVariant(idcliente));
    q.bindValue(":prodotto",QVariant(idprodotto));
    q.exec();
    q.first();

    int i=q.value(0).toInt();

    QSqlQuery k(db);

    if (i<1)
    {
        //INSERT
        sql="INSERT INTO schede (cliente,prodotto,scheda) values (:cliente,:prodotto,:scheda)";
        k.prepare(sql);
        k.bindValue(":cliente",QVariant(idcliente));
        k.bindValue(":prodotto",QVariant(idprodotto));
        k.bindValue(":scheda",QVariant(htm));

        b=k.exec();
    }
    else
    {
        //UPDATE
        sql="UPDATE schede SET scheda=:scheda WHERE cliente=:cliente and prodotto=:prodotto";
        k.prepare(sql);
        k.bindValue(":cliente",QVariant(idcliente));
        k.bindValue(":prodotto",QVariant(idprodotto));
        k.bindValue(":scheda",QVariant(htm));
        b=k.exec();

    }





    return b;
}



bool HScheda::readFile(const QString &filename)
{



        QImage *image = new QImage();



        image->load(filename);




         QTextDocumentFragment fragment;
         fragment = QTextDocumentFragment::fromHtml("<img src="+filename);
         ui->textEdit->textCursor().insertFragment(fragment);

         return true;

}

void HScheda::on_pushButton_2_clicked()
{


    bool b=save();



    loadScheda();



}

void HScheda::on_pushButton_4_toggled(bool checked)
{
    if(checked)
    {
        disconnect(ui->listView->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(loadScheda()));
        connect(ui->listView->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(loadSchedaOld()));
        loadSchedaOld();
    }
    else
    {
        disconnect(ui->listView->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(loadSchedaOld()));
        connect(ui->listView->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(loadScheda()));
        loadScheda();
    }
}
