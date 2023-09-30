#include<iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int l = i*2 + 1;
    int r = i*2 + 2;
    int largest = i;
    if ( l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if( r < n && arr[r] > arr[largest])
    {
        largest = r;
    }if( largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void buildMaxheap(int arr[], int n)
{
    for(int i=n/2 -1; i>=0; i--)
    {
        heapify(arr,n,i);
    }
}
void heapsort(int arr[], int n)
{
     buildMaxheap(arr,n);
     for(int i=n-1; i >= 0 ; i--)
     {
         swap(arr[i], arr[0]);
         heapify(arr,i,0);
     }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    heapsort(arr,n);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}


