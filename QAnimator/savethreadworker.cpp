#include "savethreadworker.h"
#include "tbbsaveworker.h"
#include "tbb/parallel_for.h"
#include "mainwindow.h"
#include "controller.h"

SaveThreadWorker::SaveThreadWorker(MainWindow *w, Controller *c, QString &path)
{
    _c = c;
    _parent = w;
    _path = path;
    connect(this, SIGNAL(finished()), _parent, SLOT(save_finished()));
}

void SaveThreadWorker::run() {
    TbbSaveWorker tbbSave(_c, _path);
    connect(&tbbSave, SIGNAL(step()), _parent, SLOT(updateProgress()));
    tbb::parallel_for(0, _c->getFrames(), 1, tbbSave);
    emit finished();
}
