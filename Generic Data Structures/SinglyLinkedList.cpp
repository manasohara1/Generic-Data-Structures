#include<iostream>

using namespace std;
template<class T>
struct node
{
	T data ;
	struct node *next;
	
};

template<class T>
class SinglyLL
{
	public:
		struct node<T> *Head;
    		int Count;
	public :	
		SinglyLL();
		void Display();
		int  CountNode();
    		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		int  SearchFirstOccurance(T);
};
template<class T>
SinglyLL<T>::SinglyLL()
{
	Head=NULL;
	Count=0;
}

template<class T>
void SinglyLL<T>::Display()
{
	cout<<"Element of linkedlist are : "<<endl;
	struct node<T>*temp=Head;
	while(temp!=0)
	{
		cout<<"|"<<temp->data<<"|->";
		temp=temp->next;
	}
	cout<<endl;
}

template<class T>
int SinglyLL<T>::CountNode()
{
	return Count;
}

template<class T>
void SinglyLL<T>::InsertFirst(T iNo)
{
	struct node<T>*newn=NULL;
	newn=new node<T>;
	
	newn->data=iNo;
	newn->next=NULL;
	
	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		newn->next=Head;
		Head=newn;
	}
	Count++;
}
template<class T>
void SinglyLL<T>::InsertLast(T iNo)
{
	struct node<T>*newn=NULL;
	newn=new node<T>;
	
	newn->data=iNo;
	newn->next=NULL;
	
	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		struct node<T> *temp=Head;
		
		while(temp->next!=0)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
	Count++;
}

template<class T>
void SinglyLL<T>::InsertAtPos(T iNo,int iPos)
{
	if((iPos<0)||(iPos>Count+1))
	{
		return ;
	}
	
	if(iPos==1)
	{
		InsertFirst(iNo);
	}
	else if(iPos==Count+1)
	{
		InsertLast(iNo);
	}
	else
	{
		struct node<T>*newn=NULL;
		newn=new node<T>;

		newn->data=iNo;
		newn->next=NULL;
		struct node<T>*temp=Head;
		
		while(temp->next->next!=0)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
		Count++;
	}

}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
	
	if(Head==NULL)
	{
		return ;
	}
	else
	{
		struct node<T>*temp=Head;
		Head=Head->next;
		delete temp;
	}
	Count--;
}
template<class T>
void SinglyLL<T>::DeleteLast()
{
	if(Head==NULL)
	{
		return;
	}
	else
	{
		struct node<T> *temp=Head;
		struct node<T> *temp2;
		
		while(temp->next!=0)
		{
			temp=temp->next;
		}
		temp2=temp->next;
		delete temp2;
		temp->next=NULL;
	}
	Count--;
}
template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
	if((iPos<0)||(iPos>Count))
	{
		return ;
	}
	
	if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==Count)
	{
		DeleteLast();
	}
	else
	{
		struct node<T> *temp=Head;
		struct node<T> *temp2;
		while(temp->next->next!=0)
		{
			temp=temp->next;
		}
		temp2=temp->next;
		delete temp2;
		temp->next=NULL;
		Count--;
	}
	

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
int SinglyLL<T>::SearchFirstOccurance(T Value)
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
	SinglyLL <int>obj1;

	obj1.InsertFirst(101);
	obj1.InsertFirst(51);
	obj1.InsertFirst(21);
	obj1.InsertFirst(11);
	
	obj1.Display();
	
	obj1.InsertLast(555);
	obj1.InsertAtPos(111,3);
	obj1.Display();
	
	obj1.DeleteAtPos(3);
	obj1.Display();
	
	obj1.DeleteFirst();
	obj1.DeleteLast();
	obj1.Display();
	
	int iRet = obj1.SearchFirstOccurance(51);
	cout<<" 51 found at "<<iRet<<" index of Singly Linear LL\n"; 
	
	return 0;
}
