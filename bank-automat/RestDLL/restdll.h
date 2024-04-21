#ifndef RESTDLL_H
#define RESTDLL_H
#include <QObject>
#include "RestDLL_global.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDebug>
#include <QMessageBox>


class RESTDLL_EXPORT RestDLL : public QObject
{
    Q_OBJECT
public:
    RestDLL(QObject *parent);
    ~RestDLL();

    void setWebToken(const QByteArray &newWebToken);

    void setAccountBalance(int newAccountBalance);

signals:
    void cardTypeSignal(QString); //multicard
    void getResult(QString);  //need to delete someday, only used in test or other stuff but code wont build without it
    void getBalanceSignal(QString); //OK
    void getLogsSignal(QString); //OK
    void pinCheckSignal(bool); //OK, need to add webtoken later


    void getAccountSignal(QString);//Not in use but Arttu said it works
    void getCardsSignal(QString);//Not in use but Arttu said it works

public slots:

    void setupGetConnection(int switchCase);
    void checkPin(QString pincode);
    void getCardID(QString cardnumber);
    void getAccountID(QString accountType);
    void checkBalance(int id);
private slots:
    void getBalanceSlot(QNetworkReply *reply);

    void postSlot(QNetworkReply *reply);
    void getCardsSlot(QNetworkReply *reply);
    void loginSlot(QNetworkReply *reply);
    void getAccountSlot(QNetworkReply *reply);
    void multicardCheckSlot(QNetworkReply *reply);
    void getLogsSlot(QNetworkReply *reply);

    void postLogs(QString date, QString event, float amount, int idAccount);

    void cardsIdSlot(QNetworkReply *reply);
    void accountIdSlot(QNetworkReply *reply);

private:

    int accountID;
    int cardsID = 4;
    int accountBalance;


    QNetworkAccessManager *getManager;
    QNetworkAccessManager *postManager;
    QNetworkAccessManager *loginManager;
    QNetworkAccessManager *accountManager;
    QNetworkAccessManager *cardsIDManager;

    QNetworkReply *reply;
    QByteArray response_data;

    QByteArray webToken;
    QMessageBox msgBox;

    QString columnName[10];


};

#endif // RESTDLL_H
