#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int L[100], U[100], i, A[100], j;
    int R[100];
    for (i = 0;i < N;i++)
    {
        cin >> L[i] >> U[i];
        A[i] = U[i] - L[i];
    }
    for (i = 0;i < N;i++)
    {
        R[i] = 0;
        for (j = 0;j < N;j++)
        {
            if (A[i] > A[j])
            {
                R[i] = R[i] + 2;
            }
            else
            {
                R[i] = R[i] + 0;
            }
        }
    }
    for (i = 0;i < N;i++)
    {
        cout << R[i] << " ";
    }
}