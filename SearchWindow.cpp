#include "SearchWindow.h"
#include <QtSql/qsqldatabase.h>
#include <Qdebug>
#include <qstring.h>

SearchWindow::SearchWindow(QWidget* parent)
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

SearchWindow::~SearchWindow()
{
    delete query;
    delete model;
}

void SearchWindow::on_Search_clicked()
{
    bool isSearch = false;
    QString filter;
    if (ui.CPUcheckBox->isChecked())
    {
        filter = "Type='CPU'";
        isSearch = true;
    }
    if (ui.SSDcheckBox->isChecked())
    {
        filter = "Type='SSD'";
        isSearch = true;
    }
    if (ui.RAMcheckBox->isChecked())
    {
        filter = "Type='RAM'";
        isSearch = true;
    }
    if (ui.GPUcheckBox->isChecked())
    {
        filter = "Type='GPU'";
        isSearch = true;
    }
    if (ui.priceBox->value() != 0)
    {
        int x = ui.priceBox->value();
        QString str = QString::number(x, 10);
        str.prepend("Price='");
        str.append("'");
        if (isSearch)
        {
            str.prepend(" and ");
            filter.append(str);
        }
        else
        {
            isSearch = true;
            filter = str;
        }
    }
    if (ui.quantityBox->value() != 0)
    {
        int x = ui.quantityBox->value();
        QString str = QString::number(x, 10);
        str.prepend("Quantity='");
        str.append("'");
        if (isSearch)
        {
            str.prepend(" and ");
            filter.append(str);
        }
        else
        {
            isSearch = true;
            filter = str;
        }
    }
    if (ui.nameBox->isModified())
    {
        QString str;
        str=ui.nameBox->text();
        str.prepend("Name LIKE '%");
        str.append("%'");
        if (isSearch)
        {
            str.prepend(" and ");
            filter.append(str);
        }
        else
        {
            isSearch = true;
            filter = str;
        }
    }
    if (!isSearch)
    {
        model->setTable("Pricelist");
    }
    else
    {
        model->setFilter(filter);
    }
    model->select();
}

void SearchWindow::on_CPUcheckBox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        ui.GPUcheckBox->setChecked(false);
        ui.RAMcheckBox->setChecked(false); 
        ui.SSDcheckBox->setChecked(false);
    }
}

void SearchWindow::on_GPUcheckBox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        ui.CPUcheckBox->setChecked(false);
        ui.RAMcheckBox->setChecked(false);
        ui.SSDcheckBox->setChecked(false);
    }
}

void SearchWindow::on_SSDcheckBox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        ui.GPUcheckBox->setChecked(false);
        ui.RAMcheckBox->setChecked(false);
        ui.CPUcheckBox->setChecked(false);
    }
}

void SearchWindow::on_RAMcheckBox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        ui.GPUcheckBox->setChecked(false);
        ui.CPUcheckBox->setChecked(false);
        ui.SSDcheckBox->setChecked(false);
    }
}

void SearchWindow::on_Reset_clicked()
{
    ui.GPUcheckBox->setChecked(false);
    ui.RAMcheckBox->setChecked(false);
    ui.SSDcheckBox->setChecked(false);
    ui.CPUcheckBox->setChecked(false);
    ui.priceBox->setValue(0);
    ui.quantityBox->setValue(0);
    ui.nameBox->clear();
    model->setTable("Pricelist");
    model->select();
}