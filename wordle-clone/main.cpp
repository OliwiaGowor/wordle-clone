#include <iostream>
#include <filesystem>

import Menu;
import FileManagement;

namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
	std::string fileNameUsers,
		fileNameDatabase;
	fs::path filesPath("C:\\Users\\Oliwia\\source\\repos\\My Github\\wordle-clone\\wordle-clone\\Data");
	FileManagement filemanagement(filesPath);
	Menu menu(filemanagement);

	menu.RunProgram();
	return 0;
}