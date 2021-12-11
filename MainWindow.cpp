#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	form.setWindowTitle("Edit of Pricelist");
	form2.setWindowTitle("Search Window");
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_Edit_clicked()
{
	form.show();
}

void MainWindow::on_Search_clicked()
{
	form2.show();
}

void MainWindow::on_Exit_clicked()
{
	close();
}