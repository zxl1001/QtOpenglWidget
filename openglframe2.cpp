#include "openglframe2.h"
#include "ui_openglframe2.h"

OpenglFrame2::OpenglFrame2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenglFrame2),
    m_glW(NULL),
    m_timer(NULL)
{
    ui->setupUi(this);

    m_timer = new QTimer(this);

    m_glW = new MyOpenglWidget2(this);
    QVBoxLayout *layout = new QVBoxLayout(ui->openglFrame);
    layout->addWidget(m_glW);
    ui->openglFrame->setLayout(layout);

    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateOgl()));

}

OpenglFrame2::~OpenglFrame2()
{
    delete ui;
}

void OpenglFrame2::updateOgl()
{
    m_glW->update();
}

void OpenglFrame2::on_updateBtn_clicked(bool checked)
{
    if(checked)
    {
        ui->updateBtn->setText("Stop Update");
        m_timer->start(100);
    }
    else
    {
        ui->updateBtn->setText("Star Update");
        m_timer->stop();
    }
}
