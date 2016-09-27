//Matthew O'brien
//Homework 5
//August 12 2014



#include "homework5.h"


//My main function that will call the functions from the other cpp file.
//The professor said that I was allowed to code in C++ because my next class will be 163, and it is all over pointers, linear linked lists, and nodes.
//I was using this assignment as a warm up.
int main()
{

	list my_list;
	char response;

	do
	{	
		my_list.bubble();	
		cout<<"Do you want to add more to the list?"<<endl;
		cin>>response;
	}while(response == 'y');
	
	my_list.display();
	cout<<endl;
}


// I used a linear linked list of sorts to keep track of all the nodes, even those that aren't linked by the links.
//The professor called it a "finger", but I just referred to it as a "nodeptr" in my struct of a node. 
//This way every single node that was created would also be linked. Then within the check function, it would see if that node already existed
//If it did, then no connection would need to be made to the over all list.
