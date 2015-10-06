#include <iostream>
#include <string>

bool is_repeated(std::string my_name)
{
	// Optimization.
	if (my_name.length()>256)
		return true;

	bool ascii[256] = {false};
	for(int i=0; i<my_name.length(); ++i)
	{
		if (ascii[(int)my_name[i]]==false)
			ascii[(int)my_name[i]]=true;
		else
		{
			return true;
			break;
		}
	}
	return false;
}

int main()
{
	std::string key1="Abhijeet";
	std::string key2="Abcdefghijklmnopqrstuvwxyz";
	std::string key3="Abhibjeet";
	std::string key4="Aabhijeett";

	if (is_repeated(key2)==true)
		std::cout<<"repeats."<<std::endl;
	else
		std::cout<<"doesn't repeat."<<std::endl;
}
