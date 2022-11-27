#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <Windows.h>
#include <time.h>



int main()
{
	

	printf("----------------------------------Arrays part--------------------------------------\n");


	
	
	// Opening of all data files
	
	FILE *file1 = fopen("data_10.txt", "r");
	FILE *file2 = fopen("data_100.txt", "r");
	FILE *file3 = fopen("data_1000.txt", "r");
	FILE *file4 = fopen("data_10000.txt", "r");
	FILE *file5 = fopen("data_100000.txt", "r");
	FILE *file6 = fopen("data_1000000.txt", "r");
	
	
	char str[120];		
	int x[6];
	
	
	double Run_time[6];
	
	
	LARGE_INTEGER elapsed_time, frequency, start_time, end_time;
	LARGE_INTEGER elapsed_time1, frequency1, start_time1, end_time1;
	LARGE_INTEGER elapsed_time2, frequency2, start_time2, end_time2;
	LARGE_INTEGER elapsed_time3, frequency3, start_time3, end_time3;
	
	

	

	// Get data from First file 
	fgets(str,120,file1);
	fgets(str,120,file1);	
	
	char* token;
	token=strtok(str," ");
	x[0]=atof(token);
		// Arrays to store data of first file 
	int   array1_id[x[0]];
	char *array1_name[x[0]];
	char *array1_city[x[0]];
	char *array1_catg[x[0]];
	int i;
	
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	for(i=0; i<x[0]; i++){
		fgets(str,120,file1);
		token=strtok(str," ");
		array1_id[i]=atof(token);
		token=strtok(NULL," ");
		array1_name[i]=token;
		token=strtok(NULL," ");
		array1_city[i]=token;
		token=strtok(NULL," ");
		array1_catg[i]=token;}
		// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    Run_time[0] = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    
    
    
    
	// sorted array
	int j,a;
	
	QueryPerformanceFrequency(&frequency1);
	QueryPerformanceCounter(&start_time1);
	
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	for (i = 0; i < x[0]; ++i) {
		for (j = i + 1; j < x[0]; ++j){
                 if (array1_id[i] > array1_id[j]){
                     a =  array1_id[i];
                    array1_id[i] = array1_id[j];
                    array1_id[j] = a;
                }}}
                
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	printf("The Sorted array is \n\n");
	for(i=0; i<x[0]; i++){
    	printf("%d\n",array1_id[i]);}
	
	QueryPerformanceCounter(&end_time1);
    elapsed_time1.QuadPart = end_time1.QuadPart - start_time1.QuadPart;
	double run_time_trav = ((double) elapsed_time1.QuadPart) / frequency1.QuadPart;
	
	
	
	// Find
	int d=0;
	int even_array1[x[0]];
	QueryPerformanceFrequency(&frequency2);
	QueryPerformanceCounter(&start_time2);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
		for(i=0; i<x[0]; i++){
		if((array1_id[i]%2)==0){
			even_array1[d]=array1_id[i];
			d++;}}

	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time2);
    elapsed_time2.QuadPart = end_time2.QuadPart - start_time2.QuadPart;
	double run_time_find = ((double) elapsed_time2.QuadPart) / frequency2.QuadPart;
	
	
	//Delete
	int b;
	QueryPerformanceFrequency(&frequency3);
	QueryPerformanceCounter(&start_time3);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	for(i=0; i<x[0]; i++)
	{
		if((i%2)!=0);
			array1_id[i]=0;
	}	
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time3);
    elapsed_time3.QuadPart = end_time3.QuadPart - start_time3.QuadPart;
	double run_time_dell = ((double) elapsed_time3.QuadPart) / frequency3.QuadPart;
	
	
	
	
	//Print all data
	printf("\nNo of Records: %d\n\n", x[0]);
	printf("Insert                    Execution Time:  %e     Memory Consumption:     %5d bytes\n",Run_time[0],x[0] * sizeof(array1_id));
	printf("Sort Traversal            Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_trav,x[0]*sizeof(array1_id));
	printf("Find                      Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_find,x[0]*sizeof(array1_id));
	printf("Delete                    Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_dell,x[0]*sizeof(array1_id));
	
	
	
	
	
	
	// Getting data from second file
	fgets(str,120,file2);
	fgets(str,120,file2);	
	token=strtok(str," ");
	x[1]=atof(token);
	
	
	// Arrays to store data of second file
	int array2_id[x[1]];
	char *array2_name[x[1]];
	char *array2_city[x[1]];
	char *array2_catg[x[1]];
	
	
	
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time); 
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	
	for(i=0; i<x[1]; i++){
		fgets(str,120,file2);
		token=strtok(str,"\t");
		array2_id[i]=atof(token);
		token=strtok(NULL,"\t");
		array2_name[i]=token;
		token=strtok(NULL,"\t");
		array2_city[i]=token;
		token=strtok(NULL,"\t");
		array2_catg[i]=token;}
	
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/

	QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	Run_time[1] = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	
	
	
	
	QueryPerformanceFrequency(&frequency1);
	QueryPerformanceCounter(&start_time1);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	for (i = 0; i < x[0]; ++i){
             for (j = i + 1; j < x[0]; ++j){
                 if (array1_id[i] > array1_id[j]){
                     a =  array1_id[i];
                    array1_id[i] = array1_id[j];
                    array1_id[j] = a;}}}

        
        // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
        
	QueryPerformanceCounter(&end_time1);
    elapsed_time1.QuadPart = end_time1.QuadPart - start_time1.QuadPart;
	double run_time_trav1 = ((double) elapsed_time1.QuadPart) / frequency1.QuadPart;
	
	
	
	
	
	d=0;
	int even_array2[x[1]];
	QueryPerformanceFrequency(&frequency2);
	QueryPerformanceCounter(&start_time2);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	
	for(i=0; i<x[1]; i++)
	{
		if((array2_id[i]%2)==0)
		{
			even_array2[d]=array2_id[i];
			d++;
		}
	}
			// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
		
	QueryPerformanceCounter(&end_time2);
    elapsed_time2.QuadPart = end_time2.QuadPart - start_time2.QuadPart;
	double run_time_find1 = ((double) elapsed_time2.QuadPart) / frequency2.QuadPart;
	
	
	
	
	QueryPerformanceFrequency(&frequency3);
	QueryPerformanceCounter(&start_time3);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	for(i=0; i<x[1]; i++)
	{
		if((i%2)!=0);
			array1_id[i]=0;
	}
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time3);
    elapsed_time3.QuadPart = end_time3.QuadPart - start_time3.QuadPart;
	double run_time_dell1 = ((double) elapsed_time3.QuadPart) / frequency3.QuadPart;
	
	
	
	//Print all data
	printf("\nNo of Records: %d\n\n", x[1]);
	printf("Insert                    Execution Time:  %e     Memory Consumption:     %5d bytes\n",Run_time[1],x[1] * sizeof(array2_id));
	printf("Sort Traversal            Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_trav,x[1]*sizeof(array2_id));
	printf("Find                      Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_find,x[1]*sizeof(array2_id));
	printf("Delete                    Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_dell,x[1]*sizeof(array2_id));
	
	
	// Get data of third file
	fgets(str,120,file3);
	fgets(str,120,file3);	
	token=strtok(str," ");
	x[2]=atof(token);
	
	
	// Arrays to store data of third file
	int array3_id[x[2]];
	char *array3_name[x[2]];
	char *array3_city[x[2]];
	char *array3_catg[x[2]];
	
	
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time); 
	
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
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
		array3_catg[i]=token;}
	
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	Run_time[2] = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	



	
	QueryPerformanceFrequency(&frequency1);
	QueryPerformanceCounter(&start_time1);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	for (i = 0; i < x[0]; ++i){
            for (j = i + 1; j < x[0]; ++j){
                if (array1_id[i] > array1_id[j]){
                     a =  array1_id[i];
                    array1_id[i] = array1_id[j];
                    array1_id[j] = a;}}}
        
        // Any code whose execution time is to be checked comes between the start and the end time	
  		/*------------------------THIS IS THE END----------------------------------------------*/
        
	QueryPerformanceCounter(&end_time1);
    elapsed_time1.QuadPart = end_time1.QuadPart - start_time1.QuadPart;
	double run_time_trav2 = ((double) elapsed_time1.QuadPart) / frequency1.QuadPart;
	
	
	
	
	
	
	d=0;
	int even_array3[x[2]];
	QueryPerformanceFrequency(&frequency2);
	QueryPerformanceCounter(&start_time2);
	
		// Any code whose execution time is to be checked comes between the start and the end time	
  	/*------------------------THIS IS THE START----------------------------------------------*/
	
		QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	for(i=0; i<x[2]; i++)
	{
		if((array3_id[i]%2)==0)
		{
			even_array3[d]=array3_id[i];
			d++;
		}
	}
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time2);
    elapsed_time2.QuadPart = end_time2.QuadPart - start_time2.QuadPart;
	double run_time_find2 = ((double) elapsed_time2.QuadPart) / frequency2.QuadPart;
	
	
	
	
	
	QueryPerformanceFrequency(&frequency3);
	QueryPerformanceCounter(&start_time3);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	for(i=0; i<x[2]; i++)
	{
		if((i%2)!=0);
			array3_id[i]=0;
	}
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time3);
    elapsed_time3.QuadPart = end_time3.QuadPart - start_time3.QuadPart;
	double run_time_dell2 = ((double) elapsed_time3.QuadPart) / frequency3.QuadPart;
	
	
	
	
	//Print all data
	printf("\nNo of Records: %d\n\n", x[2]);
	printf("Insert                    Execution Time:  %e     Memory Consumption:     %5d bytes\n",Run_time[2],x[2] * sizeof(array3_id));
	printf("Sort Traversal            Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_trav,x[2]*sizeof(array3_id));
	printf("Find                      Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_find,x[2]*sizeof(array3_id));
	printf("Delete                    Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_dell,x[2]*sizeof(array3_id));
	
	
	// Getting data from 4th file
	fgets(str,120,file4);
	fgets(str,120,file4);	
	token=strtok(str," ");
	x[3]=atof(token);
	
	
	// Arrays to store data of fourth file
	int array4_id[x[3]];
	char *array4_name[x[3]];
	char *array4_city[x[3]];
	char *array4_catg[x[3]];
	
	
	
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time); 
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	for(i=0; i<x[3]; i++){
		fgets(str,120,file4);
		token=strtok(str,"\t");
		array4_id[i]=atof(token);
		token=strtok(NULL,"\t");
		array4_name[i]=token;
		token=strtok(NULL,"\t");
		array4_city[i]=token;
		token=strtok(NULL,"\t");
		array4_catg[i]=token;}
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	Run_time[3] = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	
	
	
	
	QueryPerformanceFrequency(&frequency1);
	QueryPerformanceCounter(&start_time1);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	for (i = 0; i < x[0]; ++i){
             for (j = i + 1; j < x[0]; ++j){
                 if (array1_id[i] > array1_id[j]){
                    a =  array1_id[i];
                    array1_id[i] = array1_id[j];
                    array1_id[j] = a;}}}
        
    // Any code whose execution time is to be checked comes between the start and the end time	
  		/*------------------------THIS IS THE END----------------------------------------------*/
        
	QueryPerformanceCounter(&end_time1);
    elapsed_time1.QuadPart = end_time1.QuadPart - start_time1.QuadPart;
	double run_time_trav3 = ((double) elapsed_time1.QuadPart) / frequency1.QuadPart;
	
	
	
	
	
	d=0;
	int even_array4[x[3]];
	QueryPerformanceFrequency(&frequency2);
	QueryPerformanceCounter(&start_time2);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
    /*------------------------THIS IS THE START----------------------------------------------*/
	
	for(i=0; i<x[3]; i++)
	{
		if((array4_id[i]%2)==0)
		{
			even_array4[d]=array4_id[i];
			d++;
		}
	}
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time2);
    elapsed_time2.QuadPart = end_time2.QuadPart - start_time2.QuadPart;
	double run_time_find3 = ((double) elapsed_time2.QuadPart) / frequency2.QuadPart;
	
	
	
	
	QueryPerformanceFrequency(&frequency3);
	QueryPerformanceCounter(&start_time3);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	for(i=0; i<x[3]; i++)
	{
		if((i%2)!=0);
			array4_id[i]=0;
	}
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time3);
    elapsed_time3.QuadPart = end_time3.QuadPart - start_time3.QuadPart;
	double run_time_dell3 = ((double) elapsed_time3.QuadPart) / frequency3.QuadPart;
	



	//Print all data
	printf("\nNo of Records: %d\n\n", x[3]);
	printf("Insert                    Execution Time:  %e     Memory Consumption:     %5d bytes\n",Run_time[3],x[3] * sizeof(array4_id));
	printf("Sort Traversal            Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_trav,x[3]*sizeof(array4_id));
	printf("Find                      Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_find,x[3]*sizeof(array4_id));
	printf("Delete                    Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_dell,x[3]*sizeof(array4_id));
	
	
	
	// Getting data from 5th file
	fgets(str,120,file5);
	fgets(str,120,file5);	
	token=strtok(str," ");
	x[4]=atof(token);
	
	
	
	// Arrays to store data of fifth file
	int array5_id[x[4]];
	char *array5_name;
	array5_name=(char*)malloc(sizeof(char)*x[4]);
	char *array5_city;
	array5_city=(char*)malloc(sizeof(char)*x[4]);
	char *array5_catg;
	array5_catg=(char*)malloc(sizeof(char)*x[4]);
	
	
	
	
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time); 
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	for(i=0; i<x[4]; i++){
		fgets(str,120,file5);
		token=strtok(str,"\t");
		array5_id[i]=atof(token);
		token=strtok(NULL,"\t");
		array5_name[i]=token;
		token=strtok(NULL,"\t");
		array5_city[i]=token;
		token=strtok(NULL,"\t");
		array5_catg[i]=token;}
	
	// Any code whose execution time is to be checked comes between the start and the end time	
	  /*------------------------THIS IS THE END----------------------------------------------*/
		
	QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	Run_time[4] = ((double) elapsed_time.QuadPart) / frequency.QuadPart;



	
	
	
	QueryPerformanceFrequency(&frequency1);
	QueryPerformanceCounter(&start_time1);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	for (i = 0; i < x[0]; ++i){
             for (j = i + 1; j < x[0]; ++j){
                 if (array1_id[i] > array1_id[j]){
                     a =  array1_id[i];
                    array1_id[i] = array1_id[j];
                    array1_id[j] = a;}}}
	
	// Any code whose execution time is to be checked comes between the start and the end time	
	  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time1);
    elapsed_time1.QuadPart = end_time1.QuadPart - start_time1.QuadPart;
	double run_time_trav4 = ((double) elapsed_time1.QuadPart) / frequency1.QuadPart;
	
	
	
	
	
	d=0;
	double even_array5[x[4]];
	QueryPerformanceFrequency(&frequency2);
	QueryPerformanceCounter(&start_time2);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
    /*------------------------THIS IS THE START----------------------------------------------*/
	
	for(i=0; i<x[4]; i++)
	{
		if((array5_id[i]%2)==0)
		{
			even_array5[d]=array5_id[i];
			d++;
		}
	}
		
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time2);
    elapsed_time2.QuadPart = end_time2.QuadPart - start_time2.QuadPart;
	double run_time_find4 = ((double) elapsed_time2.QuadPart) / frequency2.QuadPart;
	
	
	
	
	
	
	QueryPerformanceFrequency(&frequency3);
	QueryPerformanceCounter(&start_time3);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	for(i=0; i<x[4]; i++)
	{
		if((i%2)!=0);
			array5_id[i]=0;
	}
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time3);
    elapsed_time3.QuadPart = end_time3.QuadPart - start_time3.QuadPart;
	double run_time_dell4 = ((double) elapsed_time3.QuadPart) / frequency3.QuadPart;
	
	
	
	
	//Print all data
	printf("\nNo of Records: %d\n\n", x[4]);
	printf("Insert                    Execution Time:  %e     Memory Consumption:     %5d bytes\n",Run_time[4],x[4] * sizeof(array5_id));
	printf("Sort Traversal            Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_trav,x[4]*sizeof(array5_id));
	printf("Find                      Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_find,x[4]*sizeof(array5_id));
	printf("Delete                    Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_dell,x[4]*sizeof(array5_id));
	
	
	// Getting data from 6th file
	fgets(str,120,file6);
	fgets(str,120,file6);	
	token=strtok(str," ");
	x[5]=atof(token);
	
	
	// Arrays to store data of 6th file
	int *array6_id;
	array6_id=(int*)malloc(sizeof(int)*x[5]);
	char *array6_name;
	array6_name=(char*)malloc(sizeof(char)*x[5]*20);
	char *array6_city;
	array6_city=(char*)malloc(sizeof(char)*x[5]);
	char *array6_catg;
	array6_catg=(char*)malloc(sizeof(char)*x[5]);
	
	
	
	
	
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time); 
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
		
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
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	Run_time[5] = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	
	
	
	
	
	
	
	
	QueryPerformanceFrequency(&frequency1);
	QueryPerformanceCounter(&start_time1);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
  
	for (i = 0; i < x[5]; ++i){
             for (j = i + 1; j < x[5]; ++j){
                 if (array6_id[i] > array6_id[j]){
                     a =  array6_id[i];
                    array6_id[i] = array6_id[j];
                    array6_id[j] = a;}}}
        
        
        // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
        
	QueryPerformanceCounter(&end_time1);
    elapsed_time1.QuadPart = end_time1.QuadPart - start_time1.QuadPart;
	double run_time_trav5 = ((double) elapsed_time1.QuadPart) / frequency1.QuadPart;
	
	
	
	
	
	d=0;
	double even_array6[x[5]];
	QueryPerformanceFrequency(&frequency2);
	QueryPerformanceCounter(&start_time2);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
    /*------------------------THIS IS THE START----------------------------------------------*/
	
	for(i=0; i<x[5]; i++)
	{
		if((array6_id[i]%2)==0)
		{
			even_array6[d]=array6_id[i];
			d++;
		}
	}
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time2);
    elapsed_time2.QuadPart = end_time2.QuadPart - start_time2.QuadPart;
	double run_time_find5 = ((double) elapsed_time2.QuadPart) / frequency2.QuadPart;

	
	
	
	
	
	
	
	QueryPerformanceFrequency(&frequency3);
	QueryPerformanceCounter(&start_time3);
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
	
	for(i=0; i<x[5]; i++)
	{
		if((i%2)!=0);
			array6_id[i]=0;
	}
	
	// Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
	
	QueryPerformanceCounter(&end_time3);
    elapsed_time3.QuadPart = end_time3.QuadPart - start_time3.QuadPart;
	double run_time_dell5 = ((double) elapsed_time3.QuadPart) / frequency3.QuadPart;
	
	
	
	
	
	
	//Print all data
	printf("\nNo of Records: %d\n\n", x[5]);
	printf("Insert                    Execution Time:  %e     Memory Consumption:     %5d bytes\n",Run_time[5],x[5] * sizeof(array6_id));
	//printf("Sort Traversal            Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_trav,x[5]*sizeof(array6_id));
	printf("Find                      Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_find,x[5]*sizeof(array6_id));
	printf("Delete                    Execution Time:  %e     Memory Consumption:     %5d bytes\n",run_time_dell,x[5]*sizeof(array6_id));

free(array5_name);
free(array6_name);
free(array5_city);
free(array6_city);
free(array5_catg);
free(array6_catg);
	
}

