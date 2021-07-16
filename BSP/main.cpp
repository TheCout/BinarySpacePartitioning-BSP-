#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include "Engine.h"
#include "Geometry.hpp"
#include "NodeTree.hpp"
#include "Math.hpp"


const unsigned int MAP_WIDTH = 50;
const unsigned int MAP_HEIGHT = 50;
extern Player player;


void BSPtest();


vec2f p0(0.f, 0.f);


using namespace Engine;
void App::tick()
{

}
void App::render()
{
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(player.position.x, -player.position.y);
    glEnd();


    float fov0x =  player.position.x + cos(player.angle - getRadians(player.FOV / 2)) * player.FOG;
    float fov0y = -player.position.y - sin(player.angle - getRadians(player.FOV / 2)) * player.FOG;
    float fov1x =  player.position.x + cos(player.angle + getRadians(player.FOV / 2)) * player.FOG;
    float fov1y = -player.position.y - sin(player.angle + getRadians(player.FOV / 2)) * player.FOG;


    float f0x = cos(player.angle - getRadians(player.FOV / 2));
    float f0y = sin(player.angle - getRadians(player.FOV / 2));
    float f1x = cos(player.angle + getRadians(player.FOV / 2));
    float f1y = sin(player.angle + getRadians(player.FOV / 2));


    float wallAngleFromPlayer = atan2f(player.position.y - p0.y, player.position.x - p0.x) * 180.0 / PI;
    float fov0Angle = atan2f(player.position.y - f0y, player.position.x - f0x) * 180.0 / PI;
    float fov1Angle = atan2f(player.position.y - f1y, player.position.x - f1x) * 180.0 / PI;

    //printf("%f  |  %f  |  %f \n\n", wallAngleFromPlayer, fov0Angle, fov1Angle);

    int side0 =  0;
    if (fov0x < player.position.x && fov1x < player.position.x)
    {
        side0 = -1;
    }
    else if (fov0x > player.position.x && fov1x > player.position.x)
    {
        side0 =  1;
    }
    int side1 =  0;
    if (p0.x < player.position.x && p0.x < player.position.x)
    {
        side1 = -1;
    }
    else if (p0.x > player.position.x && p0.x > player.position.x)
    {
        side1 =  1;
    }
    
    float biggestAngle = fov0Angle > fov1Angle ? fov0Angle : fov1Angle;
    float smallestAngle = fov0Angle > fov1Angle ? fov1Angle : fov0Angle;
    if (wallAngleFromPlayer < biggestAngle && wallAngleFromPlayer > smallestAngle && side0 == side1 | true)
    {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-10.f, 10.f);
        glVertex2f(10.f, 10.f);
        glVertex2f(10.f, -10.f);
        glVertex2f(-10.f, -10.f);
        glEnd();
    }
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(player.position.x, -player.position.y);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(fov0x, fov0y);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(fov1x, fov1y);
    glEnd();
}



int main()
{
    App app{};
    app.run();
    return 0;
}



void BSPtest() 
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
    vector<Node*> nodes = tree.getNodesAsVector();
    printf("Value coming from vector: %f \n", nodes[0]->data[1].x);


    // Gets node ids and char identifiers (name)
    for (int i = 0; i < tree.nodes_names.size(); ++i)
    {
        printf("Id of node %c is %i \n", tree.nodes_names[i], i + 1);
    }
}