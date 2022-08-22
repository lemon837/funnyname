#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <inttypes.h>
#include <sys/time.h>

#include <stdio.h>

#define MAX_LINES 100
#define MAX_LEN 1000

void readfile1 (char filename[]) {
	char data[MAX_LINES][MAX_LEN];
	FILE* file;

	file = fopen("crontab-file.txt", "r");
	if (file == NULL) {
		printf("Error opening file");
		exit (EXIT_FAILURE);
	}

	int line = 0;

	while (!feof(file) && !ferror(file)) {
		if (fgets(data[line], MAX_LEN, file) != NULL) {
			line++;
		}
	}

	fclose(file);

	for (int i = 0; i < line; i++) {
		printf("%s", data[i]);
	}
}



int main (int argc, char* argv[])
{
        if (argc !=4) {
                fprintf(stderr, "Usage: ./estimatecron month crontab-file estimates-file\n");
                exit(EXIT_FAILURE);
        }
	if ((strcmp (argv[2], "jan")) == 0) {
		printf ("I'm Jan");
	}
			
        else {
                readfile1(argv[3]);
                readfile1(argv[4]);
                exit (EXIT_SUCCESS);
        }

}

