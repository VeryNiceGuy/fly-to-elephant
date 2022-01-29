#pragma once

#include <vector>
#include "Graph.h"

class Application
{
public:
	Application();
	~Application();

	bool requestWords() const;
private:
	Graph* getGraphByLetterCount(size_t letterCount) const;

	std::vector<Graph*> graphs;
	std::vector<std::string> dictionary;
};

// Метод возвращающий граф поддерживающий количество букв заданное параметром.
inline Graph* Application::getGraphByLetterCount(size_t letterCount) const
{
	for (auto i = graphs.begin(); i != graphs.end(); ++i)
		if ((*i)->getLetterCount() == letterCount)
			return *i;

	return nullptr;
}