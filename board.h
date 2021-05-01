#pragma once

extern std::string level;

template <typename T> void clearVector(std::vector <T> &list);
template <typename T, typename U> void pushElement(std::vector <T> &list, U element);

class Board
{
private :
	STATUS status[BOARD_SIZE+2][BOARD_SIZE+2];
	std::vector <Position> whiteList;
	std::vector <Position> blackList;
	std::vector <Position> whiteAvailableList;
	std::vector <Position> blackAvailableList;

	int whiteCount;
	int blackCount;
	STATUS currentTurn;
public :
	Board() : currentTurn(ENUM_BLACK), whiteCount(0), blackCount(0)
	{
		for (int row=0; row<BOARD_SIZE+2; row++)
			for (int col=0; col<BOARD_SIZE+2; col++)
				if (row==0 || col==0 || row==BOARD_SIZE+1 || col==BOARD_SIZE+1)
					status[row][col] = ENUM_BOUND;
				else if ((row==BOARD_SIZE/2 && col==BOARD_SIZE/2) || (row==BOARD_SIZE/2+1 && col==BOARD_SIZE/2+1))
					status[row][col] = ENUM_WHITE;
				else if ((row==BOARD_SIZE/2 && col==BOARD_SIZE/2+1) || (row==BOARD_SIZE/2+1 && col==BOARD_SIZE/2))
					status[row][col] = ENUM_BLACK;
				else
					status[row][col] = ENUM_EMPTY;

		whiteCount = 2;
		blackCount = 2;

		refreshList();
		refreshAvailableList();
	}

	STATUS getTurn();
	int getWhiteCount();
	int getBlackCount();
	int getAvailableSize(STATUS status);

	void handleInput(int row, int col);
	
	void toggleTurn();
	void putDisc(int row, int col);
	bool isPutAvailable(int row, int col);

	void refreshStatus(int row, int col);
	void refreshList();
	void refreshAvailableList();

	Position positionGeneratorEasy();
	Position positionGeneratorNormal();
	Position positionGeneratorHard();
	Position positionGeneratorExpert();
	Position positionGeneratorMaster();
	std::vector <Position> &minPositionListGenerator();
	std::vector <Position> &maxPositionListGenerator();
	int minDistanceToBound(Position &rPosition);

	void show();

	~Board()
	{
		clearVector(whiteList);
		clearVector(blackList);
		clearVector(whiteAvailableList);
		clearVector(blackAvailableList);
	}
};
