#include<dessin.hh>
#include <QDebug>
Dessin::Dessin(QWidget *parent) : QToolButton (parent),
    _piece(nullptr),
    pixmap(QSize(1000, 1000))
{
    // Initialiser le pixmap avec une couleur de fond
    pixmap.fill(Qt::white);
}

void Dessin::setPiece( Piece * piece)
{
    // this->piece = piece;
    const QSize& pixmapSize = pixmap.size();

    // Dessiner la pièce dans le pixmap
    QPainter painter(&pixmap);

    // Définir la couleur et le style du pinceau en fonction de la pièce
    if (piece->estFonce()) {
        QColor marron(61, 43, 31);
        painter.setBrush(marron);
    } else {
        QColor beige(200, 173, 127);
        painter.setBrush(beige);
    }


    QRect shapeRect;
    if (piece->getTaille() == Taille::Petite) {
        int shapeWidth = pixmapSize.width() / 2;
        int shapeHeight = pixmapSize.width() / 2;
        int xOffset = (pixmapSize.width() - shapeWidth) / 2;
        int yOffset = (pixmapSize.height() - shapeHeight) / 2;
        shapeRect = QRect(xOffset, yOffset, shapeWidth, shapeHeight);

        //shapeRect = QRect(pixmapSize.width() , 1, pixmapSize.width() / 3, pixmapSize.width() / 3);  // Smaller size for small pieces
    } else {
        // shapeRect = QRect(0, 0, pixmapSize.width() * 2 / 3, pixmapSize.width() * 2 / 3);
        // Larger size for large pieces
        int shapeWidth = pixmapSize.width() ;
        int shapeHeight = pixmapSize.width() ;
        int xOffset = (pixmapSize.width() - shapeWidth) / 2;
        int yOffset = (pixmapSize.height() - shapeHeight) / 2;
        shapeRect = QRect(xOffset, yOffset, shapeWidth, shapeHeight);
    }

    // Définir la forme à dessiner
    switch (piece->getForme()) {
    case Ronde:
        painter.drawEllipse(shapeRect);
        break;
    case Carre:
        painter.drawRect(shapeRect);
        break;
    }



    int pointSize; // Size of the point (in pixels)
    int pointX, pointY; // Coordinates of the point

    if (piece->getTaille() == Taille::Petite) {
        pointSize = pixmapSize.width() /8; // Calculate size based on width
    } else {
        pointSize = pixmapSize.width() / 3; // Calculate size based on width for larger pieces
    }

    if (piece->getSommet() == Sommet::troué) {
        pointX = shapeRect.center().x() - pointSize / 2; // Centrer le point horizontalement par rapport au centre de la forme
        pointY = shapeRect.center().y() - pointSize / 2; // Centrer le point verticalement par rapport au centre de la forme
        if(piece->getCouleur()==Couleur::clair){
            QColor marron(61, 43, 31);
            painter.setBrush(marron);

        }
        else {
            QColor beige(200, 173, 127);
            painter.setBrush(beige);

        }

        //               pointX = pixmapSize.width() / 2 - pointSize / 2; // Center point horizontally
        //               pointY = pixmapSize.height() / 2; // Position point vertically
        //               painter.setBrush(Qt::red);
        painter.drawEllipse(pointX, pointY, pointSize, pointSize); // Draw the white point
    }
    // Définir le pixmap comme l'icône du bouton
    setIcon(QIcon(pixmap));

    // Redessiner le bouton
    update();
}

void Dessin::paintEvent(QPaintEvent *event)
{
    QToolButton::paintEvent(event);

    // Dessiner le pixmap sur le bouton
    QPainter painter(this);
    painter.drawPixmap(rect(),pixmap);
}
