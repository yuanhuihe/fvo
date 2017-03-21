#ifndef FVOAPP_H
#define FVOAPP_H

#include <QtWidgets/QMainWindow>
#include <ui_fvoApp.h>

class fvoApp : public QMainWindow
{
    Q_OBJECT

public:
    fvoApp(QWidget *parent = 0);
    ~fvoApp();

private:
    Ui::fvoAppClass ui;
};

#endif // FVOAPP_H
