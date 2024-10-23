#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l1=0;
        int l2=0;
        int j =0;
        vector<int> nums;
        for (int i=0 ;i<m ; i++)
        {
            nums.push_back(nums1[i]);
        }
        while (l1<m && l2<n)
        {
            if (nums[l1]<nums2[l2])
                nums1[j++] = nums[l1++];
            
            else 
                nums1[j++] = nums2[l2++];
               
            
        }
        while (l1<m){nums1[j++]=nums[l1++];}
        while (l2<n){nums1[j++]=nums2[l2++];}




    }
};
int main()
{
    return 0;
}

// void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
// int pos = m-- + n-- - 1;
// while (m >= 0 && n >= 0) {
// nums1[pos--] = nums1[m] > nums2[n]? nums1[m--]: nums2[n--];
// }
// while (n >= 0) {
// nums1[pos--] = nums2[n--];
// }
// }