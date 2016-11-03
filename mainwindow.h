#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QShortcut>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);
    //QStringListModel* loggingModel() { return &logging_model; }
public slots:
    void logMessage(const QString& msg);
    void logLineResponse(bool bResponse);
signals:
    void sgnForward();
    void sgnBackward();
    void sgnLeft();
    void sgnRight();
    void sgnStop();
    void sgnLine();
    void spnboxSpeed_valueChanged(int);

private:
     Ui::MainWindow *ui;
     QStringListModel logging_model;
};

#endif // MAINWINDOW_H
