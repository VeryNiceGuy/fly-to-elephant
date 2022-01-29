#include "Node.h"

Node::Node() : visited(false) {}

// Рекурсивный метод возвращающий список промежуточных узлов графа. Вызывается только на исходном (начальном) узле.
SearchResult Node::findInterjacentNodes(Node* destinationNode, std::list<Node*>& interjacentNodes)
{
	// Помечаем узел как посещенный чтобы избежать цикличности.
	visited = true;

	// Если мы дошли до конечного узла (destination), возвращаем соответствующее значение.
	if (destinationNode == this)
		return SearchResult::DestinationNode;

	// Итерируем через массив "соседей" связанных с данным узлом разницей на один символ.
	for (auto i = neighbors.begin(); i != neighbors.end(); ++i)
	{
		// Заходим только если узел не был посещен ранее.
		if (!(*i)->visited)
		{
			// Вызываем тот-же метод на соседнем узле.
			SearchResult neighborResult = (*i)->findInterjacentNodes(destinationNode, interjacentNodes);

			// Если был найден конечный узел, то по корректной цепочке узлов (на которой он был найден) передается значение CorrectRoute,
			// получая которое в условно говоря более "ближнем к началу" узле мы добавляем вернувшего его соседа в список промежуточных узлов. 
			if (neighborResult == SearchResult::CorrectRoute)
			{
				interjacentNodes.push_front(*i);

				return SearchResult::CorrectRoute;
			}
			// Если наш сосед - конечный узел, просто игнорируем его (не добавляя в список, так как он нам не нужен).
			else if (neighborResult == SearchResult::DestinationNode)
				return SearchResult::CorrectRoute;
		}
	}

	// Неверная цепочка (маршрут). Сюда мы можем попасть по разным причинам, например
	// все соседние узлы помечены как посещенные или нет соседей.
	return SearchResult::IncorrectRoute;
}