#include "pch.h"
#include "include.h"

int Position::getRow() { return row; }
int Position::getCol() { return col; }
void Position::setRow(int row) { this->row = row; }
void Position::setCol(int col) { this->col = col; }

void Position::setPosition(int row, int col)
{
	this->row = row;
	this->col = col;
}

bool Position::operator == (Position &rPosition)
{
	if (row == rPosition.row &&
		col == rPosition.col)
		return true;
	else
		return false;
}

bool Position::operator != (Position &rPosition)
{
	if (row == rPosition.row &&
		col == rPosition.col)
		return false;
	else
		return true;
}