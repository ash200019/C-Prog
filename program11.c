/* NAME:  ANUBRATA DAS
 * ROLL NO: 720
 * class:B.Sc. Computer Science (Hons.)
 * SEMESTER & Year: 1ST, 2018 
 * REGISTRATION: A01-1122-117-018-2018
 */ 


/*11. WAP that prints a table indicating the number of occurences of each 
 * alphabet in the text entered as command line arguments. */
 
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	int i,j,a[26] = {0};
	for ( i = 0; i < argc; ++i) {
		for ( j = 0; j < strlen(argv[i]); ++j) {
			if (argv[i][j] >= 'A' && argv[i][j] <= 'Z')
				++a[argv[i][j]-'A'];
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				++a[argv[i][j]-'a'];
		}
	}
	printf("Number of occurrences of each alphabet:\n");
	for (i = 0; i < 26; ++i)
		printf("%c or %c    %d\n", 'A'+i, 'a'+i, a[i]);
	printf("\n");
	return 0;
}
