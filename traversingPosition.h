#pragma once

class TraversingPosition : public Position
{
public :
	TraversingPosition(int row = 0, int col = 0)
				: Position(row, col) {}

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void moveRightUp();
	void moveRightDown();
	void moveLeftUp();
	void moveLeftDown();

	~TraversingPosition() {}
};
