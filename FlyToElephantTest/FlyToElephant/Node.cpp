#include "Node.h"

Node::Node() : visited(false) {}

SearchResult Node::findInterjacentNodes(Node* destinationNode, std::list<Node*>& interjacentNodes)
{
	visited = true;

	if (destinationNode == this)
		return SearchResult::DestinationNode;

	for (auto i = neighbors.begin(); i != neighbors.end(); ++i)
	{
		if (!(*i)->visited)
		{
			SearchResult neighborResult = (*i)->findInterjacentNodes(destinationNode, interjacentNodes);

			if (neighborResult == SearchResult::CorrectRoute)
			{
				interjacentNodes.push_front(*i);

				return SearchResult::CorrectRoute;
			}
			else if (neighborResult == SearchResult::DestinationNode)
				return SearchResult::CorrectRoute;
		}
	}

	return SearchResult::IncorrectRoute;
}