#include<bits/stdc++.h>

using namespace std;

template <typename T>

class heap{
    public:
        T arr[100];
        int size;
        heap(){
            size=0;
        }
        void push(T val){
            size++;
            int index=size;
            arr[index]=val;
            while(index>1){
                int parent=index/2;
                if(arr[parent]>arr[index]){
                    swap(arr[parent],arr[index]);
                    index=parent;
                }else{
                    return;
                }
            }
        } 
        void pop(){
            arr[1]=arr[size];
            size--;
            int i=0;
            while(i<size){
                int largest=i;
                int left=2*i;
                int right=2*i+1;
                if(left<=size && arr[largest]<arr[left]){
                    largest=left;
                }
                if(right<=size && arr[largest]<arr[right]){
                    largest=right;
                }
                if(largest!=i){
                    swap(arr[largest],arr[i]);
                    i=largest;
                }else{
                    return;
                }
            }
        }
        T top(){
            return arr[1];
        } 
};

void heapify(vector<int>&arr,int n,int i){
    int largest=i;
    int leftind=2*i+1;
    int rightind=2*i+2;
    if(leftind<=n && arr[largest]<arr[leftind]){
        largest=leftind;
    }
    if(rightind<=n && arr[largest]<arr[rightind]){
        largest=rightind;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }else{
        return;
    }
}

void merge2heap(vector<int>&heap1,vector<int>heap2){
    for(int i=0;i<heap2.size();i++){
        heap1.push_back(heap2[i]);
    }
    int n=heap1.size()-1;
    for(int i=n-1/2;i>=0;i--){
        heapify(heap1,n,i);
    }
    for(int i=0;i<=n;i++) cout<<heap1[i]<<" ";
}

int main(){
    vector<int>heap1={5,13,20,9,10,11,18};
    vector<int>heap2={7,16,26,3,19,22,17};
    int n=6;
    for(int i=n-1/2;i>=0;i--){
        heapify(heap1,n,i);
        heapify(heap2,n,i);
    }
    merge2heap(heap1,heap2);
}