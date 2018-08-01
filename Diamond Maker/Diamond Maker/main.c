#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER 3				// Set > 4 if need a diamond taller than 99.
#define CHARACTER '*'
#define SPACER ' '

int main(void) {
	int centerOfDiamond;
	int loopCycles;
	int angle = 1;
	int spacers;
	int charsPrinted = 1;
	
	char buffer[MAX_BUFFER + 1];
	
	printf("Enter height of diamond:\n");
	//	centerOfDiamond = atoi(fgets(buffer, BUFSIZ, stdin));
	//	loopCycles = centerOfDiamond * 2 - 1;
	loopCycles = atoi(fgets(buffer, BUFSIZ, stdin));
	if (loopCycles % 2 == 0) {
		loopCycles++;
		centerOfDiamond = loopCycles / 2 + 1;
		printf("Sorry. Height of diamond has been set to higher integer %d.\n\n", loopCycles);
	} else {
		centerOfDiamond = loopCycles / 2 + 1;
	}
	
	printf("Enter number from 1-5 to determine the width of the diamond:\n");
	(fgets(buffer, BUFSIZ, stdin));
	if (strlen(buffer) != 1) {
		angle = atoi(buffer);
	}
	
	spacers = (centerOfDiamond * angle) - angle;
	
	for (int i = 1; i <= loopCycles; i++) {
		
		for (int s = 1; s <= spacers; s++) {
			printf("%c", SPACER);
		}
		
		for (int c = 1; c <= charsPrinted; c++) {
			printf("%c", CHARACTER);
		}
		
		printf("\n");
		
		if (i >= centerOfDiamond) {
			spacers += angle;
			charsPrinted -= (angle * 2);
		} else {
			spacers -= angle;
			charsPrinted += (angle * 2);
		}
	}
	
	return EXIT_SUCCESS;
}
