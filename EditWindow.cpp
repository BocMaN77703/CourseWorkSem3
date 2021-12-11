#include "EditWindow.h"
#include <QtSql/qsqldatabase.h>
#include <Qdebug>

EditWindow::~EditWindow()
{
    delete query;
    delete model;
}



EditWindow::EditWindow(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./Pricelist_of_Computer_Parts.db");
    if (db.open())
    {
        qDebug("Opened succsessfully!");
    }
    else
    {
        qDebug("Not opened...");
    }
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Pricelist(Type TEXT, Name TEXT, Price INT, Quantity INT);");
    model = new QSqlTableModel(this, db);
    model->setTable("Pricelist");
    model->select();
    ui.tableView->setModel(model);
}

void EditWindow::on_Add_clicked()
{
    model->insertRow(model->rowCount());
}

void EditWindow::on_Delete_clicked()
{
    model->removeRow(row);
    model->select();
}

void EditWindow::on_Close_clicked()
{
    close();
}

void EditWindow::on_tableView_clicked(const QModelIndex& index)
{
    row = index.row();
}
