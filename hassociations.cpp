#include "hassociations.h"
#include "ui_hassociations.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QCompleter>

HAssociations::HAssociations(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HAssociations)
{
    ui->setupUi(this);
    qmCombo=new QSqlQueryModel();
    mClients4List =new QSqlTableModel();
    mRecipes4List =new QSqlTableModel();
    ui->tvAssociations->resizeRowsToContents();


}

HAssociations::~HAssociations()
{
    delete ui;
}

void HAssociations::initForm()
{
   db=QSqlDatabase::database(sConn);
   //db.open();

   mClients4List=new QSqlTableModel(0,db);
   mRecipes4List=new QSqlQueryModel();
   QSqlQuery q(db);

   q.exec("select ricette.ID,prodotti.ID,prodotti.descrizione,associazioni.visualizza from prodotti, ricette, associazioni where ricette.ID=associazioni.ID_ricetta and prodotti.ID=ricette.ID_prodotto and ricette.ID_cliente="+ui->cb1->currentData().toString());
   //q.exec("SELECT ID,descrizione from prodotti where ID in (select ID_prodotto from ricette) order by descrizione asc");
   //q.exec("select prodotti.ID_ricetta, prodotti.descrizione from prodotti where ID_ricetta >0");
   mRecipes4List->setQuery(q);

   //qDebug()<<"Cliente:"+ui->cb1->currentData().toString()+" "<<q.lastError().text()<<q.lastQuery();

   setWindowFlags(this->windowFlags() | Qt::WindowMinMaxButtonsHint);

   mClients4List->setTable("anagrafica");

   mClients4List->setFilter("cliente=1");
   mClients4List->setSort(1,Qt::AscendingOrder);
   mClients4List->select();

 //  mRecipes4List->setTable("prodotti");

 //  mRecipes4List->setFilter("tipo=2");
 //  mRecipes4List->setSort(1,Qt::AscendingOrder);
 //  mRecipes4List->select();

   ui->lvAssociations->setModel(mRecipes4List);
   ui->lvAssociations->setModelColumn(1);





}

void HAssociations::setConnectionName(QString conn)
{
    sConn=conn;
    initForm();
    getClientsList();
}

void HAssociations::getClientsList() //clienti nel combobox
{
    mClients=new QSqlTableModel(0,db);
    mClients->setTable("anagrafica");
    mClients->setFilter("cliente=1");
    mClients->setSort(1,Qt::AscendingOrder);
    mClients->select();

    qmCombo->clear();
    qmCombo=0;
    qmCombo=mClients;

    ui->cb1->setModel(qmCombo);
    ui->cb1->setModelColumn(1);


    comp->setModel(mClients);
    comp->setCaseSensitivity(Qt::CaseInsensitive);
    comp->setCompletionColumn(1);
    comp->setCompletionMode(QCompleter::PopupCompletion);

    ui->cb1->setCompleter(comp);




}

void HAssociations::getRecipesList() //ricette nel combobox
{

    QSqlQueryModel *qm = new QSqlQueryModel();

    //mRecipes4List->setQuery(q);


    QSqlQuery rl(db);
//    rl.exec("SELECT ricette.ID,prodotti.ID,prodotti.descrizione from prodotti,ricette where ricette.ID_prodotto=prodotti.ID and prodotti.ID in (select ricette.ID_prodotto from ricette where ID_cliente="+ui->cb1->currentData().toString()+") order by prodotti.descrizione");

    rl.exec("SELECT ricette.ID,prodotti.descrizione from prodotti,ricette where prodotti.ID=ricette.ID_prodotto and prodotti.tipo=1");
  //  rl.exec("select ricette.ID,prodotti.descrizione,associazioni.visualizza from prodotti, ricette, associazioni where ricette.ID=associazioni.ID_ricetta and prodotti.ID=ricette.ID_prodotto and ricette.ID_cliente=");
   // rl.exec("select ricette.ID,prodotti.descrizione,associazioni.visualizza from prodotti, ricette, associazioni where ricette.ID=associazioni.ID_ricetta and prodotti.ID=ricette.ID_prodotto and associazioni.ID_cliente=");

   // qm->setQuery(rl);

    qmCombo->clear();
    qmCombo=0;
    qmCombo=qm;

    ui->cb1->setModel(qmCombo);
    ui->cb1->setModelColumn(2);
}

int HAssociations::addAssociation(bool bIsRecipe)
{
    if (bIsRecipe)
    {//add Client/Recipe association
        int r=addClientRecipeAssociation();
        if(r==0)
        {
           getAssociateRecipes(1);
        }
    }
    else
    {
      int r2=  addRecipeClientAssociation();
      if (r2==0)
      {
          getAssociateClients(1);
      }
    }

    return 0;
}

int HAssociations::addClientRecipeAssociation()
{
   //TODO
    return -1;
}

int HAssociations::addRecipeClientAssociation()
{
    //TODO
    return -1;
}

void HAssociations::on_cb1_currentIndexChanged(const QString &arg1)
{


    if(ui->rbCR->isChecked())
    {
        getAssociateRecipes(ui->cb1->currentData().toInt());
    }
    else
    {
        getAssociateClients(ui->cb1->currentData().toInt());
    }

}

void HAssociations::on_rbRC_toggled(bool checked)
{
    if (checked)
    {

        getRecipesList();
        ui->lvAssociations->setModel(mClients4List);

    }

}

void HAssociations::on_rbCR_toggled(bool checked)
{
    if (checked)
    {
        getClientsList();
        ui->lvAssociations->setModel(mRecipes4List);

    }
    else
    {
        getRecipesList();
        ui->lvAssociations->setModel(mClients4List);
    }

}

void HAssociations::getClientsView()
{
    //lista clienti per listview

}

void HAssociations::getRecipesView()
{}

void HAssociations::getAssociateRecipes(int iClientId)
{
    QString c=ui->cb1->model()->index(ui->cb1->currentIndex(),0).data(0).toString();
    qrm=new QSqlQueryModel();
   // QSqlQuery q(db);


    QSqlQuery q(db);
    q.exec("select ricette.ID,prodotti.ID,prodotti.descrizione,associazioni.visualizza from prodotti, ricette, associazioni where ricette.ID=associazioni.ID_ricetta and prodotti.ID=ricette.ID_prodotto and ricette.ID_cliente="+ui->cb1->currentData().toString());
    //q.exec("SELECT ID,descrizione from prodotti where ID in (select ID_prodotto from ricette) order by descrizione asc");
    //q.exec("select prodotti.ID_ricetta, prodotti.descrizione from prodotti where ID_ricetta >0");
    qrm->setQuery(q);


 //  q.exec("select ricette.ID,prodotti.ID,prodotti.descrizione,associazioni.visualizza from prodotti, ricette, associazioni where ricette.ID=associazioni.ID_ricetta and prodotti.ID=ricette.ID_prodotto and associazioni.ID_cliente=" + c);
  //  q.exec("select ricette.ID,prodotti.descrizione,associazioni.visualizza from prodotti, ricette, associazioni where ricette.ID=associazioni.ID_ricetta and prodotti.ID=ricette.ID_prodotto and associazioni.ID_cliente="+c);
  //  qrm->setQuery(q);


    ui->tvAssociations->setModel(qrm);

    //qDebug()<<q.lastQuery();

}

void HAssociations::getAssociateClients(int iRecipeId)
{

    QString p=ui->cb1->model()->index(ui->cb1->currentIndex(),0).data(0).toString();
    qrm= new QSqlQueryModel();
    QSqlQuery q(db);


   // db.open();
 if (!db.isOpen())
    {

      QMessageBox::information(this,QApplication::applicationName(),db.lastError().text(),QMessageBox::Ok);
    }
QString qry="SELECT anagrafica.ID, anagrafica.ragione_sociale FROM anagrafica,associazioni where associazioni.ID_cliente = anagrafica.ID and associazioni.ID_ricetta="+ p;
   q.exec(qry);
   qrm->setQuery(q);
   ui->tvAssociations->setModel(qrm);
  // //qDebug()<<qrm->rowCount() << p<<qry;
}

void HAssociations::on_pushButton_5_clicked()
{
    this->close();
}



void HAssociations::on_pushButton_clicked()
{
    QString idRicetta;
    QString idCliente;
    QString sQuery;
    bool b;
    bool c;
    //Aggiungi associazione
    b=ui->rbCR->isChecked();
    if(b)
    {
        //aggiungo ricetta a cliente
        idCliente=ui->cb1->model()->index(ui->cb1->currentIndex(),0).data(0).toString();
        ////qDebug()<<ui->cb1->model()->index(ui->cb1->currentIndex(),).data(0).toString();
        idRicetta=ui->lvAssociations->model()->index(ui->lvAssociations->selectionModel()->currentIndex().row(),0).data(0).toString();
////qDebug()<<ui->lvAssociations->model()->index(ui->lvAssociations->selectionModel()->currentIndex().row(),).data(0).toString();
    }
    else
    {
        //aggiungo cliente a ricetta
       idRicetta=ui->cb1->model()->index(ui->cb1->currentIndex(),0).data(0).toString();
       idCliente=ui->lvAssociations->model()->index(ui->lvAssociations->currentIndex().row(),0).data(0).toString();
    }
        //qDebug()<<"C " + idCliente + " R " + idRicetta;
        sQuery="insert into associazioni(ID_ricetta,ID_cliente,visualizza) values (" + idRicetta +  ","+ idCliente + ",1)";
        QSqlQuery q(db);
        c=q.exec(sQuery);

        //qDebug()<<sQuery;


        if(c)
        {
            QMessageBox::information(this,QApplication::applicationName(),"Associazione salvata correttamente",QMessageBox::Ok);

            if (b)
            {
               getAssociateRecipes(1);

            }
            else
            {
               getAssociateClients(1);
            }

        }
        else
        {

            QMessageBox::information(this,QApplication::applicationName(),q.lastQuery()+q.lastError().text(),QMessageBox::Ok);
        }


    }



void HAssociations::on_pushButton_3_clicked()
{

     QString idCliente;
     QString idRicetta;
     bool b=ui->rbCR->isChecked();

    if(b)
    {
        //rimuovo associazione

       // idCliente=ui->cb1->model()->index(ui->cb1->currentIndex(),0).data(0).toString();
        idCliente=ui->cb1->model()->index(ui->cb1->currentIndex(),0).data(0).toString();
        idRicetta=ui->tvAssociations->model()->index(ui->tvAssociations->currentIndex().row(),0).data(0).toString();
    }
    else
    {

       // idRicetta=ui->cb1->model()->index(ui->cb1->currentIndex(),0).data(0).toString();
        idRicetta=ui->cb1->model()->index(ui->cb1->currentIndex(),0).data(0).toString();
        idCliente=ui->tvAssociations->model()->index(ui->tvAssociations->currentIndex().row(),0).data(0).toString();

    }


if(QMessageBox::Ok==QMessageBox::question(this,QApplication::applicationName(),"Eliminare l'associazione?",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel))
   {
    QString query = "DELETE from associazioni where ID_cliente=" + idCliente + " and ID_ricetta=" + idRicetta;
    QSqlQuery q(db);
    q.exec(query);
    qrm->setQuery(q);
    ui->tvAssociations->setModel(qrm);

    if (b)
    {
      getAssociateRecipes(1);
    }
    else
    {
      getAssociateClients(1);
    }
}

////qDebug()<<q.lastError().text() <<q.lastQuery() << "ID_Cliente: " + idCliente <<"idRicetta " +idRicetta;
//QMessageBox::information(this,"cippa",idCliente , QMessageBox::Ok);


}


