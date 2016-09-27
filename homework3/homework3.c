//Matthew O'Brien Homework #3
//July 12th 2014

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
//The defined size of the 15,000 for the matrix. Change here to adjust the size of the matrix
#define SIZE 15000




//These are the prototypes of the functions used to pass the matrix throughout the program.
void display_matrix(int matrix[SIZE][SIZE]);
void sum_matrix(int matrix[SIZE][SIZE]);
void build_matrix(int matrix[SIZE][SIZE]);
void display2_matrix(int matrix[SIZE][SIZE]);
void sum2_matrix(int matrix[SIZE][SIZE]);
void total_matrix(int matrix[SIZE][SIZE]);
void copy_matrix(int matrix[SIZE][SIZE]);
void trans_matrix(int matrix[SIZE][SIZE]);


//Main function.
int main()
{	

	static int matrix[SIZE][SIZE];

	build_matrix(matrix);
	display_matrix(matrix);
	display2_matrix(matrix);
	sum_matrix(matrix);
	sum2_matrix(matrix);
	total_matrix(matrix);
	copy_matrix(matrix);
	trans_matrix(matrix);	
}

//The transposed matrix function. Original matrix is passed in ,transposed. And time is counted.
//Important to note the static in matrix.
void trans_matrix(int matrix[SIZE][SIZE])
{ 
	int x,y;
	clock_t start_t, end_t, total_t;
	float sec_t, totalsec;
	static int matrix2[SIZE][SIZE];

	start_t = clock();
	for(x = 0; x < SIZE; x++)
	{
		for(y = 0; y < SIZE; y++)
		{
			matrix2[x][y] = matrix[y][x];
		}
	}
	end_t = clock();
	total_t =(float)(end_t - start_t);
	sec_t =(float)(total_t) / CLOCKS_PER_SEC;
	

	printf("TRANSPOSE MATRIX\n");
	printf("Total cycles %ld \n", total_t);
	printf("Seconds %f \n", sec_t);
}


//Function to copy the original matrix exactly into another matrix2. Which will be another static int matrix to allow for the massive size.
void copy_matrix(int matrix[SIZE][SIZE])
{
	int x,y;
	clock_t start_t, end_t, total_t;
	float sec_t;
	static int matrix2[SIZE][SIZE];

	start_t = clock();
	for(x = 0; x < SIZE; x++)
	{
		for(y = 0; y < SIZE; y++)
		{
			matrix2[x][y] = matrix[x][y];
		}
	}
	end_t = clock();
	total_t =(float) (end_t - start_t);
	sec_t = (float)(total_t) / CLOCKS_PER_SEC;

	printf("COPY MATRIX\n");
	printf("Total cycles %ld \n", total_t);
	printf("Seconds %f \n", sec_t);
}

//This function will be adding up the matrix and accounting for the amount of time it takes using column first.
void total_matrix(int matrix[SIZE][SIZE])
{
	int x, y;
	float total = 0;
	clock_t start_t, end_t, total_t;
	float sec_t;	

	start_t = clock();	
	for(y = 0; y < SIZE; y++)
	{
		for(x = 0; x < SIZE; x++)
		{
			total = total + matrix[x][y];
		}
	}
	end_t = clock();
	total_t = (float)(end_t - start_t);
	sec_t = (float)(total_t) / CLOCKS_PER_SEC;

	
	printf("COLUMN FIRST \nTOTAL = %f \n", total);
	printf("Total number of cycles %ld \n", total_t);
	printf("Seconds %f \n", sec_t);
}


//Function to add up the matrix using ROW first. Again time will be measured using clock().
void sum2_matrix(int matrix[SIZE][SIZE])
{
	int x, y;
	float sum2 = 0;
	float sec_t;
	clock_t start_t, end_t, total_t;

	start_t = clock();
	for(x = 0; x < SIZE; x++)
	{
		for(y = 0; y < SIZE; y++)
		{
			sum2 = sum2 + matrix[x][y];
		}
	}
	end_t = clock();
	total_t = (float)(end_t - start_t);
	sec_t = (float)(total_t) / CLOCKS_PER_SEC;

	printf("ROW FIRST\nTotal =  %f \n", sum2);
	printf("Total number of cycles %ld \n", total_t);
	printf("Seconds %f \n", sec_t);
}
	

//Function to display the bottom right corner of the matrix at 10 by 10.
void display2_matrix(int matrix[SIZE][SIZE])
{
	int x, y;

	for(y = SIZE - 10; y < SIZE; y++)
	{
		for(x = SIZE - 10; x < SIZE; x++)
		{
			printf("%d \t", matrix[x][y]);
		}
		printf("\n");
	}
}




//This fucking will build the original matrix, which will be passed through the other functions.
void build_matrix(int matrix[SIZE][SIZE])
{
	int x,y;
	
	for(y = 0; y < SIZE; y++)
	{
		for(x = 0; x < SIZE; x++)
		{
			matrix[x][y] = x + y;
		}
	}
}

//Displays the top left corner of the matrix, but only 10 by 10.
void display_matrix(int matrix[SIZE][SIZE])
{

	int x, y;	

	for(y = 0; y < 10; y++)
	{
		for(x = 0; x < 10; x++)
		{
			printf("%d \t", matrix[x][y]);
		}
		printf("\n");
	}
	

}


//Summation of the matrix using rows first but with the indices reversed.
void sum_matrix(int matrix[SIZE][SIZE])
{
	
	int x,y;
	float sum1 = 0;
	clock_t start_t, end_t, total_t;
	float sec_t;

	start_t = clock();
	for(x = 0; x < SIZE; x++)
	{
		for(y = 0; y < SIZE; y++)
		{
			sum1 = sum1 + matrix[y][x];
		}
	}
	end_t = clock();
	total_t = (float)(end_t - start_t);
	sec_t = (float)(total_t) / CLOCKS_PER_SEC;

	printf("Row first but reversed indices\ntotal  = %f \n", sum1);
	printf("Total cycles %ld \n", total_t);
	printf("Seconds %f \n", sec_t);
}




//All of the sums are the same, which is what should have happened. This shows that all of the matrixes that were added together were the same, and the orginal matrix was passed
//was the same one for each function.

//The three addition functions gave Row/Reversed at 0.924s, Row 0.61s, and column 0.927s. The column and Row/reversed were very similar in timing, were as the row first was clearly the fastest function.
//I believe this is from the computer being able to read left to right more easily. The column may need could possibly take longer due to that being an abnormal way for the computer to operate.
//The key thing to note here is locality. When a function is called, an entire array is grabbed, which is done by a row at a time. Since the function call can grab the entire row, it makes sense
//for the row creation to be the fastest. The entire row will be made and values added, rather then having to call each row for each column at a time. With reverse indices the same issue comes into play
//The rows will be grabbed all at once, but more time needs to be taken into account for the creation of the columns.


//The straight copy function had a time of 0.796s. And the transpose is 1.19s. This one is a little more clear on why the two are different times. Copying the matrix is easy, putting the same value into an exact same spot
//of an identical matrix. Where as the transpose needs to put the value of one position of matrix A to the transposed position of matrix B. There is more work for the computer to do in this situation. 
//Locality plays a part in this as well. A straight copy function is easier with location to location, again grabbing an entire row, and copying it to another row easily. Where as the transpose needs to
//grab multiple rows at a time and transpose it to the appropriate spot. 

//There are 4 libraries used. The first 3 cover the print, and basic functions need for C programming. The last time library covers the clock() and clocks constant to convert to seconds. The two standard
//libraries that were used, pretty much cover the same things. I am not the most familiar with C so I didn't know which to use and which not to use. The string library was not needed for this assignment
//but on the off chance I decide to edit this code later, I'm keeping it in there.

//The 3 outputs I got using the time command in linux were different from the ones suggested in the homework. I emailed the professor and he said those three are fine for this as long as I explain what they mean. 
//The three times I got were 8.944s for real, 8.285 for user, and 0.608s for sys.
//The real was time elapsed in seconds and not in tcsh, or the unix shell. This is the amount of time that has passed since the program strated.
//The user was the total number of CPU seconds that the process spent in user mode. The user-mode is the virtual linux kernel-based OS, or the shell used to access the school linux computers.
//The sys was the total number of CPU-seconds that the process spent in kernel mode. This is a very short time spent using the system call to run the output of the program. Everything else happens in the user-mode.
//Which is why the user-mode time is so much greater than the sys time.


