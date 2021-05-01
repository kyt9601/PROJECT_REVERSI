#include "pch.h"
#include "include.h"

void TraversingPosition::moveUp() { row--; }
void TraversingPosition::moveDown() { row++; }
void TraversingPosition::moveLeft() { col--; }
void TraversingPosition::moveRight() { col++; }
void TraversingPosition::moveRightUp() { moveUp(); moveRight(); }
void TraversingPosition::moveRightDown() { moveDown(); moveRight(); }
void TraversingPosition::moveLeftUp() { moveUp(); moveLeft(); }
void TraversingPosition::moveLeftDown() { moveDown(); moveLeft(); }