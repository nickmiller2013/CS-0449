
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

	char input;
	short x;
	int eofOK;

	if (argc < 2) {
		printf("\nINVALID FILENAME.\n");
		return 0;
	}

	FILE *f = fopen(argv[1], "rb");
	if (f == NULL) {
		printf("\nNOT A REAL FILENAME, TRY AGAIN!\n");
		return 0;
	}

	printf("These are the strings I found in %s:\n\n", argv[1]);

	while (!feof(f)) {
		
		x = 0;
		
		do {
			eofOK = fread(&input, 1, 1, f);
			x++;
		} while (input >= 32 && input <= 126 && eofOK != 0);	

		if (x >= 4) {
			char *ptr = malloc(x);
			fseek(f, -x, SEEK_CUR);
			fread(ptr, 1, x, f);
			printf("%s", ptr);
		}
	}
	fclose(f);
	printf("\n");

	return 0;
}
