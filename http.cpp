#include "http.h"

HttpCLient::HttpCLient() {

    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this,    SLOT(onFinished(QNetworkReply*)));

    setObjectName("Http-client");
}

void HttpCLient::getRequest(QString text)
{
    Request req;
    manager->get(*req.get(text));
}

void HttpCLient::onText(QString text)
{
    getRequest(text);
}

void HttpCLient::onFinished(QNetworkReply* reply) {

    ResponseHandler handler(reply);

    emit sendText(handler.getTranslate());
}


Request::Request()
{
    key = QString("trnsl.1.1.20180930T093620Z.b9bbf9af60f20997."
                  "ebb6c2591ab6eab0a18179da012128c984d155d9");

    req = QString("https://translate.yandex.net/api/v1.5/tr.json/translate"
                  "?key=%1"
                  "&text=%2"
                  "&lang=en-ru");
}

QNetworkRequest* Request::get(QString text)
{
    return new QNetworkRequest(QUrl(req.arg(key, text)));
}

ResponseHandler::ResponseHandler(QNetworkReply *reply)
{
    if (reply->error()) {
        qDebug() << "Got SOMEBAD: " << reply->errorString();
    }

    QString resp = reply->readAll();

    QJsonDocument doc = QJsonDocument::fromJson(resp.toUtf8());
    QJsonArray json = doc["text"].toArray();

    translated = json[0].toString();
}

QString ResponseHandler::getTranslate()
{
    return translated;
}
