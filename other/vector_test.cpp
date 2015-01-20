#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
{
	vector<string> words;
	int bytes = 0;

	for(int i = 1; i < argc; i++)
	{
		words.push_back(argv[i]);
		//cout << "Putting in " << argv[i] << endl;
		
		bytes += strlen(argv[i]);
	}

	cout << "You entered " << words.size() << " words!" << endl;

	cout << "That was a total of " << bytes << " bytes" << endl;
	

	return 0;
}
