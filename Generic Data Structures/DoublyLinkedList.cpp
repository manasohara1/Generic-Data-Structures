//DLL - Generic
#include<stdlib.h>
#include<iostream>
using namespace std;
template <class T>
struct node{
	T data;
	struct node *next;
	struct node *prev;
};

template <class T>
class DLL{
	private :
			struct node<T> *Head;
	public :
			DLL();
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
DLL<T>::DLL()
{
	Head = NULL;
}

template <class T>
void DLL<T>::InsertFirst(T Value)
{
	//create newn
	
	struct node<T> *newn= new node<T>;
	
	newn->data = Value;
	newn->prev = NULL;
	newn->next = NULL;
	
	
	//if LL is empty
	if( Head == NULL)
	{
		Head = newn;
	}
	else
	{
		newn->next = Head;
		Head->prev = newn;
		Head = newn;
	}
}

template <class T>
void DLL<T>::InsertLast(T Value)
{
	struct node<T> *newn= new node<T>;
	newn->data = Value;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(Head == NULL)
	{
		cout<<"LL is empty";
	}
	else
	{
		struct node<T> *temp = Head;
		while(temp->next!= NULL)
		{
			temp = temp->next;
		}
		newn->prev = temp->next;
		temp->next = newn;
	}
}

template <class T>
void DLL<T>::InsertAtPos(T Value,int iPos)
{
	if( (iPos <= 0) && (iPos >CountNode()+1) )
	{
		cout<<"Invalid position";
		return;
	}
	else if(iPos == 1)
	{
		InsertFirst(Value);
	}
	else if(iPos == CountNode()+1)
	{
		InsertLast(Value);
	}
	else
	{
		struct node<T> *newn= new node<T>;
		newn->data = Value;
		newn->next = NULL;
		newn->prev = NULL;
		
		struct node<T> *temp = Head;
		register int iCnt = 0;
		
		for(iCnt=1;iCnt<iPos-1;iCnt++)
		{
			temp = temp->next;
		}
		newn->prev = temp;
		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
	}
}

template <class T>
void DLL<T>::DeleteFirst()
{
	if(Head == NULL)
	{
		cout<<"LL is empty";
		return;
	}
	else
	{
		struct node<T> *delnode = Head;
		Head->next->prev= NULL;
		Head =  Head->next;
		delete delnode;
	}
}

template <class T>
void DLL<T>::DeleteLast()
{
	if(Head == NULL)
	{
		cout<<"LL is empty";
		return;
	}
	else if( Head->next == NULL)
	{
		delete Head;
		Head = NULL;
	}
	else
	{
		struct node<T> *temp = Head;
		
		while( temp->next->next != NULL )
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;	
	}
}
template <class T>
void DLL<T>::DeleteAtPos(int iPos)
{
	if(Head == NULL )
	{
		cout<<"LL is empty";
		return;
	}
	else if( ( iPos <= 0 ) && ( iPos > CountNode() ) )
	{
		cout<<"Invalid position";
		return;
	}
	else if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == CountNode())
	{
		DeleteLast();
	}
	else
	{
		struct node<T> *temp = Head;
		register int iCnt=0;
		for(iCnt = 1;iCnt< iPos-1;iCnt++)
		{
			temp = temp->next;
		}
		struct node<T> *delnode = temp->next;
		temp->next = delnode->next;
		delnode->next->prev = temp;
		delete delnode;
	}
}

template <class T>
void DLL<T>::Display()
{
	if(Head == NULL )
	{
		cout<<"LL is empty";
		return;
	}
	else
	{
		struct node<T> *temp = Head;
		while(temp != NULL)
		{
			cout<<"|"<<temp->data<<"|<->";
			temp = temp->next;
		}
	}
	cout<<"NULL"<<endl;	
}

template <class T>
int DLL<T>::CountNode()
{
	int iCnt = 0;
	
	if(Head == NULL )
	{
		cout<<"LL is empty";
		return iCnt;
	}
	else
	{
		struct node<T> *temp = Head;
		while(temp != NULL)
		{
			iCnt++;
			temp = temp->next;
		}
	}
	
	return iCnt;
}

//////////////////////////////////////////////////////////
//
//Function Name:    int SearchFirstOccurance
//Description:      return first occurance of element from Singly Linear Linked List
//Input:            T
//Output:           int
//Date:             22/05/2022
//Author:           Manas Ohara
//
//////////////////////////////////////////////////////////
template <class T>
int DLL<T>::SearchFirstOccurance(T Value)
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
		cout<<Value<<" not found at any index in Singly Linear LL\n";
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
	DLL <float>obj;
	obj.InsertFirst(151.67);
	obj.InsertFirst(121.78);
	obj.InsertFirst(111.89);
	obj.InsertFirst(101.78);
	obj.DeleteFirst();
	obj.InsertFirst(91.78);
	obj.InsertLast(89.8945);
	obj.InsertAtPos(59.8945,3);
	obj.Display();
	obj.DeleteFirst();
	obj.DeleteLast();
	obj.Display();
	obj.DeleteAtPos(2);
	
	obj.Display();
	cout<<"Total nodes in DLL are : "<<obj.CountNode();
	
	int iRet = obj.SearchFirstOccurance(121.78);
	cout<<" 121.78 found at "<<iRet<<" index of Doubly Linear LL\n";
	
	return 0;	
}
