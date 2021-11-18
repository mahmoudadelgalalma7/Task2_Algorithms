#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("time %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)
			//Swap Function
void swap(int* a, int* b)
{
int t = *a;
*a = *b;
*b = t;
}

			// Quick SOrt Function 
//initialization
int partition (int arr[], int low, int high)
{

	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++) 
{
	if (arr[j] <= pivot) 
	{
	i++;
	swap(&arr[i], &arr[j]);
	}
}

swap(&arr[i + 1], &arr[high]);
return (i + 1);

}

//Quick sort Function

void quickSort(int arr[], int low, int high)
{

	if (low < high)
	{
	int pi = partition(arr, low, high);
	quickSort(arr, low, pi - 1);
	quickSort(arr, pi + 1, high);
	}


}

//Print Element Of Array
void printArray_Quick(int arr[], int size) {
	int i;
	for (i=0; i < size; i++)
	printf("This is Quick Sort : %d \n", arr[i]);
}



			// Insertion Sort Function
//Insertion Sort Function
void insertionSort(int arr[], int n)
{

	int i, key, j;

	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		
	}	

}

// Print Function
void printArray_Insertion(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	printf("\nThis is Insertion Sort: %d \n", arr[i]);
}

			//Start Prog

int main()
{

//initialize Random Numbers in Array
int num_Of_array = 100000;
int i;
int arr[num_Of_array];

for (i=0;i< num_Of_array ;i++) {
		 arr[i] = rand() % 100000;
}
printf("Array of 100000 random numbers is initialized\n");

//Size of array
int n = sizeof(arr)/sizeof(arr[0]);

//Sort by Quick
	// check time by clock() AND  time.h
TICK(Quick);
quickSort(arr, 0, n-1);
TOCK(Quick);


//initialize Random Numbers in Array
for (i=0;i< num_Of_array ;i++) {
		 arr[i] = rand() % 100000;
}

//Sort by insertion
TICK(Insertion);
insertionSort(arr, n);
TOCK(Insertion);




printArray_Quick(arr, n);
printArray_Insertion(arr, n);

return 0;
}
