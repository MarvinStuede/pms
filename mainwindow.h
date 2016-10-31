#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void writeLineOutput(QString str);
    QStringListModel* loggingModel() { return &logging_model; }
public slots:
    void log(const QString& msg);
signals:
    void btnForward_clicked();
    void btnBackward_clicked();
    void btnLeft_clicked();
    void btnRight_clicked();
    void btnStop_clicked();
    void btnLine_clicked();

private:
     Ui::MainWindow *ui;
     QStringListModel logging_model;

};

#endif // MAINWINDOW_H
