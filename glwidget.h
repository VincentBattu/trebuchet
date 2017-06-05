#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>

/**
 * Classe générique permettant de définir un rendu openGl.
 * Les 3 méthodes initializeGL(), resizeGL(int width, int height), int paintGL()
 * sont virtuelles pures et doivent donc être redéfinies dans les classes filles
 */
class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    /**
     * Constructeur
     * @brief GLWidget
     * @param framePerSecond nombre d'image par seconde pour le rendu
     * @param parent widget parent
     * @param name nom de la fenêtre
     * @authors Vincent|Delphine
     */
    explicit GLWidget(int framePerSecond = 0, QWidget *parent = 0, char *name = 0);

    /**
     * Méthode appelée au lancement de l'application permettant de définir les paramètres OpenGL
     * @brief initializeGL
     * @authors Vincent|Delphine
     */
    virtual void initializeGL() = 0;

    /**
     * Méthode appelée au redimensionnement du widget
     * @brief resizeGL
     * @param width nouvelle largeur de la fenêtre
     * @param height nouvelle hauteur de la fenêtre
     * @authos Vincent|Delphine
     */
    virtual void resizeGL(int width, int height) = 0;

    /**
     * Redessine la seine OpenGl. Méthode appelée à chaque fois que le widget doit être mis à jour
     * @brief paintGL
     * @author Vincent|Delphine
     */
    virtual void paintGL() = 0;

public slots:
    /**
     * Permet l'affichage à x fps.
     * @brief timeOutSlot
     * @author Vincent
     */
    virtual void timeOutSlot();

private:
    /**
     * Timer permettant de limiter le nombre de fps
     * @brief timer
     */
    QTimer *timer;
};

#endif // GLWIDGET_H
