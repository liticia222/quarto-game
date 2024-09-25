//#include <iostream>
//#include "grille.hh"
//#include <cassert>
//#include <vector>


//Grille::Grille() {
//    this->dimX = 4;
//    this->dimY = 4;

//    this->grid = new Case[this->dimX * this->dimY];
//}

//unsigned int Grille::getDimX() const {
//    return dimX;
//}

//unsigned int Grille::getDimY() const {
//    return dimY;
//}

//Case & Grille::getCase(unsigned int x, unsigned int y) {
//    assert(x<dimX);
//    assert(y<dimY);
//    return grid[y*dimX+x];
//}

////void Grille::setCase(unsigned int x, unsigned int y, Piece * p) {
////    if (x < dimX && y < dimY) grid[y*dimX+x].setPion(p);
////}

//bool Grille::haveOneCommonCharacteristic(std::vector<Piece*> pions)
//{
//    bool canCheck = true;

//    // making sure there's no nulls pions before checking their characteristics
//    for(int i = 0; i < 4; i ++)
//    {
//        if(pions.at(i) == nullptr)
//        {
//            canCheck = false;
//        }
//    }
//    if(canCheck)
//    {
//        return ((pions.at(0)->getSommet()) && (pions.at(1)->getSommet()) && (pions.at(2)->getSommet()) &&
//                (pions.at(3)->getSommet()))
//               // les pions n'ont pas de trou
//               || (!(pions.at(0)->getSommet()) && !(pions.at(1)->getSommet()) && !(pions.at(2)->getSommet()) &&
//                   !(pions.at(3)->getSommet()))
//               // les pions sont Marron
//               || ((pions.at(0)->getCouleur()) && (pions.at(1)->getCouleur()) && (pions.at(2)->getCouleur()) &&
//                   (pions.at(3)->getCouleur()))
//               // les pions sont Baige
//               || (!(pions.at(0)->getCouleur()) && !(pions.at(1)->getCouleur()) && !(pions.at(2)->getCouleur()) &&
//                   !(pions.at(3)->getCouleur()))
//               // les pions sont carree
//               || ((pions.at(0)->getForme()) && (pions.at(1)->getForme()) && (pions.at(2)->getForme()) &&
//                   (pions.at(3)->getForme()))
//               // les pions sont ronds
//               || (!(pions.at(0)->getForme()) && !(pions.at(1)->getForme()) && !(pions.at(2)->getForme()) &&
//                   !(pions.at(3)->getForme()))
//               // les pions sont grands
//               || ((pions.at(0)->getTaille()) && (pions.at(1)->getTaille()) && (pions.at(2)->getTaille()) &&
//                   (pions.at(3)->getTaille()))
//               // les pions sont petits
//               || (!(pions.at(0)->getTaille()) && !(pions.at(1)->getTaille()) && !(pions.at(2)->getTaille()) &&
//                   !(pions.at(3)->getTaille()));
//    }
//    else
//    {
//        return false;
//    }
//}

//bool Grille::horizontalOrVerticalWin()
//{
//    std::vector<Piece*> horizontalPions;
//    std::vector<Piece*> verticalPions;
//    for(unsigned int i = 0; i < this->dimX; i++)
//    {
//        horizontalPions.clear();
//        verticalPions.clear();
//        for(unsigned int j = 0; j < this->dimX; j++)
//        {
//            verticalPions.push_back(this->getCase(i, j).getPion());
//            horizontalPions.push_back(this->getCase(j, i).getPion());
//        }
//        if(this->haveOneCommonCharacteristic(horizontalPions) || this->haveOneCommonCharacteristic(verticalPions))
//        {
//            return true;
//        }
//    }
//    return false;
//}

//bool Grille::diagonalOrReverseDiagonalWin()
//{
//    unsigned int i;
//    unsigned int j;
//    std::vector<Piece*> diagonalPions;
//    std::vector<Piece*> reverseDiagonalPions;
//    for(i = 0, j = 3; (i < this->dimX) && (j >= 0); i++, j--)
//    {
//        diagonalPions.push_back(this->getCase(i, j).getPion());
//        reverseDiagonalPions.push_back(this->getCase(i, i).getPion());
//    }
//    return this->haveOneCommonCharacteristic(diagonalPions) || this->haveOneCommonCharacteristic(reverseDiagonalPions);
//}

//bool Grille::win()
//{
//    return ( (this->horizontalOrVerticalWin()) || this->diagonalOrReverseDiagonalWin() );
//}

//bool Grille::full() {
//    for (unsigned int i = 0; i < dimX; ++i) {
//        for (unsigned int j = 0; j < dimY; ++j) {
//            if (getCase(i, j).getPion() == nullptr) return false;
//        }
//    }
//    return true;
//}

///*int Grille::heuristicValueHorizontal(unsigned int indice) {
//    int value, bestValue = 0;
//    std::vector<Piece *> tab;
//    bool equals;
//    for (unsigned int ind1 = 0; ind1 < dimX; ++ind1) {
//        tab.clear();
//        if (this->getCase(indice, ind1).getPion() != nullptr) {
//            tab.push_back(this->getCase(indice, ind1).getPion());
//            for (unsigned int ind2 = ind1; ind2 < dimY; ++ind2) {
//                if (this->getCase(indice, ind2).getPion() != nullptr) {
//                    equals = true;
//                    for (auto &k : tab) {
//                        if (k != nullptr) {
//                            equals = k->equals(this->getCase(indice, ind2).getPion());
//                        }
//                    }
//                    if (equals) tab.push_back(this->getCase(indice, ind2).getPion());
//                }
//            }
//            value = (int)tab.size();
//            if (value > bestValue) bestValue = value;
//        }
//    }

//    return bestValue;
//}


//int Grille::heuristicValueVertical(unsigned int indice) {
//    int value, bestValue = 0;
//    std::vector<Piece *> tab;
//    bool equals;
//    for (unsigned int ind1 = 0; ind1 < dimX; ++ind1) {
//        tab.clear();
//        if (this->getCase(ind1, indice).getPion() != nullptr) {
//            tab.push_back(this->getCase(ind1, 3-ind1).getPion());
//            for (unsigned int ind2 = ind1; ind2 < dimY; ++ind2) {
//                if (this->getCase(ind2, indice).getPion() != nullptr) {
//                    equals = true;
//                    for (auto &k : tab) {
//                        if (k != nullptr) {
//                            equals = k->equals(this->getCase(ind2, indice).getPion());
//                        }
//                    }
//                    if (equals) tab.push_back(this->getCase(ind2, indice).getPion());
//                }
//            }
//            value = (int)tab.size();
//            if (value > bestValue) bestValue = value;
//        }
//    }

//    return bestValue;
//}

//int Grille::heuristicValueDiagonal() {
//    int value, bestValue = 0;
//    std::vector<Piece *> tab;
//    bool equals;
//    for (unsigned int ind1 = 0; ind1 < dimX; ++ind1) {
//        tab.clear();
//        if (this->getCase(ind1, ind1).getPion() != nullptr) {
//            tab.push_back(this->getCase(ind1, 3-ind1).getPion());
//            for (unsigned int ind2 = ind1; ind2 < dimY; ++ind2) {
//                if (this->getCase(ind2, ind2).getPion() != nullptr) {
//                    equals = true;
//                    for (auto &k : tab) {
//                        if (k != nullptr) {
//                            equals = k->equals(this->getCase(ind2, ind2).getPion());
//                        }
//                    }
//                    if (equals) tab.push_back(this->getCase(ind2, ind2).getPion());
//                }
//            }
//            value = (int)tab.size();
//            if (value > bestValue) bestValue = value;
//        }
//    }

//    return bestValue;
//}

//int Grille::heuristicValueAntiDiagonal() {
//    int value, bestValue = 0;
//    std::vector<Piece *> tab;
//    bool equals;
//    for (unsigned int ind1 = 0; ind1 < dimX; ++ind1) {
//        tab.clear();
//        if (this->getCase(ind1, 3-ind1).getPion() != nullptr) {
//            tab.push_back(this->getCase(ind1, 3-ind1).getPion());
//            for (unsigned int ind2 = ind1; ind2 < dimY; ++ind2) {
//                if (this->getCase(ind2, 3-ind2).getPion() != nullptr) {
//                    equals = true;
//                    for (auto &k : tab) {
//                        if (k != nullptr) {
//                            equals = k->equals(this->getCase(ind2, 3-ind2).getPion());
//                        }
//                    }
//                    if (equals) tab.push_back(this->getCase(ind2, 3-ind2).getPion());
//                }
//            }
//            value = (int)tab.size();
//            if (value > bestValue) bestValue = value;
//        }
//    }

//    return bestValue;
//}
//*/
//int Grille::heuristicValue() {
//    int value, bestValue = 0;
//    // Comme dimX = dimY on peut faire une seule boucle
//    for (unsigned int indice = 0; indice < dimX; ++indice) {
//        value = heuristicValueHorizontal(indice);
//        if (value > bestValue) bestValue = value;

//        value = heuristicValueVertical(indice);
//        if (value > bestValue) bestValue = value;
//    }

//    value = heuristicValueDiagonal();
//    if (value > bestValue) bestValue = value;

//    value = heuristicValueAntiDiagonal();
//    if (value > bestValue) bestValue = value;

//    return bestValue;
//}


//bool Grille::checkPionsWith4Coordinates(const std::vector<std::pair<int, int>>& coordinates)
//{
//    std::vector <Piece*> blockPions;
//    blockPions.reserve(coordinates.size());
//    for(auto & coordinate : coordinates) {
//        blockPions.push_back(this->getCase(coordinate.first, coordinate.second).getPion());
//    }
//    return this->haveOneCommonCharacteristic(blockPions);
//}

//bool Grille::outOfGrid(const std::vector<std::pair<int, int>>& coordinates)
//{
//    for(auto & coordinate : coordinates)
//    {
//        if
//        (
//                (coordinate.first < 0)
//            ||  (coordinate.first > 3)
//            ||  (coordinate.second < 0)
//            ||  (coordinate.second > 3)
//        )
//        {
//            return true;
//        }
//    }
//    return false;
//}


