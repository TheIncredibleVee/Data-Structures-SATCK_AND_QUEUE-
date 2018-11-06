#include<iostream.h>
#include<dos.h>
#include<iomanip.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

//using namespace std;


struct node{
	int elem;
	node* next;
};

int nodeinsert(node*);
node* nodedelete();
int nodedisplay();
node* newnode(int);
node* front=NULL;
node* rear=NULL;
node* tempptr=NULL;
node* t=NULL;
node *ptr;

int main(){
	system("cls");
	char input;
	do{
		system("cls");
		gotoxy(20,1);cout<<"OUEUE IMPLEMENATION USING LINKED LISTS\n\nNote: Max. size of the array is 5."<<endl;
		gotoxy(20,4);   cout<<" ============================";
		gotoxy(20,5);   cout<<setw(18)<<"MAIN MENU";
		gotoxy(20,6);   cout<<" ============================";
		gotoxy(20,8);   cout<<"      1.INSERT        ";
		gotoxy(20,9);   cout<<"      2.DELETE          ";
		gotoxy(20,10);  cout<<"      3.DISPLAY           ";
		gotoxy(20,11);  cout<<"      4.EXIT";
		gotoxy(20,14);  cout<<" ============================";
		gotoxy(20,16);  cout<<"     Input Choice - ";
		input= getche() ;
		switch(input){
			case '1':
				int t;
				gotoxy(20,17);cout<<"ENTER ELEMENT TO BE INSERTED"<<endl;
				cin>>t;
				node *newptr=newnode(t);
				if(nodeinsert(newptr)){
					gotoxy(20,18);cout<<"ELEMENT INSERTED SUCCESSFULLY";
					gotoxy(20,19);cout<<"PRESS ANY KEY TO CONTINUE";
					getch();
				}
				break;
			case '2':
				if(front==NULL){
					gotoxy(20,17);cout<<"QUEUE EMPTY";
					gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
					getch();
					break;
				}
				node *tem=nodedelete();
				gotoxy(20,17);cout<<"SUCCESSFULLY DELETED"<<tem->elem;
				delete tem;
				gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case '3':
				if(nodedisplay()){
					gotoxy(20,17);cout<<"STACK EMPTY ENTER ELEMENTS BEFORE VIEWING ";
					gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
					getch();
				}
				getch();
				break;
			case '4':
				exit(0);
				break;
			default:
				gotoxy(20,20);cout<<"INAVAILD CHOICE";
				gotoxy(20,21);cout<<"TRY AGAIN";
				break;
		}
	}while(input!='4');
	return 0;
}

int nodeinsert(node* nod){
	if (front==NULL){
		front=nod;
		rear=front;
	}
	else {
		t=front;
		rear->next=nod;
		rear=rear->next;
	}
	return 1;
}

node* nodedelete(){
	tempptr=front;
	if(rear==front)
		rear=NULL;
	front=front->next;
	return tempptr;
}
int nodedisplay(){
	if(front==NULL){
		return 1;
	}
	node* tempp=front;
	while(tempp!=NULL){
		cout<<endl<<tempp->elem;
		tempp=tempp->next;
	}
	return 0;
}
node* newnode(int x){
	ptr= new node;
	ptr->elem=x;
	ptr->next=NULL;
	return ptr;	
}
