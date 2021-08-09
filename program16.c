/* NAME:  ANUBRATA DAS
 * ROLL NO: 720
 * class:B.Sc. Computer Science (Hons.)
 * SEMESTER & Year: 1ST, 2018 
 * REGISTRATION: A01-1122-117-018-2018
 */ 


/* 16.Write a menu driven program to perform following operations on strings:
 * a. Show address of each character in string
 * b. Concatenate two strings without using strcat function
 * c. Concatenate two strings using strcat function
 * d. Compare two strings
 * e. Calculate length of the string (use pointers)
 * f. Convert all lowercase characters to uppercase
 * g. Convert all uppercase characters to lowercase
 * h. Calculate number of vowels
 * i. Reverse the string
 * 
 * constrints: 1 <= size < 50  where size is the maximum string size  */
 
#include <stdio.h>
#include <string.h>

const int size = 100;

void address(char *);
void concatStr(char*, char*);
int lengthStr(char*);
void toUpperCase(char*);
void toLowerCase(char*);
int countVowel(char*);
void revStr(char*);

int main() {
	
	char s1[2*size], s2[size], s3[2*size];
	int option, i;
	printf("Enter first string: ");
	for (i = 0; i < 2*size && ((s1[i] = getchar()) != '\n'); ++i);
	s1[i] = '\0';
	printf("Enter second string: ");
	for (i = 0; i < 2*size && ((s2[i] = getchar()) != '\n'); ++i);
	s2[i] = '\0';
	do {
		printf("\n");
		printf("1. Show address of each character in string\n");
		printf("2. Concatenate two strings without using strcat function\n");
		printf("3. Concatenate two strings using strcat function\n");
		printf("4. Compare two strings\n");
		printf("5. Calculate length of the string (use pointers)\n");
		printf("6. Convert all lowercase characters to uppercase\n");
		printf("7. Convert all uppercase characters to lowercase\n");
		printf("8. Calculate number of vowels\n");
		printf("9. Reverse the string\n");
		printf("10. Quit the program\n\n");
		do {
			printf("Select an option (1 - 10): ");
			scanf("%d", &option);
		} while (option < 1 || option > 10);
		switch (option) {
			case 1: address(s1);
					break;
			case 2: concatStr(s1,s2);
					break;
			case 3: strcpy(s3,s1);
					strcat(s3,s2);
					printf("Concatenated string:\n");
					printf("%s\n", s3);
					break;
			case 4: i = strcmp(s1,s2);
					if (i == 0)
						printf("Both the strings are same\n");
					else if (i < 0)
						printf("First string is lexicographically smaller than second string\n");
					else
						printf("First string is lexicographically greater than second string\n");
					break;
			case 5: printf("Length of the first string: %d\n", lengthStr(s1));
					break;
			case 6: strcpy(s3,s1);
					toUpperCase(s3);
					printf("%s\n", s3);
					break;
			case 7: strcpy(s3,s1);
					toLowerCase(s3);
					printf("%s\n", s3);
					break;
			case 8: printf("Number of vowels in the first string are %d\n", countVowel(s1));
					break;
			case 9: printf("Original string: %s\n", s1);
					revStr(s1);
					printf("Reverse string: %s\n", s1);
					break;
			case 10: printf("Quitting the program\n");
		}
	} while (option != 10);
	return 0;
}
		
void address(char *x) {
	printf("Address of each character in the string:\n");
	for ( int i = 0; i < strlen(x); ++i)
		printf("%c is at %p\n", x[i], x+i);
	return;
}

void concatStr(char *x, char *y){
	int len1, len2, i;
	char s3[2*size];
	strcpy(s3,x);
	len1 = strlen(s3);
	len2 = strlen(y);
	for (i=0; i<len2; ++i)
		s3[len1+i] = y[i];
	s3[len1+i] = '\0';
	printf("Concatenated string:\n");
	printf("%s\n", s3);
	return;
}

int lengthStr(char *x){
	char *y = x;
	while (*y != '\0')
		++y;
	return (y-x);
}

void toUpperCase(char *x) {
	for (int i = 0; i < strlen(x); ++i)
		if (x[i] >= 'a' && x[i] <= 'z')
			x[i] = x[i] - 32;
}

void toLowerCase(char *x) {
	for (int i = 0; i < strlen(x); ++i)
		if (x[i] >= 'A' && x[i] <= 'Z')
			x[i] = x[i] + 32;
}

int countVowel(char *x) {
	int cnt = 0;
	for (int i = 0; i < strlen(x); ++i)
		if (x[i]=='a' || x[i]=='A' || x[i]=='e' || x[i]=='E' ||
			x[i]=='i' || x[i]=='I' || x[i]=='o' || x[i]=='O' ||
			x[i]=='u' || x[i]=='U')
		++cnt;
	return cnt;
}

void revStr(char *x) {
	char temp;
	int len1 = strlen(x);
	for (int i = 0; i < len1/2 - 1; ++i){
		temp = x[i];
		x[i] = x[len1-1-i];
		x[len1-1-i] = temp;
	}
	return;
}
