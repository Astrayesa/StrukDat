#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

struct Node{
	string val;
	Node *next;
};
class MyQueue{
	private:
		Node *head=NULL;
		Node *tail=NULL;
	public:
		bool kosong(){
			if(head==NULL)
				return true;
			return false;
		}
		string Head(){
			return head->val;
		}
		void enqueue(string a){
			Node *baru=new Node;
			baru->val=a;
			baru->next=NULL;
			if(kosong()){
				head=baru;
				tail=baru;
			}
			else{
				tail->next=baru;
				tail=tail->next;
			}
		}
		string dequeue(){
			string a=head->val;
			Node *tmp=head->next;
			delete head;
			head=tmp;
			return a;
		}
		void tampil(){
			if(kosong()){
				cout<<"<< Pesanan Kosong >>";
			}
			else{
				Node *bantu=head;
				while(bantu!=NULL){
					cout<<bantu->val<<" <- ";
					bantu=bantu->next;
				}
			}
		}
};
#endif
