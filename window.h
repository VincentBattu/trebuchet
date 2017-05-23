#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QTimer>

class Window : public QMainWindow
{
    Q_OBJECT

private:
    QTimer timer;
public:
    explicit Window(QWidget *parent = 0);

signals:

public slots:
};

#endif // WINDOW_H
