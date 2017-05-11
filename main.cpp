// Jon Kane
// Final Project
// Due: 5/11/17

// Multi-Agent Learning Grid World

#include <iostream>
#include <fstream>
#include <assert.h>
#include <ctime>
#include <time.h>
#include <limits>
#include <random>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <algorithm>

using namespace std;

#define LYRAND (double)rand()/RAND_MAX //LYRAND as given by Dr. Logan

//Set up Grid world for the agents

int WorldWidth;
int WorldHeight;
int generation = 10,000;

// update agent locations
int agent1X;
int agent2X;
int agent1Y;
int agent2Y;

//starting agents location
int agentStart1X;
int agentStart1Y;
int agentStart2X;
int agentStart2Y;
// initialize the goal for both agents
int goalX;
int goalY;

// Create agents and goal locations
agent1X = rand()% gridHeight;
agent1Y = rand()% gridWidth;
agent2X = rand()% gridHeight;
agent2Y = rand()% gridWidth;

agentStart1X = agent1X;
agentStart1Y = agent1Y;
agentStart2X = agent2X;
agentStart2Y = agent2Y;

goalX = rand()% gridHeight;
goalY = rand()% gridWidth;

// If agents and goal or both agents are in same location change the locations
while( agent1X == goalX && agent1Y == goalY ){

        agent1X = rand()% gridWidth;
        agent1Y = rand()% gridHeight;

        agentStart1X = agent1X;
        agentStart1Y = agent1Y;

        goalY = rand()% gridHeight;
        goalX= rand()% gridWidth;
    }
while( agent2X == goalX && agent2Y == goalY ){

        agent2X = rand()% gridWidth;
        agent2Y = rand()% gridHeight;

        agentStart2X = agent2X;
        agentStart2Y = agent2Y;

        goalY = rand()% gridHeight;
        goalX= rand()% gridWidth;
    }


// Set up the Agents
class Agents {
public:

};
