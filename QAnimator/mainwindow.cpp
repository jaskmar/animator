#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    ui->setupUi(this);
    EkranP = new QPixmap();
    Przejscia = VPrzejscia::getPrzejscia();
    for (int i=Przejscia->size()-1; i>=0; i--)
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

    //Controll.setFrames(SliderF->GetValue());
}

void MainWindow::on_pushButton_5_clicked()
{
    /*WxOpenFileDialog1->SetWildcard("Pliki JPG (*.jpg)|*.jpg");
    if (WxOpenFileDialog1->ShowModal()==wxID_OK)
    {
        Controll.getImg1().LoadFile(WxOpenFileDialog1->GetPath());
        SBitmap1->SetBackgroundColour(wxColour(240,240,240));
        refresh();
        WxPanel3->Enable(false);
    }*/

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
