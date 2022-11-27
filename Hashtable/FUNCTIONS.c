#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include "fatal.h"



typedef int ElementType;
typedef unsigned int Index;
struct HASH_TABLE;
typedef struct HASH_TABLE *HashTable;
//the 4 hash functions:

void INSERT(HashTable var0, int* var2, int size);
void SORTED_TRAVERSAL(HashTable var0,int printing,int size);
void DELETE_hash(HashTable hash1, int* var2,int size,int value1);
void FIND(HashTable var0, int* var2, int size);


//basic hash functions used and converted from previous labs mostly


HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable hash1);
ElementType Retrieve_hash(Index P, HashTable hash1);
Index Find_hash(ElementType Key, HashTable hash1, ElementType print);
void Insert_hash(ElementType Key, HashTable hash1, ElementType print);
void basic_deletion(ElementType y, HashTable hash1 );

//code ustilized from previous labs
enum KindOfEntry
{
  Legitimate,
  Empty,
  Deleted
};

struct HashEntry
{
  ElementType Element;
  enum KindOfEntry Info;
};



typedef struct HashEntry Cell;
/* Cell *TheCells will be an array of */
/* HashEntry cells, allocated later */
struct HASH_TABLE
{
  int TableSize;
  Cell *TheCells;
};
/* Return next prime; assume N >= 10 */



static int NextPrime(int N)
{
  int y;

  if (N % 2 == 0)
    N++;
  for (;; N += 2)
  {
    for (y = 3; y * y <= N; y += 2)
      if (N % y == 0)
        goto ContOuter; /* Sorry about this! */
    return N;
ContOuter:;
  }
}




/* Hash function for ints */
Index Hash(ElementType Key, int TableSize)
{
  return Key % TableSize;
}




/* START: fig5_15.txt */
HashTable InitializeTable(int TableSize)
{
  HashTable hash1;
  int y;

  /* Allocate table */
  /* 4*/ hash1 = malloc(sizeof(struct HASH_TABLE));
  /* 5*/ if (hash1 == NULL)
    /* 6*/ FatalError("Out of space!!!");

  /* 7*/ hash1->TableSize = NextPrime(TableSize);

  /* Allocate array of Cells */
  /* 8*/ hash1->TheCells = malloc(sizeof(Cell) * hash1->TableSize);
  /* 9*/ if (hash1->TheCells == NULL)
    /*10*/ FatalError("Out of space!!!");

  /*11*/ for (y = 0; y < hash1->TableSize; y++)
    /*12*/ hash1->TheCells[y].Info = Empty;

  /*13*/ return hash1;
}
/* END */





/* START: fig5_16.txt */
Index Find_hash(ElementType Key, HashTable hash1, ElementType print)
{
  //printf("ok entering find\n");
  Index CurrentPos;
  int collisions;
  static int Collisions;
  /* 1*/ collisions = 1;
  /* 2*/ CurrentPos = Hash(Key, hash1->TableSize);
  /* 3*/ while (hash1->TheCells[CurrentPos].Info != Empty &&
                hash1->TheCells[CurrentPos].Element != Key)
    
  {
    /* 4*/ CurrentPos += (collisions * collisions);
    collisions += 1;
    /* 5*/ while (CurrentPos >= hash1->TableSize) {

      /* 6*/ CurrentPos -= hash1->TableSize;
    }
  }

  Collisions += collisions;

  if (print) {
    printf("Collisions: %d\n", Collisions);
  }
  /* 7*/ return CurrentPos;
}
/* END */





/* START: fig5_17.txt */
void Insert_hash(ElementType Key, HashTable hash1, ElementType print)
{
  Index Pos;
  int collisions = 1;
  Pos = Find_hash(Key, hash1, print);
  while (hash1->TheCells[Pos].Info == Legitimate)
  {
    /* OK to insert here */

    /* 4*/ Pos += (collisions * collisions);
    collisions += 1;
    /* 5*/ if (Pos >= hash1->TableSize) {
      /* 6*/ Pos -= hash1->TableSize;
    }

    /* Probably need strcpy! */
  }
  hash1->TheCells[Pos].Info = Legitimate;
  hash1->TheCells[Pos].Element = Key;

}
/* END */


void DestroyTable(HashTable hash1)
{
  free(hash1->TheCells);
  free(hash1);
}


ElementType Retrieve_hash(Index P, HashTable hash1)
{
  return hash1->TheCells[P].Element;
}



/*function for basic_deletion*/
void basic_deletion(ElementType y, HashTable hash1 ) {
  hash1->TheCells[Find_hash(y, hash1, 0)].Info = Deleted;


}
void
Swap( ElementType *Lhs, ElementType *Rhs )
{
  ElementType Tmp = *Lhs;
  *Lhs = *Rhs;
  *Rhs = Tmp;
}

int median_function(int var0, int var2, int var4){
	if(((var2)>=var0 && (var2)<=var4) || ((var2)>=var4 && (var2)<=var0))
	{
		return var2;	}
	else if(((var4)>=var0 && (var4)<=var2) || ((var4)>=var2 && (var4)<=var0))
	{
		return var4;}
	else 
	{
		return var0;}}



void quicksorter( ElementType value1[ ], int N )
{function_for_sort( value1, 0, N - 1 );
}
//the quicksorter is as follows:
void function_for_sort( ElementType value1[ ], int Left, int Right ){
	int median_value = median_function(value1[Left], value1[(Left+Right)/2],value1[Right]);
	if(median_value == value1[Left]){
		Swap( &value1[ Left ], &value1[ Right ] );}
	
	else if(median_value == value1[(Left+Right)/2]){
		Swap( &value1[(Left+Right)/2], &value1[ Right ] );}
	static int var0=0;

	if(var0 == 0)
	{
	var0++;}
	
        {
            if( Left < Right ){
                int y, j;
                ElementType Pivot;
                y = Left; j = Right - 1;
                Pivot = value1[ Right ];

                while (1){
                    while( value1[ y ] < Pivot ) {++y;} 
                    while( value1[ j ] >= Pivot ) {--j;}     // changed > to >=
  //                  printf("Stopped at y = %d, j = %d\n", y, j);
                    if( y < j ){
    //                printf( "Swapping %d and %d...\n", value1[ y ], value1[ j ] );
                        Swap( &value1[ y ], &value1[ j ] );
                    }
                    else
                        break;}
	              Swap( &value1[ Right ], &value1[ y ] );      

                function_for_sort( value1, Left, y - 1 ); function_for_sort( value1, y + 1, Right );}}}




/* This code doesn't work; it's Figure 7.15. */
#if 0
/* START: fig7_15.txt */
/* 3*/          y = Left + 1; j = Right - 2;
/* 4*/          for ( ; ; )
{
  /* 5*/              while ( value1[ y ] < Pivot ) y++;
  /* 6*/              while ( value1[ j ] > Pivot ) j--;
  /* 7*/              if ( y < j )
    /* 8*/                  Swap( &value1[ y ], &value1[ j ] );
  else
    /* 9*/                  break;
}
/* END */
#endif
/*
Structure of this file:


-hash: 				Main function that will take input array from the main cep file and initialize hash table with dual size
	- insert: 		It will take array from hash function and insert it into hash made by hash function
	- find			It will take array and hash table from hash function and find every record with even index 
					in this array in hash table. If it would not be found then error will terminate the program
	- delete		It will take array and hash table from hash function and for every record with odd index in this array
					 it will delete that from hash table.
	- sort			It will take hash table from hash function and put it in other array and then sort using quick sort 

/*==================================HASH PART STARTING==================================*/

//insert Hash function

void INSERT(HashTable hash1, int* var2, int size_value) {

  LARGE_INTEGER start_time, end_time, elapsed_time, frequency;
  double run_time;
  //code from lab 2, used for time measurement:
  QueryPerformanceFrequency(&frequency); QueryPerformanceCounter(&start_time);
  
  // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
  
  int var1;
  for (var1 = 0; var1 < size_value; var1++) {
    Insert_hash(var2[var1], hash1, 0); }
  
  // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
  
  QueryPerformanceCounter(&end_time);
  elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;

  
  run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
  int sum = sizeof(hash1->TableSize);
  for (var1 = 0; var1 < hash1->TableSize; var1++) {
    sum += sizeof(hash1->TheCells[var1]);}
    
  printf("Insert                Execution Time:  %10.8gs     Memory Consumption:     %5d bytes\n", run_time, (sizeof(struct HASH_TABLE)+(sizeof(hash1->TheCells) * hash1->TableSize)));

}



//sort function:
void SORTED_TRAVERSAL(HashTable var0, int printing, int size_value) 
{
  LARGE_INTEGER start_time, end_time, elapsed_time, frequency;
  double run_time;
  //code from lab 2, used for time measurement:
  QueryPerformanceFrequency(&frequency);
  QueryPerformanceCounter(&start_time);
  
  // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
  int total_size = 0;
  int *value_storer = malloc(sizeof(int) * size_value); int var1;
  for (var1 = 0; var1 < var0->TableSize; var1++) 
  {
    if (var0->TheCells[var1].Info == Legitimate) 
	{
      value_storer[total_size] = var0->TheCells[var1].Element;
      total_size += 1;
    }
  }
//quick sort algorithm being used because found to be the efficient most in this case:
  quicksorter( value_storer, total_size);
  if (printing == 1) {
    printf("\nsorted order:");
    printf("\n");
    var1 = 0;
    while( var1 < total_size) 
	{
      printf("%d\n", value_storer[var1]);
      var1++;
    }
    printf("\n");
  }
  // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
  
  QueryPerformanceCounter(&end_time);
  elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;  run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;

  printf("Sorted Traversal      Execution Time:  %10.8gs     Memory Consumption:     %5d bytes\n", run_time, (sizeof(struct HASH_TABLE)+(sizeof(var0->TheCells) * var0->TableSize)));
}



//delete function
void DELETE_hash(HashTable var0, int* var2, int size_value, int value) {
  LARGE_INTEGER start_time, end_time, elapsed_time, frequency;
  double run_time;
  //code from lab 2, used for time measurement:
  QueryPerformanceFrequency(&frequency); QueryPerformanceCounter(&start_time);
  
  // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/
  
  int var1;
  for (var1 = 0; var1 < size_value; var1++) 
  {
    if (var1 % 2 == 1) {

      var0->TheCells[Find_hash(var2[var1], var0, 0)].Info = Deleted;
    }
  }
  
  
  // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
  
  QueryPerformanceCounter(&end_time);
  elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
  run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
  printf("Delete                Execution Time:  %10.8gs     Memory Consumption:     %5d bytes\n", run_time, (sizeof(struct HASH_TABLE)+(sizeof(var0->TheCells) * var0->TableSize)));
}

//find function
void FIND(HashTable var0, int* var2, int size_value) {
  LARGE_INTEGER start_time, end_time, elapsed_time, frequency;
  double run_time;
//code from lab 2, used for time measurement:
  QueryPerformanceFrequency(&frequency); QueryPerformanceCounter(&start_time);

  // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE START----------------------------------------------*/

  int var1;
  int var3;
  var1=0;
   while (var1<size_value){
    if (var1%2 ==0) {

      if (var0->TheCells[Find_hash(var2[var1], var0, 0)].Element != var2[var1]) {
        printf( "error. Not found!" );
      }
    }
    var1++;
  }
  
  // Any code whose execution time is to be checked comes between the start and the end time	
  /*------------------------THIS IS THE END----------------------------------------------*/
  
  QueryPerformanceCounter(&end_time);
  elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
  run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;


  printf("Find                  Execution Time:  %10.8gs     Memory Consumption:     %5d bytes\n", run_time, (sizeof(struct HASH_TABLE)+(sizeof(var0->TheCells) * var0->TableSize)));
}

//this is the main function, which calls all the required function and can be used affectively for printing purposes. 
//so, instead of making separate printings, this strategy serves better.
void CREATE_HASH(int* arr, int size_value) {
  HashTable hash1 = InitializeTable(size_value * 2);
  int printing = 0;
  if (size_value <= 10) {
    printing = 1;} 
  INSERT( hash1, arr, size_value); 
  FIND(hash1, arr, size_value);
  SORTED_TRAVERSAL(hash1, printing, size_value);
  DELETE_hash(hash1, arr, size_value, printing);
  DestroyTable(hash1);
}

