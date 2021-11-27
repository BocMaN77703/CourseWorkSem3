#pragma once

#include <QWidget>
#include "ui_SearchWindow.h"
#include <QtSql/qsqldatabase.h>
#include <Qdebug>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqltablemodel.h>

class SearchWindow : public QWidget
{
	Q_OBJECT

public:
	SearchWindow(QWidget *parent = Q_NULLPTR);
	~SearchWindow();
private:
	Ui::SearchWindow ui;
	QSqlDatabase db;
	QSqlQuery* query;
	QSqlTableModel* model;
protected slots:
	void on_CPUcheckBox_stateChanged(int);
	void on_GPUcheckBox_stateChanged(int);
	void on_RAMcheckBox_stateChanged(int);
	void on_SSDcheckBox_stateChanged(int);
	void on_Search_clicked();
	void on_Reset_clicked();
};