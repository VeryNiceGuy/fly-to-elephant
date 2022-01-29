#pragma once

#include <vector>
#include <string>
#include <map>
#include <list>

class Node;

class Graph
{
public:
	explicit Graph(size_t pmLetterCount): letterCount(pmLetterCount) {}
	~Graph();

	void addNode(const std::string& word);
	void printInterjacentNodes(const std::string& sourceWord, const std::string& destinationWord) const;
	void extractInterjacentNodes(const std::string& sourceWord, const std::string& destinationWord, std::list<Node*>& interjacentNodes) const;
	void reset() const;
	size_t getLetterCount() const;
private:
	void findPotentialNeighbors(const std::string& word, std::vector<Node*>& neighbors) const;
	size_t compareStrings(const std::string& first, const std::string& second) const;

	size_t letterCount;
	std::vector<Node*> nodes;
	std::map<std::string, Node*> wordsToNodes;
};

inline size_t Graph::getLetterCount() const
{
	return letterCount;
}