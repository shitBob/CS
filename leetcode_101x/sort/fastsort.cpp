#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
class fastsort
{
    public:
     void Solution(vector<int> & nums ,int l,int r)
    {           
        if (l<r)
    {
                int a=divisonpoint(nums,l,r);
                Solution(nums,l,a-1);
                Solution(nums,a+1,r);
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
int main()
{
    vector<int> a{2,0,2,1,1,0};
    fastsort t;
    t.Solution(a,0,a.size()-1);
    for (int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
}