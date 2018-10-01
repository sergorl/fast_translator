#include "fasttranslator.h"

FastTranslator::FastTranslator() : thread_http(new QThread)

{
    Clipboard* clip = new Clipboard;
    HttpCLient* hc = new HttpCLient;
    MainWindow* win = new MainWindow;
    win->show();

    hc->moveToThread(thread_http);

    QObject::connect(clip, SIGNAL(findText(QString)), hc, SLOT(onText(QString)));
    QObject::connect(hc, SIGNAL(sendText(QString)), win, SLOT(onText(QString)));
}

void FastTranslator::run()
{
    thread_http->start();
}

