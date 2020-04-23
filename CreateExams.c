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
	printf("Use buttons W S to chose an answer and press D to finally select it!\n\n");
	printf("%s", question->text);
	printf("%s%s", markAnswerA, question->answerA);
	printf("%s%s", markAnswerB, question->answerB);
	printf("%s%s", markAnswerC, question->answerC);
	printf("%s%s", markAnswerD, question->answerD);
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

}
void crateTest(int numberOfTests,struct Question* tests[3][2])
{
	printf("Enter question N:%d:\n", numberOfTests);
	char question[40];
	gets_s(question,40);

	printf("%s", question);

	strcpy(*tests[numberOfTests][0]->text, question);    //Problem
	//printf("%s", *tests[numberOfTests][0]->text);



	
	//printf("Enter the the first answer:\nA) ");
	//char answerA[20];
	//gets_s(answerA,20);
	//strcpy(tests[numberOfTests][0]->text, answerA);
	//
	//printf("%s", tests[numberOfTests + 1][0]->text);
	//printf("%s", answerA);
}

void menu()
{

}

int main()
{
	struct Question test[4];
	
	strcpy(test[0].text, "1.What is the color of water ?\n");
	strcpy(test[0].answerA, "A) Blue\n");
	strcpy(test[0].answerB, "B) Green\n");
	strcpy(test[0].answerC, "C) White\n");
	strcpy(test[0].answerD, "D) Red\n");
	test[0].answerRight = 1;

	strcpy(test[1].text, "2.What is the color of the sky ?\n");
	strcpy(test[1].answerA, "A) Blue\n");
	strcpy(test[1].answerB, "B) Green\n");
	strcpy(test[1].answerC, "C) White\n");
	strcpy(test[1].answerD, "D) Red\n");
	test[1].answerRight = 1;

	strcpy(test[2].text, "3.What is the color of fire ?\n");
	strcpy(test[2].answerA, "A) Blue\n");
	strcpy(test[2].answerB, "B) Green\n");
	strcpy(test[2].answerC, "C) White\n");
	strcpy(test[2].answerD, "D) Red\n");
	test[2].answerRight = 4;

	strcpy(test[3].text, "4.What is the color of snow ?\n");
	strcpy(test[3].answerA, "A) Blue\n");
	strcpy(test[3].answerB, "B) Green\n");
	strcpy(test[3].answerC, "C) White\n");
	strcpy(test[3].answerD, "D) Red\n");
	test[3].answerRight = 3;

	struct Question tests[3][2];

	strcpy(tests[0][0].text, "4.What is the color of the fox ?\n");
	strcpy(tests[0][0].answerA, "A) Blue\n");
	strcpy(tests[0][0].answerB, "B) Green\n");
	strcpy(tests[0][0].answerC, "C) White\n");
	strcpy(tests[0][0].answerD, "D) Red\n");
	tests[0][0].answerRight = 3;

	strcpy(tests[0][1].text, "4.What is the color of the rabbit ?\n");
	strcpy(tests[0][1].answerA, "A) Blue\n");
	strcpy(tests[0][1].answerB, "B) Green\n");
	strcpy(tests[0][1].answerC, "C) White\n");
	strcpy(tests[0][1].answerD, "D) Red\n");
	tests[0][1].answerRight = 3;

	//takeATest(tests[0]);
	//takeATest(test);

	crateTest(1,&tests);

	//printf("hello\n");
	//char proba[10];
	//gets_s(proba,10);
	//printf("%s",proba);


	return 0;
}
