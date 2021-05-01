#include "pch.h"
#include "include.h"

STATUS Board::getTurn() { return currentTurn; }
int Board::getWhiteCount() { return whiteCount; }
int Board::getBlackCount() { return blackCount; }
int Board::getAvailableSize(STATUS status)
{ return (status==ENUM_WHITE ? whiteAvailableList.size() : blackAvailableList.size()); }

void Board::handleInput(int row, int col)
{
	if (isPutAvailable(row,col))
	{
		putDisc(row,col);
		refreshStatus(row,col);
		refreshList();
		refreshAvailableList();
		toggleTurn();
	}
	else
	{
		std::cout << std::endl << "Can't put " << (currentTurn==ENUM_WHITE ? "white" : "black") << " disc to there" << std::endl;
		system("pause");
	}
}
	
void Board::toggleTurn() { currentTurn = (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); }

void Board::putDisc(int row, int col)
{
	if (currentTurn == ENUM_WHITE)
	{
		status[row][col] = ENUM_WHITE;
		whiteCount++;
	}
	else
	{
		status[row][col] = ENUM_BLACK;
		blackCount++;		
	}
}

bool Board::isPutAvailable(int row, int col)
{
	std::vector <Position> &availableList = (currentTurn==ENUM_WHITE ? whiteAvailableList : blackAvailableList);
	int size = availableList.size();

	for (int i=0; i<size; i++)
		if (availableList[i].getRow()==row && availableList[i].getCol()==col)
			return true;

	return false;
}

void Board::refreshStatus(int row, int col)
{
	TraversingPosition traversal;
	TraversingPosition selectedPosition;

	traversal.setPosition(row,col);
	selectedPosition.setPosition(row,col);
	for (traversal.moveUp(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveUp());
	if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
		for (selectedPosition.moveUp(); selectedPosition != traversal; selectedPosition.moveUp())
		{
			status[selectedPosition.getRow()][selectedPosition.getCol()] = (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK);
			whiteCount += (currentTurn==ENUM_WHITE ? 1 : -1);
			blackCount += (currentTurn==ENUM_WHITE ? -1 : 1);
		}

	traversal.setPosition(row,col);
	selectedPosition.setPosition(row,col);
	for (traversal.moveRightUp(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveRightUp());
	if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
		for (selectedPosition.moveRightUp(); selectedPosition != traversal; selectedPosition.moveRightUp())
		{
			status[selectedPosition.getRow()][selectedPosition.getCol()] = (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK);
			whiteCount += (currentTurn==ENUM_WHITE ? 1 : -1);
			blackCount += (currentTurn==ENUM_WHITE ? -1 : 1);
		}

	traversal.setPosition(row,col);
	selectedPosition.setPosition(row,col);
	for (traversal.moveRight(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveRight());
	if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
		for (selectedPosition.moveRight(); selectedPosition != traversal; selectedPosition.moveRight())
		{
			status[selectedPosition.getRow()][selectedPosition.getCol()] = (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK);
			whiteCount += (currentTurn==ENUM_WHITE ? 1 : -1);
			blackCount += (currentTurn==ENUM_WHITE ? -1 : 1);
		}

	traversal.setPosition(row,col);
	selectedPosition.setPosition(row,col);
	for (traversal.moveRightDown(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveRightDown());
	if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
		for (selectedPosition.moveRightDown(); selectedPosition != traversal; selectedPosition.moveRightDown())
		{
			status[selectedPosition.getRow()][selectedPosition.getCol()] = (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK);
			whiteCount += (currentTurn==ENUM_WHITE ? 1 : -1);
			blackCount += (currentTurn==ENUM_WHITE ? -1 : 1);
		}

	traversal.setPosition(row,col);
	selectedPosition.setPosition(row,col);
	for (traversal.moveDown(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveDown());
	if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
		for (selectedPosition.moveDown(); selectedPosition != traversal; selectedPosition.moveDown())
		{
			status[selectedPosition.getRow()][selectedPosition.getCol()] = (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK);
			whiteCount += (currentTurn==ENUM_WHITE ? 1 : -1);
			blackCount += (currentTurn==ENUM_WHITE ? -1 : 1);
		}

	traversal.setPosition(row,col);
	selectedPosition.setPosition(row,col);
	for (traversal.moveLeftDown(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveLeftDown());
	if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
		for (selectedPosition.moveLeftDown(); selectedPosition != traversal; selectedPosition.moveLeftDown())
		{
			status[selectedPosition.getRow()][selectedPosition.getCol()] = (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK);
			whiteCount += (currentTurn==ENUM_WHITE ? 1 : -1);
			blackCount += (currentTurn==ENUM_WHITE ? -1 : 1);
		}

	traversal.setPosition(row,col);
	selectedPosition.setPosition(row,col);
	for (traversal.moveLeft(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveLeft());
	if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
		for (selectedPosition.moveLeft(); selectedPosition != traversal; selectedPosition.moveLeft())
		{
			status[selectedPosition.getRow()][selectedPosition.getCol()] = (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK);
			whiteCount += (currentTurn==ENUM_WHITE ? 1 : -1);
			blackCount += (currentTurn==ENUM_WHITE ? -1 : 1);
		}

	traversal.setPosition(row,col);
	selectedPosition.setPosition(row,col);
	for (traversal.moveLeftUp(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveLeftUp());
	if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
		for (selectedPosition.moveLeftUp(); selectedPosition != traversal; selectedPosition.moveLeftUp())
		{
			status[selectedPosition.getRow()][selectedPosition.getCol()] = (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK);
			whiteCount += (currentTurn==ENUM_WHITE ? 1 : -1);
			blackCount += (currentTurn==ENUM_WHITE ? -1 : 1);
		}
}

void Board::refreshList()
{
	clearVector(whiteList);
	clearVector(blackList);

	for (int row=1; row<BOARD_SIZE+1; row++)
		for (int col=1; col<BOARD_SIZE+1; col++)
			 if (status[row][col] == ENUM_WHITE)
				 whiteList.push_back(Position(row,col));
			 else if (status[row][col] == ENUM_BLACK)
				 blackList.push_back(Position(row,col));
}

void Board::refreshAvailableList()
{	
	int size;
	int currentRow;
	int currentCol;

	TraversingPosition traversal;
	TraversingPosition oneBlankGoPosition;

	size = whiteList.size();
	clearVector(whiteAvailableList);
	for (int i=0; i<size; i++)
	{
		currentRow = whiteList[i].getRow();
		currentCol = whiteList[i].getCol();

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveUp();
		for (traversal.moveUp(); status[traversal.getRow()][traversal.getCol()] == ENUM_BLACK; traversal.moveUp());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(whiteAvailableList,traversal);

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveRightUp();
		for (traversal.moveRightUp(); status[traversal.getRow()][traversal.getCol()] == ENUM_BLACK; traversal.moveRightUp());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(whiteAvailableList,traversal);

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveRight();
		for (traversal.moveRight(); status[traversal.getRow()][traversal.getCol()] == ENUM_BLACK; traversal.moveRight());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(whiteAvailableList,traversal);

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveRightDown();
		for (traversal.moveRightDown(); status[traversal.getRow()][traversal.getCol()] == ENUM_BLACK; traversal.moveRightDown());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(whiteAvailableList,traversal);

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveDown();
		for (traversal.moveDown(); status[traversal.getRow()][traversal.getCol()] == ENUM_BLACK; traversal.moveDown());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(whiteAvailableList,traversal);

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveLeftDown();
		for (traversal.moveLeftDown(); status[traversal.getRow()][traversal.getCol()] == ENUM_BLACK; traversal.moveLeftDown());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(whiteAvailableList,traversal);

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveLeft();
		for (traversal.moveLeft(); status[traversal.getRow()][traversal.getCol()] == ENUM_BLACK; traversal.moveLeft());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(whiteAvailableList,traversal);

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveLeftUp();
		for (traversal.moveLeftUp(); status[traversal.getRow()][traversal.getCol()] == ENUM_BLACK; traversal.moveLeftUp());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(whiteAvailableList,traversal);
	}

	size = blackList.size();
	clearVector(blackAvailableList);
	for (int i=0; i<size; i++)
	{
		currentRow = blackList[i].getRow();
		currentCol = blackList[i].getCol();

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveUp();
		for (traversal.moveUp(); status[traversal.getRow()][traversal.getCol()] == ENUM_WHITE; traversal.moveUp());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(blackAvailableList,traversal);

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveRightUp();
		for (traversal.moveRightUp(); status[traversal.getRow()][traversal.getCol()] == ENUM_WHITE; traversal.moveRightUp());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(blackAvailableList,traversal);

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveRight();
		for (traversal.moveRight(); status[traversal.getRow()][traversal.getCol()] == ENUM_WHITE; traversal.moveRight());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(blackAvailableList,traversal);

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveRightDown();
		for (traversal.moveRightDown(); status[traversal.getRow()][traversal.getCol()] == ENUM_WHITE; traversal.moveRightDown());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(blackAvailableList,traversal);

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveDown();
		for (traversal.moveDown(); status[traversal.getRow()][traversal.getCol()] == ENUM_WHITE; traversal.moveDown());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(blackAvailableList,traversal);

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveLeftDown();
		for (traversal.moveLeftDown(); status[traversal.getRow()][traversal.getCol()] == ENUM_WHITE; traversal.moveLeftDown());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(blackAvailableList,traversal);

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveLeft();
		for (traversal.moveLeft(); status[traversal.getRow()][traversal.getCol()] == ENUM_WHITE; traversal.moveLeft());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(blackAvailableList,traversal);

		traversal.setPosition(currentRow,currentCol);
		oneBlankGoPosition.setPosition(currentRow,currentCol);
		oneBlankGoPosition.moveLeftUp();
		for (traversal.moveLeftUp(); status[traversal.getRow()][traversal.getCol()] == ENUM_WHITE; traversal.moveLeftUp());
		if (status[traversal.getRow()][traversal.getCol()]==ENUM_EMPTY && oneBlankGoPosition!=traversal)
			pushElement(blackAvailableList,traversal);
	}
}

Position Board::positionGeneratorEasy()
{
	int size;

	std::vector <Position> &minPositionList = minPositionListGenerator();
	std::vector <int> minDistanceList;

	size = minPositionList.size();
	for (int i=0; i<size; i++)
		minDistanceList.push_back(minDistanceToBound(minPositionList[i]));

	int maxDistance = *(max_element(minDistanceList.begin(),minDistanceList.end()));

	std::vector <Position> maxDistancePositionList;

	size = minPositionList.size();
	for (int i=0; i<size; i++)
		if (maxDistance == minDistanceList[i])
			maxDistancePositionList.push_back(minPositionList[i]);

	Position generatedPosition = maxDistancePositionList[rand() % maxDistancePositionList.size()];

	clearVector(minPositionList);
	clearVector(minDistanceList);
	clearVector(maxDistancePositionList);

	return generatedPosition;
}

Position Board::positionGeneratorNormal()
{
	if (rand() % 2)
	{
		return positionGeneratorHard();
	}
	else
	{
		std::vector <Position> &minPositionList = minPositionListGenerator();
		Position generatedPosition = minPositionList[rand() % minPositionList.size()];

		clearVector(minPositionList);
		return generatedPosition;
	}
}

Position Board::positionGeneratorHard()
{
	return (currentTurn==ENUM_WHITE ?
		whiteAvailableList[rand() % whiteAvailableList.size()] :
		blackAvailableList[rand() % blackAvailableList.size()]);
}

Position Board::positionGeneratorExpert()
{
	if (rand() % 2)
	{
		return positionGeneratorHard();
	}
	else
	{
		std::vector <Position> &maxPositionList = maxPositionListGenerator();
		Position generatedPosition = maxPositionList[rand() % maxPositionList.size()];

		clearVector(maxPositionList);
		return generatedPosition;
	}
}

Position Board::positionGeneratorMaster()
{
	int size;

	std::vector <Position> &maxPositionList = maxPositionListGenerator();
	std::vector <int> minDistanceList;

	size = maxPositionList.size();
	for (int i=0; i<size; i++)
		minDistanceList.push_back(minDistanceToBound(maxPositionList[i]));

	int minDistance = *(min_element(minDistanceList.begin(),minDistanceList.end()));

	std::vector <Position> minDistancePositionList;

	size = maxPositionList.size();
	for (int i=0; i<size; i++)
		if (minDistance == minDistanceList[i])
			minDistancePositionList.push_back(maxPositionList[i]);

	Position generatedPosition = minDistancePositionList[rand() % minDistancePositionList.size()];

	clearVector(maxPositionList);
	clearVector(minDistanceList);
	clearVector(minDistancePositionList);

	return generatedPosition;
}

std::vector <Position> &Board::minPositionListGenerator()
{
	int size;
	int currentRow;
	int currentCol;

	TraversingPosition traversal;
	TraversingPosition selectedPosition;

	std::vector <Position> &availableList = (currentTurn==ENUM_WHITE ? whiteAvailableList : blackAvailableList);

	int point;
	std::vector <int> pointList;
	std::vector <Position> positionList;

	size = availableList.size();
	for (int i=0; i<size; i++)
	{
		point = 0;
		currentRow = availableList[i].getRow();
		currentCol = availableList[i].getCol();

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveUp(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveUp());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveUp(); selectedPosition != traversal; selectedPosition.moveUp())
				point++;

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveRightUp(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveRightUp());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveRightUp(); selectedPosition != traversal; selectedPosition.moveRightUp())
				point++;

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveRight(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveRight());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveRight(); selectedPosition != traversal; selectedPosition.moveRight())
				point++;

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveRightDown(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveRightDown());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveRightDown(); selectedPosition != traversal; selectedPosition.moveRightDown())
				point++;

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveDown(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveDown());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveDown(); selectedPosition != traversal; selectedPosition.moveDown())
				point++;

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveLeftDown(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveLeftDown());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveLeftDown(); selectedPosition != traversal; selectedPosition.moveLeftDown())
				point++;

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveLeft(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveLeft());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveLeft(); selectedPosition != traversal; selectedPosition.moveLeft())
				point++;

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveLeftUp(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveLeftUp());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveLeftUp(); selectedPosition != traversal; selectedPosition.moveLeftUp())
				point++;

		pointList.push_back(point);
		positionList.push_back(availableList[i]);
	}

	int min = *(min_element(pointList.begin(),pointList.end()));

	std::vector <Position> *minPositionList = new std::vector <Position>;

	size = positionList.size();
	for (int i=0; i<size; i++)
		if (pointList[i] == min)
			minPositionList->push_back(positionList[i]);

	clearVector(pointList);
	clearVector(positionList);

	return *minPositionList;	
}

std::vector <Position> &Board::maxPositionListGenerator()
{
	int size;
	int currentRow;
	int currentCol;

	TraversingPosition traversal;
	TraversingPosition selectedPosition;

	std::vector <Position> &availableList = (currentTurn==ENUM_WHITE ? whiteAvailableList : blackAvailableList);

	int point;
	std::vector <int> pointList;
	std::vector <Position> positionList;

	size = availableList.size();
	for (int i=0; i<size; i++)
	{
		point = 0;
		currentRow = availableList[i].getRow();
		currentCol = availableList[i].getCol();

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveUp(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveUp());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveUp(); selectedPosition != traversal; selectedPosition.moveUp())
				point++;

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveRightUp(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveRightUp());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveRightUp(); selectedPosition != traversal; selectedPosition.moveRightUp())
				point++;

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveRight(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveRight());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveRight(); selectedPosition != traversal; selectedPosition.moveRight())
				point++;

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveRightDown(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveRightDown());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveRightDown(); selectedPosition != traversal; selectedPosition.moveRightDown())
				point++;

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveDown(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveDown());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveDown(); selectedPosition != traversal; selectedPosition.moveDown())
				point++;

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveLeftDown(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveLeftDown());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveLeftDown(); selectedPosition != traversal; selectedPosition.moveLeftDown())
				point++;

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveLeft(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveLeft());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveLeft(); selectedPosition != traversal; selectedPosition.moveLeft())
				point++;

		traversal.setPosition(currentRow,currentCol);
		selectedPosition.setPosition(currentRow,currentCol);
		for (traversal.moveLeftUp(); status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_BLACK : ENUM_WHITE); traversal.moveLeftUp());
		if (status[traversal.getRow()][traversal.getCol()] == (currentTurn==ENUM_WHITE ? ENUM_WHITE : ENUM_BLACK))
			for (selectedPosition.moveLeftUp(); selectedPosition != traversal; selectedPosition.moveLeftUp())
				point++;

		pointList.push_back(point);
		positionList.push_back(availableList[i]);
	}

	int max = *(max_element(pointList.begin(),pointList.end()));

	std::vector <Position> *maxPositionList = new std::vector <Position>;

	size = positionList.size();
	for (int i=0; i<size; i++)
		if (pointList[i] == max)
			maxPositionList->push_back(positionList[i]);

	clearVector(pointList);
	clearVector(positionList);

	return *maxPositionList;	
}

int Board::minDistanceToBound(Position &rPosition)
{
	int currentRow = rPosition.getRow();
	int currentCol = rPosition.getCol();

	TraversingPosition traversal;

	int distance;
	int minDistance;

	distance = 1;
	traversal.setPosition(currentRow,currentCol);
	for (traversal.moveUp(); status[traversal.getRow()][traversal.getCol()] != ENUM_BOUND; traversal.moveUp(), distance++);
	minDistance = distance;

	distance = 1;
	traversal.setPosition(currentRow,currentCol);
	for (traversal.moveRightUp(); status[traversal.getRow()][traversal.getCol()] != ENUM_BOUND; traversal.moveRightUp(), distance++);
	if (distance < minDistance) { minDistance = distance; }

	distance = 1;
	traversal.setPosition(currentRow,currentCol);
	for (traversal.moveRight(); status[traversal.getRow()][traversal.getCol()] != ENUM_BOUND; traversal.moveRight(), distance++);
	if (distance < minDistance) { minDistance = distance; }

	distance = 1;
	traversal.setPosition(currentRow,currentCol);
	for (traversal.moveRightDown(); status[traversal.getRow()][traversal.getCol()] != ENUM_BOUND; traversal.moveRightDown(), distance++);
	if (distance < minDistance) { minDistance = distance; }

	distance = 1;
	traversal.setPosition(currentRow,currentCol);
	for (traversal.moveDown(); status[traversal.getRow()][traversal.getCol()] != ENUM_BOUND; traversal.moveDown(), distance++);
	if (distance < minDistance) { minDistance = distance; }

	distance = 1;
	traversal.setPosition(currentRow,currentCol);
	for (traversal.moveLeftDown(); status[traversal.getRow()][traversal.getCol()] != ENUM_BOUND; traversal.moveLeftDown(), distance++);
	if (distance < minDistance) { minDistance = distance; }

	distance = 1;
	traversal.setPosition(currentRow,currentCol);
	for (traversal.moveLeft(); status[traversal.getRow()][traversal.getCol()] != ENUM_BOUND; traversal.moveLeft(), distance++);
	if (distance < minDistance) { minDistance = distance; }

	distance = 1;
	traversal.setPosition(currentRow,currentCol);
	for (traversal.moveLeftUp(); status[traversal.getRow()][traversal.getCol()] != ENUM_BOUND; traversal.moveLeftUp(), distance++);
	if (distance < minDistance) { minDistance = distance; }

	return minDistance;		
}

void Board::show()
{
	system("cls");

	std::cout << " ";
	for (int col=1; col<BOARD_SIZE+1; col++)
		std::cout << "  " << col;
	std::cout << std::endl << std::endl;

	for (int row=1; row<BOARD_SIZE+1; row++)
	{
		std::cout << row << "  ";
		for (int col=1; col<BOARD_SIZE+1; col++)
			 if (status[row][col] == ENUM_WHITE)
				 std::cout << "● ";
			 else if (status[row][col] == ENUM_BLACK)
				 std::cout << "○ ";
			 else
				 std::cout << "   ";

			 if (row == BOARD_SIZE/2 - 1)
				 std::cout << "\t[" << level << "]";
			 else if (row == BOARD_SIZE/2)
				 std::cout << "\t●" << " : " << whiteCount;
			 else if (row == BOARD_SIZE/2 + 1)
				 std::cout << "\t○" << " : " << blackCount;
			 else if (row == BOARD_SIZE/2 + 2)
				 std::cout << "\tTurn : " << (currentTurn==ENUM_WHITE ? "●" : "○");
			 std::cout << std::endl << std::endl;
	}
}

template <typename T>
void clearVector(std::vector <T> &list)
{
	std::vector <T> temp;
	list.swap(temp);

	temp.clear();
	list.clear();
}

template <typename T, typename U>
void pushElement(std::vector <T> &list, U element)
{
	int size = list.size();
	for (int i=0; i<size; i++)
		if (list[i] == element)
			return;

	list.push_back(element);
}