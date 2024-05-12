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

// indexing from 0...
void heapify(vector<int>&arr, int n, int i){
    int smallest = i;
    int leftind = 2 * i + 1;
    int rightind = 2 * i + 2;
    if (leftind <=n && arr[smallest] > arr[leftind]){
        smallest = leftind;
    }
    if (rightind <=n && arr[smallest] > arr[rightind]){
        smallest = rightind;
    }
    if (smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

vector<int> min_heap(vector<int>arr){
    int size=arr.size()-1;
    for(int i=size/2;i>=0;i--){
        heapify(arr,size,i);
    }
    return arr;
}


int main(){
    vector<int>arr={12, 14, 16, 20, 34, 9, 24};
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
    cout<<endl;
    vector<int>res=min_heap(arr);
    for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
    return 0;
}