#include <iostream>
#include<ctime>
using namespace std;

int getRandom(int x, int y)
{
   
    return (x + rand() % (y - x + 1));
}

int RandomSearch(int arr[],int l,int r, int x)
{
    srand(time(NULL));
    int count = 0;
     while (true)
    {
         int index = getRandom(l, r);
         if (arr[index] == x)
         {
             count++;
             cout << "Count - " << count << endl;;
             return 1;
         }
         count++;
    }
}
int main()
{
    int arr[] = { 2,3,4,10,40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cout << " Enter element to search - ";
    cin >> x;
    int found = RandomSearch(arr,0,n-1,x);
    if (found == 1)
        cout << "ELement found\n";
}

