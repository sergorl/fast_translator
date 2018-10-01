#include "clipboard.h"

Clipboard::Clipboard(QWidget *parent) : QWidget(parent) {
    clipboard = QApplication::clipboard();
    connect(clipboard, SIGNAL(selectionChanged()), this, SLOT(onSelect()));
}

void Clipboard::onSelect() {

    QString text = clipboard->text(QClipboard::Selection);
    emit findText(text);
}
