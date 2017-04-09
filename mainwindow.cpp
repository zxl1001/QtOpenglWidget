#include "openglframe1.h"
#include "openglframe2.h"
#include "openglframe3.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    ui->oglTab1->setLayout(new QVBoxLayout(this));
    ui->oglTab2->setLayout(new QVBoxLayout(this));
    ui->oglTab3->setLayout(new QVBoxLayout(this));

    ui->oglTab1->layout()->addWidget(new OpenglFrame1(this));
    ui->oglTab2->layout()->addWidget(new OpenglFrame2(this));
    ui->oglTab3->layout()->addWidget(new OpenglFrame3(this));

}

MainWindow::~MainWindow()
{
    delete ui;
}


