#include<bits/stdc++.h>

using namespace std;

class heap{
    public:
        int arr[100];
        int size;
        heap(){
            arr[0]= -1;
            size=0;
        }
        void insertdata(int val){
            size++;
            int index= size;
            arr[index]=val;
            while (index>1)
            {
                int parent =index/2;
                if(arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                    index=parent;
                }else{
                    return;
                }
            }
        }
        void printheap(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
        }
        void deletefromheap(){
            if(size==0){
                cout<<"Nothing to delete...";
                return;
            }
            arr[1]=arr[size];
            size--;
            int i=1;
            while (i<size)
            {
                int leftindex = 2*i;
                int rightindex = 2*i + 1;
                if(leftindex<=size && arr[leftindex]>arr[i]){
                    swap(arr[i],arr[leftindex]);
                    i=leftindex;
                }else if(rightindex<=size && arr[rightindex]>arr[i]){
                    swap(arr[i],arr[rightindex]);
                    i=rightindex;
                }else{
                    return;
                }
            }
        }
};

int main(){
    heap h;
    h.insertdata(34);
    h.insertdata(55);
    h.insertdata(20);
    h.insertdata(62);
    h.insertdata(18);
    h.insertdata(48);
    h.insertdata(27);
    h.insertdata(57);
    h.insertdata(31);

    h.printheap();
    h.deletefromheap();
    h.deletefromheap();
    cout<<endl;
    h.printheap();

    return 0;
}