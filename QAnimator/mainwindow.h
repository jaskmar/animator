#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include "controller.h"
#include "VPrzejscia.h"
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void save_finished();
    
private slots:
    void animation_generated_info();

    void updateProgress();

    void on_SliderF_valueChanged(int value);

    void on_SliderS_valueChanged(int value);

    void on_SliderFps_valueChanged(int value);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void onTimer();

    void on_PrzejsciaList_currentRowChanged(int currentRow);

    void on_EasingList_currentRowChanged(int currentRow);

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_Nawigator_valueChanged(int value);

private:
    void toggleGui(bool);
    virtual void resizeEvent (QResizeEvent * event);
    Ui::MainWindow *ui;
    void UpdateLabels();
    Controller Controll;
    VPrzejscia *Przejscia;
    QPixmap *EkranP;
    QTimer Timer;
    Przejscie *last;
    int _steps;
};

#endif // MAINWINDOW_H
