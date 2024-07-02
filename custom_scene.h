#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include "particle.h"

class CustomScene : public QGraphicsScene {
    Q_OBJECT

public:
    explicit CustomScene(QObject *parent = nullptr);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
};

#endif // CUSTOMSCENE_H
