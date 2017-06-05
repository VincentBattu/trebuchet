#ifndef LEVEL_H
#define LEVEL_H

#include "targetdrawer.h"

/**
 * Classe définissant les coordonnées de la cible.
 * En fonction du degré de difficulté choisie, le constructeur
 * est appelé avec un z différent. L'affichage de la cible est
 * faite par l'intermédiaire de la classe TargetDrawer.
 */
class Level
{


private:
    /**
     * Tableau contenant les limites pour le z en fonction du niveau
     * @brief z
     */
    int z[6] = {48,52,73,77,98,102};
    /**
     * Tableau contenant les coordonnées générées
     * @brief pos
     */
    int pos[3];
    /**
     * Valeur minimale de y
     * @brief minY
     */
    int minY = 6;
    /**
     * Valeur maximale de y
     * @brief maxY
     */
    int maxY = 8;
    /**
     * Valeur minimale de x
     * @brief minX
     */
    int minX = -15;

    /**
     * Valeur maximale de x
     * @brief maxX
     */
    int maxX = 15;
    /**
     * Integer correspondant au niveau de difficulté choisi
     * @brief lvl
     */
    int lvl;

public:
    /**
     * Rendu openGL de la cible
     * @brief target
     */
    TargetDrawer *target;
    /**
     * Constructeur
     * @brief Level
     * @param lvl
     * @author Delphine
     */
    explicit Level(int lvl=0);
    /**
     * Générateur des coordonnées
     * @brief choosePosition
     * @author Delphine
     */
    void choosePosition();
    /**
     * Appel drawTarget de TargetDrawer avec les coordonnées
     * de la classe
     * @brief drawTarget
     * @author Delphine
     */
    void drawTarget();

    /**
     * @brief setLevel
     * @param lvl
     * @author Delphine
     */
    void setLevel(int lvl) { this->lvl = lvl; }
};

#endif // LEVEL_H
