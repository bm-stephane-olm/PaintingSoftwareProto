#include "command.h"

DrawCommand::DrawCommand(Renderer* renderer, QImage* image, QUndoCommand* parent) :
    renderer(renderer)
{
    copyImage = *image;
}

void DrawCommand::undo() {
    renderer->setImage(copyImage);
    renderer->update();
}

void DrawCommand::redo() {
    renderer->setImage(copyImage);
    renderer->update();
}