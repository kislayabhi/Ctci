#include <iostream>

void reverse1(char * str){
	int length=sizeof(str)/sizeof(str[0]);
	char reversed[length];
	reversed[length]='\0';
	int last_index=length-1;

	for(int i=0; i<=last_index; ++i){
		reversed[i]=str[last_index-i];
	}
	std::cout<<reversed<<std::endl;
}

int main(){

	char a[]="troubles";
	char *ab="troubles"	;

	std::cout<<sizeof a<<std::endl; // will give 7.
	std::cout<<sizeof ab<<std::endl; // will give 8

	reverse1(a);
	
    // Below is the actual required code for reversing the string inplace
    // This is also a very good method to solve this question.
	int length=sizeof(a)/sizeof(a[0])-1;
	char store;
	for(int i=0; i<(length)/2; ++i){
		store=a[i];
		a[i]=a[length-1-i];
		a[length-1-i]=store;
	}
	std::cout<<a<<std::endl;
}
