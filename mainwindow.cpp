#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set logging moidel to listOutput and forbid manual edits
    ui->listOutput->setModel(&logging_model);
    ui->listOutput->setEditTriggers(0);

    connect(ui->btnForward,SIGNAL(clicked()),this,SIGNAL(sgnForward()));
    connect(ui->btnBackward,SIGNAL(clicked()),this,SIGNAL(sgnBackward()));
    connect(ui->btnRight,SIGNAL(clicked()),this,SIGNAL(sgnRight()));
    connect(ui->btnLeft,SIGNAL(clicked()),this,SIGNAL(sgnLeft()));
    connect(ui->btnStop,SIGNAL(clicked()),this,SIGNAL(sgnStop()));
    connect(ui->btnLine,SIGNAL(clicked()),this,SIGNAL(sgnLine()));
    connect(ui->spnbxSpeed,SIGNAL(valueChanged(int)),this,SIGNAL(spnboxSpeed_valueChanged(int)));

    //Keyboardshortcuts
    QShortcut *scW = new QShortcut(QKeySequence("W"),this);
    QShortcut *scA = new QShortcut(QKeySequence("A"),this);
    QShortcut *scS = new QShortcut(QKeySequence("S"),this);
    QShortcut *scD = new QShortcut(QKeySequence("D"),this);
    QShortcut *scSpace = new QShortcut(QKeySequence("Space"),this);

    connect(scW,SIGNAL(activated()),this,SIGNAL(sgnForward()));
    connect(scA,SIGNAL(activated()),this,SIGNAL(sgnLeft()));
    connect(scS,SIGNAL(activated()),this,SIGNAL(sgnBackward()));
    connect(scD,SIGNAL(activated()),this,SIGNAL(sgnRight()));
    connect(scSpace,SIGNAL(activated()),this,SIGNAL(sgnStop()));

}

MainWindow::~MainWindow()
{

  delete ui;
}

void MainWindow::logMessage(const QString &msg)
{//Insert "msg" into list-element, used for logging

  //Insert new row
  logging_model.insertRows(logging_model.rowCount(),1);
  QVariant new_row(msg);
  logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);

  //Delete first element, if list is longer than 100 elements
  if(logging_model.rowCount() > 100) logging_model.removeRow(0);

  ui->listOutput->scrollToBottom();
}

void MainWindow::logLineResponse(bool bResponse)
{
  if(bResponse) logMessage("Line following started");
  else logMessage("Line following already started");
}
void MainWindow::closeEvent(QCloseEvent *event)
{
  emit sgnStop();
}
