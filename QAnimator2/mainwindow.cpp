#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextCodec>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    ui->setupUi(this);
    EkranP = new QPixmap();
    Przejscia = VPrzejscia::getPrzejscia();
    for (int i=0; i<Przejscia->size(); i++)
    {
        QString tmp = tr(Przejscia->at(i)->getName().c_str());
        ui->PrzejsciaList->addItem(tmp);
    }
    Controll.setPrzejscie(Przejscia->at(0));
    ui->PrzejsciaList->setCurrentRow(0);

    const vector<string> E = Controll.getEasings();
    for (int i=E.size()-1; i>=0; i--)
    {
        QString tmp = tr(E[i].c_str());
        ui->EasingList->addItem(tmp);
    }
    ui->EasingList->setCurrentRow(0);

    ui->FNawigacja->setEnabled(false);

    connect(&Timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    Timer.setSingleShot(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SliderF_valueChanged(int value)
{
    ui->SliderS->setValue(value*1000/ui->SliderFps->value());
    UpdateLabels();
    ui->FNawigacja->setEnabled(false);
}

void MainWindow::on_SliderS_valueChanged(int value)
{
    ui->SliderF->setValue(value*ui->SliderFps->value()/1000);
    UpdateLabels();
    ui->FNawigacja->setEnabled(false);
}

void MainWindow::on_SliderFps_valueChanged(int value)
{
    ui->SliderF->setRange(0, 10000);
    ui->SliderF->setValue(value*ui->SliderS->value()/1000);
    ui->SliderF->setRange(value*ui->SliderS->minimum()/1000, value*ui->SliderS->maximum()/1000);
    UpdateLabels();
    ui->FNawigacja->setEnabled(false);
}

void MainWindow::UpdateLabels()
{
    QString tmp;
    int v;
    v=ui->SliderF->value();
    tmp = QString::number(v) + "f";
    ui->LabelF->setText(tmp);

    v=ui->SliderS->value();
    tmp = QString::number(v) + "ms";
    ui->LabelS->setText(tmp);

    v=ui->SliderFps->value();
    tmp = QString::number(v) + "fps";
    ui->LabelFps->setText(tmp);

    Controll.setFrames(ui->SliderF->value());
}

void MainWindow::on_pushButton_5_clicked()
{
    QFileDialog Dialog(this);
    Dialog.setFileMode(QFileDialog::ExistingFile);
    Dialog.setNameFilter(tr("Images (*.png *.jpg)"));
    QString FileName;
     if (Dialog.exec())
     {
         FileName = Dialog.selectedFiles()[0];
         Controll.getImg1().load(FileName);
         QPixmap *a = new QPixmap();
         a->convertFromImage(Controll.getImg1());
         ui->Podglad1->setPixmap(*a);
     }
}

void MainWindow::on_pushButton_6_clicked()
{
    QFileDialog Dialog(this);
    Dialog.setFileMode(QFileDialog::ExistingFile);
    Dialog.setNameFilter(tr("Images (*.png *.jpg)"));
    QString FileName;
     if (Dialog.exec())
     {
         FileName = Dialog.selectedFiles()[0];
         Controll.getImg2().load(FileName);
         QPixmap *a = new QPixmap();
         a->convertFromImage(Controll.getImg2());
         ui->Podglad2->setPixmap(*a);
     }
}

void MainWindow::on_pushButton_clicked()
{
    if (Controll.getImg1().isNull() || Controll.getImg2().isNull())
    {
        QMessageBox::warning(this, tr("Brak gotowości"), tr("Musisz wybrać dwa obrazki"));
        return;
    }
    //setSizeOk();
    Controll.clear();
    Controll.generate();
    ui->Nawigator->setRange(0, ui->SliderF->value()-1);
    ui->Nawigator->setValue(0);
    ui->FNawigacja->setEnabled(true);

    //ui->Ekran->SetBackgroundColour(QColour(240,240,240));
    QMessageBox::information(this, tr("Sukces"), tr("Animacja została wygenerowana"));
    //refresh();
}

void MainWindow::on_pushButton_3_clicked()  //play
{
    if (ui->Nawigator->value()==ui->Nawigator->maximum()) ui->Nawigator->setValue(0);
    Timer.setInterval(1000.0/ui->SliderFps->value() + 0.5);
    Timer.start();
}

void MainWindow::onTimer()
{
    int N = ui->Nawigator->value();
    ui->Nawigator->setValue(N+1);

    QImage *tmp = &Controll.getOutput(N);

    QPixmap *a = new QPixmap();
    a->convertFromImage(*tmp);
    ui->Ekran->setPixmap(*a);

    if (N>=ui->Nawigator->maximum())
    {
        Timer.stop();
        return;
    }
}

void MainWindow::on_PrzejsciaList_currentRowChanged(int currentRow)
{
    int N = currentRow;
    Controll.setPrzejscie(Przejscia->at(N));
    ui->FNawigacja->setEnabled(false);
}
