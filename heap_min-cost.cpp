#include<bits/stdc++.h>

using namespace std;

template <typename T>

class minheap{
    public:
        T arr[100];
        int size;
        minheap(){
            size=0;
        }
        void push(T val){
            size++;
            int index=size;
            arr[index]=val;
            while (index>1)
            {
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
            if(size==0){
                cout<<"Nothing to pop()...";
                return;
            }
            arr[1]=arr[size];
            size--;
            int i=1;
            while(i<size)
            {
                int smallest=i;
                int leftind=2*i;
                int rightind=2*i+1;
                if(leftind<=size && arr[smallest]>arr[leftind]){
                    smallest=leftind;
                }
                if(rightind<=size && arr[smallest]>arr[rightind]){
                    smallest=rightind;
                }
                if(smallest!=i){
                    swap(arr[smallest],arr[i]);
                    i=smallest;
                }else{
                    return;
                }
            }
        }
        T top(){
            if(size==0){
                return -1;
            }
            return arr[1];
        }
        bool empty(){
            if(size==0){
                return true;
            }
            return false;
        }
};

int find_mincost(int arr[],int n){
    minheap<int>mh;
    for(int i=0;i<n;i++){
        mh.push(arr[i]);
    }
    int cost=0;
    while (mh.size>1)
    {
        int a=mh.top();
        mh.pop();
        int b=mh.top();
        mh.pop();
        int sum=a+b;
        cost+=sum;
        mh.push(sum);
    }
    return cost;
}

int main(){
    int arr[]={4,3,2,6};
    int cost=find_mincost(arr,4);
    cout<<"Minimum cost of making rope: "<<cost;

    return 0;
}