#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;


//state of the game
	//FIRST: choosing the first cell
	//SECOND: choosing the second cell
	//MATCH: There was a match, congratulate the player and reset state to FIRST
	//NO_MATCH: There was not a match, tell the player, reset the cells, and reset state to FIRST
enum State { FIRST, SECOND, MATCH, NO_MATCH };
// Concentration game model
// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    // Initialize a grid of letters randomly
    Model(int w, int h);
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    // Methods (member functions)
    // Return the width
    int getWidth();
    // Return the height
    int getHeight();
    // Return visible stuff (invisible stuff is shown with character *)
    char get(int row, int column);
    // Flip this row/column
    void flip(int row, int column);
    // Is the game over?
    bool gameOver();
	
	State getState()
	{
		return state;
	}
private:
    // Is the row/column valid?
    bool valid(int row, int column);
    // Did the cell at current row/column match the cell at the last row/column 
    bool matched(int row, int column);
    // Fields (member data)
    // Randomly generated grid. This has pairs of characters in it
    char ** grid;
    // What is visible to the user?
    char ** visible;
    // What's the width?
    int width;
    // What's the height?
    int height;
    // Used when flipping the second cell
    int lastRow;
    int lastColumn;
	
	//used when picking flipping the first cell
	int lasterRow;
	int lasterColumn;
	
    State state;
};

// Show (output) the state of the model
class View {
public:
    // Print out the visible stuff in the grid
    void show(Model * model);
};

// Handle input
class Controller {
public:
    Controller() {
        model = new Model(8,8);
        view = new View;
    }
	
	~Controller()
	{
		delete model;
		delete view;
	}
    // Event loop
    void loop();
private:
    Model * model;
    View * view;
};

// Constructor initializes the object
Model::Model(int w, int h) {
    width = w;
    height = h;
	
    lastRow = -1;
    lastColumn = -1;
	lasterRow = -1;
	lasterColumn = -1;
	
    state = FIRST;
    grid = new char*[h];
    visible = new char*[h];
    for (int i = 0; i < height; i++) {
        grid[i] = new char[w];
        visible[i] = new char[w];
    }
    // TODO: make this random-ish
	//makes the grid
	
	//assume we always have an 8x8 grid, so 64 slots and 32 unique pairs
	char options[] =   {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F',
						'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F'};
	
	//init randomness
	srand(time(0));
	//swap characters 1000 times
	for(int i = 0; i < 1000; i++)
	{
		int place1 = rand() % 64;
		int place2 = rand() % 64;
		
		char temp = options[place1];
		options[place1] = options[place2];
		options[place2] = temp;
	}
	
	//output answers to separate file for testing/cheating
	ofstream out;
	out.open("answers.txt");
	
	//index of random letters
	int index = 0;
	
    for (int i = 0; i < height; i++) {
		out << endl;
        for (int j = 0; j < width; j++) {
           // grid[i][j] = 'a';
		   grid[i][j] = options[index++];
		   out << grid[i][j] << " ";
            visible[i][j] = '*';
        }
    }
	
	out.close();
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
    for (int i = 0; i < height; i++) {
        delete grid[i];
        delete visible[i];
    }
    delete grid;
    delete visible;
}
// TODO: Is the row/column valid?
// That is, is the row within the height, and is the column within the width?
// Return whether it is or isn't.
bool Model::valid(int row, int column) {
    return row < width && column < height;
}
bool Model::matched(int row, int column) {
    return grid[row][column] == grid[lastRow][lastColumn];
}
// TODO: Flip a cell
void Model::flip(int row, int column) {
	//cout << "Flipping row " << row << " and column " << column << " with state " << state << endl;
    // If the row and column are not valid, break out and don't do anything
    if (!valid(row, column)) { return; }
    
	if(state == FIRST)
	{
		visible[row][column] = grid[row][column];
		lasterRow = row;
		lasterColumn = column;
		
		state = SECOND;
	}
	else if (state == SECOND)
	{
		if(lasterRow == row && lasterColumn == column)
			//don't want to pick the same cell
			return;
		visible[row][column] = grid[row][column];
		lastRow = row;
		lastColumn = column;
		
		if(grid[lasterRow][lasterColumn] == grid[lastRow][lastColumn])
		{
			//we have a match
			state = MATCH;
		}
		else
		{
			//no match7
			state = NO_MATCH;
		}
		
	}
	else if (state == MATCH)
	{
		cout << endl << "Congratulations! You have made a match!!" << endl;
		
		//reset variables
		lasterRow = -1;
		lasterColumn = -1;
		lastRow = -1;
		lastColumn = -1;
		
		state = FIRST;
	}
	else if (state == NO_MATCH)
	{
		cout << endl << "Sorry, that was not a match, please try again." << endl;
		
		//reset visible cells
		visible[lasterRow][lasterColumn] = '*';
		visible[lastRow][lastColumn] = '*';
		
		//reset variables
		lasterRow = -1;
		lasterColumn = -1;
		lastRow = -1;
		lastColumn = -1;
		state = FIRST;
	}
	else
	{
		cout << endl << "Error..." << endl; 
	}
	
	
    // If the last selected row and column are invalid,
        // It means we're selecting the first "cell" to flip
    // Otherwise, we are selecting the next "cell" to flip
        // If the last cell and the current cell match, great!
        // Otherwise, make the last cell invisible (set it to *)
    // Make the current cell visible
}
// If everything is visible, then it's game over
bool Model::gameOver() {
    for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if(visible[i][j] == '*')
				return false;
		}
	}
	
    return true;
}
int Model::getWidth() {
    return width;
}
int Model::getHeight() {
    return height;
}
char Model::get(int row, int col) {
    return visible[row][col];
}
// Show the model, one cell at a time
void View::show(Model * model) {
    for (int j = 0; j < model->getWidth(); j++) {
        cout << "\t" << j;
    }
    cout << endl;
    for (int i = 0; i < model->getHeight(); i++) {
        cout << i;
        for (int j = 0; j < model->getWidth(); j++) {
            cout << "\t" << model->get(i, j);
        }
        cout << endl;
    }
}

// Show the board
// Read in coordinates
// Until we're done
void Controller::loop() {
    int row, col;
    while (!model->gameOver()) {
		//cout << endl << "DEBUG    " << model->getState() << "   DEBUG" << endl;

		view->show(model);
				
		if(!(model->getState() == MATCH || model->getState() == NO_MATCH))
		{
			cout << "Enter row:    ";
			cin >> row;
			cout << "Enter column: ";
			cin >> col;
		}
        model->flip(row, col);
    }
	
	cout << endl << "You win! Thanks for playing!" << endl;
}

int main() {
    Controller c;
    c.loop();
}
