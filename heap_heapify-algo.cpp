#include <bits/stdc++.h>

using namespace std;

class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insertdata(int val)
    {
        size++;
        int index = size;
        arr[index]=val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void printheap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int leftind = 2 * i;
    int rightind = 2 * i + 1;
    if (leftind <=n && arr[largest] < arr[leftind]){
        largest = leftind;
    }
    if (rightind <=n && arr[largest] < arr[rightind]){
        largest = rightind;
    }
    if (largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main(){
    int arr[] = {-1, 14, 16, 20, 34, 9, 24};
    int n = 6;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr,n,i);
    }
    for(int i=1;i<=n; i++) cout<<arr[i]<<" ";

    return 0;
}