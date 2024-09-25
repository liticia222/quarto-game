#pragma once
#include<iostream>
#include <QWidget>
#include<QPainter>
#include<QPushButton>
#include <QPixmap>
#include"piece.hh"
#include<QRect>
#include<QToolButton>

class Dessin : public QToolButton
{
    Q_OBJECT

public:
    Dessin(QWidget *parent = nullptr);
    Piece * getPiece() {return _piece;};

    void setPiece(Piece * piece);
    void afficher(){std::cout<<_piece;}

signals:
    void mouseEntered();
    //  void mouseLeft();

protected:

    void enterEvent(QEvent *event) override {
        //         QWidget::enterEvent(event);
        //         afficher();
        emit mouseEntered();// Afficher les caractéristiques de la pièce lorsque la souris entre dans la zone du dessin
    }
    void paintEvent(QPaintEvent *event) override;

private:
    Piece * _piece ;
    QPixmap pixmap;

};
