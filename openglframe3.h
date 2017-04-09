#ifndef OPENGLFRAME3_H
#define OPENGLFRAME3_H

#include <QDialog>

namespace Ui {
class OpenglFrame3;
}

class OpenglFrame3 : public QDialog
{
    Q_OBJECT

public:
    explicit OpenglFrame3(QWidget *parent = 0);
    ~OpenglFrame3();

private:
    Ui::OpenglFrame3 *ui;
};

#endif // OPENGLFRAME3_H
