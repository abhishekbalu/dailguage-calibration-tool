#include "mcalib.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include<QPainter>
#include <QPrinter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *Mlogo=new QSplashScreen;
    Mlogo->setPixmap(QPixmap(":/mcalib/Logo/resource/metrics.png"));
    Mlogo->show();

    MCALIB w;

    QTimer::singleShot(2000,Mlogo,SLOT(close()));
    QTimer::singleShot(2000,&w ,SLOT(show()));
    w.show();

    return a.exec();
}
