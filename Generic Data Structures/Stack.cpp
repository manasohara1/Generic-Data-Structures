#include<iostream>
///////////////////////////////////////
//Implementation of Generic Stack
//////////////////////////////////////
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class Stack
{
    public:
        struct node<T> *Head;
        int Count;

        Stack();
        void Push(T);        // InsertLast
        void Pop();            // DeleteFirst
        void Display();
        int CountNode();
        int  SearchFirstOccurance(T);
};

template<class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void Stack<T>::Push(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

   newn->next=Head;
   Head=newn;
   Count++;
}

template <class T>
void Stack<T>::Pop()       // Deletefirst
{
    T no;   // int no;

    if(Count == 0)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }

    no = Head -> data;
    struct node<T> *temp = Head;
    Head = Head->next;
    delete temp;

    Count--;
    cout<<"Removed element is : "<<no<<endl;
}

template<class T>
void Stack<T>::Display()
{
    cout<<"Elements from Stack are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
int Stack<T>::CountNode()
{
    return Count;
}

//////////////////////////////////////////////////////////
//
//Function Name:    int SearchFirstOccurance
//Description:      return first occurance of element from Stack
//Input:            T
//Output:           int
//Date:             15/06/2022
//Author:           Manas Ohara
//
//////////////////////////////////////////////////////////
template <class T>
int Stack<T>::SearchFirstOccurance(T Value)
{
	int iElementIndex=1;
	bool bRet = false;
//	iElementIndex=;
	while( Head != NULL)
	{
		if(Head->data ==  Value)
		{
			bRet = true;
			break;
		}
		Head=Head->next;
		iElementIndex++;
	}
	if(bRet == false)
	{
		cout<<Value<<" not found at any index in Stack\n";
		return -1;
	}
	else
	{
		return iElementIndex;
	}	
}

int main()
{
      Stack <char>obj1;
      
      obj1.Push('M');
      obj1.Push('K');
      obj1.Push('C');
      obj1.Push('M');
      obj1.Push('S');
      
      obj1.Pop();
      obj1.Pop();
      
      obj1.Display();
      
      obj1.Push('Z');
      obj1.Pop();
      
      int iRet = obj1.SearchFirstOccurance('K');
      cout<<" K found at "<<iRet<<" index of Stack\n"; 
      
      return 0;
}
