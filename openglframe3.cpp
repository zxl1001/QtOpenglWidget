#include "openglframe3.h"
#include "ui_openglframe3.h"

OpenglFrame3::OpenglFrame3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenglFrame3)
{
    ui->setupUi(this);
}

OpenglFrame3::~OpenglFrame3()
{
    delete ui;
}
