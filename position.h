#pragma once

class Position
{
protected :
	int row;
	int col;
public :
	Position(int row = 0, int col = 0)
		: row(row), col(col) {}

	int getRow();
	int getCol();
	void setRow(int row);
	void setCol(int col);

	void setPosition(int row, int col);

	bool operator == (Position &rPosition);
	bool operator != (Position &rPosition);

	~Position() {}
};
