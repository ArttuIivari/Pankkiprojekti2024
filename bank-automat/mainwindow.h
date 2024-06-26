#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include <QMessageBox>
#include "bankwindow.h"
#include "RestDLL/restdll.h"
#include "RFID_DLL/rfid_dll.h"
#include "pinui_dll/pinuidll.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    bool bviewflag = false;
    bool pinuiflag = false;
    QString cardType;

    bankwindow *secWindow;
    RFID_DLL *ptr_rfid;
    PINUIDLL *ptr_pinui;
    RestDLL *ptr_rest;
    QMessageBox pinmsg;
    QString tries;

private slots:

    void secondViewOpen();
    void cardHandler(QString&);
    void pinHandler(QString);
    void pinCheckHandler(bool);
    void CardCheckHandler(QString);
    void triesHandler(QString);
    void restart();

    void on_debitButton_clicked();

    void on_creditButton_clicked();

    void on_OFFButton_clicked();

signals:
    void secondViewOpenSignal();


};
#endif // MAINWINDOW_H
