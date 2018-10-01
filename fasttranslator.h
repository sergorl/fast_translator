#ifndef FASTTRANSLATOR_H
#define FASTTRANSLATOR_H

#include <QThread>
#include "http.h"
#include "clipboard.h"
#include "mainwindow.h"

struct FastTranslator {

    FastTranslator();

    void run();

private:
    QThread* thread_http;
};


#endif // FASTTRANSLATOR_H


