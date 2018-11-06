#include<iostream.h>
#include<dos.h>
#include<iomanip.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

//using namespace std;


typedef struct{
	int elem;
}stack;

int stackpush(stack*, stack, int);
stack stackpop(stack*);
int stackdisplay(stack*);
int toppos=-1;

int main(){
	system("cls");
	stack s[5];
	int len=5;
	char input;
	do{
		system("cls");
		gotoxy(20,1);cout<<"STACK IMPLEMENATION USING ARRAY OF STRUCTURES\n\nNote: Max. size of the array is 5."<<endl;
		gotoxy(20,4);   cout<<" ============================";
		gotoxy(20,5);   cout<<setw(18)<<"MAIN MENU";
		gotoxy(20,6);   cout<<" ============================";
		gotoxy(20,8);   cout<<"      1.PUSH        ";
		gotoxy(20,9);   cout<<"      2.POP          ";
		gotoxy(20,10);  cout<<"      3.DISPLAY           ";
		gotoxy(20,11);  cout<<"      4.EXIT";
		gotoxy(20,14);  cout<<" ============================";
		gotoxy(20,16);  cout<<"     Input Choice - ";
		input= getche() ;
		switch(input){
			case '1':
				stack temp;
				gotoxy(20,17);cout<<"ENTER ELEMENT TO BE PUSHED"<<endl;
				cin>>temp.elem;
				if(stackpush(s,temp,len)){
					gotoxy(20,18);cout<<"ELEMNT PUSHED SUCCESSFULLY";
					gotoxy(20,19);cout<<"PRESS ANY KEY TO CONTINUE";
					getch();
					break;
				}
				gotoxy(20,18);cout<<"STACK FULL";
				gotoxy(20,19);cout<<"TRY POPPING ELEMENT BEFORE PUSHING";
				gotoxy(20,20);cout<<"PRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case '2':
				if(toppos==-1){
					gotoxy(20,17);cout<<"STACK EMPTY";
					gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
					getch();
					break;
				}
				stack tem=stackpop(s);
				gotoxy(20,17);cout<<"SUCCESSFULLY POPPED "<<tem.elem;
				gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case '3':
				if(stackdisplay(s)){
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

int stackpush(stack* s, stack el, int len){
	if(toppos==len-1){
		return 0;
	}
	s[++toppos]=el;
	return 1;
}

stack stackpop(stack* s){
	return s[toppos--];
}
int stackdisplay(stack* s){
	if(toppos==-1){
		return 1;
	}
	for(int i=toppos;i>=0;--i){
		cout<<endl<<s[i].elem;
	}
	return 0;
}
