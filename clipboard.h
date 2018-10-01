#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <QClipboard>
#include <QApplication>
#include <QMimeData>
#include <QString>
#include <QDebug>
#include <QWidget>

class Clipboard : public QWidget
{
    Q_OBJECT
public:
    Clipboard(QWidget *parent = 0);

signals:
    void findText(QString text);

public slots:
    void onSelect();

private:
    QClipboard* clipboard;
};


#endif // CLIPBOARD_H
