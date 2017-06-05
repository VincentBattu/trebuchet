#ifndef GLWINDOW_H
#define GLWINDOW_H

#include "glwidget.h"
#include "terraindrawer.h"
#include "trebuchetdrawer.h"
#include "level.h"
#include "trajectory.h"


/**
 * Classe gérant l'appel pour l'affichage des différents
 * éléments de la scène.
 */
class GLWindow : public GLWidget
{
    Q_OBJECT

private:
    /**
     * @brief yRot
     * Rotation du trébuchet autour de l'axe Y
     */
    int yRot;

    /**
     * @brief xRot
     * Rotation du trébuchet autour de l'axe X
     */
    int xRot;

    /**
     * @brief terrain
     * Objet servant à dessiner le terrain
     */
    TerrainDrawer *terrain;

    /**
     * @brief trebuchet
     * Objet servant à dessiner le trébuchet
     */
    TrebuchetDrawer *trebuchet;

    /**
     * @brief level
     * Objet servant à définir la position aléatoire de la cible
     */
    Level *level;


public:
    /**
     * @brief isLaunched
     * Boolean servant à déterminer si le projectile a été lancé.
     */
    bool isLaunched;

    /**
     * @brief trajectoire
     * Objet servant à dessiner la trajectoire (calcul des coordonnées)
     */
    Trajectory *trajectoire;

    /**
     * @brief GLWindow
     * Constructeur
     * @param parent élément parent
     * @authors Delphine|Vincent
     */
    explicit GLWindow(QWidget *parent = 0);

    /**
     * @see GLWidget::initializeGL();
     * @brief initializeGL
     */
    void initializeGL();

    /**
     * @brief resizeGL
     * @see GlWidget::resizeGL();
     * @param width
     * @param height
     */
    void resizeGL(int width, int height);

    /**
     * @brief paintGL
     * @see GlWidget::paintGL();
     */
    void paintGL();

    /**
     * @brief setLevel
     * Fixe le level choisi à l'object Level de la classe.
     * @param level
     * @author Delphine
     */
    void setLevel(int level);

public slots:
    /**
     * @brief setYRotation
     * Modifie l'angle de rotation par rapport à y pour le trébuchet.
     * @param angle
     * @author Vincent
     */
    void setYRotation(int angle);
    /**
     * @brief setXRotation
     * Modifie l'angle de rotation par rapport à x pour le trébuchet.
     * @param angle
     * @author Vincent
     */
    void setXRotation(int angle);
    /**
     * @brief launchProjectile
     * Execute une fonction par l'object trajectoire pour lancer le
     * projectile.
     * @author Delphine
     */
    void launchProjectile();

};

#endif // GLWINDOW_H
