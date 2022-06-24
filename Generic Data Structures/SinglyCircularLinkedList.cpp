//scll - generic
#include<iostream>
#include<stdlib.h>
using namespace std;

template <class T>
struct node{
	T data;
	struct node *next;
};

template <class T>
class SCLL
{
	private :
			struct node<T> *Head;
			struct node<T> *Tail;
	public :
			SCLL();
			//~SCLL();
			void InsertFirst(T);
			void InsertLast(T);
			void InsertAtPos(T,int);
			void DeleteFirst();
			void DeleteLast();
			void DeleteAtPos(int);
			void Display();
			int CountNode();
			int  SearchFirstOccurance(T);
};
template <class T>
SCLL<T>::SCLL()
{
	Head = NULL;
	Tail = NULL;
}

template <class T>
void SCLL<T>::InsertFirst(T Value)
{
	//create a new node<T>
	struct node<T> *newn = new node<T>;
	
	//assign the data to newn
	newn->data = Value;
	newn->next = NULL;
	
	//if LL is empty
	if( (Head == NULL) && (Tail == NULL) )
	{
		Head = newn;
		Tail = newn;	
	}
	
	//if LL contains at least one node
	else 
	{
		newn->next=Head;
		Head = newn;
	}
	
	//common statement 
	Tail->next = Head;
}

template <class T>
void SCLL<T>::InsertLast(T Value)
{
	//create a newn
	struct node<T> *newn = new node<T>;
	
	//assign data
	newn->data = Value;
	newn->next = NULL;
	
	//if LL is empty
	if( (Head == NULL) && (Tail == NULL) )
	{
		Head = newn;
		Tail = newn;	
	}
	//if LL contains at-least one node
	else
	{
		Tail->next=newn;
		newn->next=Head;
		Tail= newn;
	}
	
	//common statement
	Tail->next = Head;
}

template <class T>
void SCLL<T>::InsertAtPos(T Value,int iPos)
{
	struct node<T> *temp = Head;
	
	//if position is invalid
	if( ( iPos < 0 ) && ( iPos > CountNode()+1 ) )
	{
		cout<<"Position is invalid \n";
		return;
	}
	//if iPos==1
	if(iPos==1)
	{
		InsertFirst(Value);
	}
	else if( iPos == CountNode()+1 )
	{
		InsertLast(Value);
	}
	else
	{
		//craete a newn
		struct node<T> *newn = new node<T>;
		register int iCnt = 0;
		//assign the data
		newn->data = Value;
		newn->next = NULL;
		
		//travel LL till iPos-1
		for(iCnt=1;iCnt<iPos-1;iCnt++)
		{
			temp=temp->next;
		}
		//now temp at iPos-1
		newn->next= temp->next;
		temp->next = newn;
	}
}

template <class T>
void SCLL<T>::DeleteFirst()
{
	//if LL is empty
	if( (Head == NULL) && (Tail == NULL) )
	{
		cout<<"Linked list is already empty";
		return;
	}
	
	//if LL contains 1 node
	if ( Head == Tail )
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
	}
	//if LL contains more than one node
	else
	{
		Head = Head->next;
		delete Tail->next;
		Tail->next = Head;
	}
}

template <class T>
void SCLL<T>::DeleteLast()
{
	struct node<T> *temp = Head;
	
	//if LL is empty
	if( (Head == NULL) && (Tail == NULL) )
	{
		cout<<"Linked list is already empty";
		return;
	}
	
	//if LL contains 1 node
	if ( Head == Tail )
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
	}
	//if LL contains more than one node
	else
	{
		//travel till Tail
		register int iCnt = 0;
		while( temp->next != Tail )
		{
			temp = temp->next;
		}
		delete Tail;
		Tail =  temp;
		Tail->next = Head;
	}
}

template <class T>
void SCLL<T>::DeleteAtPos(int iPos)
{
	//if invalid iPos
	if( (iPos < 0) && (iPos > CountNode()) )
	{
		cout<<"Invalid position\n";
		return;
	}
	//if iPos ==1
	else if(iPos == 1)
	{
		DeleteFirst();
	}
	//if iPos==Last pos
	else if(iPos == CountNode() )
	{
		DeleteLast();
	}
	else
	{
		//travel till iPos-1
		struct node<T> *temp = Head;
		register int iCnt = 0;
		for(iCnt=1;iCnt<iPos-1;iCnt++)
		{
			temp=temp->next;
		}
		//now at pos-1
		struct node<T> *delnode = temp->next;
		temp->next = delnode->next;
		delnode->next = NULL;
		delete delnode;
	}
}

template <class T>
void SCLL<T>::Display()
{
	struct node<T> *temp = Head;
	
	if( ( Head == NULL) && (Tail == NULL) )
	{
		cout<<"Linked List is empty\n";
		return;
	}
	do{
		cout<<"|"<<temp->data<<"|->";
		temp=temp->next;		
	}while(temp != Tail->next);
	cout<<endl;
}

template <class T>
int SCLL<T>::CountNode()
{
	struct node<T> *temp = Head;
	int iCnt = 0;
	
	if( ( Head == NULL) && (Tail == NULL) )
	{
		cout<<"Linked List is empty\n";
		return -1;
	}
	do{
		//cout<<"|"<<temp->data<<"|->";
		iCnt++;
		temp=temp->next;		
	}while(temp != Tail->next);
	
	return iCnt;
}

//////////////////////////////////////////////////////////
//
//Function Name:    int SearchFirstOccurance
//Description:      return first occurance of element from Singly Circular LL
//Input:            T
//Output:           int
//Date:             27/05/2022
//Author:           Manas Ohara
//
//////////////////////////////////////////////////////////
template <class T>
int SCLL<T>::SearchFirstOccurance(T Value)
{
	int iElementIndex=1;
	struct node<T> *temp = Head;
	bool bRet = false;
	do{
		if(temp->data ==  Value)
		{
			bRet = true;
			break;
		}
		temp=temp->next;
		iElementIndex++;		
	}while(temp != Tail->next);
	
	if(bRet == false)
	{
		cout<<Value<<" not found at any index in Singly Circular LL\n";
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
	SCLL <int>obj1;
	obj1.InsertFirst(101);
	obj1.InsertFirst(51);
	obj1.InsertFirst(21);
	obj1.InsertFirst(11);
	obj1.InsertLast(151);
	obj1.InsertAtPos(91,4);
	obj1.InsertFirst(76);
	obj1.InsertLast(344);
	obj1.InsertAtPos(71,4);
	
	obj1.Display();
	obj1.DeleteAtPos(4);
	obj1.DeleteFirst();
	obj1.DeleteLast();
	obj1.Display();
	cout<<"Total nodes are : "<<obj1.CountNode();
	
	int iRet = obj1.SearchFirstOccurance(51);
	cout<<" 51 found at "<<iRet<<" index of Singly Circular LL\n"; 
	
	return 0;
}
