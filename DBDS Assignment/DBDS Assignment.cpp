// DBDS Assignment.cpp : Defines the entry point for the console application.
//
#include<stdio.h>
#include<conio.h>
#include<string>
#include<Windows.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAXSIZE 5
using namespace std;
void main();// Show the "Welcome page logo"
void choice(); // Choice to choose linked list or stack
void mainpage(); // show the linked list mainpage
void mainpage2();
void stack();
struct StudentData {
	char StudNm[256];
	char StudInt[256];
	char StudBr[256];
	int lvlNum;
}Stud;
struct Node {
	char StudentName[256];
	char StudentIntake[256];
	char StudentBranch[256];
	int StudentLvlNum;
	struct Node *Next;
}*NewNode = NULL, *HeadNode = NULL, *CurNode = NULL, *PrevNode = NULL;
char *ChPos = NULL;
int c = 0;
int i = 0, len = 80;

int GetData(void);
int NodeInsertion(void);
void NodeSorting(void);
void NodeDeletion(void);
void NodeDisplay(void);
int main3();
struct stacker
{
	int stk[MAXSIZE];
	int top;
}s;
struct stacker1
{
	int stk1[MAXSIZE];
	int top;
}s1;
struct stacker2
{
	int stk2[MAXSIZE];
	int top;
}s2;
struct stacker3
{
	int stk3[MAXSIZE];
	int top;
}s3;
struct stacker4
{
	int stk4[MAXSIZE];
	int top;
}s4;
void push();
int  pop();
void display();

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
void main()
{
	gotoxy(15, 5);
	printf("\t**************************************************\n");
	gotoxy(15, 6);
	printf("\t*     Welcome to The Main Page                   *\n");
	gotoxy(15, 7);
	printf("\t**************************************************\n");
	choice();
}
void choice()// To choose to choose option between linked list and stack
{
	int code;
	gotoxy(15, 7);
	printf("\n\t\t*1. Linked List                                  *");
	gotoxy(15, 8);
	printf("\n\t\t*2. Stack                                        *");
	gotoxy(15, 9);
	printf("\n\t\t*3. Exit                                         *");
	gotoxy(15, 11);
	printf("\t**************************************************\n");
	gotoxy(15, 12);
	printf("\n\t\tChoose one of the option below!\t");
	scanf("%d", &code);
	switch (code)
	{
	case 1:
		printf("\t\tYou have chosen linked list.\n");
		system("cls");
		mainpage();
		break;
	case 2:
		printf("\t\tYou have chosen stack.\n");
		system("cls");
		mainpage2();
		break;
	case 3:
		exit(0);
	default:
		printf("\t\tThat's not an answer! Press any key to exit.\n");
		getch();
		exit(0);
	}
	getch();
}


void mainpage() // linked list main menu
{
	printf("\t**************************************************\n");
	printf("\t*     Welcome to main menu of the Linked List    *\n");
	printf("\t**************************************************\n");
	main3();
}
void mainpage2() // stack main menu
{
	printf("\t**************************************************\n");
	printf("\t*     Welcome to main menu of the Stack          *\n");
	printf("\t**************************************************\n");
	stack();
}

int GetData(void) {
	int WhileSwitch = 1, isValid = 0;
	char Ch;
	printf("Add Record\n");

	while (WhileSwitch) {
		printf(" Name: ");
		gets_s(Stud.StudNm, sizeof(Stud.StudNm));
		printf(" Intake: ");
		gets_s(Stud.StudInt, sizeof(Stud.StudInt));
		printf(" Branch: ");
		gets_s(Stud.StudBr, sizeof(Stud.StudBr));
		printf(" Level [1-5]: ");
		scanf_s("%d", &Stud.lvlNum);
		while ((c = getchar()) != '\n' && c != EOF);
		printf("\n Add Another Record? [Y/n]>");
		scanf_s("%c", &Ch);
		while ((c = getchar()) != '\n' && c != EOF);
		if (Ch == 'Y' || Ch == 'y') {
			NodeInsertion();
			WhileSwitch = 1;
		}
		else if (Ch == 'N' || Ch == 'n') {
			NodeInsertion();
			WhileSwitch = 0;
			system("cls");
		}
		else {
			printf("Option not Available...Exiting...");
			getchar();
			NodeInsertion();
			WhileSwitch = 0;
			system("cls");
		}
	}
	return EXIT_SUCCESS;
}


int NodeInsertion(void) {
	NewNode = (struct Node *)malloc(sizeof(struct Node));
	strcpy_s(NewNode->StudentName, sizeof(NewNode->StudentName), Stud.StudNm);
	strcpy_s(NewNode->StudentIntake, sizeof(NewNode->StudentIntake), Stud.StudInt);
	strcpy_s(NewNode->StudentBranch, sizeof(NewNode->StudentBranch), Stud.StudBr);
	NewNode->StudentLvlNum = Stud.lvlNum;
	NewNode->Next = NULL;

	if (HeadNode == NULL) {
		HeadNode = NewNode;
		CurNode = NewNode;
	}

	else {
		NodeSorting();
	}
	return 0;
}


void NodeSorting(void) {
	struct Node *CmpNode;
	CmpNode = HeadNode;
	PrevNode = CmpNode;
	int sortFlag = 0, Counter = 0;

	while (sortFlag == 0) {
		if (CmpNode == HeadNode && CmpNode->Next == NULL) {
			if (NewNode->StudentLvlNum < CmpNode->StudentLvlNum) {
				NewNode->Next = HeadNode;
				CurNode = HeadNode;
				HeadNode = NewNode;
				sortFlag = 1;
			}
			else if (NewNode->StudentLvlNum > CmpNode->StudentLvlNum) {
				HeadNode->Next = NewNode;
				CurNode = NewNode;
				sortFlag = 1;
			}
			else if (NewNode->StudentLvlNum == CmpNode->StudentLvlNum) {
				if (strcmp(NewNode->StudentName, CmpNode->StudentName) < 0) {
					NewNode->Next = HeadNode;
					CurNode = HeadNode;
					HeadNode = NewNode;
					sortFlag = 1;
				}
				else {
					HeadNode->Next = NewNode;
					CurNode = NewNode;
					sortFlag = 1;
				}
			}
		}
		else {
			if (NewNode->StudentLvlNum < CmpNode->StudentLvlNum) {
				PrevNode->Next = NewNode;
				NewNode->Next = CmpNode;
				sortFlag = 1;
			}
			else if (NewNode->StudentLvlNum > CmpNode->StudentLvlNum || NewNode->StudentLvlNum == CmpNode->StudentLvlNum) {
				while (CmpNode->Next != NULL && NewNode->StudentLvlNum >= CmpNode->Next->StudentLvlNum && sortFlag != 1) {
					if (NewNode->StudentLvlNum > CmpNode->StudentLvlNum) {
						while (CmpNode->Next != NULL && NewNode->StudentLvlNum > CmpNode->Next->StudentLvlNum) {
							PrevNode = CmpNode;
							CmpNode = CmpNode->Next;
						}
						if (CmpNode->Next == NULL) {
							CmpNode->Next = NewNode;
							CurNode = NewNode;
							sortFlag = 1;
						}
						else {
							NewNode->Next = CmpNode->Next;
							CmpNode->Next = NewNode;
							sortFlag = 1;
						}
					}
					else if (strcmp(NewNode->StudentName, CmpNode->StudentName) == 0 && CmpNode->Next->StudentLvlNum == NewNode->StudentLvlNum) {
						while (CmpNode->Next != NULL && strcmp(NewNode->StudentName, CmpNode->Next->StudentName) == 0) {
							PrevNode = CmpNode;
							CmpNode = CmpNode->Next;
						}
						if (CmpNode->Next != NULL) {
							NewNode->Next = CmpNode->Next;
							CmpNode->Next = NewNode;
							sortFlag = 1;
						}
						else {
							CurNode->Next = NewNode;
							CurNode = NewNode;
							sortFlag = 1;
						}
					}
					else if (strcmp(NewNode->StudentName, CmpNode->StudentName) > 0 && CmpNode->Next->StudentLvlNum == NewNode->StudentLvlNum) {
						while (CmpNode->Next != NULL && strcmp(NewNode->StudentName, CmpNode->Next->StudentName) > 0) {
							PrevNode = CmpNode;
							CmpNode = CmpNode->Next;
						}
						if (CmpNode->Next != NULL) {
							NewNode->Next = CmpNode->Next;
							CmpNode->Next = NewNode;
							sortFlag = 1;
						}
						else {
							CurNode->Next = NewNode;
							CurNode = NewNode;
							sortFlag = 1;
						}
					}
					else if (strcmp(NewNode->StudentName, CmpNode->StudentName) < 0 && CmpNode->Next->StudentLvlNum == NewNode->StudentLvlNum) {
						if (CmpNode == HeadNode) {
							NewNode->Next = HeadNode;
							HeadNode = NewNode;
							sortFlag = 1;
						}
						else {
							PrevNode->Next = NewNode;
							NewNode->Next = CmpNode;
							sortFlag = 1;
						}
					}
					PrevNode = CmpNode;
					CmpNode = CmpNode->Next;
				}
			}
		}
		if (sortFlag == 0) {
			if (CmpNode->Next != NULL) {
				NewNode->Next = CmpNode->Next;
				CmpNode->Next == NewNode;
				sortFlag = 1;
			}
			else {
				CmpNode->Next = NewNode;
				CurNode = NewNode;
				sortFlag = 1;
			}
		}
	}
	return;
}

void NodeDisplay(void) {
	struct Node *DisplayNode;
	DisplayNode = HeadNode;
	for (i = 0; i < len; i++) {
		printf("=");
	}
	printf("List\n");
	for (i = 0; i < len; i++) {
		printf("=");
	}
	if (HeadNode == NULL) {
		printf("List Is Empty...[Press Any Key to Continue]");
		getchar();
		return;
	}
	while (DisplayNode != NULL) {
		printf("Name: ");
		puts(DisplayNode->StudentName);
		printf("Intake: ");
		puts(DisplayNode->StudentIntake);
		printf("Branch: ");
		puts(DisplayNode->StudentBranch);
		printf("Level Number: %d\n", DisplayNode->StudentLvlNum);
		for (i = 0; i < len; i++) {
			printf("=");
		}
		DisplayNode = DisplayNode->Next;
	}
	printf("Press any Key to continue...");
	getchar();
	system("cls");
	return;
}

void NodeDeletion() {
	struct Node *DelNode;
	int delFlag = 0;
	DelNode = HeadNode;
	if (HeadNode == NULL) {
		printf("\nList is Empty (Press Any Key to Continue...)");
		getchar();
		return;
	}
	char tmp_StudentIntake[256];
	printf("Student Intake: ");
	gets_s(tmp_StudentIntake, sizeof(tmp_StudentIntake));
	while (DelNode != NULL && delFlag != 1) {
		if (strcmp(DelNode->StudentIntake, tmp_StudentIntake) == 0) {
			if (DelNode->Next == NULL) {
				PrevNode->Next = NULL;
				CurNode = PrevNode;
				delFlag = 1;
			}
			else if (DelNode->Next == NULL && DelNode == HeadNode) {
				HeadNode = NULL;
				delFlag = 1;
			}
			else if (DelNode == HeadNode) {
				HeadNode = HeadNode->Next;
				delFlag = 1;
			}
			else {
				PrevNode->Next = DelNode->Next;
				delFlag = 1;
			}
		}
		else {
			PrevNode = DelNode;
			DelNode = DelNode->Next;
		}
	}
	if (delFlag == 0) {
		printf("\nStudent Not Found (Press Any Key to Continue...)");
		getchar();
	}
	else {
		printf("Student Record Deleted (Press Any Key to Continue...)");
		getchar();
	}
	return;
}

int main3(void) {
	int WhileFlag = 1, SwitchCmd = 1;
	while (WhileFlag) {
		system("cls");
		printf("Main Menu\n");
		printf(" 1-New Student Node\n 2-Display Student List\n 3-Remove a Student Node From The List\n 4-Quit The Program\n\nChoice (1 to 4): ");
		scanf_s("%d", &SwitchCmd);
		while ((c = getchar()) != '\n' && c != EOF);
		switch (SwitchCmd) {
		case 1:
			system("cls");
			GetData();
			break;
		case 2:
			system("cls");
			NodeDisplay();
			break;
		case 3:
			system("cls");
			NodeDeletion();
			break;
		case 4:
			WhileFlag = 0;
			break;
		default:
			break;
		}
	}
	return 0;
}


void stack()
{
	int choice;
	int option = 1;
	s.top = -1;
	while (option)
	{
		printf("*******************************************\n");
		printf("      1   Push              \n");
		printf("      2   Pop               \n");
		printf("      3   Display               \n");
		printf("      4   Exit           \n");
		printf("*******************************************\n");
		printf("Enter choice:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		}
	}
}


/* Add items to retailer*/
void push()
{
	int num;
	int num2;
	printf("Enter items into the retailer:\n");
	printf("Product ID\tBinID\n");
	scanf("%d", &num);
	scanf("%d", &num2);
	if (num2 == 1)
	{
		if (s.top == (MAXSIZE - 1))
		{
			printf("Stack is Full\n");
			return;
		}
		s.top = s.top + 1;
		s.stk[s.top] = num;
	}

	if (num2 == 2)
	{
		if (s1.top == (MAXSIZE - 1))
		{
		printf("Stack is Full\n");
		return;
		}
			s1.top = s1.top + 1;
			s1.stk1[s1.top] = num;
	}
	if (num2 == 3)
	{
		if (s2.top == (MAXSIZE - 1))
		{
			printf("Stack is Full\n");
			return;
		}
		s2.top = s2.top + 1;
		s2.stk2[s2.top] = num;
	}
	if (num2 == 4)
	{
		if (s3.top == (MAXSIZE - 1))
		{
			printf("Stack is Full\n");
			return;
		}
		s3.top = s3.top + 1;
		s3.stk3[s3.top] = num;
	}
	if (num2 == 5)
	{
		if (s4.top == (MAXSIZE - 1))
		{
			printf("Stack is Full\n");
			return;
		}
		s4.top = s4.top + 1;
		s4.stk4[s4.top] = num;
	}
	return;
}
/*  delete stack */
int pop()
{
	int num;
	if (s.top == -1)
	{
		printf("Stack is empty\n");
	}
	else if (s1.top == -1)
	{
		printf("Stack is empty\n");
	}
	else if (s2.top == -1)
	{
		printf("Stack is empty\n");
	}
	else if (s3.top == -1)
	{
		printf("Stack is empty\n");
	}
	else if (s4.top == -1)
	{
		printf("Stack is empty\n");
	}
	printf("Enter which bin you wish to pop\n");
	scanf("%d", &num);
	if (num == 1)
	{
		s.stk[s.top];
		printf("poped element is = %d\n", s.stk[s.top]);
		s.top = s.top - 1;
	}
	else if (num == 2)
	{
		s1.stk1[s1.top];
		printf("poped element is = %d\n", s1.stk1[s1.top]);
		s1.top = s1.top - 1;
	}
	else if (num == 3)
	{
		s2.stk2[s2.top];
		printf("poped element is = %d\n", s2.stk2[s2.top]);
		s2.top = s2.top - 1;
	}
	else if (num == 4)
	{
		s3.stk3[s3.top];
		printf("poped element is = %d\n", s3.stk3[s3.top]);
		s3.top = s3.top - 1;
	}
	else if (num == 5)
	{
		s4.stk4[s4.top];
		printf("poped element is = %d\n", s4.stk4[s4.top]);
		s4.top = s4.top - 1;
	}
	return(num);
}
/*  display stack */
void display()
{
	int i;
	int a;
	int b;
	int c;
	int d;
	printf("\n The status of the stack is \n");
	if (s.top == -1)
	{
		printf("Stack is empty\n");
	}
	else if (s1.top == -1)
	{
		printf("Stack is empty\n");
	}
	else if (s2.top == -1)
	{
		printf("Stack is empty\n");
	}
	else if (s3.top == -1)
	{
		printf("Stack is empty\n");
	}
	else if (s4.top == -1)
	{
		printf("Stack is empty\n");
	}
	
	printf("Product ID\tBin ID\n");
	for (i = s.top; i > 0; i--)
	{
		printf("%d\t\t%d\n", s.stk[i], 1);
	}
	for (a = s1.top; a > 0; a--)
	{
		printf("%d\t\t%d\n", s1.stk1[a], 2);
	}
	for (b = s2.top; b > 0; b--)
	{
		printf("%d\t\t%d\n", s2.stk2[b], 3);
	}
	for (c = s3.top; c > 0; c--)
	{
		printf("%d\t\t%d\n", s3.stk3[c], 4);
	}
	for (d = s4.top; d > 0; d--)
	{
		printf("%d\t\t%d\n", s4.stk4[d], 5);
	}
	printf("\n");
}



