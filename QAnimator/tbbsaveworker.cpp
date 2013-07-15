#include "tbbsaveworker.h"
#include "controller.h"
#include <QMessageBox>

TbbSaveWorker::TbbSaveWorker(Controller *c, QString &path) {
    _c = c;
    _path = path;
}

void TbbSaveWorker::operator()(int i) const {
    QString fname = _path + QString::number(i).rightJustified(5, '0') + ".png";
    bool success = _c->getOutput(i).save(fname);

    if ( ! success ) {
        QMessageBox::critical(NULL, tr("Błąd"), tr("Wystąpił błąd podczas zapisu pliku."));
        return;
    }
    emit step();
}
