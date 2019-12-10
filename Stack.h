#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

struct Node
{
	string val;
	Node *next;
};

class MyStack
{
	private:
		Node *head=NULL;

	public:
		bool kosong()
		{
			if(head==NULL)
				return true;
			return false;
		}

		void push(string a)
		{
			Node *baru=new Node;
			baru->val=a;
			baru->next=NULL;
			if(kosong())
			{
				head=baru;
			}
			else
			{
				baru->next=head;
				head=baru;
			}
		}

		string pop()
		{
			if(kosong())
			{
				cout<<"Stack kosong!"<<endl;
				return '\0';
			}
			else
			{
				string a=head->val;
				Node *tmp=head->next;
				delete head;
				head=tmp;
				return a;
			}
		}

		void tampil()
		{
			if(kosong())
			{
				cout<<"stack kosong!";
			}
			else
			{
				Node *bantu=head;
				while(bantu!=NULL)
				{
					cout<<bantu->val<<endl;
					bantu=bantu->next;
				}
			}
		}
};

#endif
