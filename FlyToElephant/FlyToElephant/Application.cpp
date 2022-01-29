#include "Application.h"
#include <iostream>
#include <fstream>
#include <string>

Application::Application()
{
	// Загружаем словарь.
	std::ifstream file("dictionary.txt");
	std::string line;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			dictionary.push_back(line);

			bool graphFound = false;

			// Ищем граф поддерживающий текущее количество букв.
			for (auto i = graphs.begin(); i != graphs.end(); ++i)
			{
				if ((*i)->getLetterCount() == line.size())
				{
					(*i)->addNode(line);
					graphFound = true;
				}
			}

			// Если нужный нам граф не найден, создаем его.
			if (!graphFound)
			{
				Graph* graph = new Graph(line.size());
				graph->addNode(line);
				graphs.push_back(graph);
			}
		}

		file.close();
	}
}

Application::~Application()
{
	for (auto i = graphs.begin(); i != graphs.end(); ++i)
		delete (*i);
}

// Метод взаимодействующий с пользователем на протяжении всей жизни приложения.
bool Application::requestWords() const
{
	std::string sourceWord;
	std::string destinationWord;
	std::string serviceQuestion;

	std::cout << "Would you like to quit? (Y/N)";
	std::cin >> serviceQuestion;

	if (serviceQuestion[0] == 'Y')
		return false;

	std::cout << "Would you like to see all available words? (Y/N)";
	std::cin >> serviceQuestion;

	if (serviceQuestion[0] == 'Y')
	{
		for (auto i = dictionary.begin(); i != dictionary.end(); ++i)
			std::cout << *i << std::endl;

		return true;
	}

	std::cout << "Please enter a source word:" << std::endl;
	std::cin >> sourceWord;

	std::cout << "Please enter a destination word:" << std::endl;
	std::cin >> destinationWord;

	Graph* graph = getGraphByLetterCount(sourceWord.size());

	if (!graph)
	{
		std::cout << "Something is wrong, let us try again" << std::endl;

		return true;
	}

	graph->printInterjacentNodes(sourceWord, destinationWord);
	graph->reset();

	return true;
}