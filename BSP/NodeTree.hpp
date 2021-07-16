#pragma once
#include "Node.hpp"


class NodeTree {
public:
	Node* root = new Node();
	std::vector<char> nodes_names;


	NodeTree(_2fpolygon value) 
	{
		root->data = value;
		nodes_names.push_back('A');
	}



	Node* MakeTree(_2fpolygons* list)
	{
		if (list == NULL) return this->root;

		Node* tree = new Node();
		//tree->back = MakeTree(list->back());
	}



	/// <summary>
	/// Print all the Binary-Space-Partitioning(BSP) Nodes data
	/// </summary>
	void PrintAll()
	{
		Node* currentNode = root;
		Node* otherPathNode = nullptr; // The forgoten node :(  :C lol
		bool stop = false;

		int depth = 0; // Thats not necessary here, it just shows how much we cave into the tree to get into a especific node
		while (!stop)
		{
			// Prints everything
			if (currentNode != NULL)
			{
				printf("Printing data in depth: %i \n", depth);
				for (int index = 0; index < currentNode->data.size(); ++index)
					printf("	Point %i = X: %f, Y: %f \n", index + 1, currentNode->data[index].x, currentNode->data[index].y);
				printf("Data printed \n\n");
			}
			if (otherPathNode != NULL)
			{
				printf("Printing data in depth: %i \n", depth);
				for (int index = 0; index < otherPathNode->data.size(); ++index)
					printf("	Point %i = X: %f, Y: %f \n", index + 1, otherPathNode->data[index].x, otherPathNode->data[index].y);
				printf("Data printed \n\n");
			}


			// Search
			if (currentNode->front != NULL)
			{
				if (currentNode->back != NULL)
				{
					otherPathNode = currentNode->back;
					nodes_names.push_back(nodes_names.back() + 1);
				}
				currentNode = currentNode->front;
				nodes_names.push_back(nodes_names.back() + 1);
			}
			else if (currentNode->back != NULL) 
			{
				currentNode = currentNode->back;
				nodes_names.push_back(nodes_names.back() + 1);
			}
			else
			{
				stop = true;
			}
			depth++;
		}
	}



	std::vector<Node*> getNodesAsVector()
	{
		std::vector<Node*> nodes;
		Node* currentNode = root;
		Node* otherPathNode = nullptr; // The forgoten node :(  :C lol
		bool stop = false;
		while (!stop)
		{
			// Search
			if (currentNode->front != NULL)
			{
				if (currentNode->back != NULL)
				{
					otherPathNode = currentNode->back;
					nodes.push_back(otherPathNode);
				}
				currentNode = currentNode->front;
				nodes.push_back(currentNode);
			}
			else if (currentNode->back != NULL)
			{
				currentNode = currentNode->back;
				nodes.push_back(currentNode);
			}
			else
			{
				stop = true;
			}
		}
		return nodes;
	}
};