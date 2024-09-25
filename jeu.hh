
//#ifndef JEU_HH
//#define JEU_HH



//#include <vector>
//#include "grille.hh"


//class Jeu {
//private:

//    /**
//     * @brief grille de jeu
//     */
//    Grille * g{};

//    /**
//     * @brief nombre detour écoulé
//     */
//    unsigned int tour{};

//    /**
//     * @brief nom J1 et J2
//     */
//    std::string J1, J2;

//    /**
//     * @brief tableau des pions disponibles
//     */
//    Piece ** tabPion{};



//    /**
//     * @brief Motif de victoire
//     */
//    Motif _motif = NONE;

//public:

//    /**
//     * @brief constructeur de la classe Jeu
//     */
//    Jeu();

//    /**
//     * @brief Initialise tout les attribut pour que la partie puisse être joué
//     */
//    void init();

//    /**
//     * Affichage la fenêtre de choix des pièces / des règles
//     * @param [in] pvp : si la partie est pvp (true) ou non
//     */
//    void choixPieces(bool pvp);

//    /**
//     * @brief selection le pion en fonction de la position de la sourie lors du clique
//     * @param [in] mousseX coordonnées X de la sourie
//     * @param [in] mousseY coordonnées Y de la sourie
//     * @param [in] og tableau où les texture des pion sont représenter
//     * @return l'indice du pion qui à été cliqué
//     */
//    int selectPion(int mousseX, int mousseY, std::vector<sf::RectangleShape> & og);

//    /**
//     * @brief selection la case de la grille en fonction de la position de la sourie lors du clique
//     * @param [in] mousseX coordonnées X de la sourie
//     * @param [in] mousseY coordonnées Y de la sourie
//     * @param [in, out] x coordonnées X de la case
//     * @param [in, out] y coordonnées Y de la case
//     */
//    void selectCaseGrille(int mousseX, int mousseY, int & x, int & y);

//    /**
//     * @brief affiche le menu du jeu
//     */
//    void menu();

//    /**
//     * @brief affiche le résultat du jeu
//     * @param [in] gagnant nom du gagant ou "match nul" si il n'y a aucun vainqueur
//     */
//    void resultat(const std::string& gagnant);

//    /**
//     * @brief partie Joueur contre Joueur
//     */
//    void pvp();


//};



//#endif // JEU_HH
