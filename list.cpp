#include <iostream>
#include <cmath>
#include <iomanip>
#include "list_node.cpp"
using namespace std;
class list
{

public:

// Default Constructor
	list()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
// Parameterize Constructor
	list(list_node* h, list_node* t, int s)
	{
		head = h;
		tail = t;
		size = s;
	}
	list_node* top()
	{
		return head;
	}

void add_s(char c, int f)
{
    if(head == NULL)
    {
        list_node* temp = new list_node;
        temp->data = c;
        temp->freq = f;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        list_node* temp = new list_node;
        temp->data = c;
        temp->freq = f;
        temp->next = head;
        head = temp;
    }
}

// --------------------------- Adding at End -----------------------
void add_e(char c, int f)
{
    if(head == NULL)
    {
        list_node* temp = new list_node;
        temp->data = c;
        temp->freq = f;
        temp->pre = NULL;
        temp->next = NULL;
        head = temp;
        tail = temp;
        size++;
    }
    else
    {
        list_node* temp = new list_node;
        temp->data = c;
        temp->freq = f;
        temp->next = NULL;
        temp->pre = tail;
        tail->next = temp;
        tail = temp;
        size++;
    }
}

// ------------------------- Deleting from Start ----------------------------
list_node* del_s()
{
	list_node* store;
		if (head != NULL)
		{
			list_node* temp;
			store = head;
			temp = head->next;
			head = temp;

			temp = NULL;
			delete temp;
		}
		return store;
}
void display_list() {
		list_node* temp = head;
		if (temp != NULL)
		{
			cout << "The list has: ";
			while (temp != NULL)
			{
				
				cout << temp->data << " ";
				cout << temp->freq << " ";
				temp = temp->next;
			}
			cout << endl;
		}
		else
		{
			cout << "The list has no Elements.\n";
		}
	}


private:
	list_node* head;
	list_node* tail;
	int size;
};