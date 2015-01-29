#include <iostream>

using namespace std;

//g++ -g pointer_test.cpp -o pointer_test.exe
//-g means run with the debugger (basically attaches the source to the byte-code)

//gdb pointer_test.exe
//run the executable with the debugger

int main(int argc, char* argv[])
{
	//Declaring a variable allocates space in memory for that variable
	//That memory is on the stack
	int variable;
	
	//Initializing it changes the value
	variable = 500;
	
	//Creating a pointer also declares a variable
	//That memory is also on the stack
	int* pointer;
	
	//points pointer to the variable, wherever it happens to be
	pointer = &variable;
	
	//*pointer dereferences the pointer (get what it's pointing at)
	cout << *pointer << endl;
	
	//debugging:
	//set breakpoints tell the debugger where to stop
	
	//1) break main //sets a break point on main
	//2) run [arguments]
	//3) step goes to next line
	
	
	
	//de-reference: go from a pointer to data
	//*pointer
	
	//address to get the memory location
	//&data
	
	//Where can data live:
	// - constant pool: global variables and constants
	// - stack: function and return values
	// - heap: dynamic memory allocation
	return 0;
}