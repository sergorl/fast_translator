#ifndef HTTP_H
#define HTTP_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QJsonArray>
#include <QDebug>

struct Request {

    Request();

    QNetworkRequest* get(QString text);

private:
    QString key;
    QString req;
};


struct ResponseHandler {


};

class HttpCLient : public QObject  {
    Q_OBJECT

public:
    HttpCLient();

    void getRequest(QString text);

signals:
    void sendText(QString translated);

public slots:
    void onText(QString text);

private slots:
    void onFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager* manager;
    QString key;
    QString req;
};

#endif // HTTP_H
