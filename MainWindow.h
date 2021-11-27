#pragma once

#include <QMainWindow>
#include "ui_MainWindow.h"
#include "EditWindow.h"
#include "SearchWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();
private:
	Ui::MainWindow ui;
	EditWindow form;
	SearchWindow form2;
protected slots:
	void on_Search_clicked();
	void on_Edit_clicked();
};
