#ifndef GENERATETHREADWORKER_H
#define GENERATETHREADWORKER_H

#include <QObject>

struct Controller;
struct Przejscie;

class GenerateThreadWorker : public QObject {
    Q_OBJECT
public:
    GenerateThreadWorker(Przejscie*, Controller *, int);
public slots:
    void run();
signals:
    void finished();
private:
    Przejscie *_parent;
    Controller *_c;
    int _stop;
};


#endif // GENERATETHREADWORKER_H
