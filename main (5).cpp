#include <iostream>
//quick sort
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    
    for (int i = start + 1;i <= end;i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
        
    }
    int pi = start + count;
    swap(arr[pi], arr[start]);
    
    
    int i = start;
    int j = end;
    
    while (i < pi && j > pi)
    {
        
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        
        if (i < pi && j > pi)
        {
            swap(arr[i++], arr[j--]);
        }   
    }
    return pi;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
    return;
    
    int p = partition(arr, start, end); //partition
    quickSort(arr, start, p - 1); //left
    quickSort(arr, p + 1, end);   //right
    
}

int main()
{
    int n;
    cout<<"Enter number of elements in array "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements in array "<<endl;
    for (int i = 0;i < n;i++)
    {
        cin>>arr[i];
    } 
    
    quickSort(arr, 0, n - 1);
    cout<<"quickSort"<<endl;
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}

