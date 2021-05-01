#include "pch.h"
#include "include.h"

std::string level;
static RESULT result;

void run()
{
	int difficulty;
	bool exitByUser;

	srand(time(NULL));
	result = ENUM_INIT;

	while ( (difficulty = select()) )
	{
		Board board;
		Position (Board::*positionGenerator) () = NULL;
		Position computerPosition;
		int row, col;

		switch (difficulty)
		{
		case 1 : positionGenerator = &(Board::positionGeneratorEasy); level = "Easy"; break;
		case 2 : positionGenerator = &(Board::positionGeneratorNormal); level = "Normal"; break;
		case 3 : positionGenerator = &(Board::positionGeneratorHard); level = "Hard"; break;
		case 4 : positionGenerator = &(Board::positionGeneratorExpert); level = "Expert"; break;
		case 5 : positionGenerator = &(Board::positionGeneratorMaster); level = "Master"; break;
		}

		exitByUser = false;
		while (board.getAvailableSize(ENUM_WHITE) || board.getAvailableSize(ENUM_BLACK))
		{
			board.show();
			std::cout << "ex. 23 for (2,3)" << std::endl;
			std::cout << "¡Ø. 00 for back to Menu" << std::endl;
			std::cout << "Input 2 numbers : ";

			if ((board.getTurn()==ENUM_WHITE ? board.getAvailableSize(ENUM_WHITE) : board.getAvailableSize(ENUM_BLACK)) == 0)
			{
				std::cout << std::endl << std::endl << "Can't put " << (board.getTurn()==ENUM_WHITE ? "white" : "black") << " disc anywhere. Pass" << std::endl;
				system("pause");
				board.toggleTurn();
				continue;
			}

			if (board.getTurn() == ENUM_BLACK)	
			{
				std::string input;
				int firstCharacterIndex;

				firstCharacterIndex = positionInputChecker(input);

				if (firstCharacterIndex != -1)
				{
					row = input[firstCharacterIndex] - '0';
					col = input[firstCharacterIndex+1] - '0';

					if (!row && !col) { exitByUser = true; result = ENUM_INIT; break; }
				}
				else
				{
					std::cout << std::endl;
					std::cout << "Invalid input :/" << std::endl;
					system("pause");
					continue;
				}
			}
			else
			{
				computerPosition = (board.*positionGenerator)();
				Sleep(COMPUTER_SLEEP_TIME_MS);
				std::cout << computerPosition.getRow() << computerPosition.getCol();
				Sleep(COMPUTER_SLEEP_TIME_MS);
				row = computerPosition.getRow();
				col = computerPosition.getCol();
			}

			board.handleInput(row, col);
		}

		if (exitByUser) { continue; }

		board.show();

		int whiteCount = board.getWhiteCount();
		int blackCount = board.getBlackCount();

		switch (difficulty)
		{
		case 1 : result = (whiteCount<blackCount ? ENUM_WIN_EASY : 
					 (whiteCount==blackCount ? ENUM_DRAW_EASY : ENUM_LOSE_EASY)); break;
		case 2 : result = (whiteCount<blackCount ? ENUM_WIN_NORMAL : 
					 (whiteCount==blackCount ? ENUM_DRAW_NORMAL : ENUM_LOSE_NORMAL)); break;
		case 3 : result = (whiteCount<blackCount ? ENUM_WIN_HARD : 
					 (whiteCount==blackCount ? ENUM_DRAW_HARD : ENUM_LOSE_HARD)); break;
		case 4 : result = (whiteCount<blackCount ? ENUM_WIN_EXPERT : 
					 (whiteCount==blackCount ? ENUM_DRAW_EXPERT : ENUM_LOSE_EXPERT)); break;
		case 5 : result = (whiteCount<blackCount ? ENUM_WIN_MASTER : 
					 (whiteCount==blackCount ? ENUM_DRAW_MASTER : ENUM_LOSE_MASTER)); break;
		}

		if (whiteCount == blackCount)
			std::cout << "Draw !!" << std::endl;
		else
			std::cout << (whiteCount<blackCount ? "User" : "Computer") << " win "
				<< (whiteCount<blackCount ? ":)" : ":(") << std::endl;

		system("pause");
	}
}

int select()
{
	int select;
	std::string message1 = "Hello, player :)";
	std::string message2 = "Thank you for playing !!";

	system("cls");

	switch (result)
	{
		case ENUM_WIN_EASY : 
			message1 = "You are good :)";
			message2 = "Challenge to Normal difficulty !!";
			break;
		case ENUM_LOSE_EASY : 
			message1 = "Don't be sad ;)";
			message2 = "Try again !!";
			break;
		case ENUM_DRAW_EASY : 
			message1 = "Do you want to defeat him ?";
			message2 = "Try Easy difficulty again !!";
			break;
		case ENUM_WIN_NORMAL : 
			message1 = "You plays well :)";
			message2 = "Challenge to Hard difficulty !!";
			break;
		case ENUM_LOSE_NORMAL :
			message1 = "That was close :)";
			message2 = "Try again !!";
			break;
		case ENUM_DRAW_NORMAL : 
			message1 = "Do you want defeat him ?";
			message2 = "Try Normal difficulty again !!";
			break;
		case ENUM_WIN_HARD : 
			message1 = "I think you are good at Reversi ..";
			message2 = "Challenge to Expert difficulty !!";
			break;
		case ENUM_LOSE_HARD : 
			message1 = "Cheer up :)";
			message2 = "Try again !!";
			break;
		case ENUM_DRAW_HARD : 
			message1 = "Do you want defeat him ?";
			message2 = "Try Hard difficulty again !!";
			break;
		case ENUM_WIN_EXPERT :
			message1 = "Unbelievable ..";
			message2 = "Challenge to Master difficulty !!";
			break;
		case ENUM_LOSE_EXPERT : 
			message1 = "I think you need more practice ;)";
			message2 = "How about play Hard difficulty ?";
			break;
		case ENUM_DRAW_EXPERT : 
			message1 = "Do you want defeat him ?";
			message2 = "Try Expert difficulty again !!";
			break;
		case ENUM_WIN_MASTER :
			message1 = "Incredible XD";
			message2 = "You are a Reversi Master !!";
			break;
		case ENUM_LOSE_MASTER : 
			message1 = "You can't defeat him yet ;)";
			message2 = "Practice more !!";
			break;
		case ENUM_DRAW_MASTER : 
			message1 = "Do you want defeat him ?";
			message2 = "Try Master difficulty again !!";
			break;
	}

	do
	{
		std::cout << message1 << std::endl;
		std::cout << message2 << std::endl << std::endl;

		std::cout << "[1] Easy" << std::endl;
		std::cout << "[2] Normal" << std::endl;
		std::cout << "[3] Hard" << std::endl;
		std::cout << "[4] Expert" << std::endl;
		std::cout << "[5] Master" << std::endl << std::endl;
		std::cout << "[0] Exit" << std::endl;
		std::cout << "Please select difficulty : ";

		if ( (select = menuInputChecker()) == -1)
		{
			std::cout << std::endl;
			std::cout << "Invalid input :/" << std::endl;
			system("pause");
		}
		else if (select<0 || 5<select)
		{
			std::cout << std::endl;
			std::cout << "Invalid number !!" << std::endl;
			system("pause");		
		}

		system("cls");
	}
	while (select<0 || 5<select);

	return select;
}

int menuInputChecker()
{
	std::string input;
	int index;
	int length;
	int firstCharacterIndex;

	std::getline(std::cin, input, '\n'); fflush(stdin); std::cin.clear();
	length = input.length();

	for (index=0; index<length && input[index]==' '; index++);
	firstCharacterIndex = index;

	if (length == firstCharacterIndex) { return -1; }
	else if (input[firstCharacterIndex]<'0' || '9'<input[firstCharacterIndex]) { return -1; }

	for (index++; index<length && input[index]==' '; index++);

	if (index != length) { return -1; }

	return input[firstCharacterIndex] - '0';	
}

int positionInputChecker(std::string &input)
{
	int index;
	int length;
	int firstCharacterIndex;

	std::getline(std::cin, input, '\n'); fflush(stdin); std::cin.clear();
	length = input.length();

	for (index=0; index<length && input[index]==' '; index++);
	firstCharacterIndex = index;

	if (length-1 <= firstCharacterIndex) { return -1; }
	else if (input[firstCharacterIndex]<'0' || '9'<input[firstCharacterIndex]) { return -1; }
	else if (input[firstCharacterIndex+1]<'0' || '9'<input[firstCharacterIndex+1]) { return -1; }

	for (index+=2; index<length && input[index]==' '; index++);

	if (index != length) { return -1; }

	return firstCharacterIndex;	
}