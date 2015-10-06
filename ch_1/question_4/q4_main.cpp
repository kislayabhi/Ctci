#include <iostream>
#include <string>

int main()
{
	std::string s="Mr Abhijeet John Doe       ";
	int true_length=20;

	int i=0, count=0;
	while(i<true_length)
	{
		if (s[i]==' ')
			{count++;}
		i++;
	}

	int back_index=true_length-1+2*count;
	i=true_length-1;
	
	while(i>=0)
	{
		if (s[i]!=' ')
		{
			s[back_index]=s[i];
			i--;
			back_index--;
		}
		else
		{
			s[back_index]='0';
			s[back_index-1]='2';
			s[back_index-2]='%';
			i--;
			back_index=back_index-3;
		}		
	}

	std::cout<<s<<std::endl;
}
