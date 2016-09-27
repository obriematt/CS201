//Matthew O'Brien Homework 1.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;




int main( int argc, char * argv[], char * envp[])
{
	//The variables that will be used for this program.
	char g_string[10000];
	float total;
	int index = 0;
	int index1 = 0;
	int j = 0;	
	
	//This if statement checks to make sure the amount of arguments are with 2 to 8. Errors if not.
	if(argc <= 2 || argc >= 8)
	{	
		printf("ERROR!\n");
	}
	else
	{
		//Sets the beginning of the string to zero.
		g_string[0] = (char)(0);
	
		//strcat will concatenate all of the arguments into one string. The for statement makes sure to go through all entered arguments, and stops.
		for( int i = 1; i < argc; i++)
		{
			strcat(g_string, argv[i]);
		}
		printf("The concatenated string is %s\n", g_string );
		//atof will convert the string into a floating point number. Removing the possible "e" and showing the correct corresponding number.
		total = atof(g_string);	
		printf("The floating point number is %e\n", total); 	

		//Total number of arguments
		printf( "%d command line args passed. \n", argc);

		//This while loop shows all of the arguments entered inlcuding the a.out
		while(j < argc)
		{
			printf("arg %d = \"%s\"\n", j, argv[j++]);
		}
	}

	//This portion will run even if the arguments aren't within the parameters.
	//It will show the environment variables.
	while(envp[index])
	{	
		printf("envp[%d] = \"%s\"\n", index, envp[index]);
		index = index + 1;
	}
	printf("Number of environment variables = %d\n", index);
	
	//This loop should find, compare, and redisplay the string that contains the PATH= variable.	
	while(envp[index1])
	{
		if(!strncmp(envp[index1], "PATH", 3))
		printf("Here is the PATH= variable again\nenvp[%d] = \"%s\"\n", index1, envp[index1]);
		index1 = index1 + 1;
	}
	
}


/*
	The stdio.h was included for the basic input and output functions used within this program. It was needed for the use of "printf"
	The stdlib.h and string.h  was included for the use of the atof function. Which converted the string to a floating point number.
	Those libraries also helped with use of the strncmp function to single out the PATH= variable.
*/


