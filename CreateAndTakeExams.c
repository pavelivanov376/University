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
};

void printQuestion(struct Question* question, int currAnswer, int currQuestion)
{
	char markAnswerA[] = "  ";
	char markAnswerB[] = "  ";
	char markAnswerC[] = "  ";

	switch (currAnswer)
	{
	case 1:
		markAnswerA[1] = '(';
		markAnswerB[1] = ' ';
		markAnswerC[1] = ' ';
		break;
	case 2:
		markAnswerA[1] = ' ';
		markAnswerB[1] = '(';
		markAnswerC[1] = ' ';
		break;
	case 3:
		markAnswerA[1] = ' ';
		markAnswerB[1] = ' ';
		markAnswerC[1] = '(';
		break;
	}
	system("cls");
	printf("--------------------------------QUESTION------------------------------\n");
	printf("  Use buttons W S to chose an answer and press D to finally select it!\n\n");
	printf("%d.%s ?\n",currQuestion, question->text);
	printf("  %sA) %s\n", markAnswerA, question->answerA);
	printf("  %sB) %s\n", markAnswerB, question->answerB);
	printf("  %sC) %s\n", markAnswerC, question->answerC);
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
	printf("%sCorrect or Create a Test\n\n", secondChoice);
	printf("%sExit", thirdChoice);
	
}

int chooseAnswer(struct Question* q1, int currQuestion)
{
	int input = 1;
	int currAns;
	printQuestion(q1, input, currQuestion);
	while (1)
	{
		currAns = _getch();
		switch (currAns)
		{
		case 'w':  
			input--;
			if (input < 1) { input = 3; }
			system("cls");
			printQuestion(q1, input, currQuestion);
			break;
		case 's': 
			input++;
			if (input > 3) { input = 1; }
			system("cls");
			printQuestion(q1, input, currQuestion);
			break;
		case 'd':
			if (input == q1->answerRight)
			{
				system("cls");
				printf("\nNEXT QUESTION:");
				Sleep(700);
				system("cls");
				return 5;
			}
			else
			{
				system("cls");
				printf("\nNEXT QUESTION:");
				Sleep(700);
				system("cls");
				return -1;
			}
		}
	}
	return 0;
}

void takeATest(struct Question test[4])
{
	int grade = 0;
	for (int i = 0; i < 10; i++)
	{
		grade += chooseAnswer(&test[i],i+1);
	}
	system("cls");
	printf("\n  Your score is: %d\n",grade);
	if (grade>10)
	{
		printf("\n  Congratulations! You successfully passed the test!\n");
	}
	else
	{
		printf("\n  You failed miserably! Try again!\n");
	}
	Sleep(3000);

}
void createOrCorrectTest(int testIndex,int* numberOfTests,struct Question* tests)
{
	system("cls");
	printf("Write your questions and their answers and then press Enter!\n");
	for (int i = 0; i < 4; i++)
	{
		printf("\nEnter question N:%d\n %d.", i+1,i+1);
		char question[40];
		gets_s(question,40);
		strcpy((tests + testIndex - 1)[i].text, question);
		
		printf("Enter the first answer:\nA) ");
		char answerA[20];
		gets_s(answerA,20);
		strcpy((tests + testIndex -1)[i].answerA, answerA);
		
		printf("Enter the second answer:\nB) ");
		char answerB[20];
		gets_s(answerB, 20);
		strcpy((tests + testIndex -1)[i].answerB, answerB);

		printf("Enter the third answer:\nC) ");
		char answerC[20];
		gets_s(answerC, 20);
		strcpy((tests + testIndex -1)[i].answerC, answerC);

		printf("Enter the index of the right answer: 1 for A) and so on..\n");
		_getch(&(tests + testIndex -1)[i].answerRight);
	}
	system("cls");
	printf("\nThe was successfully Correcte/Created!");
	Sleep(1000);
	system("cls");
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
				printf("You can choose between %d tests\n",*numberOfTests);
				printf("Enter the index of the test: 1 for the first..\n");
				testIndex = _getch() - 48;
				takeATest(tests + testIndex - 1);
				system("cls");
			}
			else if(input == 2)
			{
				int testIndex;
				system("cls");
				printf("Enter the index of the test: 1 for the first\n");
				printf("There are %d finished tests. You can correct them or create a new one by entring the index of a non existing test: for example 2 \n", *numberOfTests);
				testIndex = _getch()-48;
				createOrCorrectTest(testIndex,numberOfTests, tests);
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

void menu(struct Question* tests, int* numberOfTests)
{
	int exit = 1;
	while (exit)
	{
		chooseInMenu(tests, numberOfTests,&exit);
	}
}

int main()
{
	struct Question tests[3][10];
	int numberOfTests = 1;
	
	strcpy(tests[0][0].text, "What is the color of water");
	strcpy(tests[0][0].answerA, "Green");
	strcpy(tests[0][0].answerB, "Blue");
	strcpy(tests[0][0].answerC, "White");
	tests[0][0].answerRight = 2;

	strcpy(tests[0][1].text, "What is the color of the sky");
	strcpy(tests[0][1].answerA, "White");
	strcpy(tests[0][1].answerB, "Green");
	strcpy(tests[0][1].answerC, "Blue");
	tests[0][1].answerRight = 3;

	strcpy(tests[0][2].text, "What is the color of fire");
	strcpy(tests[0][2].answerA, "Blue");
	strcpy(tests[0][2].answerB, "Green");
	strcpy(tests[0][2].answerC, "Red");
	tests[0][2].answerRight = 3;

	strcpy(tests[0][3].text, "What is the color of snow");
	strcpy(tests[0][3].answerA, "Blue");
	strcpy(tests[0][3].answerB, "Green");
	strcpy(tests[0][3].answerC, "White");
	tests[0][3].answerRight = 3;

	strcpy(tests[0][4].text, "What is the color of Pavel's car");
	strcpy(tests[0][4].answerA, "Blue");
	strcpy(tests[0][4].answerB, "Green");
	strcpy(tests[0][4].answerC, "White");
	tests[0][4].answerRight = 3;

	strcpy(tests[0][5].text, "What is the color of sun");
	strcpy(tests[0][5].answerA, "Blue");
	strcpy(tests[0][5].answerB, "Yellow");
	strcpy(tests[0][5].answerC, "White");
	tests[0][5].answerRight = 2;

	strcpy(tests[0][6].text, "What is the color of a red house");
	strcpy(tests[0][6].answerA, "Blue");
	strcpy(tests[0][6].answerB, "Green");
	strcpy(tests[0][6].answerC, "Red");
	tests[0][6].answerRight = 3;

	strcpy(tests[0][7].text, "What is the color of TU's fourth corpus");
	strcpy(tests[0][7].answerA, "Blue");
	strcpy(tests[0][7].answerB, "Green");
	strcpy(tests[0][7].answerC, "White");
	tests[0][7].answerRight = 3;

	strcpy(tests[0][8].text, "What is the color of tree leaves");
	strcpy(tests[0][8].answerA, "Blue");
	strcpy(tests[0][8].answerB, "Green");
	strcpy(tests[0][8].answerC, "White");
	tests[0][8].answerRight = 2;

	strcpy(tests[0][9].text, "What is the name of this app creator");
	strcpy(tests[0][9].answerA, "Ivan");
	strcpy(tests[0][9].answerB, "Pavel");
	strcpy(tests[0][9].answerC, "Petar");
	tests[0][9].answerRight = 2;

	menu(&tests,&numberOfTests);

	return 0;
}
