#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

/**
 * Classe de la fenêtre principale de l'application.
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * Constructeur
     * @brief MainWindow
     * @param parent
     * @author Vincent
     */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /**
     * Tableau contenant le nombre de cible à toucher par niveau.
     */
    int nbRunsRemainded[3] = {5,4,3};

private:
    /**
     * Attribut créé par la gestion graphique de la classe.
     * @brief ui
     */
    Ui::MainWindow *ui;

    /**
     * Webcam
     * @brief cap
     */
    cv::VideoCapture cap;
    /**
     * Matrice contenant l'image captée par la webcam.
     * @brief matOriginal
     */
    cv::Mat matOriginal;
    /**
     * Matrice représentant l'image à rechercher dans la frame.
     * @brief templateImage
     */
    cv::Mat templateImage;

    /**
     * Matrice contenant le résultat du matchTemplate.
     * @brief resultImage
     */
    cv::Mat resultImage;
    /**
     * Nombre de colonne de la matrice resultImage.
     * @brief resultCols
     */
    int resultCols;
    /**
     * Nombre de ligne de la matrice resultImage.
     * @brief resultRows
     */
    int resultRows;
    /**
     * Rectangle aidant à redéfinir de la matrice templateImage pour la
     * frame suivante.
     * @brief resultRect
     */
    cv::Rect resultRect;

    /**
     * booléan pour savoir si l'application vient d'être ouverte.
     * @brief firsTime
     */
    bool firsTime;
    /**
     * La coordonnée y du rectangle comportant l'image recherchée dans la frame,
     * la fois d'avant.
     * @brief yPreviousFrame
     */
    int yPreviousFrame;
    /**
     * Distance verticale parcourue. Est utilisée pour repérer le mouvement lent
     * de démarrage et celui rapide de lancer.
     * @brief distance
     */
    int distance;
    /**
     * Stocke le nombre de coût d'horloge nécessaire pour effectuer la distance
     * dans le cas du mouvement rapide.
     * @brief nbTimer
     */
    int nbTimer=0;
    /**
     * @brief processTimer QTimer pour le processus de matching
     */
    QTimer *processTimer;
    /**
     * @brief changeCoordTimer QTimer pour changer les coordonnées
     * du projectile
     */
    QTimer *changeCoordTimer;


    // Rectangle pour mémoriser la main
    int templateWidth = 64;
    int templateHeight = 64;
    cv::Rect templateRect;

    // coordonnées récupérées par la caméra
    double minVal;
    double maxVal;

    // Points récupérées après le matchTemplate.
    cv::Point minLoc;
    cv::Point maxLoc;

    /**
     * QTimer pour l'affichage de la webcam avant de contrôler le trébuchet.
     * @brief displayCamTimer
     */
    QTimer* displayCamTimer;

    /**
     * QTime pour l'affichage du temps de session de jeu
     * @brief totalTime
     */
    QTime *totalTime;

    /**
     * QTime pour l'affichage du temps de jeu
     * @brief gameTime
     */
    QTime *gameTime;

    /**
     * Booléan pour éviter de contrôler le trébuchet lorsque le projectile est lancé.
     * @brief wait
     */
    bool wait;


private slots:
    /**
     * Gére l'affichage de la webcam tant qu'on ne contrôle pas le trébuchet.
     * @brief displayCam
     * @author Vincent
     */
    void displayCam();
    /**
     * Gére l'affichage Webcam jusqu'au lancé du projectile.
     * @brief getCoordinate
     * @author Vincent
     */
    void getCoordinate();
    /**
     * Change l'affichage du temps de jeu complet affiché
     * @brief updateTotalTime
     * @author Vincent
     */
    void updateTotalTime();
    /**
     * Change l'affichage du temps de jeu affiché
     * @brief updateGameTime
     * @author Vincent
     */
    void updateGameTime();
    /**
     * Appelé lorsque l'utilisateur change le niveau sélectionné.
     * @brief changeLevel
     * @author Vincent
     */
    void changeLevel(int);
    /**
     * Réinitialise les éléments nécessaires pour un affichage avant lancé
     * du projectile.
     * @brief restartScene
     * @author Vincent
     */
    void restartScene();

    /**
     * Permet de sauvegarder les scores dans un fichier
     * @brief save
     */
    void save();

signals:
    /**
     * Est émis lors de mouvements horizontaux par l'utilisateur.
     * @brief yRotationChanged
     * @param angle
     */
    void yRotationChanged(int angle);
    /**
     * Est émis lors de mouvements verticaux par l'utilisateur.
     * @brief xRotationChanged
     * @param angle
     */
    void xRotationChanged(int angle);
};

#endif // MAINWINDOW_H
