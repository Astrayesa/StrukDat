#include <iostream>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"
using namespace std;

int main(){
	string pesanan;
	int tbl;
	MyQueue order;
	MyStack piring;
	string meja[5][4]={{"0","0","0","0"},{"0","0","0","0"},{"0","0","0","0"},{"0","0","0","0"},{"0","0","0","0"}};
	piring.push("P1");piring.push("P2");piring.push("P3");piring.push("P4");piring.push("P5");
	char menu;
	
	while (menu!=3){
		cout<<"Daftar Pesanan : \n\n";order.tampil();cout<<"\n\n";piring.tampil();cout<<"\n\n";
		for(int i=0; i<5; i++){
			cout<<"Meja "<<i+1<<" : ";
			for(int j=0; j<4; j++){
				if(meja[i][j]!="0")
					cout<<meja[i][j]<<',';
			}
			cout<<endl;
		}
		cout<<"\n\nOpsi : \n(1)Baru (2)Siap (3)Bersihkan Meja (4)Tutup"<<endl<<">>> ";
		cin>>menu;
		switch(menu){
			case '1':
				cout<<"\nMasukan pesanan: ";
				cin.ignore();
				getline(cin,pesanan);
				order.enqueue(pesanan);	
				break;
			case '2': 
				if(order.kosong()){
					cout<<"\n<< Tidak ada pesanan! >>\n"<<endl;
					system("pause");
				}
				else{
					if(piring.kosong()){
						cout<<"\n<< Piring habis! Cuci dlu gan >>\n\n";
						system("pause");
						break;
					}
					cout<<"\n<< Pesanan siap : "<<order.Head()<<" >>\n\n";
					cout<<"Nomor Meja : ";cin>>tbl;
					if(meja[tbl-1][3]!="0"){
						cout<<"<< Meja "<<tbl<<" Penuh! >>";
						system("pause");
						break;
					}
					for(int i=0; i<4; i++){
						if(meja[tbl-1][i]=="0"){
							meja[tbl-1][i]=piring.Head();
							order.dequeue();
							piring.pop();
							system("pause");
							break;
						}
					}
				}
				break;
			case '3':
				cout<<"\nPiring pada meja : ";cin>>tbl;
				if(meja[tbl-1][0]=="0"){
					cout<<"\n<< Meja Sudah Bersih >>\n\n";
					system("pause");
					break;
				}
				else
				{
					cout<<"\n<< Meja " << tbl << " telah dibersihkan >>\n\n";
					system("pause");
					for(int i=0; i<4; i++){
							if(meja[tbl-1][i]!="0"){
								piring.push(meja[tbl-1][i]);
								meja[tbl-1][i]="0";
							}
						}
					break;
				}
			case '4':
				cout<<"\n<< Terimakasih >>\n"<<endl;
				return 0;
			default:
				cout<<"Pilihan salah!"<<endl;
				break;
		}
		system("cls");
	}
	return 0;
}
