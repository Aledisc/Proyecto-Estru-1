#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <random>

#include "Mapa.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->bframe1->setVisible(false);
    ui->bframe2->setVisible(false);
    ui->bframe3->setVisible(false);
    ui->bframe4->setVisible(false);
    ui->bframe5->setVisible(false);
    ui->bframe6->setVisible(false);


}

void inicializarPaneles(QWidget* parent) {
    // Ocultar paneles horizontales (autoposX_Y)
    for (int x = 1; x <= 6; ++x) {         // Reemplaza 6 con el máximo número de filas horizontales
        for (int y = 1; y <= 12; ++y) {    // Reemplaza 12 con el máximo número de columnas horizontales
            QString nombreHorizontal = QString("autopos%1_%2").arg(x).arg(y);
            QWidget* panelHorizontal = parent->findChild<QWidget*>(nombreHorizontal);
            if (panelHorizontal) {
                panelHorizontal->setVisible(false);
            }

            if (y ==2){
                QString nombreHorizontal = QString("autpos%1_%2").arg(x).arg(y);
                QWidget* panelHorizontal = parent->findChild<QWidget*>(nombreHorizontal);
                if (panelHorizontal) {
                    panelHorizontal->setVisible(false);
                }
            }
        }

    }

    // Ocultar paneles verticales (autoposVX_Y)
    for (int x = 1; x <= 6; ++x) {         // Reemplaza 6 con el máximo número de filas verticales
        for (int y = 1; y <= 12; ++y) {    // Reemplaza 12 con el máximo número de columnas verticales
            QString nombreVertical = QString("autoposV%1_%2").arg(x).arg(y);
            QWidget* panelVertical = parent->findChild<QWidget*>(nombreVertical);
            if (panelVertical) {
                panelVertical->setVisible(false);
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    exit(0);
}


void MainWindow::on_pushButton_clicked()
{
    inicializarPaneles(this);
    Mapa mapa(4,4);

    mapa.inicializarTablero();
    mapa.imprimirTablero();

    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_5_clicked()
{
    int random = generarRandom(1,6);
    switch(random){
    case 1:
        ui->bframe1->setVisible(true);
        break;
    case 2:
        ui->bframe2->setVisible(true);
        break;
    case 3:
        ui->bframe3->setVisible(true);
        break;
    case 4:
        ui->bframe4->setVisible(true);
        break;
    case 5:
        ui->bframe5->setVisible(true);
        break;
    case 6:
        ui->bframe6->setVisible(true);
        break;
    }
}

int MainWindow::generarRandom(int min, int max)
{
    std::random_device rd; // Semilla
    std::mt19937 gen(rd()); // Mersenne Twister como generador
    std::uniform_int_distribution<> distrib(min, max); // Distribución uniforme

    return distrib(gen); // Generar número aleatorio
}

