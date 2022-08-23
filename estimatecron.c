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

#define MAX_LINES 100
#define MAX_LEN 1000

int monthlength = 0;
char monthname[] = {'m', 't', 'h'}; 
int linelength = 0;

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
		//sets j's conditional every i's iteration
		linelength = sizeof(data[0]);
		for (int j = 0; j < linelength; j++) {
		//if j=0, start of line, convert [i][0] to string, strcmp againt "#", if true, break, if not, progress to print all	
		if ( data[i][0] == '#')  {
		break;
		}
		
		printf("%c", data[i][j]);
		}
	}
}


void monthset (char monthname[]) {
	//prints the first 3 characters from monthname array, to test if monthname is being set correctly. Need precision indicator since not null terminated.
	//printf ("%.3s\n", monthname);
	if (strcmp (monthname, "jan") == 0) {
		monthlength = 31;
	}
	else if (strcmp (monthname, "feb") == 0) {
		monthlength = 28;
	}
	else if (strcmp (monthname, "mar") == 0) {
		monthlength = 31;
	}
	else if (strcmp (monthname, "apr") == 0) {
		monthlength = 30;
	}
	else if (strcmp (monthname, "may") == 0) {
		monthlength = 31;
	}
	else if (strcmp (monthname, "jun") == 0) {
		monthlength = 30;
	}
	else if (strcmp (monthname, "jul") == 0) {
		monthlength = 31;
	}
	else if (strcmp (monthname, "aug") == 0) {
		monthlength = 31;
	}
	else if (strcmp (monthname, "sep") == 0) {
		monthlength = 30;
	}
	else if (strcmp (monthname, "oct") == 0) {
		monthlength = 31;
	}
	else if (strcmp (monthname, "nov") == 0) {
		monthlength = 30;
	}
	else if (strcmp (monthname, "dec") == 0) {
		monthlength = 31;
	}
	else {
		printf("Error, invalid month");
		exit (EXIT_FAILURE);
	}
	//to test if monthlength is being set correctly, currently working. Prints to terminal
	//printf( "%d", monthlength);
}




int main (int argc, char* argv[])
{
        if (argc !=4) {
                fprintf(stderr, "Usage: ./estimatecron month crontab-file estimates-file\n");
                exit(EXIT_FAILURE);
        }
//copies argv[1] to array global array monthname, allowing it to pass to monthset
	strcpy(monthname, argv[1]);
	
	readfile1(argv[2]);
	readfile1(argv[3]);
	monthset(monthname);
        exit (EXIT_SUCCESS);
}


