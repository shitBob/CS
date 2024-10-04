#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        vector<int> a;
        while(l <= r)
        {
            if (numbers[l]+numbers[r]==target)
            {
                a.push_back(l+1);
                a.push_back(r+1);
                break;
            }
            else if (numbers[l]+numbers[r]>target)
            {
                r--;
            }
            else 
            {
                l++;
            }

        }
        return a;


    }
};
int main()
{   
    vector<int> input1={2,3,4};
    int target = 6 ;
    Solution a;
    vector<int> t= a.twoSum(input1,target);
    cout<<t[0]<<endl;
    cout<<t[1]<<endl;


     return 0;
}