#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "controller.h"
#include "VPrzejscia.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void on_SliderF_valueChanged(int value);

    void on_SliderS_valueChanged(int value);

    void on_SliderFps_valueChanged(int value);

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    void UpdateLabels();
    Controller Controll;
    VPrzejscia *Przejscia;
    QPixmap *EkranP;
};

#endif // MAINWINDOW_H
