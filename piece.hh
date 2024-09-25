#ifndef PIECE_HH
#define PIECE_HH


#include <string>
#include <ostream>

enum Forme {
    Ronde,
    Carre,
};

enum Taille {
    Petite,
    Grande
};

enum Couleur {
    clair,
    Foncé
};
enum Sommet {
    troué,
    paine
};

class Piece
{
public:
    Piece(Forme forme, Taille taille , Couleur couleur , Sommet sommet);
    Piece();

    Forme getForme() const;
    void setForme(Forme forme);

    Taille getTaille() const;
    void setTaille(Taille taille);

    Couleur getCouleur() const;
    void setCouleur(Couleur couleur);

    Sommet getSommet() const;
    void setSommet(Sommet sommet);

    bool estFonce() const;
    bool estRonde() const;

private:
    Forme m_forme;
    Taille m_taille;
    Couleur m_couleur;
    Sommet m_sommet;
};

std::ostream& operator<<(std::ostream& os, const Piece& piece);



class Case {
private:
    Piece *pion; // Pointeur vers la pièce sur la case
public:
    // Constructeur par défaut
    Case() : pion(nullptr) {}

    // Getter pour récupérer la pièce sur la case
    Piece* getPion() const {
        return pion;
    }

    // Setter pour modifier la pièce sur la case
    void setPiece(Piece *piece) {
        pion = piece;
    }
};


#endif // PIECE_HH

