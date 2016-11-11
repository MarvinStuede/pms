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
    void emitStandardValues();

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
    void sgnSpeedValueChanged(int);
    void sgnReductionValueChanged(double);

private:
     Ui::MainWindow *ui;
     QStringListModel logging_model;

private slots:
     void on_sgnStop();
     void on_sgnLine();
     void on_sgnReductionValueChanged();
     void on_sgnSpeedValueChanged();
};

#endif // MAINWINDOW_H
