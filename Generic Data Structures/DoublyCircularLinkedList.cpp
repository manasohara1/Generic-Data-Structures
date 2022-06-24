//Doubly Circular Linked List
#include<iostream>
using namespace std;

template <class T>
struct node{
	T data;
	struct node *next;
	struct node *prev;
};

template <class T>
class DoublyCLL
{
	private :
			//Characteristics
			struct node<T> *Head;
			struct node<T> *Tail;
			
			int iCountNode;
	public :	
			//Behaviours
			DoublyCLL();
			
			void InsertFirst(T);
			void InsertLast(T);
			void InsertAtPos(T,int);
			
			void DeleteFirst();
			void DeleteLast();
			void DeleteAtPos(int);
			
			int Count();
			void Display();
			int  SearchFirstOccurance(T);
};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
	Head = NULL;
	Tail = NULL;
	iCountNode = 0;
}

template <class T>
void DoublyCLL<T>::InsertFirst(T Value)
{
	//creating a new node
	struct node<T> * newn = NULL;
	
	//memory allocation for newn
	newn = new node<T>;
	newn->data = Value;
	newn->next = NULL;
	newn->prev = NULL;
	
	//if there is no any node in LL
	if(iCountNode == 0) //if( (Head == NULL) && (Tail == NULL) ----another option
	{
		Head = newn;
		Tail = newn;
		newn->prev=Tail;
	}
	//if there is at least 1 node
	else
	{
		newn->next=Head;
		Head->prev=newn;
		Head=newn;
	}
	//Below 2 statements are used to maintain circular nature of Linked List
	//////////////////////////////////////////////////////////
	Head->prev = Tail;
	Tail->next = Head;
	//////////////////////////////////////////////////////////
	iCountNode++;
}

template <class T>
void DoublyCLL<T>::InsertLast(T Value)
{
	//creating a new node
	struct node<T> *newn = NULL;
	
	//memory allocation for newn
	newn = new node<T>;
	newn->data = Value;
	newn->next = NULL;
	newn->prev = NULL;
	
	//if there is no any node in LL
	if(iCountNode == 0) //if( (Head == NULL) && (Tail == NULL) ----another option
	{
		Head = newn;
		Tail = newn;
		newn->prev=Tail;
	}
	//if there is at least 1 node
	else 
	{
		Tail->next = newn;
		newn->prev = Tail;
		Tail=newn;
	}
	Head->prev = Tail;
	Tail->next = Head;
	
	iCountNode++;
}

template <class T>
void DoublyCLL<T>::InsertAtPos(T Value,int iPos)
{
	if( (iPos<1) || (iPos > iCountNode+1) )
	{
		cout<<"Invalid Position ";
		return;	
	}
	else if(iPos == 1)
	{
		InsertFirst(Value);
	}
	else if(iPos == iCountNode+1)
	{
		InsertLast(Value);
	}
	else
	{
		int i = 0;
		struct node<T> * temp = Head;
		//creating a new node
		struct node<T> * newn = NULL;
	
		//memory allocation for newn
		newn = new node<T>;
		newn->data = Value;
		newn->next = NULL;
		newn->prev = NULL;
		
		for(i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;	
		iCountNode++;
	}
	
}

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
	//if LL is empty
	if(iCountNode == 0)
	{
		cout<<"Linked List is already empty";
		return;
	}
	//if LL contains at least One Node
	else if(iCountNode == 1)
	{
		delete Head; //delete Tail --> he pan chalel
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		Head = Head->next;
		delete Tail->next; //delete Head->prev
	}
	Head->prev = Tail;
	Tail->next = Head;
	iCountNode--;
}

template <class T>
void DoublyCLL<T>::DeleteLast()
{
	//if LL is empty
	if(iCountNode == 0)
	{
		cout<<"Linked List is already empty";
		return;
	}
	//if LL contains at least One Node
	else if(iCountNode == 1)
	{
		delete Tail; //delete Head --> this will also work
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		Tail = Tail->prev;
		delete Tail->next; //delete Head->prev
	}
	Head->prev = Tail;
	Tail->next = Head;
	iCountNode--;
}

template <class T>
void DoublyCLL<T>::DeleteAtPos(int iPos)
{
	if( (iPos<1) || (iPos > iCountNode) )
	{
		cout<<"Invalid Position ";
		return;	
	}
	else if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iCountNode)
	{
		DeleteLast();
	}
	else
	{
		struct node<T> *temp = Head;
		int i = 0;
		for(i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		delete temp->next->prev;
		temp->next->prev=temp;
		iCountNode--;
	}
}

template <class T>
void DoublyCLL<T>::Display()
{
	int i = 0;
	struct node<T> * temp = Head;
	
	for(i=1;i<=iCountNode;i++)
	{
		cout<<"|"<<temp->data<<"|<-->";
		temp = temp->next; 
	}
	cout<<"\n";
}

template <class T>
int DoublyCLL<T>::Count()
{
	return iCountNode;
}
//////////////////////////////////////////////////////////
//
//Function Name:    int SearchFirstOccurance
//Description:      return first occurance of element from Doubly Circular Linked List
//Input:            T
//Output:           int
//Date:             12/06/2022
//Author:           Manas Ohara
//
//////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::SearchFirstOccurance(T Value)
{
	int iElementIndex=1;
	bool bRet = false;

	int i = 0;
	struct node<T> * temp = Head;
	
	for(i=1;i<=iCountNode;i++)
	{
		if(temp->data ==  Value)
		{
			bRet = true;
			break;
		}
		temp=temp->next;
		iElementIndex++; 
	}
	if(bRet == false)
	{
		cout<<Value<<" not found at any index in Doubly Circular LL\n";
		return -1;
	}
	else
	{
		//cout<<Value<<" found at "<<iElement<<" index of Singly Linear LL\n"; 
		return iElementIndex;
	}	
}
int main()
{
	DoublyCLL <int>obj;
	obj.InsertFirst(151);
	obj.InsertFirst(101);
	obj.InsertFirst(51);
	obj.InsertLast(201);
	obj.InsertAtPos(21,1);
	obj.Display();
	
	obj.InsertFirst(67);
	obj.InsertLast(78);
	obj.Display();
	obj.DeleteFirst();
	obj.DeleteLast();
	obj.Display();
	
	int iRet = obj.SearchFirstOccurance(51);
	cout<<" 51 found at "<<iRet<<" index of Doubly Circular LL\n"; 
	
	return 0;
}	
