#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int start1 = handmakelowwer_bound(nums,target);
        if (start1 ==nums.size()|| nums[start1]!=target)
        {return vector<int>{-1,-1};}
      int  end1 = handmakelowwer_bound(nums,target+1);
      return vector<int>{start1,end1};  

}
};
int handmakelowwer_bound(vector<int>& nums, int target)
{
    int l=0;
    int r=nums.size()-1;      //记得减1
    while (l<=r)
    {
       int  mid = l+((r-l)>>1);   //注意位运算符的优先级
        if (nums[mid]>=target) 
            r = mid-1;
        else
            l = mid+1; 

    }
    return r+1;
}