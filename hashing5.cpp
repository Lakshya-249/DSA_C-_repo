#include <bits/stdc++.h>

using namespace std;

int maxLen(int A[], int n){
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += A[i];
        if (sum == 0){
            maxi = i + 1;
        }else{
            if (mpp.find(sum) != mpp.end()){
                maxi = max(maxi , i - mpp[sum]);
            }else{
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}

int main()
{
    int vec[] = {7,9,10,8,5,-6,1};
    cout << "Answer of maximum length for max 0 zero sum  : " << maxLen(vec,7);
    return 0;
}