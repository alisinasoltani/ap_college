#ifndef COBITEX_H
#define COBITEX_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Cobitex;
}
QT_END_NAMESPACE

class Cobitex : public QMainWindow
{
    Q_OBJECT

public:
    Cobitex(QWidget *parent = nullptr);
    ~Cobitex();

private:
    Ui::Cobitex *ui;
};
#endif // COBITEX_H
