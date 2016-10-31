#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listOutput->setModel(&logging_model);
    QObject::connect(ui->btnForward,SIGNAL(clicked()),this,SIGNAL(btnForward_clicked()));
    QObject::connect(ui->btnBackward,SIGNAL(clicked()),this,SIGNAL(btnBackward_clicked()));
    QObject::connect(ui->btnRight,SIGNAL(clicked()),this,SIGNAL(btnRight_clicked()));
    QObject::connect(ui->btnLeft,SIGNAL(clicked()),this,SIGNAL(btnLeft_clicked()));
    QObject::connect(ui->btnStop,SIGNAL(clicked()),this,SIGNAL(btnStop_clicked()));
    QObject::connect(ui->btnLine,SIGNAL(clicked()),this,SIGNAL(btnLine_clicked()));
    QObject::connect(ui->spnbxSpeed,SIGNAL(valueChanged(int)),this,SIGNAL(spnboxSpeed_valueChanged(int)));

}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::log(const QString &msg)
{//Insert "msg" into list-element, used for logging

  //Insert new row
  logging_model.insertRows(logging_model.rowCount(),1);
  QVariant new_row(msg);
  logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);

  //Delete first element, if list is longer than 100 elements
  if(logging_model.rowCount() > 100) logging_model.removeRow(0);

  ui->listOutput->scrollToBottom();
}
