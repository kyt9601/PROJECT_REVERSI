#include "pch.h"
#include "include.h"

void exit()
{
	system("cls");

	for (int sec=WAITING_SECONDS; 0<sec; sec--)
	{
		std::cout << " �Ѥ� Project Reversi �ѤѤѤѤѤѤѤѤѤѤѤѤ�" << std::endl;
		std::cout << "/                                              /" << std::endl;
		std::cout << "/               Made by kyt9601                /" << std::endl;
		std::cout << "/             since July 08, 2017              /" << std::endl;
		std::cout << "/                 ver " << VERSION << "                    /" << std::endl;
		std::cout << "/                                              /" << std::endl;
		std::cout << "/  " << DEVELOPER_PAGE << "  /" << std::endl;
		std::cout << "/                                              /" << std::endl;
		std::cout << " �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << std::endl << std::endl;
		std::cout << "Thank you for playing :)" << std::endl;
		std::cout << "Reversi will close in " << sec << " seconds ..";

		Sleep(1000);
		system("cls");
	}
}