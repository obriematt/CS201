


//Creating a Header file for the struct and class of this assignment.
//Matthew O'Brien
//August 12, 2014
//Homework 5



#include <iostream>
using namespace std;


//The node containing the information

typedef struct node * nodeptr;
typedef struct link * linkptr;


//My struct for the node that I will be creating throughout the program. Contains the int name, and the connection between nodes and links. As well as the bool variable, but it wasn't used.
struct node
{
	int name;
	nodeptr next;
	linkptr nextlink;
	bool visit;
};


//The struct for the link that will connect all of the nodes, even if the nodes aren't connected
struct link
{
	nodeptr nextnode;
	linkptr nextlink;
};


//list of the functions used for the graph and list.

class list
{
	public:
		list();
		~list();
		node*  add(int name);
		void display();
		node*  check(int name);
		void bubble();
		bool check_list(nodeptr first, nodeptr second);
		link* make_link(linkptr first, nodeptr second);
		
	private:
		node * head;
};
