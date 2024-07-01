#include "engine.h"
#include "ui_engine.h"
#include <QList>

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
    spawn(5);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    connect(timer, SIGNAL(timeout()), this, SLOT(refreshBg()));
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
        qreal x = (rand()%798) + 25 - d;
        qreal y = (rand()%598) + 15 - d;
        Particle *obj = new Particle(x,y,d,d);
        particles << obj;
        scene->addItem(particles.last());
    }
}

void Engine::refreshBg()
{
    scene->setBackgroundBrush(QBrush(QColor(100,100,100)));
}
