#include <iostream>

int main()
{
	int m=3,n=3;
	int image[3][3]={1,0,3,4,5,0,7,8,9};
	// length of col is 3
	bool col[3]={false};
	bool row[3]={false};


	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
		{
			if(image[i][j]==0)
			{
				if(col[j]!=true);
					col[j]=true;
				if(row[i]!=true);
					row[i]=true;
			}
		}

	for(int i=0; i<m; i++)
	{
		if(row[i]==true)
		{
			for(int j=0; j<n; j++)
				image[i][j]=0;
		}
		if(col[i]==true)
		{
			for(int j=0; j<m; j++)	
				image[j][i]=0;
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			std::cout<<image[i][j]<<" ";
		}
		std::cout<<""<<std::endl;
	}
}