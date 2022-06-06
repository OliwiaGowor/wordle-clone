#include <iostream>
#include <filesystem>

import Menu;
import FileManagement;

namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
	std::string fileNameUsers,
		fileNameDatabase;
	fs::path filesPath("C:\\Users\\Oliwia\\source\\repos\\76e2647c-gr52-repo\\Projekt\\Klon_Wordle\\Klon_Wordle\\Data");

	FileManagement filemanagement(filesPath);
	Menu menu(filemanagement);

	menu.RunProgram();
	return 0;
}