#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l=0;
        int r=nums.size()-1;
        int n=nums.size();
        if (l==r)  return nums[l];
        while(l<r)
        {
            int q=findpoint(nums,l,r);
            if (q==n-k)
            {
                return nums[q];
            }
            else if (q<n-k)
            {
                l=q+1;
            }
            else{
                r=q-1;
            }
        }
        return nums[l];
    }
    int findpoint(vector<int> &nums,int l,int r)
    {
          int t=l+rand()%(r-l+1);
            int temp;
            temp=nums[l];
            nums[l]=nums[t];
            nums[t]=temp;
            
            int point =nums[l];

            while (l<r)
            {
                while (l<r && nums[r]>=point) {r--;}
                nums[l]=nums[r];
                while (l<r && nums[l]<=point) {l++;}
                nums[r]=nums[l];
            }
            nums[l]=point;
            return l;
    }
};

int main()
{
    vector<int> a{3,2,3,1,2,4,5,5,6};
    Solution t;
    cout<<t.findKthLargest(a,4);
}
