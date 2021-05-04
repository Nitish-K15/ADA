#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <chrono> 
using namespace std::chrono;
using namespace std; 
int count = 0;
int count1 = 0;
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	::count++;
	int pivot = arr[high];  
	int i = (low - 1);  

	for (int j = low; j <= high - 1; j++)
	{
	 
		if (arr[j] < pivot)
		{
			i++;  
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	::count1++;
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
 
int main()
{
	int arr[1000];
	int n = 1000;
	srand(time(NULL));
	for(int i = 0;i<n;i++)
		arr[i] = rand() % 2000 + 1;
	auto start = high_resolution_clock::now();
	quickSort(arr, 0, n - 1);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Sorted array: \n";
	printArray(arr, n);
	cout << duration.count() << " microseconds"<<endl;
	cout << "partition "<< ::count<<endl;
	cout << "quicksort " << ::count1 << endl;
	 start = high_resolution_clock::now();
	quickSort(arr, 0, n - 1);
	 stop = high_resolution_clock::now();
	 duration = duration_cast<microseconds>(stop - start);
	//printArray(arr, n);
	cout << endl;
	cout << duration.count()<<" microseconds" << endl;
	return 0;
}

 

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

