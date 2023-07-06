#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Fusion");

    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&translator);

    MainWindow w;

    QTimer *timer = new QTimer(&a);
    QObject::connect(timer, SIGNAL(&QTimer::timeout), &a, SLOT(a.show()));
    timer->start(3000);

    return a.exec();
}
