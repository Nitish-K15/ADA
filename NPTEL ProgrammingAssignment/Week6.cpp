#include<stdio.h>
#include<iostream>   
#include<algorithm>
using namespace std;

int main()
{
    int n, p, c;
    cin >> n >> p >> c;
    int ANS = 0;
    int ar1[10000], arr2[10000];
    for (int i = 0;i < n;i++)
    {
        cin >> ar1[i];
    }
    for (int i = 0;i < n;i++)
    {
        cin >> arr2[i];
    }
    sort(ar1, ar1 + n);
    sort(arr2, arr2 + n, greater<int>());
    for (int i = 0;i < n;i++)
    {
        int dif = arr2[i] + ar1[i];
        if (dif > p)
        {
            int dii = dif - p;
            ANS += dii * c;
        }
    }
    cout << ANS << endl;
    return 0;
}