#include "openglframe1.h"
#include "ui_openglframe1.h"

OpenglFrame1::OpenglFrame1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenglFrame1),
    m_glW(Q_NULLPTR),
    m_timer(Q_NULLPTR)
{
    ui->setupUi(this);
    m_glW = new MyOpenglWidget1(this);
    QVBoxLayout *layout = new QVBoxLayout(ui->openglFrame);
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(m_glW);
    ui->openglFrame->setLayout(layout);

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateOgl()));
}

OpenglFrame1::~OpenglFrame1()
{
    delete ui;
}

void OpenglFrame1::updateOgl()
{
    m_glW->update();
}

void OpenglFrame1::on_rotateBtn_toggled(bool checked)
{
    if(checked)
    {
        m_timer->start(100);
        ui->rotateBtn->setText("停止旋转");
    }
    else
    {
        m_timer->stop();
        ui->rotateBtn->setText("开始旋转");
    }
}
