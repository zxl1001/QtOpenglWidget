#include "openglframe2.h"
#include "ui_openglframe2.h"

OpenglFrame2::OpenglFrame2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenglFrame2),
    m_glW(NULL)
{
    ui->setupUi(this);
    m_glW = new MyOpenglWidget2(this);
    QVBoxLayout *layout = new QVBoxLayout(ui->openglFrame);
    layout->addWidget(m_glW);
    ui->openglFrame->setLayout(layout);
}

OpenglFrame2::~OpenglFrame2()
{
    delete ui;
}
