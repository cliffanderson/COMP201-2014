#include<iostream>
#include<fstream>

using namespace std;

int main(int a, char* args[])
{
	ifstream in;
	in.open(args[1]);

	if(in.fail())
	{
		cout << "FAIL" << endl;
		in.close();
		exit(1);
	}

	cout << "x\tx^2\tsum" << endl;
	cout << "=\t===\t===" << endl;
	
	int read = 0;
	int sum = 0;

	while(in >> read)
	{
		//cout << read << endl;
		//add read to sum
		sum += read;
		
		cout << read << "\t" << read * read << "\t" << sum << endl;
	}


	in.close();

	return 0;
}
