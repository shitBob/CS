class Solution {
public:
    void sortColors(vector<int>& nums) {
        Solution1(nums,0,nums.size()-1);
    }
     public:
     void Solution1(vector<int> & nums ,int l,int r)
    {           
        if (l<r)
    {
                int a=divisonpoint(nums,l,r);
                Solution1(nums,l,a-1);
                Solution1(nums,a+1,r);
    }
               
    }
    int divisonpoint(vector<int> & nums,int l,int r)
    {
            //为了避免卡成n^2，我们常常使用随机选择。

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