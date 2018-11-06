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
queue queuedelete(queue*, int);
int queuedisplay(queue*, int);
int front=-1;
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
				if(front==-1 ){
					gotoxy(20,17);cout<<"QUEUE EMPTY";
					gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
					getch();
					break;
				}
				queue tem=queuedelete(s, len);
				
				gotoxy(20,17);cout<<"SUCCESSFULLY DELETED "<<tem.elem;
				gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case '3':
				if(queuedisplay(s, len)){
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
	if(rearpos==len-1 && front==0||front==rearpos+1){
		return 0;
	}
	else if (front==-1)
		front=0;
	else if(rearpos==len-1)
		rearpos=-1;
	s[++rearpos]=el;
	return 1;
}

queue queuedelete(queue* s, int len){
	queue temp=s[front];
	if(front==rearpos)
		front=rearpos=-1;
	else if(front==len-1)
		front=0;
	else	
		front++;
	return temp;
}
int queuedisplay(queue* s, int len){
	if(front==-1){
		return 1;
	}
	if(rearpos>=front){
		for(int i=front;i<=rearpos;i++){
			cout<<endl<<s[i].elem;
		}
	}
	else{
		for(int i=front;i<len;i++){
			cout<<endl<<s[i].elem;
		}
		for(int j=0;j<=rearpos;++j){
			cout<<endl<<s[j].elem;
		}	
	}
	return 0;
}
