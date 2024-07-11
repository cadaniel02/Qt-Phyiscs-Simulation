#include "engine.h"
#include "ui_engine.h"
#include <QList>
#include "collisions.h"

Engine::Engine(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Engine)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QBrush(QColor(100,100,100)));
    QRect bg(0,0,798,598);
    scene->setSceneRect(bg);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    spawn(4);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    connect(timer, SIGNAL(timeout()), this, SLOT(refreshBg()));
    connect(timer, SIGNAL(timeout()), this, SLOT(checkCollisions()));
    timer->start(17);
}

Engine::~Engine()
{
    delete ui;
}

void Engine::spawn(int num)
{
    for (int i = 0; i < num; i++){
        qreal d=40;
        qreal f=.99;
        qreal x = (rand()%798) + 25 - d;
        qreal y = (rand()%598) + 15 - d;
        MyPhysics::RigidBody *obj = new MyPhysics::RigidBody(x,y,d,d,f);
        bodies << obj;
        scene->addItem(bodies.last());
    }
}

void Engine::checkCollisions()
{
    for (int i = 0; i < particles.size() - 1; ++i) {
        Particle *p1 = this->particles[i];
        for (int j = i + 1; j < particles.size(); ++j) {
            Particle *p2 = this->particles[j];
            PVector normal;
            qreal depth;
            if(Collisions::intersectCircles(p1->position(), p1->radius(), p2->position(), p2->radius(), normal, depth)){
                p1->move(normal*depth/2);
                p2->move(-normal*depth/2);

                p1->impulse(normal * (p1->speed() + p2->speed()) / 2);
                p2->impulse(-normal * (p1->speed() + p2->speed())/ 2);
            }
        }
    }
}

void Engine::refreshBg()
{
    scene->setBackgroundBrush(QBrush(QColor(100,100,100)));
}
