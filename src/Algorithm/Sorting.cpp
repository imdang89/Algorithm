#include "../../include/Algorithm/Sorting.h"

void Swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

vector<int> SortArray(vector<int> arr)
{
    int n = arr.size();
    for(int i=0; i< n-1 ; i++)
    {
        for(int j= i; j< n; j++)
        {
            if(arr[i]> arr[j])
            {
                Swap(arr[i], arr[j]);
            }
        }
    }
    return arr;
}

void SortArray(int arr[], int n)
{
    for(int i=0; i< n-1 ; i++)
    {
        for(int j= i; j< n; j++)
        {
            if(arr[i]> arr[j])
            {
                Swap(arr[i], arr[j]);
            }
        }
    }
}
