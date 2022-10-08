class list_node
{
public:
	char data;
	int freq;
	list_node* next;
	list_node* pre;
// Default Constructor
	list_node()
	{
		data = ' ';
		freq = 0;
		next = NULL;
		pre = NULL;
	}
// Parameterize Constructor
	list_node(char c, int f, list_node* p = NULL, list_node* n = NULL)
	{
		data = c;
		freq = f;
		next = n;
		pre = p;
	}

};