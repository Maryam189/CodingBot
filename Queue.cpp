#include<iostream>
#include "QNode.cpp"
using namespace std;

class Queue 
{
public:
    QNode* head; 
    int *L;		// Length of Bits
    int* F; 	// Frequencies of corresponding Bits
	int length;

Queue()
{
    head = NULL;
    length=0;
}
QNode* getFront()
{
	return head;
}
void update_LF(int size)
{
	L = new int[size];
	F = new int[size];
}
int getLength()
{
	return length;
}

void enqueue(char data, int freq, QNode* left = NULL, QNode* right = NULL)
{
	
	QNode *ptr;
	QNode *temp = new QNode;
	temp->data = data;
	temp->freq = freq;
	temp->next = NULL;
	temp->left = left;
	temp->right = right;
	
	if(head==NULL)
	{
		// this section runs if linked list is empty
		// we simply set head to temp
		head = temp;	
	}
	else if(temp->freq < head->freq)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		ptr = head;
		while(ptr->next!=NULL && ptr->next->freq < temp->freq)
		{
			ptr = ptr->next;
		}

// inserting temp between ptr and ptr->next
		temp->next = ptr->next;
		ptr->next = temp;
	}
	
	length++;
	
}

QNode* newNode(char ch, int f, QNode* left = NULL, QNode* right = NULL)
{
		QNode* temp = new QNode;
		temp->data = ch;
		temp->freq = f;
		temp->left = left;
		temp->right = right;
		return temp;
}
QNode* extract_min()
{  
	if (head == NULL)
    {
    	cout << "\n\tQueue is Empty\n";
    	return 0;
	}   
    QNode* temp = head;
    QNode* ex = new QNode;
    head = head->next;

	ex = temp;
	temp = NULL;
	delete temp;
	length--;
	return ex;

}

bool isEmpty()
{
	return (head == NULL);
}

void display()
{
   	if(isEmpty())
   	{
   		cout << "Empty\n";
	}
	else
	{
		QNode* temp;
		temp = head;
		while(temp != NULL)
		{
			cout << temp->data << " ";
			cout << temp->freq << " ";
			temp = temp->next;
		}
	}
	cout << endl;
}

int len(string str)
{
	int size;
	for(size = 0; str[size]!='\0'; size++){	}
	return size;
}

int i=0;

char* storeCodes(string str, int f, int idx)
{
	
	L[idx] = len(str);
	F[idx] = f;
}
void printCodes(QNode* root, string str)
{

	    if (!root)
	        return;
	    if (root->data != '$')
	    {
	    	cout << root->data << ": " << str << "\n";
		}	
	    printCodes(root->left, str + "0");
	    if(root->left == NULL && root->right == NULL)
	    {
	    	storeCodes(str, root->freq, i++);
		}		
	    printCodes(root->right, str + "1");
}
};
