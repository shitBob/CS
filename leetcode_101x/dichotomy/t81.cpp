#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while (l<=r)
        {
            int mid=l+((r-l)>>1);
            if (nums[mid]==target)
            return true;
            if (nums[l]==nums[mid])
            {
                l++;
            }
            else if (nums[r]==nums[mid])
            {
                r--;
            }
            else if (nums[mid]<nums[r])
            {
                if (nums[mid]<=target && target<=nums[r])
                {
                    l=mid+1;
                }
                else 
                {
                    r=mid-1;
                }
                
            }
            else 
            {
                if (nums[l]<=target && nums[mid]>=target)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }

        }
        if (l==nums.size())return 0; 
        return nums[l]==target;
    }
};
int main()
{
   vector<int> a{1,2,1};
   Solution t;
   cout<<t.search(a,0);

}