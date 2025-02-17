#ifndef __BUTTONGROUP__
#define __BUTTONGROUP__

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
    class ButtonGroup;
}
QT_END_NAMESPACE

class ButtonGroup : public QWidget
{
    Q_OBJECT

    public:
        ButtonGroup(QWidget *parent = nullptr);
        ~ButtonGroup();

    private:
        QVBoxLayout* body;
        QHBoxLayout* buttonLayout;
        QGroupBox* buttonContainer;
        QPushButton* btn1;
        QPushButton* btn2;
        QPushButton* btn3;
        QPushButton* btn4;
};
#endif
