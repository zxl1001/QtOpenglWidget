#ifndef OPENGLFRAME1_H
#define OPENGLFRAME1_H


#include "myopenglwidget1.h"
#include <QDialog>
#include <QTimer>

namespace Ui {
class OpenglFrame1;
}

class OpenglFrame1 : public QDialog
{
    Q_OBJECT

public:
    explicit OpenglFrame1(QWidget *parent = 0);
    ~OpenglFrame1();

public slots:
    void updateOgl();

private slots:
    void on_rotateBtn_toggled(bool checked);

private:
    Ui::OpenglFrame1 *ui;
    MyOpenglWidget1 *m_glW;
    QTimer         *m_timer;
    ItemDrawFunc   *m_drawFunc;
};

#endif // OPENGLFRAME1_H
