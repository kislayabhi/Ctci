#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// I still have no idea how to insert numbers in the form of a string in c+
int main()
{
	string s="aabcccccaa", result;
	int i=1, count=1;
	char f_letter=s[0];
	result.push_back(f_letter);
	while(s[i]!='\0')
	{
		if(s[i]==f_letter)
		{
			count++;
		}
		else
		{
			result.push_back('9');
			f_letter=s[i];
			result.push_back(f_letter);
		}
		i++;
	}
	result.push_back('9');
	cout<<result<<endl;
}
