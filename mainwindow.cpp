#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onText(QString text)
{
    ui->textBrowser->setText(text);
    QPoint pos = QCursor::pos();
    move(pos.x(), pos.y()+20);
    activateWindow();
}
