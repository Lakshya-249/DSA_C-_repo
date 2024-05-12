#include<bits/stdc++.h>

using namespace std;

class solution{
    public:
    string k_permutation(int n, int k){
        int fact=1;
        vector<int>number;
        for(int i=1;i<n;i++){
            fact=fact*i;
            number.push_back(i);
        }
        number.push_back(n);
        k=k-1;
        string sol="";
        while(true){
            sol=sol + to_string(number[k/fact]);
            number.erase(number.begin()+k/fact);
            if(number.size()==0){
                break;
            }
            k=k%fact;
            fact=fact/number.size();
        }
        return sol;
    }
};

int main(){
    solution s1;
    string ans;
    ans=s1.k_permutation(4,17);
    cout<<ans;
}