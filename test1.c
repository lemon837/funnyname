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

	file = fopen(filename, "r");
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

	fclose(fp);
	
	//int minute = 0;
	char minute[2];
	int counter = 0;
	char hour[2];
	char daymon[2];
	char month[2];
	char dayofweek[2];
	for (int i = 0; i < 1; i++){
		linelength = sizeof(command1[0]);
		counter = 0;
		for (int j = 0; j < linelength; j++) {
			//if ((command1[i][j] == ' ') && (command1[i-1][j] != ' ')) {
			//	counter++;		
			//}
			if (counter == 0) {
				//minute = command1[i][j];
				minute[j] = command1[i][j];			
			}
			if (counter == 1) {
				hour[0] = command1[i][j];
			}
			if (counter == 2) {
				daymon[0] = command1[i][j];
			}
			if (counter == 3) {
				month[0] = command1[i][j];
			}
			if (counter == 4) {
				dayofweek[0] = command1[i][j];
			}
			if ((command1[i][j] == ' ') && (command1[i-1][j] != ' ')){
				counter++;
			}
		
				
		}
	
	}
	printf("Minute: %s", minute);
	printf("Hour: %s", hour);
	printf("Day of the Month: %s", daymon);
	printf("Month %s", month);
	printf("Day of the week %s", dayofweek);
	
}

void readfile2(char filename[])
{
	FILE* file;
	file = fopen("crontab_file", "r");
	
	int i = 0;
	char line[100];

	struct {
		char minute[2];
		char hour[2];
		char date[2];
		char month[2];
		char day[2];
		char command[40+1];
	}crontabs[40];
	
	while(fgets(line, sizeof line, file) != NULL) {
		char crontab_minute[2];
		char crontab_hour[2];
		char crontab_date[2];
		char crontab_month[2];
		char crontab_day[2];
		char crontab_command[40+1];

		if(line[0] != '#') {
			sscanf(line, "%s %s %s %s %s %s", crontab_minute, crontab_hour, crontab_date, crontab_month, crontab_day, crontab_command);
			strcpy(crontabs[i].minute, crontab_minute);
			strcpy(crontabs[i].hour, crontab_hour);
			strcpy(crontabs[i].date, crontab_date);
			strcpy(crontabs[i].month, crontab_month);
			strcpy(crontabs[i].day, crontab_day);
			strcpy(crontabs[i].command, crontab_command);
			i++;
		}
	}
	
	printf("%s", crontabs[0].minute); 
	fclose(file);
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
	//readfile1(argv[2]);
	//TODO change me to readfile2 when readfile2's function written
	//readfile1(argv[3]);
	monthset(monthname);
	readfile2(argv[2]);
	
        exit (EXIT_SUCCESS);
}


