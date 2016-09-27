//MAtthew O'Brien Homework #4
//July 31th 2014

//Libraries included for the program
#include <stdio.h>
#include <time.h>
#include <math.h>

//Prototype for the track cycles
void track_cycles(int unused);


//Main function 
int main()
{
	//Necessary variables 
	clock_t start_t, end_t, total_t;
	float sec_t;
	int magic = 10;
	int total = 0;
	int j = 2;
	int i = 0;

	//Expo FOR loop. Using the expos of 3 to 12. The later expos will show a greater time length,  but allow for me to see the difference in time for optimization levels and inlining.
	for(j; j < 11; j++)
	{
		total =  pow(5 , j);
		start_t = clock();
		//The function call loops
		for( i; i < total; i++)
		{
			track_cycles(magic);
		}
		end_t = clock();
		total_t = (float)(end_t - start_t);
		sec_t = (float)(total_t) / CLOCKS_PER_SEC;
		printf("The total number of calls is %d.\n", total);
		printf("The time taken is %f seconds.\n", sec_t);
	}

	return 0;

}


//Function for tracking the amount of cycles.
void track_cycles(int unused)
{
	int i;
	for(i = 0; i < 10000; i++)

	{
		unused += 1;
	}
}

