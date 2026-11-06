#include "renderer.h"

Renderer::Renderer(QWidget* parent) :
    QWidget(parent),
    penColor(Qt::black),
    penWidth(1)
{
    image = new QImage(500,500, QImage::Format::Format_ARGB32);
    image->fill(Qt::white);
    update();
}

void Renderer::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.drawImage(0, 0, *image);
}

void Renderer::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        isDrawing = true;
        drawTo(event->pos());
        startPos = event->pos();
    }
}

void Renderer::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        drawTo(event->pos());
        isDrawing = false;
    }
}

void Renderer::mouseMoveEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        drawTo(event->pos());
        startPos = event->pos();
    }
}

void Renderer::drawTo(QPoint endPos) {
    QPainter painter(image);
    painter.setPen(QPen(penColor, penWidth));
    painter.drawLine(startPos, endPos);
    qDebug() << "Draw";
    update();
}

