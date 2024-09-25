#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QMessageBox>
#include<QSize>
#include <QPainter>
#include <QGroupBox>
#include<iostream>
#include<QtDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    this->setWindowTitle(tr("Quarto"));
    QHBoxLayout *layout2 = new QHBoxLayout;

    //je cree un vecteur pour stoquer mes pieces
    std::vector< Dessin *> dessins;

    Dessin *dessin = new Dessin;
    Dessin *dessin2 = new Dessin;
    Dessin *dessin3 = new Dessin;
    Dessin *dessin4 = new Dessin;
    Dessin *dessin5 = new Dessin;
    Dessin *dessin6 = new Dessin;
    Dessin *dessin7 = new Dessin;
    Dessin *dessin8 = new Dessin;
    Dessin *dessin9 = new Dessin;
    Dessin *dessin10 = new Dessin;
    Dessin *dessin11 = new Dessin;
    Dessin *dessin12 = new Dessin;
    Dessin *dessin13 = new Dessin;
    Dessin *dessin14 = new Dessin;
    Dessin *dessin15 = new Dessin;
    Dessin *dessin16 = new Dessin;
    // QString style = "border: 2px solid black;";
    // dessin->setStyleSheet(style);
    // clairs
    dessin->setPiece(new Piece(Forme::Carre, Taille::Petite, Couleur::clair, Sommet::troué));
    dessin->setStyleSheet("border-width: 2px; border: 2px solid black;");
    dessins.push_back(dessin);
    layout2->addWidget(dessin);


    dessin2->setPiece(new Piece(Forme::Carre, Taille::Petite, Couleur::clair, Sommet::paine));
    layout2->addWidget(dessin2);
    dessins.push_back(dessin2);

    dessin3->setPiece(new Piece(Forme::Carre, Taille::Grande, Couleur::clair, Sommet::troué));
    dessin->setStyleSheet("border-width: 2px; border: 2px solid black;");
    layout2->addWidget(dessin3);
    dessins.push_back(dessin3);

    dessin4->setPiece(new Piece(Forme::Carre, Taille::Grande, Couleur::clair, Sommet::paine));
    layout2->addWidget(dessin4);
    dessins.push_back(dessin4);

    dessin5->setPiece(new Piece(Forme::Ronde, Taille::Petite, Couleur::clair, Sommet::troué));
    layout2->addWidget(dessin5);
    dessins.push_back(dessin5);

    dessin6->setPiece(new Piece(Forme::Ronde, Taille::Grande, Couleur::clair, Sommet::troué));
    layout2->addWidget(dessin6);
    dessins.push_back(dessin6);

    dessin7->setPiece(new Piece(Forme::Ronde, Taille::Petite, Couleur::clair, Sommet::paine));
    layout2->addWidget(dessin7);
    dessins.push_back(dessin7);

    dessin8->setPiece(new Piece(Forme::Ronde, Taille::Grande, Couleur::clair, Sommet::paine));
    layout2->addWidget(dessin8);
    dessins.push_back(dessin8);

    //  foncés
    dessin9->setPiece(new Piece(Forme::Carre, Taille::Petite, Couleur::Foncé, Sommet::troué));
    layout2->addWidget(dessin9);
    dessins.push_back(dessin9);

    dessin10->setPiece(new Piece(Forme::Carre, Taille::Petite, Couleur::Foncé, Sommet::paine));
    layout2->addWidget(dessin10);
    dessins.push_back(dessin10);

    dessin11->setPiece(new Piece(Forme::Carre, Taille::Grande, Couleur::Foncé, Sommet::paine));
    layout2->addWidget(dessin11);
    dessins.push_back(dessin11);

    dessin12->setPiece(new Piece(Forme::Carre, Taille::Grande, Couleur::Foncé, Sommet::troué));
    layout2->addWidget(dessin12);
    dessins.push_back(dessin12);

    dessin13->setPiece(new Piece(Forme::Ronde, Taille::Petite, Couleur::Foncé, Sommet::troué));
    layout2->addWidget(dessin13);
    dessins.push_back(dessin13);

    dessin14->setPiece(new Piece(Forme::Ronde, Taille::Grande, Couleur::Foncé, Sommet::troué));
    layout2->addWidget(dessin14);
    dessins.push_back(dessin14);

    dessin15->setPiece(new Piece(Forme::Ronde, Taille::Petite, Couleur::Foncé, Sommet::paine));
    layout2->addWidget(dessin15);
    dessins.push_back(dessin15);

    dessin16->setPiece(new Piece(Forme::Ronde, Taille::Grande, Couleur::Foncé, Sommet::paine));
    layout2->addWidget(dessin16);
    dessins.push_back(dessin16);

    QVBoxLayout *verticalLayout = ui->verticalLayout;
    verticalLayout->insertLayout(1, layout2);
    ui->affichage->setAlignment(Qt::AlignLeft | Qt::AlignBottom);

    QGridLayout *gridLayout=new QGridLayout ;
    GridWidget *maGrille = new GridWidget(4, 4, this);
    gridLayout->addWidget(maGrille,0,0);
    gridLayout->setAlignment(Qt::AlignCenter);
    //pour enlever l'espace entre collones
    gridLayout->setSpacing(1);

    gridLayout->setContentsMargins(0, 0, 0, 0);
    verticalLayout->insertLayout(2,gridLayout);

    connect(maGrille, &GridWidget::buttonClicked, this, &MainWindow::handleButtonClicked);




    // Supposons que vous avez plusieurs QToolButtons que vous voulez faire disparaître lorsqu'ils sont cliqués
    for (auto dessin:dessins){
        connect(dessin, &QToolButton::clicked, this, &MainWindow::cacherToolButton);
    }


    ui->joueur->setText(tr("joueur 1"));
    ui->joueur->setAlignment(Qt::AlignCenter);
    ui->tour->setText(tr("le joueur 1 dois selectionner une piece que le joueur 1 dois joué"));
    ui->tour->setAlignment(Qt::AlignCenter);

    // Boucle à travers la liste d'actions de menu et connecte l'événement de survol à la fonction de mise à jour du QLabel


    //pour afficher en bas les different menu
    for (QAction *action : ui->menuFichier->actions()) {
        connect(action, &QAction::hovered, this, [this, action]() {
            afficherInstruction(action->text());
        });
    }

    for (QAction *action : ui->menuApropos->actions()) {
        connect(action, &QAction::hovered, this, [this, action]() {
            afficherInstruction(action->text());
        });
    }
    //je converti mon pointeur un une refference const pour ne pas avoir un arret
    //au debut jai essayer avec une reference constante sur piece directemont et ca planter car y'avaus un overflow memoir
    //c'est bien ca mais je sais pas pourqoi elle maffiche rien
    for (auto dessin:dessins){
        connect(dessin, &Dessin::mouseEntered, this, [=]() {
            if (dessin->getPiece() != nullptr) {
                Piece const& pieceRef = *(dessin->getPiece());
                // Dé-référencement du pointeur pour obtenir l'objet Piece
                afficherCaracteristiquesPiece(pieceRef);
            }
        });


    }


    // connect(maGrille, &GridWidget::buttonClicked, this, &MainWindow::showPiece));
    connect(maGrille, &GridWidget::buttonClicked, this, &MainWindow::placeRemovedButton);
    connect(ui->actionVoir_l_historique_, &QAction::triggered,this, &MainWindow::loadfil);
}



///pour historique
void writeToHistory(const QString &message) {
    QFile file("/home/etud/quarto/historic.log");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << message << "\n";
        file.close();
    } else {
        qDebug() << "Erreur lors de l'ouverture du fichier d'historique";
    }
}

/*void MainWindow::showPiece(int row, int column) {
    // Stockez la position du bouton supprimé
      removedButtonRow = row;
      removedButtonColumn = column;
    }*/
// Dans votre constructeur ou toute autre méthode où vous configurez vos Dessins


// Fonction pour afficher les caractéristiques de la pièce
void MainWindow::afficherCaracteristiquesPiece(Piece const & piece) {
    // Récupérez l'objet Dessin qui a émis le signal
    //QString caracteristique = std::cout<<piece;
    std::cout << piece <<std::endl ;

    qDebug() << piece.getForme();
    qDebug() << piece.getTaille();
    qDebug() << piece.getCouleur();
    qDebug() << piece.getSommet();
    QString caracteristiques = QString("Forme: %1- Taille: %2-, Couleur: %3- Sommet: %4")
            .arg(piece.getForme() == Forme::Ronde ? "Ronde" : "Carrée")
            .arg(piece.getTaille() == Taille::Petite ? "Petite" : "Grande")
            .arg(piece.getCouleur() == Couleur::clair ? "Clair" : "Foncé")
            .arg(piece.getSommet() == Sommet::troué ? "Troué" : "Plein");

    afficherInstruction(caracteristiques);
    writeToHistory(caracteristiques);
}

//pour afficher dans mon label
void MainWindow::afficherInstruction(const QString &instruction) {
    ui->affichage->setText(instruction);
}

void MainWindow::on_actionNouvelle_partie_triggered()
{
    clearHistory();
}


void MainWindow::handleButtonClicked(int row, int column) {
    // Handle button click here
    std::cout << "Case (" << row << ", " << column << ") clicked." << std::endl;

    // Créez une instruction avec les coordonnées du bouton cliqué
    QString instruction = QString("Bouton à la position (%1, %2) cliqué.").arg(row).arg(column);
    // Appelez la fonction afficherInstruction avec cette instruction
    afficherInstruction(instruction);
    writeToHistory(instruction);
}





MainWindow::~MainWindow()
{
    delete ui;
}

//pour le menu a propos de QT creator
void MainWindow::on_actionA_propos_de_Qt_triggered()
{
    QMessageBox::aboutQt(this,tr("A propos de Qt"));
}
//pour le menu de a propos de quarto
void MainWindow::on_actionA_propos_de_Quarto_triggered()
{
    //je charge l'image
    QPixmap pixmap("/home/etud/quarto/Quarto.jpg");
    QMessageBox msg;
    //pour la taille de l'image
    QSize image (100,75);
    pixmap=pixmap.scaled(image);
    msg.setWindowTitle("Apropos de quarto");
    msg.setText(tr("cette application a été réaliser par MOUSSOUNI liticia dans le cadre de l'unité Developpement d'interfaces Graphique de L3 Informatique"));
    msg.setIconPixmap(pixmap);
    msg.exec();
}

void MainWindow::on_actionQuitter_2_triggered()
{
    QApplication::closeAllWindows();
}
void MainWindow::cacherToolButton() {
    QToolButton* toolButton = qobject_cast<QToolButton*>(sender());
    if (toolButton) {
        ui->gridLayout->removeWidget(toolButton);
        removedButton = toolButton; // Stockez le bouton supprimé
        removedButton->setVisible(true);
        toolButton->setVisible(false);
        boutonsRetires.append(toolButton);
        //        QString instruction = "quitter la partie.";
        //          afficherInstruction(instruction);

        toolButton->deleteLater(); // Libérer la mémoire

    }
}

void MainWindow::placeRemovedButton(int row, int column) {
    if (removedButton != nullptr) {
        removedButton->setVisible(true); // Afficher le bouton supprimé
        ui->gridLayout->addWidget(removedButton, row, column); // Ajouter le bouton à la nouvelle position
        removedButton = nullptr; // Réinitialiser le pointeur vers le bouton supprimé
    }
}


void MainWindow::loadfil()

{
    QFile file("historic.log");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Erreur lors de l'ouverture du fichier d'historique";
        return;
    }

    // Lire le contenu du fichier d'historique
    QTextStream in(&file);
    QString historyContent = in.readAll();
    file.close();

    // Afficher le contenu du fichier dans un QMessageBox
    QMessageBox::information(this, "Historique", historyContent);

}

void MainWindow::clearHistory() {
    // Vide le contenu du fichier historique en réouvrant le fichier en mode WriteOnly (qui efface le contenu)
    QFile file("history.log");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.resize(0); // Vide le fichier
        file.close();
    } else {
        qDebug() << "Erreur lors de l'ouverture du fichier d'historique";
    }
    QMessageBox::information(this, "Historique", ""); // Boîte de message vide
}
