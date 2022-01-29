#pragma once

#include <vector>
#include <list>

enum class SearchResult : int
{
	CorrectRoute,
	IncorrectRoute,
	DestinationNode
};

class Node
{
public:
	Node();

	SearchResult findInterjacentNodes(Node* destinationNode, std::list<Node*>& interjacentNodes);

	bool visited;
	std::string word;
	std::vector<Node*> neighbors;
};