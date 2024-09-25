#pragma once
#include <QPixmap>
#include <QMainWindow>
#include <QCoreApplication>
#include<piece.hh>
#include<dessin.hh>
#include<grilledes.hh>
#include<QFile>
#include<QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionA_propos_de_Qt_triggered();

    void on_actionA_propos_de_Quarto_triggered();

    void on_actionQuitter_2_triggered();
    void cacherToolButton();
    void afficherInstruction(const QString &instruction);

    void on_actionNouvelle_partie_triggered();
    void clearHistory();


    void afficherCaracteristiquesPiece (Piece const & piece);
    void handleButtonClicked (int row,int column);
    //void showPiece(int row, int column);
    void placeRemovedButton(int row, int column);
    void loadfil();
private:
    Ui::MainWindow *ui;
    QList<QToolButton*> boutonsRetires;
    //pour stocker le bouton supprimé
    QToolButton * removedButton = nullptr;
};

