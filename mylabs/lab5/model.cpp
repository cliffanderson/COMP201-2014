#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
    width = w;
    height = h;
    Coordinate head;
    Coordinate tail;
    direction = RIGHT;
    head.x = 1;
    head.y = 0;
    tail.x = 0;
    tail.y = 0;
    food.x = 5;
    food.y = 10;
    snake.push_front(head);
    snake.push_back(tail);
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}

bool Model::gameOver() {
    return snake.empty() || snake.size() == 64 * 48 ;
}

// Which way should the snake face?
void Model::go(Direction d) {
    direction = d;
}

// Move foward
void Model::crawl() {
	
    Coordinate front = snake.front();
    switch(direction) {
    case UP: front.y--; break;
    case DOWN: front.y++; break;
    case LEFT: front.x--; break;
    case RIGHT: front.x++; break;
    }
    // TODO: Colliding with the perimeter of the screen should set direction to DEAD
    // When DEAD, the snake slowly shrinks down to nothing
    if(front.x < 0 || front.x == 64 || front.y < 0 || front.y == 48)
	{
		//dead
		direction = DEAD;
	}
	
	
	//move forward
    if (direction != DEAD) {
        snake.push_front(front);
    }
	else
	{
		//is dead
		snake.pop_front();
		snake.pop_back();
		return;
	}

    // TODO: Colliding with food grows the snake (so don't pop_back in that case)
	if(front.x == food.x && front.y == food.y)
	{
		// TODO: Also, colliding with food should cause us to place the food somewhere
		// else, but not anywhere on the snake.
		
		food.x = rand() % 64;
		food.y = rand() % 48;
	}
	else
	{
		snake.pop_back();
	}
    
}
