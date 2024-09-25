#include "mainwindow.h"
#include<iostream>
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    if(translator.load(QLocale::system(), "Annotations", "_", a.applicationDirPath(), ".qm")) {
        a.installTranslator(&translator);
    }
Piece p (Forme::Carre,Taille::Grande,Couleur::Foncé,Sommet::troué) ;
std::cout<<p<<std::endl ;
Dessin d ;
std::cout<<d.getPiece();
    MainWindow w;
    w.show();
    return a.exec();
}
