#include <iostream>
#include <stdio.h>
#include "Geometry.hpp"
#include "NodeTree.hpp"


int main()
{
    using namespace std;
    vec2f point0(0.0f, 0.0f);
    vec2f point1(0.5f, 0.0f);
    vec2f point2(0.5f, 0.5f);
    vec2f point3(0.0f, 0.5f);


    _2fpolygon polygon0;
    polygon0.push_back(point0);
    polygon0.push_back(point1);
    polygon0.push_back(point2);
    polygon0.push_back(point3);
    _2fpolygon polygon1;
    polygon1.push_back(point0);
    polygon1.push_back(point1);
    polygon1.push_back(point3);
    _2fpolygon polygon2;
    polygon2.push_back(point0);
    polygon2.push_back(point1);
    polygon2.push_back(point2);

    _2fpolygons polygons;
    polygons.push_back(polygon0);
    polygons.push_back(polygon1);
    polygons.push_back(polygon2);


    NodeTree tree(polygons[1]);
    tree.root->front = new Node(polygons[0]);
    tree.root->back = new Node(polygons[2]);

    tree.PrintAll(); // Print all the Binary-Space-Partitioning(BSP) Nodes datas
    std::vector<Node*> nodes = tree.getNodesAsVector();
    printf("Value coming from vector: %f \n", nodes[0]->data[1].x);


    // Gets node ids and char identifiers (name)
    for (int i = 0; i < tree.nodes_names.size(); ++i)
    {
        printf("Id of node %c is %i \n", tree.nodes_names[i], i + 1);
    }
    system("pause");
    return 0;
}