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
        void insertdata(T val){
            size++;
            int index=size;
            arr[size]=val;
            while (index>1){
                int parent=index/2;
                if(arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                    index=parent;
                }else{
                    return;
                }
            }
        }
        void deleletefromheap(){
            arr[1]=arr[size];
            size--;
            int i=1;
            while(i<size){
                int largest=i;
                int leftind=2*i;
                int rightind=2*i+1;
                if(leftind<=size && arr[largest]<arr[leftind]){
                    largest=leftind;
                }
                if(rightind<=size && arr[largest]<arr[rightind]){
                    largest=rightind;
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
        void printheap(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
        }
};

int kthsmallest(int arr[],int k,int n){
    heap<int>h;
    for(int i=0;i<k;i++){
        h.insertdata(arr[i]);
    }
    h.printheap();
    cout<<endl;
    for(int i=k;i<n;i++){
        if(h.top()>arr[i]){
            h.deleletefromheap();
            h.insertdata(arr[i]);
        }
    }
    h.printheap();
    return h.top();
}

// 2-Method
int kthsmallest2(int arr[],int k,int n){
    priority_queue<int>pq;
    for(int i=0;i<k;i++) pq.push(arr[i]);
    for(int i=k;i<n;i++){
        if(pq.top()>arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main(){
    int arr[]={12,3,17,5,9,4,11,16};
    int n=sizeof(arr)/sizeof(int);
    int smallelm=kthsmallest(arr,5,n);
    cout<<"\nKth Smallest element of the array: "<<smallelm<<endl;
    int smallelm2=kthsmallest2(arr,5,n);
    cout<<"Kth Smallest element of the array using Priority queue: "<<smallelm2;

    return 0;
}
