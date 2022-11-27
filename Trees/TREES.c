#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "FUNCTIONS.c"
#include <Windows.h>
#include <time.h>



int main()
{


printf("----------------------------------Trees part--------------------------------------\n");
	
	// Open all data files
	FILE *file1 = fopen("data_10.txt", "r");
	FILE *file2 = fopen("data_100.txt", "r");
	FILE *file3 = fopen("data_1000.txt", "r");
	FILE *file4 = fopen("data_10000.txt", "r");
	FILE *file5 = fopen("data_100000.txt", "r");
	FILE *file6 = fopen("data_1000000.txt", "r");
	
	int x[6];
	char str[120];
	
	

										 
	fgets(str,120,file1);			// Get data from First file
	fgets(str,120,file1);	
	
	char* token;
	token=strtok(str," ");
	x[0]=atof(token);
	
	int array1_id[x[0]];			// Arrays to store data of first file 
	char *array1_name[x[0]];
	char *array1_city[x[0]];
	char *array1_catg[x[0]];
	int i;
	
	
	for(i=0; i<x[0]; i++)
	{
		fgets(str,120,file1);
		
		token=strtok(str," ");
		array1_id[i]=atof(token);
		
		token=strtok(NULL," ");
		array1_name[i]=token;
		
		token=strtok(NULL," ");
		array1_city[i]=token;
		
		token=strtok(NULL," ");
		array1_catg[i]=token;
	}
	
	
	fgets(str,120,file2);			// Get data from second file
	fgets(str,120,file2);
		
	token=strtok(str," ");
	x[1]=atof(token);
	
	int array2_id[x[1]];			// arrays to store data of second file
	char *array2_name[x[1]];
	char *array2_city[x[1]];
	char *array2_catg[x[1]];
	
	
	for(i=0; i<x[1]; i++)
	{
		fgets(str,120,file2);
		
		token=strtok(str,"\t");
		array2_id[i]=atof(token);
		
		token=strtok(NULL,"\t");
		array2_name[i]=token;
		
		token=strtok(NULL,"\t");
		array2_city[i]=token;
		
		token=strtok(NULL,"\t");
		array2_catg[i]=token;
	}
	

	fgets(str,120,file3);
	fgets(str,120,file3);

	token=strtok(str," ");
	x[2]=atof(token);
		
	// arrays to store data of third file
	int array3_id[x[2]];
	char *array3_name[x[2]];
	char *array3_city[x[2]];
	char *array3_catg[x[2]];

	
	for(i=0; i<x[2]; i++)
	{
		fgets(str,120,file3);

		token=strtok(str,"\t");
		array3_id[i]=atof(token);

		token=strtok(NULL,"\t");
		array3_name[i]=token;

		token=strtok(NULL,"\t");
		array3_city[i]=token;

		token=strtok(NULL,"\t");
		array3_catg[i]=token;
	}
	

	fgets(str,120,file4);
	fgets(str,120,file4);	

	token=strtok(str," ");
	x[3]=atof(token);
	
	// arrays to store data of fourth file
	int array4_id[x[3]];
	char *array4_name[x[3]];
	char *array4_city[x[3]];
	char *array4_catg[x[3]];
	
	
	for(i=0; i<x[3]; i++)
	{
		fgets(str,120,file4);

		token=strtok(str,"\t");
		array4_id[i]=atof(token);

		token=strtok(NULL,"\t");
		array4_name[i]=token;

		token=strtok(NULL,"\t");
		array4_city[i]=token;

		token=strtok(NULL,"\t");
		array4_catg[i]=token;
	}
	
	
	fgets(str,120,file5);
	fgets(str,120,file5);	
	token=strtok(str," ");
	x[4]=atof(token);
	// arrays to store data of fifth file
	int array5_id[x[4]];
	char *array5_name;
	array5_name=(char*)malloc(sizeof(char)*x[4]);
	char *array5_city;
	array5_city=(char*)malloc(sizeof(char)*x[4]);
	char *array5_catg;
	array5_catg=(char*)malloc(sizeof(char)*x[4]);
	for(i=0; i<x[4]; i++)
	{
		fgets(str,120,file5);
		token=strtok(str,"\t");
		array5_id[i]=atof(token);
		token=strtok(NULL,"\t");
		array5_name[i]=token;
		token=strtok(NULL,"\t");
		array5_city[i]=token;
		token=strtok(NULL,"\t");
		array5_catg[i]=token;		
	}

	fgets(str,120,file6);
	fgets(str,120,file6);	
	token=strtok(str," ");
	x[5]=atof(token);
	// arrays to store data of 6th file
	int *array6_id;
	array6_id=(int*)malloc(sizeof(int)*x[5]);
	char *array6_name;
	array6_name=(char*)malloc(sizeof(char)*x[5]);
	char *array6_city;
	array6_city=(char*)malloc(sizeof(char)*x[5]);
	char *array6_catg;
	array6_catg=(char*)malloc(sizeof(char)*x[5]);
	for(i=0; i<x[5]; i++)
	{
		fgets(str,120,file6);
		token=strtok(str,"\t");
		array6_id[i]=atof(token);
		token=strtok(NULL,"\t");
		*(array6_name + i) *= *token;
		token=strtok(NULL,"\t");
		*(array6_city + i) *= *token;
		token=strtok(NULL,"\t");
		*(array6_catg + i) *= *token;
	}
	
	
		
	// declare BST for storing data
	struct node *nodi;
	struct node *NODE1 = NULL;
	struct node *NODE2 = NULL;
	struct node *NODE3 = NULL;
	struct node *NODE4 = NULL;
	struct node *NODE5 = NULL;
	struct node *NODE6 = NULL;				

	FILE *file;
	
	double Run_time[6];
	int j;
	
	clock_t start, end, start_1, end_1, start_2, end_2, start_3, end_3;
	
	LARGE_INTEGER elapsed_time, frequency, start_time, end_time;
	LARGE_INTEGER elapsed_time1, frequency1, start_time1, end_time1;
	LARGE_INTEGER elapsed_time2, frequency2, start_time2, end_time2;
	LARGE_INTEGER elapsed_time3, frequency3, start_time3, end_time3;
			
	// Insert all data into BST
	for(i=0; i<=5; i++)
	{
		QueryPerformanceFrequency(&frequency1);
		QueryPerformanceCounter(&start_time1);
		
		for(j=0; j<x[i]; j++)
		{
			if(i==0)
				NODE1 = insert(NODE1, array1_id[j]);
			if(i==1)
				NODE2 = insert(NODE2, array2_id[j]);
			if(i==2)
				NODE3 = insert(NODE3, array3_id[j]);
			if(i==3)
				NODE4 = insert(NODE4, array4_id[j]);
			if(i==4)
				NODE5 = insert(NODE5, array5_id[j]);
			if(i==5)
				NODE6 = insert(NODE6, array6_id[j]);
		}

	QueryPerformanceCounter(&end_time1);
	elapsed_time1.QuadPart = end_time1.QuadPart - start_time1.QuadPart;
	Run_time[i]=((double)elapsed_time1.QuadPart) / frequency1.QuadPart;
	}



	// Run_time calculation 

	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	printf("The sorted form is:\n\n");
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	inorder10(NODE1);
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	
	
	
	QueryPerformanceFrequency(&frequency2);
	QueryPerformanceCounter(&start_time2);
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	find(NODE1);
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time2);
    elapsed_time2.QuadPart = end_time2.QuadPart - start_time2.QuadPart;

	
	//deletion starts
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time3);

 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/

	for(i=0; i<x[0]; i++)
	{
		if((i%2)!=0)
			deleteNode(NODE1, i);
	}
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time3);
    elapsed_time3.QuadPart = end_time3.QuadPart - start_time3.QuadPart;
	//deletion ends

	
	double run_time_trav = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	double run_time_find = ((double)elapsed_time2.QuadPart) / frequency2.QuadPart;
	double run_time_dell = ((double)elapsed_time3.QuadPart) / frequency3.QuadPart;
	
	//Print all data
	printf("\nNo of Records: %d\n\n", x[0]);
	printf("Insertion              Execution Time:  %e     Memory Consumption:     %5d bytes\n",Run_time[0],x[0] * sizeof(NODE1));
	printf("Inorder                Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_trav,x[0]*sizeof(NODE1));
	printf("Find                   Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_find,x[0]*sizeof(NODE1));
	printf("Deletion               Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_dell,x[0]*sizeof(NODE1));
	
	
	
	
		
	// Run_time calculation for second file
	
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/

	inorder(NODE2);
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	printf("\n");
	
	
	QueryPerformanceFrequency(&frequency2);
	QueryPerformanceCounter(&start_time2);
		
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
		
	find(NODE2);
		
 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/

	QueryPerformanceCounter(&end_time2);
    elapsed_time2.QuadPart = end_time2.QuadPart - start_time2.QuadPart;
	
	
	
	//deletion starts
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time3);

	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/

	for(i=0; i<x[0]; i++)
	{
		if((i%2)!=0)
			deleteNode(NODE2, i);
	}

	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
  
	QueryPerformanceCounter(&end_time3);
    elapsed_time3.QuadPart = end_time3.QuadPart - start_time3.QuadPart;
	
	
	double run_time_trav2 = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	double run_time_find2 = ((double)elapsed_time2.QuadPart) / frequency2.QuadPart;
	double run_time_dell2 = ((double)elapsed_time3.QuadPart) / frequency3.QuadPart;
	
	
	//Print all data
	printf("\nNo of Records: %d\n\n", x[1]);
	printf("Insertion              Execution Time:  %e     Memory Consumption:     %5d bytes\n",Run_time[1],x[1] * sizeof(NODE2));
	printf("Inorder                Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_trav2,x[1]*sizeof(NODE2));
	printf("Find                   Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_find2,x[1]*sizeof(NODE2));
	printf("Deletion               Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_dell2,x[1]*sizeof(NODE2));
	
	
	
	
	// Run_time calculation for third file

	
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);

	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/

	inorder(NODE3);
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	printf("\n");
	
	
	QueryPerformanceFrequency(&frequency2);
	QueryPerformanceCounter(&start_time2);
		
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	find(NODE3);
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time2);
    elapsed_time2.QuadPart = end_time2.QuadPart - start_time2.QuadPart;
	
	
	
	//deletion starts
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time3);

	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/

	for(i=0; i<x[0]; i++)
	{
		if((i%2)!=0)
			deleteNode(NODE3, i);
	}
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time3);
    elapsed_time3.QuadPart = end_time3.QuadPart - start_time3.QuadPart;
	//deletion ends
	
	
	double run_time_trav3 = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	double run_time_find3 = ((double)elapsed_time2.QuadPart) / frequency2.QuadPart;
	double run_time_dell3 = ((double)elapsed_time3.QuadPart) / frequency3.QuadPart;
	
	
	//Print all data
	printf("\nNo of Records: %d\n\n", x[2]);
	printf("Insertion              Execution Time:  %e     Memory Consumption:     %5d bytes\n",Run_time[2],x[2] * sizeof(NODE3));
	printf("Inorder                Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_trav3,x[2]*sizeof(NODE3));
	printf("Find                   Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_find3,x[2]*sizeof(NODE3));
	printf("Deletion               Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_dell3,x[2]*sizeof(NODE3));
	
	
	// Run_time calculation for fourth file
	
	
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);

	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/

	inorder(NODE4);
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;		
	printf("\n");
	
	
	
	QueryPerformanceFrequency(&frequency2);
	QueryPerformanceCounter(&start_time2);
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	find(NODE4);
		
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
		
	QueryPerformanceCounter(&end_time2);
    elapsed_time2.QuadPart = end_time2.QuadPart - start_time2.QuadPart;
	
	
	
	//deletion starts
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time3);

	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/

	for(i=0; i<x[0]; i++)
	{
		if((i%2)!=0)
			deleteNode(NODE4, i);
	}
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time3);
    elapsed_time3.QuadPart = end_time3.QuadPart - start_time3.QuadPart;
	//deletion ends
	
	
	double run_time_trav4 = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	double run_time_find4 = ((double)elapsed_time2.QuadPart) / frequency2.QuadPart;
	double run_time_dell4 = ((double)elapsed_time3.QuadPart) / frequency3.QuadPart;
	
	
	//Print all data
	printf("\nNo of Records: %d\n\n", x[3]);
	printf("Insertion              Execution Time:  %e     Memory Consumption:     %5d bytes\n",Run_time[3],x[3] * sizeof(NODE4));
	printf("Inorder                Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_trav4,x[3]*sizeof(NODE4));
	printf("Find                   Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_find4,x[3]*sizeof(NODE4));
	printf("Deletion               Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_dell4,x[3]*sizeof(NODE4));
	
	
	
	// Run_time calculation for 5th file
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/

	inorder(NODE5);
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	
	
		
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);

	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/

	find(NODE5);
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
		
	

	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time3);

	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/

	for(i=0; i<x[0]; i++)
	{
		if((i%2)!=0)
			deleteNode(NODE5, i);
	}
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
		
	
	double run_time_trav5 = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	double run_time_find5 = ((double)elapsed_time2.QuadPart) / frequency2.QuadPart;
	double run_time_dell5 = ((double)elapsed_time3.QuadPart) / frequency3.QuadPart;
	
		
	//Print all data
	printf("\nNo of Records: %d\n\n", x[4]);
	printf("Insertion              Execution Time:  %e     Memory Consumption:     %5d bytes\n",Run_time[4],x[4] * sizeof(NODE5));
	printf("Inorder                Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_trav5,x[4]*sizeof(NODE5));
	printf("Find                   Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_find5,x[4]*sizeof(NODE5));
	printf("Deletion               Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_dell5,x[4]*sizeof(NODE5));
	
	
	// Run_time calculation for 6th file
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);

	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/

	inorder(NODE6);
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
		
		
		
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);

	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/

	find(NODE6);
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
		


	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time3);

	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/

	for(i=0; i<x[0]; i++)
	{
		if((i%2)!=0)
			deleteNode(NODE6, i);
	}
	
	 // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time3);
    elapsed_time.QuadPart = end_time3.QuadPart - start_time3.QuadPart;
		

	double run_time_trav6 = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	double run_time_find6 = ((double)elapsed_time2.QuadPart) / frequency2.QuadPart;
	double run_time_dell6 = ((double)elapsed_time3.QuadPart) / frequency3.QuadPart;
	
	
	//Print all data
	printf("\nNo of Records: %d\n\n", x[5]);
	printf("Insertion              Execution Time:  %e     Memory Consumption:     %5d bytes\n",Run_time[5],x[5] * sizeof(NODE6));
	printf("Inorder                Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_trav6,x[5]*sizeof(NODE6));
	printf("Find                   Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_find6,x[5]*sizeof(NODE6));
	printf("Deletion               Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_dell6,x[5]*sizeof(NODE6));

free(array5_name);
free(array6_name);
free(array5_city);
free(array6_city);
free(array5_catg);
free(array6_catg);



}


