#pragma once
#include "Node.hpp"


class NodeTree {
public:
	Node* root = new Node();

	NodeTree(_2fpolygon value) 
	{
		root->data = value;
	}


	/// <summary>
	/// Print all the Binary-Space-Partitioning(BSP) Nodes data
	/// </summary>
	void PrintAll()
	{
		Node* currentNode = root;
		Node* otherPathNode = nullptr; // The forgoten node :(  :C lol
		bool stop = false;
		while (!stop)
		{
			// Prints everything
			if (currentNode != NULL)
			{
				printf("Printing data... \n");
				for (int index = 0; index < currentNode->data.size(); ++index)
					printf("	X: %f, Y: %f \n", currentNode->data[index].x, currentNode->data[index].y);
				printf("Data printed \n\n");
			}
			if (otherPathNode != NULL)
			{
				printf("Printing data... \n");
				for (int index = 0; index < otherPathNode->data.size(); ++index)
					printf("	X: %f, Y: %f \n", otherPathNode->data[index].x, otherPathNode->data[index].y);
				printf("Data printed \n\n");
			}


			// Search
			if (currentNode->front != NULL)
			{
				if (currentNode->back != NULL)
					otherPathNode = currentNode->back;
				currentNode = currentNode->front;
			}
			else if (currentNode->back != NULL) 
			{
				currentNode = currentNode->back;
			}
			else
			{
				stop = true;
			}
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