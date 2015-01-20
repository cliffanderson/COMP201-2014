#include<iostream>
#include<fstream>

using namespace std;

int main(int a, char* args[])
{
	ifstream in;
	in.open(args[1]);

	ofstream out;
	out.open("output.txt");

	if(in.fail())
	{
		cout << "FAIL" << endl;
		in.close();
		exit(1);
	}

	out << "x\tx^2\tsum" << endl;
	out << "=\t===\t===" << endl;
	
	int read = 0;
	int sum = 0;

	while(in >> read)
	{
		//cout << read << endl;
		//add read to sum
		sum += read;
		
		out << read << "\t" << read * read << "\t" << sum << endl;
	}

	cout << "Please see output.txt for the output of the program." << endl;

	in.close();
	out.close();

	return 0;
}
