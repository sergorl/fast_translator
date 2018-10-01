#include <QApplication>

#include "http.h"
#include "clipboard.h"
#include "mainwindow.h"
#include "fasttranslator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FastTranslator fs;
    fs.run();

    return a.exec();
}
