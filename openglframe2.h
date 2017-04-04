#ifndef OPENGLFRAME2_H
#define OPENGLFRAME2_H

#include "myopenglwidget2.h"
#include <QDialog>

namespace Ui {
class OpenglFrame2;
}

class OpenglFrame2 : public QDialog
{
    Q_OBJECT

public:
    explicit OpenglFrame2(QWidget *parent = 0);
    ~OpenglFrame2();

private:
    Ui::OpenglFrame2 *ui;
    MyOpenglWidget2 *m_glW;
};

#endif // OPENGLFRAME2_H
