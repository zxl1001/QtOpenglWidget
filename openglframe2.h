#ifndef OPENGLFRAME2_H
#define OPENGLFRAME2_H

#include "myopenglwidget2.h"
#include <QDialog>
#include <QTimer>

namespace Ui {
class OpenglFrame2;
}

class OpenglFrame2 : public QDialog
{
    Q_OBJECT

public:
    explicit OpenglFrame2(QWidget *parent = 0);
    ~OpenglFrame2();

public slots:
    void updateOgl();

private slots:
    void on_updateBtn_clicked(bool checked);

private:
    Ui::OpenglFrame2 *ui;
    MyOpenglWidget2 *m_glW;
    QTimer          *m_timer;
};

#endif // OPENGLFRAME2_H
