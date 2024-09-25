#include "piece.hh"

Piece::Piece(Forme forme, Taille taille, Couleur couleur, Sommet sommet) :
    m_forme(forme),
    m_taille(taille),
    m_couleur(couleur),
    m_sommet(sommet)
{}

Piece::Piece()
{

}



Forme Piece::getForme() const { return m_forme; }
void Piece::setForme(Forme forme) { m_forme = forme; }

Taille Piece::getTaille() const { return m_taille; }
void Piece::setTaille(Taille taille) { m_taille = taille; }

Couleur Piece::getCouleur() const { return m_couleur; }
void Piece::setCouleur(Couleur couleur) { m_couleur = couleur; }

Sommet Piece::getSommet() const { return m_sommet; }
void Piece::setSommet(Sommet sommet) { m_sommet = sommet; }

bool Piece::estFonce() const { return m_couleur == Couleur::Foncé; }
bool Piece::estRonde() const { return m_forme == Forme::Ronde; }

std::ostream& operator<<(std::ostream& os, const Piece& piece)
{
    os << "Piece(";
    switch (piece.getForme()) {
        case Ronde:   os << "Ronde"; break;
        case Carre:   os << "Carre"; break;
    }
    os << " - ";
    switch (piece.getTaille()) {
        case Petite: os << "Petite"; break;
        case Grande:  os << "Grande"; break;
    }
    os << "- ";
    switch (piece.getCouleur()) {
        case clair:  os << "clair"; break;
        case Foncé: os << "Foncé"; break;
    }
    os << "- ";
    switch (piece.getSommet()) {
        case troué:  os << "troué"; break;
        case paine: os << "paine"; break;
    }
    os << ")";
    return os;
}
