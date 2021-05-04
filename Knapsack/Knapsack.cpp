#include<iostream>
using namespace std;
struct Item
{
    int w;
    int v;
    float d;
};
void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void SelectionSort(Item a[3])
{
    int min;
    for (int i = 0;i < 3;i++)
    {
        min = i;
        for (int j = i + 1;j < 10;j++)
            if (a[j].d > a[min].d)
                min = j;
        swap(a[i].d, a[min].d);
    }
    for (int i = 0; i < 3;i++)
        cout << a[i].d << " ";
    cout << endl;
}
void input(Item items[], int sizeOfItems)
{
    cout << "Enter total " << sizeOfItems << " item's values and weight" << endl;
    for (int i = 0; i < sizeOfItems; i++)
    {
        cout << "Enter " << i + 1 << " V ";
        cin >> items[i].v;
        cout << "Enter " << i + 1 << " W ";
        cin >> items[i].w;
    }
}
void display(Item items[], int sizeOfItems)
{
    int i;
    cout << "values: ";
    for (i = 0; i < sizeOfItems; i++)
    {
        cout << items[i].v << "\t";
    }
    cout << endl << "weight: ";
    for (i = 0; i < sizeOfItems; i++)
    {
        cout << items[i].w << "\t";
    }
    cout << endl;
}
float knapsack(Item items[], int sizeOfItems, int W)
{
    float TotalValue = 0;
    float TotalWeight = 0;
    for (int i = 0;i < sizeOfItems; i++)
        items[i].d = items[i].v / items[i].w;
    SelectionSort(items);
    for (int i = 0; i < sizeOfItems;i++)
    {
        if (TotalWeight + items[i].w <= W)
        {
            cout << items[i].v <<" "<< items[i].w<<endl;
            TotalWeight += items[i].w;
            cout << TotalWeight << endl;
            TotalValue += items[i].v;
            cout << TotalValue << endl;
        }
        else
        {
            int wt = W - TotalWeight;
            cout << "wt " << wt << endl;
            TotalValue += (wt * items[i].d);
            cout << TotalValue << endl;
            TotalWeight += wt;
            cout << TotalWeight << endl; 
            break;
        }
    }
    cout << "Total Weight in the bag " << TotalWeight << endl;
    return TotalValue;
}
int main()
{
    int W;
    Item items[3];
    input(items, 3);
    cout << "Entered data \n";
    display(items, 3);
    cout << "Enter Knapsack weight \n";
    cin >> W;
    float mxVal = knapsack(items, 3, W);
    cout << "Max value for " << W << " weight is " << mxVal;
}