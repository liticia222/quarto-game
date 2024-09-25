
//#include <vector>
//#include "piece.hh"

//#include <QGridLayout>
//#include <QPushButton>



//class Grille {
//private:
//    Case * grid;

//    /**
//     grid's heigth
//     */
//    unsigned int dimX;

//    /**
//     *  grid's length
//     */
//    unsigned int dimY;

//public:
//    Grille();
//    unsigned int getDimX() const;
//    unsigned int getDimY() const;
//    Case & getCase(unsigned int x, unsigned int y);
//    void setCase(unsigned int x, unsigned int y, Piece * p);
//    bool win();

//    /**
//     * regarde si la grille est plaine sinon elle retourne faux
//     */
//    bool full();
//    int heuristicValueHorizontal(unsigned int indice);

//    int heuristicValueVertical(unsigned int indice);
//    int heuristicValueDiagonal() ;
//    int heuristicValueAntiDiagonal();

//    /**
//     * @brief Calculate a heurestical value of the grid
//     * @return heurestical value of the grid
//     */
//    int heuristicValue();

//    /**
//     *
//     * @param pions A 4-sized vector containing pions
//     * @return true if the "pions" have one common characteristic. False otherwise
//     */
//    bool haveOneCommonCharacteristic(std::vector<Piece*> pions);
//    /**
//     * @brief Checks if the player won horizontally
//     * @return true if won. False otherwise
//     */
//    bool horizontalOrVerticalWin();

//    /**
//     * Checks if the player won with the diagonals.
//     * @return true if won. False otherwise
//     */
//    bool diagonalOrReverseDiagonalWin();

//    /**
//     * @param [in] coordinates a vector of pairs of ints.
//     * @return true if 4 given pions (according to their coordinates) have a common characteristics. False otherwise
//     */
//    bool checkPionsWith4Coordinates(const std::vector<std::pair<int, int>>& coordinates);

//    /**
//     * @brief says if the coordinates are out of the grid or not
//     * @param coordinates a vector of pairs of ints.
//     * @return true if some of the coordinates are out of the grid. false otherwise
//     */
//    bool outOfGrid(const std::vector<std::pair<int, int>>& coordinates);
//};
///**
//  *checkPionsWith4Coordinates: Une méthode pour vérifier si quatre pions situés à des coordonnées spécifiques ont une caractéristique commune.

//outOfGrid: Une mé
//mthode pour vérifier si des coordonnées spécifiques se trouvent en dehors de la grille.

//*/
