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
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::log(const QString &msg)
{

  logging_model.insertRows(logging_model.rowCount(),1);
  QVariant new_row(msg);
  logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
  ui->listOutput->scrollToBottom();
}
