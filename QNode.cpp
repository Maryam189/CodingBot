#include<iostream>
using namespace std;
struct QNode {
public:
	char data;
	int freq;
	QNode* next;
	QNode* left;
	QNode* right;
public:
	QNode()
	{
		this->data = ' ';
		this->freq = 0;
		next = NULL;
		left = NULL;
		right = NULL;
	}
	QNode(char data, int freq) 
	{
		this->data = data;
		this->freq = freq;
		next = NULL;
		left = NULL;
		right = NULL;
	}

};
