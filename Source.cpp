#include <iostream>
#include "Menu.h"
#include "DialogFinder.h"
#include "FileInput.h"
#include "FileOutput.h"
#include "TextInput.h"
#include"SaveInitialData.h"
#include"ConsoleOutput.h"
#include "Check.h"
#include <Windows.h>

enum class Type
{
	console = 1,
	file
};

enum class Answer
{
	Yes = 1,
	No
};


int main()
{	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "---------------------------" << std::endl
		<< "Berdiev Eduard gr. 415 KR-4" << std::endl
		<< "---------------------------" << std::endl;

	std::cout << "!!! Important Condition :" << std::endl
		<< "for the correct work of the program need two conditions must be met :" << std::endl
		<< "1 - A dash must be at the beginning of a sentence" << std::endl
		<< "2 - After dialog should be a signs of the end like [!] [?] [.] " << std::endl;

	std::string text;

	while (true)
	{
		Type input = static_cast<Type>(AscUserInputType());
		switch (input)
		{
		case Type::console:
			text = InputText();
			if (static_cast<Answer>(AscInitialDataSaveMenu()) == Answer::Yes)
				SaveInitialData(text);
			break;
		case Type::file:
			text = FileInput();
			break;
		}
		DialogFinder finder(text);

		finder.FindDialogs();

		Type output = static_cast<Type>(AscOutputType());
		switch (output)
		{
		case Type::console:
			ConsoleOutput(finder);
			break;
		case Type::file:
			FileOutputResult(finder);
		}
		std::cout << "\nEnd program?\n1 - Yes\n2 - No" << std::endl;
		Answer endProgram = static_cast<Answer>(CheckMenu(2));
		if (endProgram == Answer::Yes)
			return 0;
	}
}