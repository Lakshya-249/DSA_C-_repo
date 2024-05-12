#include<bits/stdc++.h>

using namespace std;

class heap{
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insertdata(int val){
        size++;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }else{
                return;
            }
        }
    }
    void deletefromheap(){
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size){
            int leftindex=2*i;
            int rightindex=2*i+1;
            if(leftindex<=size && arr[i]<arr[leftindex]){
                swap(arr[i],arr[leftindex]);
                i=leftindex;
            }else if(rightindex<=size && arr[i]<arr[rightindex]){
                swap(arr[i],arr[rightindex]);
                i=rightindex;
            }else{
                return;
            }
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

void heapsort(int arr[],int n){
    int size=n;
    for (int i = size/2; i>0; i--)
    {
        heapify(arr,size,i);
    }
    while (size>1)
    {
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}

int main(){
    int arr[]={-1,17,24,82,77,90,36,67};
    int n=sizeof(arr)/sizeof(int)-1;
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    heapsort(arr,n);
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";

    return 0;
}