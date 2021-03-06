#pragma once

#include <QObject>
#include <QPointF>
#include <QPixmap>
#include <QTimer>
#include <QGraphicsItem>

class Explosion : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Explosion(const QPointF &point, double radius);

    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QPixmap *explosion = nullptr;
    QTimer timer;
    double r = 0;
    int currentSpriteCoordinate = 0;

private slots:
    void nextSprite();
};
