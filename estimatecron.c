#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <inttypes.h>
#include <sys/time.h>

void readfile1 (char filename[]) 
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
      perror("Unable to open file");
      exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, fp) != -1) {
      printf("%s", line);
    }

    fclose(fp);
    free(line);
}

int main (int argc, char* argv[])
{
        if (argc !=4) {
                fprintf(stderr, "Usage: ./estimatecron month crontab-file estimates-file");
                exit(EXIT_FAILURE);
        }
        else {
                readfile1(argv[3]);
                readfile1(argv[4]);
                exit (EXIT_SUCCESS);
        }

}

