#ifndef __PROFILE__
#define __PROFILE__
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
class Profile: public QWidget {
public:
    Profile(QWidget* parent = nullptr);
    ~Profile();
private:
    QGridLayout* layout;
    QWidget* sideBar;
};

#endif
