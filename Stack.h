#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

struct Note{
	string val;
	Note *next;
};
class MyStack{
	private:
		Note *head=NULL;
	public:
		bool kosong(){
			if(head==NULL)
				return true;
			return false;
		}
		string Head(){
			return head->val;
		}
		void push(string a){
			Note *baru=new Note;
			baru->val=a;
			baru->next=NULL;
			if(kosong()){
				head=baru;
			}
			else{
				baru->next=head;
				head=baru;
			}
		}
		string pop(){
			string a=head->val;
			Note *tmp=head->next;
			delete head;
			head=tmp;
			return a;
		}
		void tampil(){
			if(kosong()){
				cout<<"<< Piring Kosong >>";
			}
			else{
				cout<<"^\n|\n";
				Note *bantu=head;
				while(bantu!=NULL){
					cout<<bantu->val<<endl;
					bantu=bantu->next;
				}
			}
		}
};

#endif
