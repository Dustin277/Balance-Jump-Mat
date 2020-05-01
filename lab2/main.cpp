
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

#include "array_funcs.h"

using namespace std;

int main()
{
using clock = chrono::steady_clock;
int a[ARRAY_CAPACITY];
int a_size = 0;
char choice = 'c';
  
cout<<"Please enter c or e (c: test the correctness of sorting, "
<<"e: measure the execution time of sorting): ";
cin>>choice;
  
if(choice == 'c')
{
cout<<"Please input the array size (<=1000000): ";
cin>>a_size;
  
//Code to initialize the array
initial_array_input(a, a_size);
  
//Print the array
print_array(a, a_size);
  
//Sort the array
selection_sort(a, a_size);
  
//Print the array
print_array(a, a_size);
}

else if(choice == 'e')
{
cout<<"Please input the array size (<=1000000): ";
cin>>a_size;
  
//Code to initialize array with random values
initial_array_rand(a, a_size);
  
clock::time_point start = clock::now();
  
//sort the array
selection_sort(a, a_size);
  
clock::time_point end = clock::now();
  
clock::duration time_span = end - start;
double nseconds = double(time_span.count())*clock::period::num / clock::period::den;
cout<<"The execution time of selection sorting is: "<<nseconds;
}
  
else
{
cout<<"Enter the wrong letter. ";
return 0;
}
}

//array_funcs.h

const int ARRAY_CAPACITY = 1000000;

//Prototype for Initializing Arrays with Input Values
void initial_array_input(int list[], int list_size);

//Prototype for Initializing Arrays with Random Values
void initial_array_rand(int list[], int list_size);

//Prototype for Sorting Array
void selection_sort(int list[], int list_size);

//Prototype to print the Array
void print_array(const int list[], int list_size);

//array_funcs.cpp

//Include necessary header files
#include <iostream>
#include <stdlib.h>

#include "array_funcs.h"

//Define the functions

void initial_array_input(int list[], int list_size)
{
for(int i=0; i<list_size; i++)   
std::cin>>list[i];
}

void initial_array_rand(int list[], int list_size)
{
srand(time(0));
for(int i=0; i<list_size; i++)
list[i] = rand()%ARRAY_CAPACITY;
}

void selection_sort(int list[], int list_size)
{
for(int i=0; i<list_size-1; i++)
{
int current_min = list[i];
int current_min_index = i;
for(int j=i+1; j<list_size; j++)
{
if(current_min > list[j])
{
current_min = list[j];
current_min_index = j;
}
}
  
if(current_min_index != i)
{
list[current_min_index] = list[i];
list[i] = current_min;
}
}
}

void print_array(const int list[], int list_size)
{
for(int i=0; i<list_size; i++)
std::cout<<list[i]<<" ";
std::cout<<std::endl;
}