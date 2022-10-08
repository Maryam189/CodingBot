#include <iostream>
#include <fstream>
#include "hf.cpp"
#include "list.cpp"
#include "Queue.cpp"
using namespace std;

// Function to check whether the given Character is ASCII value or not
bool isASCII(int ch)
{
  	return((ch <= 127) && (ch >= 0));
}
// ------------------------ Array Sorting ------------------------
template <typename T>
void swap(T *x, T *y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}
void Sort_Array(int *arr1, char *arr2, int n)	 // here arr1 = exponent Array , arr2 = coefficient array
{ 
   bool swapped;
   int i, j;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr1[j] > arr1[j+1])		// If exponent is same, swap both exponent and coefficient
        {
           swap(&arr1[j], &arr1[j+1]);	
           swap(&arr2[j], &arr2[j+1]);
           swapped = true;
        }
     }
// Applying condition for Best Case of Time Complexity
     if (swapped == false)
        break;
   }
}

int remove_dup(char* str, int size)
{
	int i, j, k;
	for (i = 0; i < size; i++) 
    {
    		j = i+1;
	       while(j < size)
		   {
			         if (str[j] == str[i])
					 {
						 	k = j;
						 	while (k < size)
						 	{
						 		str[k] = str[k + 1];
						 		k++;
							}
				            size--;
			         }
					 else
					 {
					 		j++;
					 }
	            
	       }
    }
   return size;
}

void print(char* str, int size)
{
	int i = 0;
	for(i=0; i<size; i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
}
int Calculate_freq(char* str, char key)
{
	int count = 0;
	int size = len(str);
    for(int i = 0; i<size; i++) 
	{
	    if(str[i] == key)
	    	count++;
    }
    return count;
}

void task1(char* ch1, char* ch2, int* fre, int size, int freq_size)
{
// Sorting the array
	Sort_Array(fre, ch2, freq_size);
	list l1;
	for(int i=0; i<freq_size; i++)
	{
		l1.add_e(ch2[i], fre[i]);
	}
// ----------------------------------------------------------------1st time -----------------------
	list_node* v1 = l1.del_s();		// first min element
	list_node* v2 = l1.del_s();		// second min element
	int sum = v1->freq + v2->freq;
	l1.add_s('$', sum);
// Now we have to make tree from these three variables v1, v2, and Sum
	hf h1;
	node* hf_n1 = h1.newNode(v1->data, v1->freq);
	node* hf_n2 = h1.newNode(v2->data, v2->freq);
	node* hf_sum = h1.newNode('$', sum);
	hf_sum = h1.dummy(hf_n1, hf_n2, hf_sum);

	int i=0;
	list_node* k = new list_node;
	k = l1.top();
	while( k->next != NULL )
	{
			l1.del_s();				// first min element
			v2 = l1.del_s();		// second min element
			sum = sum + v2->freq;
			l1.add_s('$', sum);
// Now we have to make tree from these three variables sum, v2
			hf_n2 = h1.newNode(v2->data, v2->freq);
			node* temp = new node;
			temp = hf_sum;
			hf_sum = h1.newNode('$', sum);
			hf_sum = h1.dummy(temp, hf_n2, hf_sum);	// it will store the previous tree
			k = l1.top();
	}

	string ans;
	h1.update_LF(freq_size);
	h1.printCodes(hf_sum , ans);
	
	double ABR = 0;	
	double UnCompressed = 0;
	
	for(int i=0; i<freq_size; i++)
	{
		UnCompressed = UnCompressed + h1.F[i] *8;	// Before Compression Bits
		ABR = ABR + h1.F[i] * h1.L[i];				// After Compression Bits
	}
	cout << "\n--> Compression Ratio is  " << UnCompressed/ABR << "\n"; 
}

void task2(char* ch2, int* fre, int fre_size)
{
	int x = 0;
	int sum = 0;
	Queue q;
	QNode* v1 = new QNode;
	QNode* v2 = new QNode;
	QNode* hf_sum = new QNode;
	
	for(int i=0; i<fre_size; i++)
	{
		q.enqueue(ch2[i], fre[i]);
	}
	int loop = q.getLength();
	int flag = 0;
	while(loop != 1)
	{
				v1 = q.extract_min();	v2 = q.extract_min();	// Two minimum Nodes
				sum = v1->freq + v2->freq;  
				hf_sum = q.newNode('$', sum, v1, v2);
				q.enqueue(hf_sum->data, hf_sum->freq, hf_sum->left, hf_sum->right);
		loop--;
	}

	string ans;
	q.update_LF(fre_size);
	q.printCodes(hf_sum , ans);
	double ABR = 0;
	double UnCompressed = 0;
	for(int i=0; i<fre_size; i++)
	{	
		UnCompressed = UnCompressed + q.F[i] *8;	// Bits without Compression
		ABR = ABR + q.F[i] * q.L[i];				// Bits After Compression
	}
	cout << "\n--> Compression Ratio is  " << UnCompressed/ABR << "\n"; 
}

int ReadMe(string &arr)
{
	string filename;
	cout << "\nEnter FileName:  ";
	cin >> filename;
// Opening file in Read Mode
	ifstream in_file(filename);
	char rough;
	int count = 0;
	int size;
	if (!in_file) 
	{
		cout << "\n\t\tERROR! Unable to Open File!\n\n";
		return 0;
	}
	else    
    {
    	// just to find the length
    		while (! in_file.eof( ))  
			{
				rough = in_file.get();
				count++;
			}
			in_file.close();
			size = count - 2;
			
	}
	
			count = 0;
			in_file.open(filename);
			int i = 0;
			while (! in_file.eof( ))  
			{
				count++;
				in_file.get(rough);
				if(count != size+1 && count != size+2 )
				{
					if( !(isASCII(rough)) ) 
					{
						cout << "\n********* The file has Non-ASCII character *********\n\n";
						return 0;
					}		
				}
				arr = arr + rough;
				i++;
			}
			in_file.close();
			return 1;
}

int main()
{
	string str;
	cout << "\n________________________________________________________________________________________________________________________\n\n";
	cout << "\t\t\t******************  DATA COMPRESSION  ******************\n";
	cout << "\n________________________________________________________________________________________________________________________\n";

	string arr1;
	int Validity_Check = ReadMe(arr1);
	if( !(Validity_Check) ) 
		return 0;		
	int size = len(arr1) - 2;
// Finding frequency and Sorting the String according to frequencies

	char ch1[size]; char ch2[size];
	for(int i=0; i<size; i++)
		ch1[i] = ch2[i] = arr1[i];

	int freq_size = remove_dup(ch2, size);
	int fre[freq_size];
	for (int i = 0; i < freq_size; i++)
	{
		fre[i] = Calculate_freq(ch1, ch2[i]);	// it will find the frequency of each element of s2 from s1
	}
	
	cout << "****************  Enter your Choice of TASK  ****************\n";
	int choice;
	do
	{
		cout << "\n[1] TASK 1\n[2] TASK 2\n[0] Quit\n";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "\n________________Compression through HuffMan Tree________________\n\n";
				task1(ch1, ch2, fre, size, freq_size);
				break;
			case 2:
				cout << "\n________________Compression through Optimal HuffMan Tree _______________\n\n";
				task2(ch2, fre, freq_size);
				break;
			case 0:
					cout << "\n________________________________________________________________________________________________________________________\n\n";
					cout << "\t\t\t******************  THANK YOU  ******************\n";
					cout << "\n________________________________________________________________________________________________________________________\n\n\n\n";
				break;
		}
	}
	while(choice != 0);
	return 0;
}
