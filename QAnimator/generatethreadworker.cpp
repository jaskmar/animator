#include "generatethreadworker.h"
#include "przejscie.h"
#include "controller.h"
#include <tbb/parallel_for.h>

GenerateThreadWorker::GenerateThreadWorker(Przejscie* parent, Controller *c, int stop) {
    _parent = parent;
    _c = c;
    _stop = stop;
}
void GenerateThreadWorker::run() {
    tbb::parallel_for(0, _stop, 1, Przejscie::TbbGenerateWorker(_parent, _c));
    delete[] _parent->_start;
    delete[] _parent->_stop;
    _c->generated();
    emit _parent->generatingFinished();
}
