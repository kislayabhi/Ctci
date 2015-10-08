#include <iostream>

// For some reason I feel that I am not doing it correct
//void rotate_matrix(int n, int image[][4])
void rotate_matrix(int n, int** image)
{
	int i, j, l, swap, swap2;

	int jj=0;
	while(jj<n/2)
	{

		for(int k=jj; k<n-1-jj; k++)
		{
			
			// If you know that you have to perform a set of loops known number of times
			// then there is no need to have a separate loop for that. Simply writing them
			// down is also cool.
			i=jj;
			j=k;
			swap = image[i][j];
			image[i][j]=image[j][n-i-1];
			image[j][n-i-1]=image[n-i-1][n-j-1];
			image[n-i-1][n-j-1]=image[n-j-1][i];
			image[n-j-1][i]=swap;
		}

		jj++;
	}
}

int main()
{
	int n = 5;


	//int image[4][4];
	
	// If we want to make a function rotate matrix which works without providing 
	// it the value of n beforehand, we have to initialize the matrix in the
	// dynamic way.
	int **image;
	image = new int*[n];
	for(int i=0; i<n; i++)
		image[i] = new int[n];

	// Let's fill the matrix with some elements.
	for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				image[i][j] = i+2*j;
				std::cout<<image[i][j]<<" ";
			}
			std::cout<<""<<std::endl;
		}
	std::cout<<"\n"<<std::endl;
	
	rotate_matrix(n, image);

	std::cout<<"\n"<<std::endl;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			std::cout<<image[i][j]<<" ";
		}
		std::cout<<""<<std::endl;
	}
}
// My algo rotates the first layer first, then the second layer and then ... so
// on until it reaches the center of the matrix. I think I need something better
// than this.