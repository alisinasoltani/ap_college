#ifndef __INPUT__
#define __INPUT__

#include <QWidget>
#include <QGroupBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QLabel>
#include <QGridLayout>

class Input: public QWidget {
    Q_OBJECT
public:
    Input(QWidget* parent = nullptr);
    ~Input();

private:
    QHBoxLayout* row;
    QGroupBox* container;
    QGridLayout* inputLayout;
    QLineEdit* line1;
    QLineEdit* line2;
    QLineEdit* line3;
    QLabel* lineLabel1;
    QLabel* lineLabel2;
    QLabel* lineLabel3;
    QTextEdit* textBox;
};

#endif
