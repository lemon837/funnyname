//CITS2002 Project 1 2022
//Student1: 22249533 HART JUSTIN
//Student2: 22976862 FREDERICK LEMAN

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
#define MAX_LEN 101

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
//TODO, "trimmed.txt" spacing behaviour for subsequent lines based on MAX_LEN. Not an issue when using cat. Unsure if need to fix.
	int line = 0;
	while (!feof(file) && !ferror(file)) {
		if (fgets(data[line], MAX_LEN, file) != NULL) {
			line++;
		}
	}
	fclose(file);


	FILE *fp;
	fp = fopen ("trimmed.txt", "w");
	for (int i = 0; i < line; i++) {
		//sets j's conditional every i's iteration
		linelength = sizeof(data[0]);
		for (int j = 0; j < linelength; j++) {
		//if j=0, start of line, convert [i][0] to string, strcmp againt "#", if true, break, if not, progress to print all	
			if ( data[i][0] == '#')  {
			//if the line starts with "#", skip printing that line
			break;
			}
			//prints trimmed output to "trimmed.txt"	
			fputc(data[i][j], fp);			
		}
	}
	fclose(fp);
	
	//reopen trimmed.txt for reading
	fp = fopen ("trimmed.txt", "r");
	char command1[MAX_LINES][MAX_LEN];
	if (fp == NULL) {
		printf("Error opening file");
		exit (EXIT_FAILURE);
	}
	int line1 = 0;	
	while (!feof(fp) && !ferror(fp)) {
		if (fgets(command1[line1], MAX_LEN, fp) != NULL){
			line1++;
		}
	}
	for (int i = 0; i < line1; i++){
		linelength = sizeof(command1[0]);
		for (int j = 0; j < linelength; j++) {
			printf("%c", command1[i][j]);
		}

	}
	fclose(fp);
	
	
	
	//prints contents of "trimmed.txt" for testing purposes, delete later
	//if (fp) {
	//	while ((c = getc(fp)) != EOF)
	//		putchar(c);
	//scanf? fscanf?
	//	}	
	//fclose(fp);
	//delete temp file after use
	//remove("trimmed.txt")
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
	//TODO change me to readfile2 when readfile2's function written
	//readfile1(argv[3]);
	monthset(monthname);
        exit (EXIT_SUCCESS);
}


