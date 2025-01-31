#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> hashSet;
        for (int num : nums)
        {
            hashSet.insert(num);
        }
        int longestStreak = 0;
        for (int num : nums)
        {
            if (!hashSet.count(num - 1))
            {
                int currentNum = num;
                int currentStreak = 1;
                while (hashSet.count(currentNum + 1))
                {
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};

int main(){
    Solution s1;
    vector<int>vec={7,5,9,10,8,6,19};
    cout<<"Answer is : "<<s1.longestConsecutive(vec);
    return 0;
}