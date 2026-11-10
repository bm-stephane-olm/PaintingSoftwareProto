#ifndef COMMAND_H
#define COMMAND_H
#include <QUndoCommand>
#include <QImage>
#include "renderer.h"

class DrawCommand : public QUndoCommand {
    public:
        explicit DrawCommand(Renderer* renderer, QImage* image, QUndoCommand* parent = nullptr);
        void undo();
        void redo();
    private:
        QImage copyImage;
        Renderer* renderer;
};

#endif // COMMAND_H
