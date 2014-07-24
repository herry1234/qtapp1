#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "iostream"
#include "stdio.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_goButton_clicked()
{
    //say something
    std::cout << "I has been clicked" << std::endl;
    //QMessageBox("hi"); not working
    fprintf(stdout,"Hi\n");
    QMessageBox::information(this,"clicked","warning");
}
