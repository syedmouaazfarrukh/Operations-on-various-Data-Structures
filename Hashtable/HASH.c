#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FUNCTIONS.c"


void READ(char *filename, int *arr) {
  FILE *read = fopen(filename, "r");

  if (read == NULL)
  	{printf("Error: The file is empty hence could not open %s", filename);}
  char value1[500]; int value2 = 0;
  fscanf(read, "%*s %*s");
  while (fscanf(read, "%s %*s %*s %*s ", value1) == 1) {
    arr[value2] = atoi(value1);
    value2++;}
  fclose(read);}

//printing all in int main
int main()
{
printf("Hash Table part:\n");

int *file_10 = (int*) malloc(10*sizeof(int));
READ("data_10.txt",file_10);
printf("\nNumber of records = 10\n\n");
CREATE_HASH(file_10, 10);
free(file_10);


int *file_100 = (int*) malloc(100*sizeof(int));
READ("data_100.txt",file_100);
printf("\nNumber of records = 100\n\n");
CREATE_HASH(file_100, 100);
free(file_100);

int *file_1000 = (int*) malloc(1000*sizeof(int));
READ("data_1000.txt",file_1000);
printf("\nNumber of records = 1000\n\n");
CREATE_HASH(file_1000, 1000);
free(file_1000);


int *file_10000 = (int*) malloc(10000*sizeof(int));
READ("data_10000.txt",file_10000);
printf("\nNumber of records = 10000\n\n");
CREATE_HASH(file_10000, 10000);
free(file_10000);


int *file_100000 = (int*) malloc(100000*sizeof(int));
READ("data_100000.txt",file_100000);
printf("\nNumber of records = 100000\n\n");
CREATE_HASH(file_100000, 100000);
free(file_100000);


int *file_1000000 = (int*) malloc(1000000*sizeof(int));
READ("data_1000000.txt",file_1000000);
printf("\nNumber of records = 1000000\n\n");
CREATE_HASH(file_1000000, 1000000);
free(file_1000000);




	return 0;
}
