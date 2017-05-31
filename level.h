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
     * Coordonnées dépendant du niveau de difficulté
     * @brief z
     */
    int z;
    /**
     * Tableau contenant les coordonnées générées : x et y
     * @brief pos
     */
    int pos[2];
    /**
     * Valeur minimale de y
     * @brief minY
     */
    int minY = 4;
    /**
     * Valeur maximale de y
     * @brief maxY
     */
    int maxY = 10;
    /**
     * Valeur minimale de x
     * @brief minX
     */
    int minX = -4;
    /**
     * Valeur maximale de x
     * @brief maxX
     */
    int maxX = 4;
    TargetDrawer *target;
public:

    /**
     * Constructeur
     * @brief Level
     * @param z
     */
    explicit Level(int z=0);
    /**
     * Générateur des coordonnées x et y
     * @brief choosePosition
     */
    void choosePosition();
    /**
     * Appel drawTarget de TargetDrawer avec les coordonnées
     * de la classe
     * @brief drawTarget
     */
    void drawTarget();
    /**
     * Fixe z
     * @brief setZ
     * @param z
     */
    void setZ(int z);
};

#endif // LEVEL_H
