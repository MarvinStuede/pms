#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->show();

    //Set logging model to listOutput and forbid manual edits
    ui->listOutput->setModel(&logging_model);
    ui->listOutput->setEditTriggers(0);

    connect(ui->btnForward,SIGNAL(clicked()),this,SIGNAL(sgnForward()));
    connect(ui->btnBackward,SIGNAL(clicked()),this,SIGNAL(sgnBackward()));
    connect(ui->btnRight,SIGNAL(clicked()),this,SIGNAL(sgnRight()));
    connect(ui->btnLeft,SIGNAL(clicked()),this,SIGNAL(sgnLeft()));
    connect(ui->btnStop,SIGNAL(clicked()),this,SLOT(at_sgnStop()));
    connect(ui->btnLine,SIGNAL(clicked()),this,SLOT(at_sgnLine()));
    connect(ui->spnbxSpeed,SIGNAL(editingFinished()),this,SLOT(at_sgnSpeedValueChanged()));
    connect(ui->spnbxReduction,SIGNAL(editingFinished()),this,SLOT(at_sgnReductionValueChanged()));

    //Keyboard shortcuts
    QShortcut *scW = new QShortcut(QKeySequence("W"),this);
    QShortcut *scA = new QShortcut(QKeySequence("A"),this);
    QShortcut *scS = new QShortcut(QKeySequence("S"),this);
    QShortcut *scD = new QShortcut(QKeySequence("D"),this);
    QShortcut *scSpace = new QShortcut(QKeySequence("Space"),this);

    connect(scW,SIGNAL(activated()),ui->btnForward,SIGNAL(clicked()));
    connect(scA,SIGNAL(activated()),ui->btnLeft,SIGNAL(clicked()));
    connect(scS,SIGNAL(activated()),ui->btnBackward,SIGNAL(clicked()));
    connect(scD,SIGNAL(activated()),ui->btnRight,SIGNAL(clicked()));
    connect(scSpace,SIGNAL(activated()),this,SLOT(at_sgnStop()));

}

MainWindow::~MainWindow()
{

  delete ui;
}

void MainWindow::logMessage(const QString &msg)
{//Insert "msg" into list-element, used for logging
  QString strLastLine = "";

  //Get String of last entry
  if(!logging_model.stringList().isEmpty())
  {
    strLastLine = logging_model.stringList().back();
  }

  if(msg.compare(strLastLine) != 0)
  {
    //Insert new row
    logging_model.insertRows(logging_model.rowCount(),1);
    QVariant new_row(msg);
    //Set Data of new row
    QModelIndex vIndex = logging_model.index(logging_model.rowCount()-1);
    logging_model.setData(vIndex,new_row);

    //Set vIndex to end to remove selection bar
    vIndex = logging_model.index(logging_model.rowCount());

    //Delete first element, if list is longer than 100 elements
    if(logging_model.rowCount() > 100) logging_model.removeRow(0);

    ui->listOutput->scrollToBottom();
    ui->listOutput->setCurrentIndex(vIndex);
  }

  else
  {
      //Set selection to last entry
     // QModelIndex vIndex = logging_model.index(logging_model.rowCount()-1);
   //   ui->listOutput->setCurrentIndex(vIndex);

  }
}

void MainWindow::logLineResponse(bool bResponse)
{
  if(bResponse) logMessage("Line following started");
  else logMessage("Line following already started");
}

void MainWindow::emitStandardValues()
{
    emit sgnSpeedValueChanged(ui->spnbxSpeed->value());
    emit sgnReductionValueChanged(ui->spnbxReduction->value());
}

void MainWindow::at_sgnStop()
{

    ui->btnBackward->setEnabled(true);
    ui->btnForward->setEnabled(true);
    ui->btnLeft->setEnabled(true);
    ui->btnRight->setEnabled(true);
    ui->btnLine->setEnabled(true);

    ui->btnBackward->blockSignals(false);
    ui->btnForward->blockSignals(false);
    ui->btnLeft->blockSignals(false);
    ui->btnRight->blockSignals(false);
    ui->btnLine->blockSignals(false);

    emit sgnStop();
}

void MainWindow::at_sgnLine()
{

    ui->btnBackward->setEnabled(false);
    ui->btnForward->setEnabled(false);
    ui->btnLeft->setEnabled(false);
    ui->btnRight->setEnabled(false);
    ui->btnLine->setEnabled(false);

    ui->btnBackward->blockSignals(true);
    ui->btnForward->blockSignals(true);
    ui->btnLeft->blockSignals(true);
    ui->btnRight->blockSignals(true);
    ui->btnLine->blockSignals(true);

    ui->btnStop->setFocus();
    emit sgnLine();
}

void MainWindow::at_sgnReductionValueChanged()
{
    emit sgnReductionValueChanged(ui->spnbxReduction->value());
}

void MainWindow::at_sgnSpeedValueChanged()
{
    emit sgnSpeedValueChanged(ui->spnbxSpeed->value());
}

void MainWindow::closeEvent(QCloseEvent */*unused*/)
{
    emit sgnStop();
}
