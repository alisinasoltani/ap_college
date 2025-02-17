#ifndef __NAVBAR__
#define __NAVBAR__
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>

class Navbar: public QWidget {
public:
    Navbar(QWidget* parent = nullptr);
    ~Navbar();
private:
    QWidget *navbar;
    QHBoxLayout *navbarLayout;
};

#endif
