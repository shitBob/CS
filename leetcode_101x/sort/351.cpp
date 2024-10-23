#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
struct numtime
{
    int value;
    int count=0;
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
      vector<numtime> tem;
      vector<int> ans;
      for (int i=0;i<nums.size();i++)
            if (i==0)
            tem.push_back({nums[i],1});
            else 
            {
                if (nums[i]!=nums[i-1])
               tem.push_back({nums[i],1});
                else 
               tem[tem.size()-1].count++;
            }
        sort(tem.begin(),tem.end(),[](numtime a,numtime b){return a.count>b.count;});
        for (int i=0;i<k;i++)
        ans.push_back(tem[i].value);
        return ans;
    }


};
int main()
{
    
  
}