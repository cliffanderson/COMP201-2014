#include <iostream>
using namespace std;

//References are nicer syntax for pointers
void age_a_year(int &age)
{
	age++;
}

//C style
void age_a_year_C(int *age)
{
	(*age)++;
}

int main()
{
	int jack = 50;
	
	//age_a_year(jack);
	age_a_year_C(&jack);
	//cout << jack << endl;
	
	
	int number;
	int product = 1;
	
	cout << "How many ints? " << endl;
	cin >> number;
	
	//Ask operating system for memory
	int * array = new int[number];
	
	for(int i = 0; i < number; i++)
	{
		cout << "Number please: ";
		cin >> array[i];
	}
	
	for(int i = 0; i < number; i++)
	{
		product *= array[i];
	}
	
	//Clean up your mess
	delete array;
	cout << "Product: " << product << endl;
	
	return 0;
	
}