#include<iostream.h>
#include<dos.h>
#include<iomanip.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

//using namespace std;


typedef struct{
	int elem;
}queue;

int queueinsert(queue*, queue, int);
queue queuedelete(queue*);
int queuedisplay(queue*);
int toppos=-1;
int rearpos=-1;

int main(){
	system("cls");
	queue s[5];
	int len=5;
	char input;
	do{
		system("cls");
		gotoxy(20,1);cout<<"QUEUE IMPLEMENATION USING ARRAY OF STRUCTURES\n\nNote: Max. size of the array is 5."<<endl;
		gotoxy(20,4);   cout<<" ============================";
		gotoxy(20,5);   cout<<setw(18)<<"MAIN MENU";
		gotoxy(20,6);   cout<<" ============================";
		gotoxy(20,8);   cout<<"      1.INSERT        ";
		gotoxy(20,9);   cout<<"      2.DELETE       ";
		gotoxy(20,10);  cout<<"      3.DISPLAY           ";
		gotoxy(20,11);  cout<<"      4.EXIT";
		gotoxy(20,14);  cout<<" ============================";
		gotoxy(20,16);  cout<<"     Input Choice - ";
		input= getche() ;
		switch(input){
			case '1':
				queue temp;
				gotoxy(20,17);cout<<"ENTER ELEMENT TO BE INSERTED"<<endl;
				cin>>temp.elem;
				if(queueinsert(s,temp,len)){
					gotoxy(20,18);cout<<"ELEMENT INSERTED SUCCESSFULLY";
					gotoxy(20,19);cout<<"PRESS ANY KEY TO CONTINUE";
					getch();
					break;
				}
				gotoxy(20,18);cout<<"QUEUE FULL";
				gotoxy(20,19);cout<<"TRY DELETING ELEMENT BEFORE INSERTING";
				gotoxy(20,20);cout<<"PRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case '2':
				if(toppos==-1  || rearpos<toppos){
					gotoxy(20,17);cout<<"QUEUE EMPTY";
					gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
					getch();
					break;
				}
				queue tem=queuedelete(s);
				if(rearpos<toppos)	
					rearpos=toppos=-1;
				gotoxy(20,17);cout<<"SUCCESSFULLY DELETED "<<tem.elem;
				gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case '3':
				if(queuedisplay(s)){
					gotoxy(20,17);cout<<"QUEUE EMPTY INSERT ELEMENTS BEFORE VIEWING ";
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

int queueinsert(queue* s, queue el, int len){ 
	if(rearpos==len-1){
		return 0;
	}
	if (toppos==-1){
		toppos=0;
	}
	s[++rearpos]=el;
	return 1;
}

queue queuedelete(queue* s){
	return s[toppos++];
}
int queuedisplay(queue* s){
	if(toppos==-1||toppos>rearpos){
		return 1;
	}
	for(int i=toppos;i<=rearpos;i++){
		cout<<endl<<s[i].elem;
	}
	return 0;
}
