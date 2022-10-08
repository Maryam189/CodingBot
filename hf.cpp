#include <iostream>
#include "node.cpp"
using namespace std;

int len(string str)
{
	int size;
	for(size = 0; str[size]!='\0'; size++){	}
	return size;
}

class hf
{
public:
    unsigned size;		// Current size of min heap
    unsigned capacity;	// capacity of min heap
    int* L;				// Length of Bits
    int* F; 			// Frequencies of corresponding Bits
    node* root;
//    node** arr;	// Array of minheap node pointers

// Functions
	void update_LF(int size)
	{
		L = new int[size];
		F = new int[size];
	}
	node* newNode(char ch, int f)
	{
		node* temp = new node;
		temp->data = ch;
		temp->freq = f;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	node* dummy(node* n1, node* n2, node* s)
	{
		root = s;
		if(n1->data > n2->data)
		{
			root->left = n1;
			root->right = n2;
		}
		else
		{
			root->right = n1;
			root->left = n2;
		}
		return root;
	}

	void print_In(node* n) 
	{ if (n == NULL)
			return;
		print_In(n->left); //print left subtree
		cout << n->data << " "; //print current node
		print_In(n->right); //print right subtree
	}
	int index = 0;
	
	char* CodesLength(string str, int fr, int idx)
	{
		L[idx] = len(str);
		F[idx] = fr;
	}
	void printCodes(node* root, string str)
	{
			if (!root)
			{
				return;
			}
		    if (root->data != '$')
		    {
		    	cout << root->data << ": " << str << "\n";
			}
		    printCodes(root->left, str + "0");
		    if(root->left == NULL && root->right == NULL)
		    {
		    	CodesLength(str, root->freq, index++);
			}		
		    printCodes(root->right, str + "1");
	}
};

