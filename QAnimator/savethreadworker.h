#ifndef SAVETHREADWORKER_H
#define SAVETHREADWORKER_H

#include <QObject>
#include <QString>

struct Controller;
struct MainWindow;

class SaveThreadWorker : public QObject
{
    Q_OBJECT
public:
    SaveThreadWorker(MainWindow *, Controller *, QString &);
public slots:
    void run();
signals:
    void finished();
private:
    Controller *_c;
    MainWindow *_parent;
    QString _path;
};

#endif // SAVETHREADWORKER_H
