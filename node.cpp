#include <iostream>
using namespace std;
class node
{
public:
    char data;		// Input Character
    unsigned int freq;	// Frequency of the Character
	node* left;
	node* right;
	node* parent;
    node()
    {
        data = 0;
        freq = 0;
	    left = NULL;
	    right = NULL;
	    parent = NULL;
    }
	node(char d, int f)
	{
	    data = d;
	    freq = f;
	    left = NULL;
	    right = NULL;
	    parent = NULL;
	}
	
	
};
