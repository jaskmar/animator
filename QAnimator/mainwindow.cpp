#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "savethreadworker.h"
#include <QFileDialog>
#include <QTextCodec>
#include <QMessageBox>
#include <QDateTime>
#include <QMutex>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    ui->setupUi(this);
    EkranP = new QPixmap();
    Przejscia = VPrzejscia::getPrzejscia();
    for (unsigned int i=0; i<Przejscia->size(); i++)
    {
        QString tmp = tr(Przejscia->at(i)->getName().c_str());
        ui->PrzejsciaList->addItem(tmp);
    }
    last = Przejscia->at(0);
    connect(last, SIGNAL(generatingFinished()), this, SLOT(animation_generated_info()));
    Controll.setPrzejscie(last);
    ui->PrzejsciaList->setCurrentRow(0);

    const vector<string> E = Controll.getEasings();
    for (unsigned int i=0; i<E.size(); i++)
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

void MainWindow::on_pushButton_5_clicked()  //Wczytaj1
{
    QFileDialog Dialog(this);
    Dialog.setFileMode(QFileDialog::ExistingFile);
    Dialog.setNameFilter(tr("Images (*.png *.jpg)"));
    QString FileName;
     if (Dialog.exec())
     {
         FileName = Dialog.selectedFiles()[0];
         Controll.getImg1().load(FileName);
         resizeEvent(NULL);
     }
}

void MainWindow::on_pushButton_6_clicked()  //Wczytaj2
{
    QFileDialog Dialog(this);
    Dialog.setFileMode(QFileDialog::ExistingFile);
    Dialog.setNameFilter(tr("Images (*.png *.jpg)"));
    QString FileName;
     if (Dialog.exec())
     {
         FileName = Dialog.selectedFiles()[0];
         Controll.getImg2().load(FileName);
         resizeEvent(NULL);
     }
}

void MainWindow::on_pushButton_clicked()    //generuj
{
    if (Controll.getImg1().isNull() || Controll.getImg2().isNull())
    {
        QMessageBox::warning(this, tr("Brak gotowości"), tr("Musisz wybrać dwa obrazki"));
        return;
    }
    toggleGui(false);
    Controll.clear();
    Controll.generate(ui->progressBar);
}

void MainWindow::animation_generated_info() {
    ui->Nawigator->setRange(0, ui->SliderF->value()-1);
    ui->Nawigator->setValue(0);
    toggleGui(true);
    ui->progressBar->setValue(1);

    QMessageBox::information(this, tr("Sukces"), tr("Animacja została wygenerowana"));
    on_Nawigator_valueChanged(0);
    ui->progressBar->setValue(0);
}

void MainWindow::on_pushButton_3_clicked()  //play
{
    if (ui->Nawigator->value()>=ui->Nawigator->maximum()) ui->Nawigator->setValue(0);
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
    ui->Ekran->setPixmap( a->scaled(ui->Ekran->size(), Qt::KeepAspectRatio) );
    delete a;

    if (N>=ui->Nawigator->maximum())
    {
        Timer.stop();
    }
}

void MainWindow::toggleGui(bool enable) {
    ui->SliderF->setEnabled(enable);
    ui->SliderFps->setEnabled(enable);
    ui->SliderS->setEnabled(enable);

    ui->FNawigacja->setEnabled(enable);

    ui->pushButton->setEnabled(enable);
    ui->pushButton_2->setEnabled(enable);
    ui->pushButton_5->setEnabled(enable);
    ui->pushButton_6->setEnabled(enable);
}

void MainWindow::on_PrzejsciaList_currentRowChanged(int currentRow) //wybor przejscia
{
    disconnect(last, SIGNAL(generatingFinished()), this, SLOT(animation_generated_info()));
    last = Przejscia->at(currentRow);
    connect(last, SIGNAL(generatingFinished()), this, SLOT(animation_generated_info()));
    Controll.setPrzejscie(last);
    ui->FNawigacja->setEnabled(false);
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    if(Controll.isReady()) on_Nawigator_valueChanged(ui->Nawigator->value());
    if (!Controll.getImg1().isNull())
    {
        QPixmap *a = new QPixmap();
        a->convertFromImage(Controll.getImg1());
        QPixmap Skalowana = a->scaled(ui->Podglad1->size(), Qt::KeepAspectRatio);
        delete a;
        ui->Podglad1->setPixmap(Skalowana);
    }
    if (!Controll.getImg2().isNull())
    {
        QPixmap *a = new QPixmap();
        a->convertFromImage(Controll.getImg2());
        QPixmap Skalowana = a->scaled(ui->Podglad1->size(), Qt::KeepAspectRatio);
        delete a;
        ui->Podglad2->setPixmap(Skalowana);
    }
}

void MainWindow::on_EasingList_currentRowChanged(int currentRow)    //wybor easing'u
{
    Controll.setEasing(currentRow);
    ui->FNawigacja->setEnabled(false);
}

void MainWindow::on_pushButton_2_clicked()  //zapis
{
    if( ! Controll.isReady() )
    {
        QMessageBox::critical(this, tr("Błąd"), tr("Animacja nie została jeszcze wygenerowana!"));
        return;
    }

    QFileDialog Dialog(this);
    Dialog.setFileMode(QFileDialog::Directory);
    QString Path;
     if (Dialog.exec())
     {
         Path = Dialog.selectedFiles()[0];
         QDateTime time = QDateTime::currentDateTime();
         Path += "/" + time.toString("dd-MM-yyyy_hh-mm-ss_");

         ui->progressBar->setRange(0, Controll.getFrames()-1);
         toggleGui(false);
         _steps = 0;

         SaveThreadWorker *worker = new SaveThreadWorker(this, &Controll, Path);
         QThread *t = new QThread();
         worker->moveToThread(t);
         connect(t, SIGNAL(started()), worker, SLOT(run()));
         connect(worker, SIGNAL(finished()), t, SLOT(quit()));
         connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
         connect(t, SIGNAL(finished()), t, SLOT(deleteLater()));
         t->start();
     }
}

void MainWindow::save_finished() {
    ui->progressBar->setValue(1);
    QMessageBox::information(this, tr("Sukces"), tr("Pliki zostały zapisane."));
    ui->progressBar->setValue(0);
    toggleGui(true);
}

void MainWindow::updateProgress() {
    QMutex mutex;
    mutex.lock();
    _steps++;
    mutex.unlock();

    ui->progressBar->setValue(100*_steps/(Controll.getFrames()-1));
    ui->progressBar->parentWidget()->repaint();
}

void MainWindow::on_pushButton_4_clicked()
{
    Timer.stop();
}

void MainWindow::on_Nawigator_valueChanged(int value)
{
    int N = value;

    QImage *tmp = &Controll.getOutput(N);

    QPixmap *a = new QPixmap();
    a->convertFromImage(*tmp);
    ui->Ekran->setPixmap( a->scaled(ui->Ekran->size(), Qt::KeepAspectRatio) );
    delete a;
}
