//Matthew O'Brien
//Homework 5 
//August 12 2014

#include <iostream>
#include "homework5.h"
using namespace std;


//This is my list cpp file that contains all of the functions from the class. 


//The function to add a node using the int name variable.
node*  list::add(int name)
{
	node * temp = new node;
	temp -> name = name;
	temp -> next = head;
	head = temp;
	return temp;
}

//This is the display function to show the successors. It will display after the user doesn't want to do any more inputs.
void list::display()
{
	node * current = head;
	while(current)
	{
		if(!current -> nextlink)
			cout<<"\nNode "<<current->name<<" has no succesors.";
		else
			cout<<"\nNode "<<current->name<<" successors are: ";
			link * temp = current -> nextlink;
			while(temp)
			{
				cout<<temp->nextnode->name<<" ";
				temp = temp -> nextlink;
			}
		current = current -> next;
		
	}

}

//The constructor for the nodes
list::list()
{
	head = NULL;
}


//The deconstructor for the nodes.
list::~list()
{
	node * temp;
	while(head)
	{
		temp = head -> next;
		delete head;
		head = temp;
	}
}



//The check function to see if the node already exists.
node*  list::check(int name)
{

	if(!head)
		return head;

	node * current = head;

	while(current)
	{
		if(current -> name == name)
		{
			cout<<current->name<<" is pre-existing."<<endl;
			return current;
		}
		current = current -> next;
	}
	return NULL;
}


//Program will create a link between nodes using the link struct, if there is no link already in place.
link* list::make_link(linkptr first, nodeptr second)
{
	if(!first)
	{
		linkptr temp = new link;
		temp -> nextnode = second;
		temp -> nextlink = NULL;
		return temp;
	}
	else
	{
		linkptr temp = new link;
		temp -> nextnode = second;
		temp -> nextlink = first;
		return temp;
	}
	
}
//This bool function will check to see if there is a connection of links between nodes. Returning true if there is no link, false if there is a link between them.
bool list::check_list(nodeptr first, nodeptr second)
{

	if(!first ->nextlink)
		return true;
	else
	{
		linkptr current = first -> nextlink;
		while(current)
		{
			if(current -> nextnode == second)
				return false;
			current = current -> nextlink;
		}
	}
	return true;
	
}

//This bubble function is used to call the other functions listed above in the correct order, as well as input the int names, and output if they exist already or not.
//I understand that this display is not the same as the one from the assignment but it was the only way I knew how to do it, and it works in the correct fashion.
//It will take in each number of the pair, one at a time, then output whether they exist or not, then ask the user if they want to put in more pairs.
//After the user decides that there are no more pairs needed, the successor display output is shown.
void list::bubble()
{

	int name1;
	int name2;
	node * first = NULL;
	node * second = NULL;
	linkptr link = NULL;

	cout<<"What is the first?"<<endl;
	cin>>name1;
	cout<<"What is the second?"<<endl;
	cin>>name2;

	if(!(first = check(name1)))
	{
		first = add(name1);
		cout<<name1<<" node is new!"<<endl;
	}
	if(!(second = check(name2)))
	{
		second = add(name2);
		cout<<name2<<" node is new!"<<endl;	
	}
	if(check_list(first, second))
	{
		link = make_link(first->nextlink, second);
		first -> nextlink = link;
	}
	
}	




























 
