// Matthew O'Brien Homework 2
// July 5th, 2014

#include <iostream>
using namespace std;

//Struct used in test case 5 and 6
struct int_array
{
	int test1[5];
};
//Prototype functions
int value_int(int x);
int ref_int(int & x);
void ptr_int(int *x);
void array_int(int x[]);
void str_func(int_array x);
void str_ref(int_array & x);


int main()
{
	int x = 8;
	//The beginning integer that will be passed for test case 1 and 2.
	cout<<"The actual integer value is :"<<x<<endl;
	int y = value_int(x);

	//Test case 1 for value passing.
	cout<<"Test Case 1 in main."<<endl;
	cout<<"After the function call, the beginning value is: "<<x<<endl;
	cout<<"After the function call, the changed value is: "<<y<<endl;
	if(x == 8)
		cout<<"The initial value is still 8. It worked"<<endl;	
	else
		cout<<"ERROR"<<endl;

	//Test case 2 for reference passing.
	int u = ref_int(x);
	cout<<"Test Case 2 in main."<<endl;
	cout<<"After the function call, the beginning value changed to: "<<x<<endl;
	cout<<"After the function call, the changed value is: "<<u<<endl;
	if(u == 9)
		cout<<"The initial value was changed to 9. It worked"<<endl;
	else
		cout<<"ERROR"<<endl;
	
	//Test case 3 for pointers.
	cout<<"TEST CASE 3."<<endl;
	int t = 8;
	int *ptr;
	ptr = &t;
	cout<<"Before the function call the value is "<<*ptr<<endl;
	ptr_int(ptr);
	cout<<"After the function call the value is :"<<*ptr<<endl;
	if(t == 9)	
		cout<<"The initial value was changed to 9. It worked"<<endl;
	else
		cout<<"ERROR"<<endl;

	//Test case 4 for an array of integers.
	cout<<"TEST CASE 4."<<endl;
	int h [5] = { 1, 2, 3, 4, 5 };
	cout<<"The array before the call is: "<<endl;
	for(int i = 0; i< 5; i++)
	{
		cout<<h[i]<<" ";
	}
	cout<<endl;
	array_int(h);
	cout<<"The array after the call is: "<<endl;
	for(int i = 0; i < 5; i++)
	{	
		cout<<h[i]<<" ";
	}
	cout<<endl;
	if(h[0] == 10)
		cout<<"The array was passed correctly"<<endl;
	else
		cout<<"ERROR!"<<endl;

	
	//Test case 5 for a structure of integers.
	cout<<"TEST CASE 5."<<endl;
	int_array num;
	for(int i = 0; i < 5; i++)
	{	
		num.test1[i] = i;
	}	
	cout<<"My structure before the call is: "<<endl;
	for(int i = 0; i < 5; i++)
	{
		cout<<num.test1[i]<<" ";
	}
	cout<<endl;
	str_func(num);
	cout<<"My structure after the call is: "<<endl;
	for(int i = 0; i < 5; i++)
	{
		cout<<num.test1[i]<<" ";
	}
	cout<<endl;
	if(num.test1[0] == 0)
		cout<<"The struct was passed correctly."<<endl;
	else	
		cout<<"ERROR"<<endl;
	

	//Test case 6 for structs by reference.
	//Re-using the struct from case 5.
	cout<<"TEST CASE 6"<<endl;
	cout<<"Struct before the call.";
	cout<<endl;
	for(int i = 0; i < 5; i++)
	{
		cout<<num.test1[i]<<" ";
	}
	cout<<endl;
	str_ref(num);
	cout<<"Struct after the call"<<endl;
	for(int i = 0; i < 5; i++)
	{
		cout<<num.test1[i]<<" ";
	}
	cout<<endl;

	if(num.test1[0] == 5)
		cout<<"The struct was passed correctly"<<endl;
	else
		cout<<"ERROR!:"<<endl;

}

//Function to pass by value int only.
int value_int(int x)
{
	int y = 0;
	cout<<"TEST CASE 1 in function."<<endl;
	cout<<"Within the function, the beginning value is: "<<x<<endl;
	y = x + 1;
	cout<<"Within the function, the changed value is: "<<y<<endl;
	return y;

}

//Function to pass by reference int only.
int ref_int(int & x)
{
	cout<<"TEST CASE 2 in function."<<endl;
	cout<<"Within the function, the beginning value is: "<<x<<endl;
	x = x + 1;
	cout<<"Within the function, the changed value is: "<<x<<endl;
	return x; 
}

//Function for passing a pointer for an int.
void ptr_int(int *x)
{
	cout<<"TEST CASE 3 in function."<<endl;
	cout<<"The original value in the function is : "<<*x<<endl;
	cout<<"The original address in function is: "<<x<<endl;
	*x = *x + 1;
	cout<<"The changed value in the function is: "<<*x<<endl;
	cout<<"The changed address in the function is: "<<x<<endl;

	
}
//Function for an array of integers.
void array_int(int x[])
{
	cout<<"Inside the function the original array is: "<<endl;
	for( int i = 0; i < 5; i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
	x[0] = 10;
	cout<<"Inside the function the changed array is: "<<endl;
	for(int i = 0; i < 5; i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;

}

//Function for a struct of integers

void str_func(int_array x)
{
	cout<<"The structure of arrays of integers inside the functin is: "<<endl;
	for(int i = 0; i < 5; i++)
	{
		cout<<x.test1[i]<<" ";
	}
	cout<<endl;
	x.test1[0] = 5;
	cout<<"The changed struct within the function is: "<<endl;
	for(int i = 0; i < 5; i++)
	{
		cout<<x.test1[i]<<" ";
	}
	cout<<endl;
}
//Function for a struct of integers by reference.
void str_ref(int_array & x)
{
	cout<<"The struct inside the function is: "<<endl;
	for(int i = 0; i < 5; i++)
	{
		cout<<x.test1[i]<<" ";
	}
	cout<<endl;
	x.test1[0] = 5;
	cout<<"The changed struct in function is: "<<endl;
	for(int i = 0; i < 5; i++)
	{
		cout<<x.test1[i]<<" ";
	}
	cout<<endl;
}


// The only library that was used was the iostream library for C++. It was used to be able to use the cin and cout function for the program. Though in this case, all the values were hard coded into the program
//So only the cout out was used. No other libraries were needed since this program is only testing the compiler to be sure all values are being passed correctly. 
