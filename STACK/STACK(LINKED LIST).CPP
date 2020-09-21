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

int nodepush(node*);
node* nodepop();
int nodedisplay();
node* newnode(int);
node* top=NULL;
node* tempptr=NULL;
node* t=NULL;
node *ptr;

int main(){
	system("cls");
	char input;
	do{
		system("cls");
		gotoxy(20,1);cout<<"STACK IMPLEMENATION USING LINKED LISTS\n\nNote: Max. size of the array is 5."<<endl;
		gotoxy(20,4);   cout<<" ============================";
		gotoxy(20,5);   cout<<setw(18)<<"MAIN MENU";
		gotoxy(20,6);   cout<<" ============================";
		gotoxy(20,8);   cout<<"      1.PUSH        ";
		gotoxy(20,9);   cout<<"      2.POP          ";
		gotoxy(20,10);  cout<<"      3.DISPLAY           ";
		gotoxy(20,11);  cout<<"      4.IS EMPTY           ";
		gotoxy(20,12);  cout<<"      5.CLEAR           ";
		gotoxy(20,13);  cout<<"      6.EXIT";
		gotoxy(20,16);  cout<<" ============================";
		gotoxy(20,18);  cout<<"     Input Choice - ";
		input= getche() ;
		switch(input){
			case '1':
				int t;
				gotoxy(20,17);cout<<"ENTER ELEMENT TO BE PUSHED"<<endl;
				cin>>t;
				node *newptr=newnode(t);
				if(nodepush(newptr)){
					gotoxy(20,18);cout<<"ELEMENT PUSHED SUCCESSFULLY";
					gotoxy(20,19);cout<<"PRESS ANY KEY TO CONTINUE";
					getch();
				}
				break;
			case '2':
				if(top==NULL){
					gotoxy(20,17);cout<<"STACK EMPTY";
					gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
					getch();
					break;
				}
				node *tem=nodepop();
				gotoxy(20,17);cout<<"SUCCESSFULLY POPPED "<<tem->elem;
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
				if(top==NULL){
					gotoxy(20,17);cout<<"STACK EMPTY";
					gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
				}
				else{
					gotoxy(20,17);cout<<"STACK NOT EMPTY";
					gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
				}
				getch();
				break;
			case '5':
				Node* current = *top;  
				Node* next;  
				while (current != NULL) {  
    					next = current->next;  
    					free(current);  
    					current = next;  
				}  
				*top = NULL; 
				gotoxy(20,17);cout<<"STACK CLEARED";
				gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case '6':
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

int nodepush(node* nod){
	
	if (top==NULL)
		top=nod;
	else {
		t=top;
		top=nod;
		top->next=t;
	}
	return 1;
}

node* nodepop(){
	tempptr=top;
	top=top->next;
	return tempptr;
}
int nodedisplay(){
	if(top==NULL){
		return 1;
	}
	node* tempp=top;
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
