#ifndef HSCHEDA_H
#define HSCHEDA_H

#include <QWidget>
#include <QSqlDatabase>
#include "htextedit.h"

#include "huser.h"

namespace Ui {
class HScheda;
}

class HScheda : public QWidget
{
    Q_OBJECT

public:
    explicit HScheda(QWidget *parent = 0);
    void init(QString conn, HUser *user);
    ~HScheda();

private slots:
    void on_pushButton_clicked();
    void getRecipesForClient();
    void getSubclients();
    void loadScheda();
    void loadSchedaOld();
    void on_checkBox_toggled(bool checked);
    void setIDCLiente();
    bool readFile(const QString &filename);
    bool save();

    void on_cbClienti_currentIndexChanged(int index);



    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_4_toggled(bool checked);

private:
    QString sConn;
    Ui::HScheda *ui;
    QSqlDatabase db;
    HUser* user;


    int idcliente;
    int idprodotto;
};

#endif // HSCHEDA_H
