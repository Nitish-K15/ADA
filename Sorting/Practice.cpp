// Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdlib.h>
#include<time.h>

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void SelectionSort(int a[])
{
    int min;
    for (int i = 0;i < 9;i++)
    {
        min = i;
        for (int j = i + 1;j < 10;j++)
            if (a[j] < a[min])
                min = j;
        swap(a[i], a[min]);
    }
}
void display(int a[])
{
    for (int i = 0; i < 10;i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
}
int partition(int a[], int l, int h,int pivot)
{
    while (l <= h)
    {
        while (a[l] < pivot)
        {
            l++;
        }
        while (a[h] > pivot)
        {
            h--;
        }
        if(l<=h)
        {
            swap(a[l],a[h]);
            l++;
            h--;
        }
    }
    return l;
}
void QuickSort(int a[], int l, int h)
{
    if (l >= h)
    {
        return;
    }
    else
    {
        int pivot = a[(l + h) / 2];
        int index = partition(a, l, h, pivot);
        QuickSort(a, l, index - 1);
        QuickSort(a, index, h);
    }
}
int main()
{
    srand (time(NULL));
    int a[10];
    for(int i = 0;i < 10; i++)
        a[i] = rand() % 10 + 1;
    std::cout << "Array before sorting is ";
    display(a);
    //SelectionSort(a);
    QuickSort(a, 0, 9);
    std::cout << "Array after sorting is ";
    display(a);
}

