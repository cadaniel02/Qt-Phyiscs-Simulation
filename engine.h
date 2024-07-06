#ifndef ENGINE_H
#define ENGINE_H

#include <QDialog>
#include <QGraphicsScene>
#include <QTimer>
#include <QtMath>
#include "particle.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class Engine;
}
QT_END_NAMESPACE

class Engine : public QDialog
{
    Q_OBJECT

public:
    Engine(QWidget *parent = nullptr);
    ~Engine();
private:
    Ui::Engine *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QList <Particle*> particles;
protected:
    void spawn(int num);
protected slots:
    void refreshBg();
    void checkCollisions();
};
#endif // ENGINE_H
