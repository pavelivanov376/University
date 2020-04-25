#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct Question
{
	char text[40];
	int answerRight;
	char answerA[20];
	char answerB[20];
	char answerC[20];
	char answerD[20];
};

void printQuestion(struct Question* question, int currAnswer)
{
	char markAnswerA[] = "  ";
	char markAnswerB[] = "  ";
	char markAnswerC[] = "  ";
	char markAnswerD[] = "  ";

	switch (currAnswer)
	{
	case 1:
		markAnswerA[1] = '(';
		markAnswerB[1] = ' ';
		markAnswerC[1] = ' ';
		markAnswerD[1] = ' ';
		break;
	case 2:
		markAnswerA[1] = ' ';
		markAnswerB[1] = '(';
		markAnswerC[1] = ' ';
		markAnswerD[1] = ' ';
		break;
	case 3:
		markAnswerA[1] = ' ';
		markAnswerB[1] = ' ';
		markAnswerC[1] = '(';
		markAnswerD[1] = ' ';
		break;
	case 4:
		markAnswerA[1] = ' ';
		markAnswerB[1] = ' ';
		markAnswerC[1] = ' ';
		markAnswerD[1] = '(';
		break;
	}
	system("cls");
	printf("--------------------------------QUESTION------------------------------\n");
	printf("  Use buttons W S to chose an answer and press D to finally select it!\n\n");
	printf("%s\n", question->text);
	printf("%s%s\n", markAnswerA, question->answerA);
	printf("%s%s\n", markAnswerB, question->answerB);
	printf("%s%s\n", markAnswerC, question->answerC);
	printf("%s%s\n", markAnswerD, question->answerD);
}

void printMenu(int currChoice)
{
	char firstChoice[] = "  ";
	char secondChoice[] = "  ";
	char thirdChoice[] = "  ";
	
	switch (currChoice)
	{
	case 1:
		firstChoice[1] = '>';
		secondChoice[1] = ' ';
		thirdChoice[1] = ' ';
		break;
	case 2:
		firstChoice[1] = ' ';
		secondChoice[1] = '>';
		thirdChoice[1] = ' ';
		break;
	case 3:
		firstChoice[1] = ' ';
		secondChoice[1] = ' ';
		thirdChoice[1] = '>';
		break;
	}
	system("cls");
	printf("\n--------------------------------MENU------------------------------\n");
	printf("Use buttons W S to chose an answer and press D to finally select it!\n\n");
	printf("%sTake a Test\n\n", firstChoice);
	printf("%sCreate a Test\n\n", secondChoice);
	printf("%sExit", thirdChoice);
	
}

int chooseAnswer(struct Question* q1)
{
	int input = 1;
	int currAns;
	printQuestion(q1, input);
	while (1)
	{
		currAns = _getch();
		switch (currAns)
		{
		case 'w':  
			input--;
			if (input < 1) { input = 4; }
			system("cls");
			printQuestion(q1, input);              
			break;
		case 's': 
			input++;
			if (input > 4) { input = 1; }
			system("cls");
			printQuestion(q1, input);                
			break;
		case 'd':
			if (input == q1->answerRight)
			{
				system("cls");
				printf("\nNEXT QUESTION:");
				Sleep(700);
				system("cls");
				return 1;
			}
			else
			{
				system("cls");
				printf("\nNEXT QUESTION:");
				Sleep(700);
				system("cls");
				return 0;
			}
		}
	}
	return 0;
}

void takeATest(struct Question test[4])
{
	int grade = 2;
	for (int i = 0; i < 4; i++)
	{
		grade += chooseAnswer(&test[i]);
	}
	system("cls");
	printf("\n  Your grade is: %d\n",grade);
	Sleep(700);

}
void createTest(int* numberOfTests,struct Question* tests)
{
	system("cls");
	printf("Write your questions and their answers and then press Enter!\n");
	for (int i = 0; i < 4; i++)
	{
		printf("\nEnter question N:%d\n", i+1);
		char question[40];
		gets_s(question,40);
		strcpy((tests+*numberOfTests)[0].text, question);   
		
		printf("Enter the first answer:\nA) ");
		char answerA[20];
		gets_s(answerA,20);
		strcpy((tests + *numberOfTests)[0].answerA, answerA);
		
		printf("Enter the second answer:\nB) ");
		char answerB[20];
		gets_s(answerB, 20);
		strcpy((tests + *numberOfTests)[0].answerB, answerB);

		printf("Enter the third answer:\nC) ");
		char answerC[20];
		gets_s(answerC, 20);
		strcpy((tests + *numberOfTests)[0].answerC, answerC);

		printf("Enter the fourth answer:\nD) ");
		char answerD[20];
		gets_s(answerD, 20);
		strcpy((tests + *numberOfTests)[0].answerD, answerD);

		printf("Enter the index of the right answer: 1 for A) and so on..\n");
		_getch(&(tests + *numberOfTests)[0].answerRight);
	}
	system("cls");
	printf("\nThe was successfully created!");
	Sleep(700);
	system("cls");
	(*numberOfTests)++;
}

void chooseTest(int testIndex)
{

}

void chooseInMenu(struct Question* tests, int* numberOfTests, int* exit)
{
	int input = 1;
	int currAns;
	
	while (*exit)
	{
		printMenu(input);
		currAns = _getch();
		switch (currAns)
		{
		case 'w':
			input--;
			if (input < 1) { input = 3; }
			system("cls");
			printMenu(input);
			break;
		case 's':
			input++;
			if (input > 3) { input = 1; }
			system("cls");
			printMenu(input);
			break;
		case 'd':
			if (input == 1)
			{
				//TODO: Choose a test and take it and then go back to menu
				int testIndex;
				system("cls");
				printf("You can choose between %d test\n",*numberOfTests);
				printf("Enter the index of the test: 1 for the first..\n");
				testIndex = _getch();
				takeATest(tests + testIndex - 48 - 1);
				system("cls");
			}
			else if(input == 2)
			{
				createTest(numberOfTests, tests);
				//TODO: Go back to menu in func Menu not here
			}
			else if (input == 3)
			{
				//TODO: Exit
				*exit = 0;
			}
			break;
		}
	}
}

void menu(struct Question* tests, int* numberOfTests)   //TODO: Visualise the menu and the creation of tests
{
	int exit = 1;
	while (exit)
	{
		chooseInMenu(tests, numberOfTests,&exit);
	}


}

int main()
{
	struct Question tests[3][2];
	int numberOfTests = 1;
	
	strcpy(tests[0][0].text, "1.What is the color of water ?");
	strcpy(tests[0][0].answerA, "A) Blue");
	strcpy(tests[0][0].answerB, "B) Green");
	strcpy(tests[0][0].answerC, "C) White");
	strcpy(tests[0][0].answerD, "D) Red");
	tests[0][0].answerRight = 1;

	strcpy(tests[0][1].text, "2.What is the color of the sky ?");
	strcpy(tests[0][1].answerA, "A) Blue");
	strcpy(tests[0][1].answerB, "B) Green");
	strcpy(tests[0][1].answerC, "C) White");
	strcpy(tests[0][1].answerD, "D) Red");
	tests[0][1].answerRight = 1;

	strcpy(tests[0][2].text, "3.What is the color of fire ?");
	strcpy(tests[0][2].answerA, "A) Blue");
	strcpy(tests[0][2].answerB, "B) Green");
	strcpy(tests[0][2].answerC, "C) White");
	strcpy(tests[0][2].answerD, "D) Red");
	tests[0][2].answerRight = 4;

	strcpy(tests[0][3].text, "4.What is the color of snow ?");
	strcpy(tests[0][3].answerA, "A) Blue");
	strcpy(tests[0][3].answerB, "B) Green");
	strcpy(tests[0][3].answerC, "C) White");
	strcpy(tests[0][3].answerD, "D) Red");
	tests[0][3].answerRight = 3;

	menu(&tests,&numberOfTests);

	return 0;
}
