#pragma once

#include <QtWidgets/QWidget>
#include "ui_EditWindow.h"
#include <QtSql/qsqldatabase.h>
#include <Qdebug>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqltablemodel.h>

class EditWindow : public QWidget
{
    Q_OBJECT
public:
    EditWindow(QWidget *parent = Q_NULLPTR);
    ~EditWindow();
private:
    Ui::Form ui;
    QSqlDatabase db;
    QSqlQuery* query;
    QSqlTableModel *model;
    int row;
protected slots:
    void on_Add_clicked();
    void on_Delete_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_Close_clicked();
};


