#include "Graph.h"
#include "Node.h"
#include <list>
#include <iostream>

Graph::~Graph()
{
	for (auto i = nodes.begin(); i != nodes.end(); ++i)
		delete (*i);
}

void Graph::addNode(const std::string& word)
{
	auto node = new Node();
	node->word = word;

	std::vector<Node*> neighbors;
	findPotentialNeighbors(node->word, neighbors);

	for (auto i = neighbors.begin(); i != neighbors.end(); ++i)
	{
		(*i)->neighbors.push_back(node);
		node->neighbors.push_back(*i);
	}

	nodes.push_back(node);
	wordsToNodes[word] = node;
}

void Graph::printInterjacentNodes(const std::string& sourceWord, const std::string& destinationWord) const
{
	auto sourceIterator = wordsToNodes.find(sourceWord);
	auto destinationIterator = wordsToNodes.find(destinationWord);

	if (sourceIterator == wordsToNodes.end())
		std::cout << sourceWord << " hasn't been recognized" << std::endl;

	if (destinationIterator == wordsToNodes.end())
		std::cout << destinationWord << " hasn't been recognized" << std::endl;

	if (sourceIterator == wordsToNodes.end() || destinationIterator == wordsToNodes.end())
		return;

	std::list<Node*> interjacentNodes;
	sourceIterator->second->findInterjacentNodes(destinationIterator->second, interjacentNodes);

	if (interjacentNodes.size())
	{
		std::cout << "Interjacent word chain:" << std::endl;

		for (auto i = interjacentNodes.begin(); i != interjacentNodes.end(); ++i)
			std::cout << (*i)->word << std::endl;
	}
	else
		std::cout << "No intejacent words found :(" << std::endl;
}

// Метод для тестов. Извлекает промежуточные узлы.
void Graph::extractInterjacentNodes(const std::string& sourceWord, const std::string& destinationWord, std::list<Node*>& interjacentNodes) const
{
	auto sourceIterator = wordsToNodes.find(sourceWord);
	auto destinationIterator = wordsToNodes.find(destinationWord);
	sourceIterator->second->findInterjacentNodes(destinationIterator->second, interjacentNodes);
}

void Graph::reset() const
{
	for (auto i = nodes.begin(); i != nodes.end(); ++i)
		(*i)->visited = false;
}

void Graph::findPotentialNeighbors(const std::string& word, std::vector<Node*>& neighbors) const
{
	for (auto i = nodes.begin(); i != nodes.end(); ++i)
		if (compareStrings(word, (*i)->word) == 1)
			neighbors.push_back(*i);
}

size_t Graph::compareStrings(const std::string& first, const std::string& second) const
{
	size_t charCount = 0;
	size_t mismatchCount = 0;

	while (charCount < first.size())
	{
		if (first[charCount] != second[charCount])
			++mismatchCount;

		++charCount;
	}

	return mismatchCount;
}