#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* letterToMorse(char letter)
{
	char* morseLetter= (char*)calloc(10,sizeof(char));
	switch (letter)
	{
	case 'a':
		strcpy(morseLetter,".-\0");
		break;
	case 'b':
		strcpy(morseLetter, "-...\0");
		break;
	case 'c':
		strcpy(morseLetter, "-.-.\0");
		break;
	case 'd':
		strcpy(morseLetter, "-..\0");
		break;
	case 'e':
		strcpy(morseLetter, ".\0");
		break;
	case 'f':
		strcpy(morseLetter, "...-.\0");
		break;
	case 'g':
		strcpy(morseLetter, "--.\0");
		break;
	case 'h':
		strcpy(morseLetter, "....\0");
		break;
	case 'i':
		strcpy(morseLetter, "..\0");
		break;
	case 'j':
		strcpy(morseLetter, ".---\0");
		break;
	case 'k':
		strcpy(morseLetter, "-.-\0");
		break;
	case 'l':
		strcpy(morseLetter, ".-..\0");
		break;
	case 'm':
		strcpy(morseLetter, "--\0");
		break;
	case 'n':
		strcpy(morseLetter, "-.\0");
		break;
	case 'o':
		strcpy(morseLetter, "---\0");
		break;
	case 'p':
		strcpy(morseLetter, ".--.\0");
		break;
	case 'q':
		strcpy(morseLetter, "--.-\0");
		break;
	case 'r':
		strcpy(morseLetter, ".-.\0");
		break;
	case 's':
		strcpy(morseLetter, "...\0");
		break;
	case 't':
		strcpy(morseLetter, "-\0");
		break;
	case 'u':
		strcpy(morseLetter, "..-\0");
		break;
	case 'v':
		strcpy(morseLetter, "...-\0");
		break;
	case 'w':
		strcpy(morseLetter, ".--\0");
		break;
	case 'x':
		strcpy(morseLetter, "-..-\0");
		break;
	case 'y':
		strcpy(morseLetter, "-.--\0");
		break;
	case 'z':
		strcpy(morseLetter, "--..\0");
		break;
	case '0':
		strcpy(morseLetter, "----\0");
		break;
	case '1':
		strcpy(morseLetter, ".----\0");
		break;
	case '2':
		strcpy(morseLetter, "..---\0");
		break;
	case '3':
		strcpy(morseLetter, "...--\0");
		break;
	case '4':
		strcpy(morseLetter, "....-\0");
		break;
	case '5':
		strcpy(morseLetter, ".....\0");
		break;
	case '6':
		strcpy(morseLetter, "-....\0");
		break;
	case '7':
		strcpy(morseLetter, "--...\0");
		break;
	case '8':
		strcpy(morseLetter, "---..\0");
		break;
	case '9':
		strcpy(morseLetter, "----.\0");
		break;
	case '?':
		strcpy(morseLetter, "..--..\0");
		break;
	case '.':
		strcpy(morseLetter, "--..--\0");
		break;
	case '/':
		strcpy(morseLetter, "-..-.\0");
		break;
	}
	return morseLetter;
}

void strToMorse(char str[], char* morseCode[])
{
	for (int i = 0; i < strlen(str); i++)
	{
		morseCode[i] = (char*)letterToMorse(str[i]);
	}
}

void testFuncPrint(char str[], char* morseCode[])
{
	printf("%s = ", str);
	for (int i = 0; i < strlen(str); i++)
	{
		printf("%s", morseCode[i]);
	}

	for (int i = 0; i < strlen(str); i++)
	{
		printf("\n%c = %s",str[i],morseCode[i]);
	}
	
}



int main()
{
	char str[256]="pavel";
	char* morseLetters[256];

	strToMorse(str, morseLetters);

	testFuncPrint(str, morseLetters);

	return 0;
}


