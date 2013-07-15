#ifndef TBBSAVEWORKER_H
#define TBBSAVEWORKER_H

#include <QObject>
#include <QString>
struct Controller;

class TbbSaveWorker : public QObject
{
    Q_OBJECT
public:
    TbbSaveWorker(Controller*, QString &);
    void operator()(int) const;
signals:
    void step() const;
private:
    Controller *_c;
    QString _path;
};

#endif // TBBSAVEWORKER_H
