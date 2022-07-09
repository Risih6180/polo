#include<stdio.h>
#include<conio.h>
#include<unistd.h>
#include<string.h>
#include<windows.h>
#define ENTER 13  
#define SPACE 32
#define BKSP 8
#define ESC 27
#define TAB 9

int gotoxy(int, int);


void display();
void graphic();
void prototype();
void login();

int compare(int *a1,int *a2);
void fill(int *a1,int *a2);

void menu();

void best_of_three();
void how_to_play();
void player_mode();

void computer_mode();
void show_score();

//for loading

void fordelay(int j)
{
	int i,k;
	for(i=0;i<j;i++)
	k=i;
}

void login()
{
	int j,i=0;
	char password[10];
	char username[10];
	char ch;
	//top border
	gotoxy(10,4);
	for(j=0;j<=96;j++)
	printf("%c",254);
	
	gotoxy(45,10);  
    printf("Enter the user name and password");
    gotoxy(45,12); 
	printf("Enter username:\n");
	
	//bottom border
	gotoxy(10,25);
	for(j=0;j<=96;j++)
	printf("%c",254);
	
	//left & right border
	for(j=0;j<20;j++)
	{
		gotoxy(10,5+j);
		printf("%c",219);
		
		gotoxy(105,5+j);
		printf("%c",219);
		
	}
	gotoxy(45,13); 
	gets(username);
	gotoxy(45,16);
	printf("Enter password:\n");
	gotoxy(45,17);
	if(strcmp(username,"aalu")==0)

	{
			while(1)
			{
			ch=getch();
			if(ch==ENTER)
			{
				password[i]='\0';
				break;
			}
			else if(ch==BKSP)
			{
				if(i>0)
				{
					i--;
					password[i]='\0';
					printf("\b \b");
				}
			}
		else if(ch==SPACE||ch==ESC||ch==TAB)
		{
			continue;
		}
		else
		{
			password[i]=ch;
			i++;
			printf("*");
		}
		}
		int num;
		num=strcmp(password,"1234");
		if(num==0)
		{
			gotoxy(45,18);
			printf("Welcome(*_*)");
			gotoxy(45,19);
			printf("Waiting.....");
			for(i=0;i<=12;i++)
			{
				fordelay(100000000);
				printf(".");
			}
			menu();
		}
		else
		{
			gotoxy(45,18);
			printf("Invalide password\n");
			gotoxy(45,19);
			printf(" ");
			system("pause");
			system("cls");
			login();
		}
	}
}


struct record
{
	int win,loss;
	char player_name[15];	
};

int i;

//main function
int main()
{
	for(i=0;i<3;i++)
	{
	login();
	getch();
	system("cls");
}
	return 0;
	menu();	
	printf("\n\n");
	return 0;
}



//For showing main menu
void menu()
{
	int j;
	char choice;
	system("cls");
    display();

	//top border
	gotoxy(10,4);
	for(j=0;j<=96;j++)
	printf("%c",254);
	
		//left & right border
	for(j=0;j<20;j++)
	{
		gotoxy(10,5+j);
		printf("%c",219);
		
		gotoxy(105,5+j);
		printf("%c",219);
	}

	//bottom border
	gotoxy(10,25);
	for(j=0;j<=96;j++)
	printf("%c",254);
		
	gotoxy(45,14);		
	printf("How to play/Help------------------[1]");
	gotoxy(45,15);		
	printf("Player vs computer----------------[2]");
	gotoxy(45,16);      
	printf("Best of three (player vs player)--[3]");
	gotoxy(45,17);		
	printf("Player vs player------------------[4]");
	gotoxy(45,18);		
	printf("Show score------------------------[5]");
	gotoxy(45,19);		
	printf("Exit------------------------------[6]");
	gotoxy(45,22);		
	printf("Enter your choice :) ");
	scanf("%c",&choice);
	
	switch(choice)
	{
		case '1':
			how_to_play();
			break;
		
		case '2':
			computer_mode();
			break;
			
		case '3':
		    best_of_three();
		    break;
		
		case '4':
			player_mode();
			break;
		
		case '5':
			show_score();
			break;
		
		case '6':
			exit(1);
			break;
		
		default:
			gotoxy(45,24);
			printf("Invalid choice!");
			break;
			
			getch();
	}	
	
	menu();
}


//Shows score
void show_score()
{
	FILE *fp;
	i=1;
	struct record det;
	system("cls");
	
	fp=fopen("score.txt","rb");
	
	if(fp==NULL)
	{
		display();		
		gotoxy(52,19);
		printf("No player found");
	}
	else
	{
		gotoxy(47,2);
		printf("Player name    Win       Loss\n");
		
		while(fread(&det,sizeof(det),1,fp)!=0)
		{
			gotoxy(47,3+i);
			printf("%-15s %-10d %-10d\n",det.player_name,det.win,det.loss);
			i++;
		}
	}
	fclose(fp);
	
	getch();
	menu();
}


//for moving the mouse pointer
int gotoxy(int x,int y)
{
	COORD c;
	c.X=x,
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);	
}


//shows the instruction to play game
void how_to_play()
{
	system("cls");

	gotoxy(48,1);	
	printf("----------------------");
	gotoxy(48,2);   
	printf("|    Aalu and Cross  |");
	gotoxy(48,3);   
	printf("----------------------");
	
	//prototype
	gotoxy(105,4);	
	printf("-------------");
	gotoxy(105,5);  
	printf("| prototype |");
	gotoxy(105,6);	
	printf("-------------");
	gotoxy(105,7);	
	printf("| 1 | 2 | 3 |");
	gotoxy(105,8);	
	printf("-------------");
	gotoxy(105,9);	
	printf("| 4 | 5 | 6 |");
	gotoxy(105,10);	
	printf("-------------");
	gotoxy(105,11);	
	printf("| 7 | 8 | 9 |");
	gotoxy(105,12);	
	printf("-------------");
	
	gotoxy(1,5);	printf(">> How to play :\n\n");
	
	sleep(1);		printf(">> You need to follow the prototype as shown in the figure\n");
	
	sleep(1);		printf(">> Choices need to be in between 1 and 9.\n");
	
	sleep(1);		printf(">> If choice is not according to the prototype, another chance will be\n");
					printf("   provided untill it satisfies the prototype.\n");	
	
	sleep(1);		printf(">> If a player chooses the number such that those numbers appear in a\n");
					printf("   continous row/ column/ diagonal, will be declared as winner.\n\n\n");
					
	sleep(1);		printf(">> Good ");
	sleep(1);		printf("Luck ");
	sleep(1);		printf(" :)\n");
	
	sleep(1);
	
	gotoxy(45,25);	
	printf("Enter any key to continue...");	
	
	getch();
}


//fills O and  X 
void fill(int *a1,int *a2)
{
	int k;
	system("cls");
	graphic();
	for(k=0;k<9;k++)
	{
		if  (a1[k]==1)	
		{
			gotoxy(55,15);	printf("X");
		}			
		else if(a1[k]==2) 
		{
			gotoxy(59,15);	printf("X");
		}
		else if(a1[k]==3)	
		{	
		    gotoxy(63,15);	printf("X");	
		}
		else if(a1[k]==4)	
		{
			gotoxy(55,17);	printf("X");
		}
		else if(a1[k]==5)
		{
			gotoxy(59,17);	printf("X");
		}
		else if(a1[k]==6)	
		{	
			gotoxy(63,17);	printf("X");	
		}
		else if(a1[k]==7)	
		{
		    gotoxy(55,19);	printf("X");
		}
		else if(a1[k]==8)	
		{
	    	gotoxy(59,19);	printf("X");
		}
		else if(a1[k]==9)	
		{
		gotoxy(63,19);	printf("X");
		}
		else 				
		{
	    	gotoxy(1,1);	printf(".");
		}		
	
		if     (a2[k]==1)	
		{
			gotoxy(55,15);	printf("O");
		}			
		else if(a2[k]==2)	
		{
			gotoxy(59,15);	printf("O");
		}
		else if(a2[k]==3)	
		{	
		    gotoxy(63,15);	printf("O");
		}
		else if(a2[k]==4)	
		{	
		    gotoxy(55,17);	printf("O");
		}
		else if(a2[k]==5)	
		{
			gotoxy(59,17);	printf("O");	
		}
		else if(a2[k]==6)	
		{
			gotoxy(63,17);	printf("O");	
		}
		else if(a2[k]==7)		
		{
			gotoxy(55,19);	printf("O");
		}
		else if(a2[k]==8)	
		{
			gotoxy(59,19);	printf("O");
		}
		else if(a2[k]==9)	
		{
	    	gotoxy(63,19);	printf("O");
		}
		else 				
		{
		gotoxy(1,1);	printf(".");
		}
	}
}


//game board
void graphic()
{
	gotoxy(53,14);	
	printf("-------------");
	gotoxy(53,15);	
	printf("|   |   |   |");
	gotoxy(53,16);	
	printf("-------------");
	gotoxy(53,17);
	printf("|   |   |   |");
	gotoxy(53,18);	
	printf("-------------");
	gotoxy(53,19);	
	printf("|   |   |   |");
	gotoxy(53,20);	
	printf("-------------");
}


//rule
void prototype()
{
	gotoxy(100,13);	
	printf("Follow this pattern");
	gotoxy(103,14);	
	printf("-------------");
	gotoxy(103,15);	
	printf("| 1 | 2 | 3 |");
	gotoxy(103,16);	
	printf("-------------");
	gotoxy(103,17);	
	printf("| 4 | 5 | 6 |");
	gotoxy(103,18);	
	printf("-------------");
	gotoxy(103,19);	
	printf("| 7 | 8 | 9 |");
	gotoxy(103,20);	
	printf("-------------");
}


void display()
{
	gotoxy(42,10);		
	printf("-----------------------------------------");	
	gotoxy(42,11);		
	printf("|             Aalu and Cross            |");
	gotoxy(42,12);		
	printf("-----------------------------------------");	
}


//player Vs computer mode : player name should be entered
void computer_mode()
{
	
	FILE *fp1,*fp2;
	
	struct record det;

	int l=0, w=0, j, c=0, p=0, cmp;
	int count=0, count1=0, count2=0;
	
	int player_choice, computer_choice;
	int player[9],computer[9];
	
	char name[15];
	
	system("cls");
    display();	

	// to store the player name to save their information(name) of the player
    
		gotoxy(26,15);
		printf("Enter your first name : ");
		scanf("%s",name);
		fflush(stdin);
		strupr(name);

	//top border
	gotoxy(10,4);
	for(j=0;j<=96;j++)
	printf("%c",254);
	
	//bottom border
	gotoxy(10,25);
	for(j=0;j<=96;j++)
	printf("%c",254);
	
		//left & right border
	for(j=0;j<20;j++)
	{
		gotoxy(10,5+j);
		printf("%c",219);
		
		gotoxy(105,5+j);
		printf("%c",219);
		
	}
	
     	
	for(i=0;i<9;i++)
	{
		player[i]=55;
		computer[i]=66;
	}

	i=1;
	do{
		
		if(i==10)
		break;
		
		fill(player,computer);
		prototype();
		gotoxy(40,10); 
		display();
		//determining whoose turn (computer or player)
		if(i%2==1)
		{
			loop:

			//player's turn
			gotoxy(5,14);			
			printf("Enter your choice : ");
			scanf("%d",&player_choice);
			fflush(stdin);
			
			if(player_choice>0 && player_choice<10)
			{
				//checking if currently given choice is already made by either of ther player(player and computer)
				for(j=0;j<9;j++)
				{
					if( player_choice==player[j] || player_choice==computer[j])
					{
						count1++;
					}
				}
			
				if(count1>0)
				{
					gotoxy(6,25);
					printf("Sorry this choice is already taken!\n");
					count1=0;
					getch();
					system("cls");
					fill(player,computer);
					prototype();
					
					goto loop;
				}
				else
				{
					player[p]=player_choice;
					p++;
				}
			}
	
			else
			{
					gotoxy(48,25);
					printf("Sorry! invalid choice.");
					getch();
					goto loop;
			}
		}
		else
		{
			//computer's turn
			loop1:
			
			computer_choice=(rand() % (9)) + 1;
			
			//checking if computer's choice is already taken previously
			for(j=0;j<9;j++)
			{
				if(computer_choice==computer[j] || computer_choice==player[j])
				{
					count2++;
				}
			}
			
			if(count2>0)
			{
				count2=0;
				goto loop1;
			}
			else
			{
				computer[c]=computer_choice;
				c++;
				gotoxy(5,14);
				printf("Computer choice : ");
			
				sleep(1);
					printf("%d",computer_choice);
			}
		}
	
		cmp=compare(player,computer);
		
		i++;
		if(i>9 && cmp==0)
		{
			fill(player,computer);
			gotoxy(55,24);	
			printf("Game Draw");
			l=0;
			w=0;
			getch();
		}
	}
	while(cmp==0);
	
	if(cmp==0)
	{
		fill(player,computer);
		gotoxy(55,24);	printf("Game Draw");
		getch();
	}
	if(cmp==1)
	{
		fill(player,computer);
		gotoxy(50,25);
		w++;
		printf("You won the match.");
	}
	
	if(cmp==2)
	{
		fill(player,computer);
		gotoxy(48,25);
		printf("Computer won the match.");
		l++;
	}
	
	fp1=fopen("score.txt","rb");
	
	if(fp1==NULL)
	{
		fclose(fp1);
		
		fp1=fopen("score.txt","wb");
		strcpy(det.player_name,name);
		det.loss=l;
		det.win=w;
		
		fwrite(&det,sizeof(det),1,fp1);
		fclose(fp1);
	}
	else
	{
		//check if the player name is already present in the file
		while(fread(&det,sizeof(det),1,fp1))		
		{
			if(strcmp(det.player_name,name)==0)
				count++;
		}
		fclose(fp1);
		if(count==0)
		{
			//player previously not present
			fp1=fopen("score.txt","ab");
			
			strcpy(det.player_name,name);
			
			if(w>0)
			{
				det.win=1;
				det.loss=0;
			}
			else if(l>0)
			{
				det.loss=1;
				det.win=0;
			}
			else
			{
				det.win=0;
				det.loss=0;
			}
			
			fwrite(&det,sizeof(det),1,fp1);
			
			fclose(fp1);
		}
		else
		{
			//player already present
			fp1=fopen("score.txt","rb");
			fp2=fopen("score_dup.txt","wb");
			
			while(fread(&det,sizeof(det),1,fp1)!=0)
			{
				if(strcmp(det.player_name,name)==0)
				{
					if(w>0)
					{
						det.win++;
					}
					else if(l>0)
					{
						det.loss++;
					}
					else
					{
						det.win+=0;
						det.loss+=0;
					}
					fwrite(&det,sizeof(det),1,fp2);
				}
				else
				{
					if(w>0)
					{
						det.win=1;
						det.loss=0;
					}
					else if(l>0)
					{
						det.loss=1;
						det.win=0;
					}
					else
					{
						det.win=0;
						det.loss=0;
					}
					fwrite(&det,sizeof(det),1,fp2);
				}
			}
			fclose(fp1);
			fclose(fp2);
			
			remove("score.txt");
			rename("score_dup.txt","score.txt");
		}
	}
	getch();
}


//player Vs player
void player_mode()

{
	int cmp=0;
	int j;
	int count1=0, count2=0;
	int p1=0,p2=0;
	int player1[9],player2[9];
	int player1_choice, player2_choice;
	int choice;
	system("cls");
	display();

	//top border
	gotoxy(10,4);
	for(j=0;j<=96;j++)
	printf("%c",254);
	
	//bottom border
	gotoxy(10,25);
	for(j=0;j<=96;j++)
	printf("%c",254);
	
	//left & right border
	for(j=0;j<20;j++)
	{
		gotoxy(10,5+j);
		printf("%c",219);
		
		gotoxy(105,5+j);
		printf("%c",219);
		
	}
	
	gotoxy(45,14);
    printf("Pick your choice X or O\n");
    gotoxy(45,15);
    printf("1.Play with X\n");
    gotoxy(45,16);
    printf("2.Play with O\n");
    gotoxy(45,17);
    printf("3.Exit\n");
    gotoxy(45,19);
    printf("Enter your choice>>");
    scanf("%d",&choice);
    
	switch(choice)
    {
    	case 1: 
	
	for(i=0;i<9;i++)
	{
		player1[i]=55;
		player2[i]=66;
	}
	
	i=1;
	do
	{
		if(i==10)
		break;	
		
		fill(player1,player2);
		prototype();
		display();
			
		//determining whoose turn
		if(i%2==1)
		{
			gotoxy(10,15);	
				printf("Player 1 turn : ");
				scanf("%d",&player1_choice);
				fflush(stdin);

			if(player1_choice>0 && player1_choice<10)
			{
				for(j=0;j<9;j++)
				{
					if(player1_choice==player1[j] || player1_choice==player2[j])
					count1++;
				}
				if(count1==0)
				{
					player1[p1]=player1_choice;
					p1++;
				}
				else
				{
					gotoxy(50,23);
					printf("This number is already taken!");
					count1=0;
					getch();
					
				}
			}
			else
			{
				gotoxy(50,23);
				printf("Invalid choice!");
				getch();
				
			}			
		}
		else
		{
			gotoxy(10,15);	
				printf("Player 2 turn : ");
				scanf("%d",&player2_choice);
				fflush(stdin);
			
			if(player2_choice>0 && player2_choice<10)
			{
				for(j=0;j<9;j++)
				{
					if(player2_choice==player1[j] || player2_choice==player2[j])
					count2++;
				}
				if(count2==0)
				{
					player2[p2]=player2_choice;
					p2++;
				}
				else
				{
					gotoxy(10,17);
					count2=0;
					printf("Sorry this number is already taken!");
					getch();
				}
			}
			else
			{
				gotoxy(50,23);
				printf("Invalid choice!");
				getch();
			}
		}
   
		cmp=compare(player1,player2);
		i++;
	
		if(i>9 && cmp==0)
		{
			fill(player1,player2);
			gotoxy(55,24);	
			printf("Game Draw");
		}	
    } 
	
	while(cmp==0);
	{     
		if(cmp==0)
		{
			fill(player1,player2);
			gotoxy(55,24);	
			printf("Game Draw");
		}	
    
	if(cmp==1)
	{
		fill(player1,player2);
		gotoxy(50,24);	
		printf("Player 1 won the match");
	}
	
	if(cmp==2)
	{
		fill(player1,player2);
		gotoxy(50,24);	
		printf("Player 2 won the match");
	}
	 getch();
  }
	break;
    	
  
  	case 2:
	for(i=0;i<9;i++)
	{
		player1[i]=66;
		player2[i]=55;
	}
	
	i=1;
	do
	{
		if(i==10)
		break;	
		
		fill(player2,player1);
		prototype();
		display();
			
		//determining whoose turn
		if(i%2==1)
		{
			gotoxy(10,15);	
				printf("Player 1 turn : ");
				scanf("%d",&player1_choice);
				fflush(stdin);

			if(player1_choice>0 && player1_choice<10)
			{
				for(j=0;j<9;j++)
				{
					if(player1_choice==player1[j] || player1_choice==player2[j])
					count1++;
				}
				if(count1==0)
				{
					player1[p1]=player1_choice;
					p1++;
				}
				else
				{
					gotoxy(50,23);
					printf("This number is already taken!");
					count1=0;
					getch();
					
				}
			}
			else
			{
				gotoxy(50,23);
				printf("Invalid choice!");
				getch();
				
			}			
		}
		else
		{
			gotoxy(10,15);	
				printf("Player 2 turn : ");
				scanf("%d",&player2_choice);
				fflush(stdin);
			
			if(player2_choice>0 && player2_choice<10)
			{
				for(j=0;j<9;j++)
				{
					if(player2_choice==player1[j] || player2_choice==player2[j])
					count2++;
				}
				if(count2==0)
				{
					player2[p2]=player2_choice;
					p2++;
				}
				else
				{
					gotoxy(10,17);
					count2=0;
					printf("Sorry this number is already taken!");
					getch();
				}
			}
			else
			{
				gotoxy(50,23);
				printf("Invalid choice!");
				getch();
			}
		}
   
		cmp=compare(player2,player1);
		i++;
	
		if(i>9 && cmp==0)
		{
			fill(player1,player2);
			gotoxy(55,24);	
			printf("Game Draw");
		}	
    } 
	
	while(cmp==0);
	{     
		if(cmp==0)
		{
			fill(player2,player1);
			gotoxy(55,24);	
			printf("Game Draw");
		}	
    
	if(cmp==1)
	{
		fill(player2,player1);
		gotoxy(50,24);	
		printf("Player 2 won the match");
	}
	
	if(cmp==2)
	{
		fill(player2,player1);
		gotoxy(50,24);	
		printf("Player 1 won the match");
	}
	getch();
  }
  
break;
    	
    	case 3:
    		printf("Exit\n");
    		menu();
    		break;
    	
    	default:
    		printf("Invalide Input!!");
    		break;
    		getch();
	}
}


void best_of_three()
{
	int cmp=0;
	int j;
	int n;
	char name[15];
	int count1=0, count2=0;
	int p1=0,p2=0;
	int player1[9],player2[9];
	int player1_point=0, player2_point=0;
	int player1_choice, player2_choice;
	display();
	system("cls");

for(n=0;n<3;n++)
{
	for(i=0;i<9;i++)
	{
		player1[i]=66;
		player2[i]=55;
	}

	i=1;
	do
    {
	
		if(i==10)
		break;
		loop:	
		fill(player1,player2);
		prototype();
		display();
		gotoxy(48,23);    printf("player1=%d\t player2=%d",player1_point,player2_point); 
		
		//determining whoose turn
		if(i%2==1)
		{
			gotoxy(10,15);	
				printf("Player 1 turn : ");
				scanf("%d",&player1_choice);
				fflush(stdin);

			if(player1_choice>0 && player1_choice<10)
			{
				for(j=0;j<9;j++)
				{
					if(player1_choice==player1[j] || player1_choice==player2[j])
						count1++;
				}
				if(count1==0)
				{
					player1[p1]=player1_choice;
					p1++;
				}
				else
				{
					gotoxy(45,25);
					printf("This number is already taken!");
					count1=0;
					getch();
					goto loop;
					
				}
			}
			else
			{
				gotoxy(10,17);
				printf("Invalid choice!");
				getch();
			    goto loop;
			}			
		}
		else
		{
			gotoxy(10,15);	
				printf("Player 2 turn : ");
				scanf("%d",&player2_choice);
				fflush(stdin);
			
			if(player2_choice>0 && player2_choice<10)
			{
				for(j=0;j<9;j++)
				{
					if(player2_choice==player1[j] || player2_choice==player2[j])
						count2++;
				}
				if(count2==0)
				{
					player2[p2]=player2_choice;
					p2++;
				}
				else
				{
					gotoxy(10,17);
					count2=0;
					printf("Sorry this number is already taken!");
					getch();
				    goto loop;
				}
			}
			else
			{
				gotoxy(101,17);
				printf("Invalid choice!");
				getch();
				goto loop;
			}
		}
		 
		cmp=compare(player1,player2);
		i++;
		if(i>9 && cmp==0)
			{
			fill(player1,player2);
			gotoxy(55,24);	
			printf("Game Draw");
			player1_point++;
			player2_point++;
		    gotoxy(48,23);    
			printf("player1=%d\t ",player1_point); 
			gotoxy(62,23); 
			printf("player2=%d",player2_point); 
		}	
    } 
	while(cmp==0);
   	 {     
		if(cmp==0)
		{
			fill(player1,player2);
			gotoxy(55,24);	
			printf("Game Draw");
			player1_point;
			player2_point;
			gotoxy(48,23);    
			printf("player1=%d\t ",player1_point);
			gotoxy(62,23);
			printf("player2=%d",player2_point);
		}	

	
	if(cmp==1)
	{
		fill(player1,player2);
		gotoxy(50,24);
		printf("Player1 won the match");
		player1_point++;
		gotoxy(48,23);   
	    printf("player1=%d\t ",player1_point); 
	    gotoxy(62,23);  
	    printf("player2=%d",player2_point);
		getch();
	}
	
	if(cmp==2)
	{
		fill(player1,player2);
		gotoxy(50,24);	
		printf("Player2 won the match");
		player2_point++;
		gotoxy(48,23);    
		printf("player1=%d\t ",player1_point);
		gotoxy(62,23);
		printf("player2=%d",player2_point);
		getch();   
 	}
 
  }
   
   system("cls");
   
   fill(player1,player2);
   }
   if (player1_point > player2_point)
	{
	gotoxy(48,23);
    printf("Player 1 win the game by %d point",player1_point);
    }
    else if (player1_point < player2_point)
	{
	    gotoxy(48,23); 
		printf("Player 2 win the game by %d point",player2_point);
    }
    else
    {
    	gotoxy(48,23); 
		printf("Game draw by %d and %d points ",player1_point, player2_point);
	}
	getch();
  }
  

//checks if the either of the player has won the game or not
int compare(int *a1,int *a2)
{
	int a,b,c;
	int x,y,z;
	int win;

	for(x=0;x<10;x++)
	{
		a=a1[x];
		for(y=0;y<10;y++)
		{
			b=a1[y];
			for(z=0;z<10;z++)
			{
		    	c=a1[z];
			    	if(a!=b && a!=c && b!=c)
			   		{
					if(a==1 || a==2 || a==3)
					{
					if(b==1 || b==2 || b==3)
						{
							if(c==1 || c==2 || c==3)
							{
								win=1;
								return win;
							}
						}
					}

					if(a==4 || a==5 || a==6)
					{
					if(b==4 || b==5 || b==6)
						{
						if(c==4 || c==5 || c==6)
						{
							win=1;
							return win;
							}
						}
					}

					if(a==7 || a==8 || a==9)
					{
					if(b==7 || b==8 || b==9)
						{
						if(c==7 || c==8 || c==9)
							{
							win=1;
							return win;
							}
						}
					}

					if(a==1 || a==4 || a==7)
					{
					if(b==1 || b==4 || b==7)
					{
						if(c==1 || c==4 || c==7)
						{
							win=1;
							return win;
							}
						}
					}

					if(a==2 || a==5 || a==8)
					{
					if(b==2 || b==5 || b==8)
					{
						if(c==2 || c==5 || c==8)
						{
							win=1;
							return win;
							}
						}
					}

					if(a==3 || a==6 || a==9)
					{
					if(b==3 || b==6 || b==9)
					{
						if(c==3 || c==6 || c==9)
						{
							win=1;
							return win;
							}
						}
					}

					if(a==1 || a==5 || a==9)
					{
					if(b==1 || b==5 || b==9)
					{
				    	if(c==1 || c==5 || c==9)
							{
							win=1;
							return win;
							}
						}
					}

					if(a==3 || a==5 || a==7)
					{
					if(b==3 || b==5 || b==7)
					{
						if(c==3 || c==5 || c==7)
						{
							win=1;
							return win;
							}
						}
					}
				}
		 	   else
				win=0;
			}
		}
	}

	for(x=0;x<10;x++)
	{
		a=a2[x];
		for(y=0;y<10;y++)
		{
			b=a2[y];
			for(z=0;z<10;z++)
			{
			    c=a2[z];
			    if(a!=b && a!=c && b!=c)
			    {
				if(a==1 || a==2 || a==3)
				{
					if(b==1 || b==2 || b==3)
					{
						if(c==1 || c==2 || c==3)
						{
							win=2;
							return win;
							}
						}
					}	

				if(a==4 || a==5 || a==6)
				{
				if(b==4 || b==5 || b==6)
				{
					if(c==4 || c==5 || c==6)
					{
						win=2;
						return win;
						}
					}
				}

				if(a==7 || a==8 || a==9)
				{
				if(b==7 || b==8 || b==9)
				{
					if(c==7 || c==8 || c==9)
					{
						win=2;
						return win;
						}
					}
				}

				if(a==1 || a==4 || a==7)
				{
				if(b==1 || b==4 || b==7)
				{
					if(c==1 || c==4 || c==7)
					{
						win=2;
						return win;
						}
					}
				}

				if(a==2 || a==5 || a==8)
				{
				if(b==2 || b==5 || b==8)
				{
					if(c==2 || c==5 || c==8)
						{
						win=2;
						return win;
						}
					}
				}

				if(a==3 || a==6 || a==9)
				{
				if(b==3 || b==6 || b==9)
					{
					if(c==3 || c==6 || c==9)
						{
						win=2;
						return win;
						}
					}
				}

				if(a==1 || a==5 || a==9)
				{
				if(b==1 || b==5 || b==9)
				{
					if(c==1 || c==5 || c==9)
					{
						win=2;
						return win;
						}
					}
				}

				if(a==3 || a==5 || a==7)
				{
				if(b==3 || b==5 || b==7)
				{
					if(c==3 || c==5 || c==7)
						{
						win=2;
						return win;
						}
					}
				}
			}
		    else
			win=0;
		}
	 }
	}
	return win;
}

