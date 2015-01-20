#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int getInt(string s);
void debug(string s);

int main(int argc, char* argv[])
{
	string str;
	
	vector<int> stack;

	while(cin >> str)
	{
		if(str == "+")
		{
			if(stack.size() < 2)
			{
				cout << "Vector is too small" << endl;
				continue;
			}
			
			int a = stack.back();
			stack.pop_back();
			int b = stack.back();
			stack.pop_back();
			int sum = a + b; // order does not matter
			stack.push_back(sum);
		}
		else if(str == "-")
		{
			if(stack.size() < 2)
			{
				cout << "Vector is too small" << endl;
				continue;
			}
			
			int a = stack.back();
			stack.pop_back();
			int b = stack.back();
			stack.pop_back();
			int sum = b - a; //reverse because we are getting the elements backwards
			stack.push_back(sum);
		}
		else if(str == "*"){
			if(stack.size() < 2)
			{
				cout << "Vector is too small" << endl;
				continue;
			}
			
			int a = stack.back();
			stack.pop_back();
			int b = stack.back();
			stack.pop_back();
			int sum = a * b; //order does not matter
			stack.push_back(sum);
		}
		else if(str == "/")
		{
			if(stack.size() < 2)
			{
				cout << "Vector is too small" << endl;
				continue;
			}
			
			int a = stack.back();
			stack.pop_back();
			int b = stack.back();
			stack.pop_back();
			int sum = b / a; //reverse because we are getting the elements backwards
			stack.push_back(sum);
		}
		else if(str == ".")
		{
			//add all contents, output sum, and clear
			int sum = 0;
			
			while(stack.size() > 0)
			{
				sum += stack.back();
				stack.pop_back();
			}
			
			cout << "The sum is: " << sum << endl;
		}
		else
		{
			//must be a number
			stack.push_back(getInt(str));
		}
		
		//print out contents of vector
		debug("==");
		debug("Contents of vector: ");
		vector<int> temp(stack);
		while(temp.size() > 0)
		{
			//cout << temp.back() << endl;
			temp.pop_back();
		}
		debug("==");
	}
	return 0;
}

int getInt(string s)
{
	char *end;
	int result;

	result = strtol(s.c_str(), &end, 10);

	return result;
}

void debug(string s)
{
	//cout << s << endl;
}
