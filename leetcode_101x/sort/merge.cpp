#include<iostream>
#include <vector>
using namespace std;
class mergesort
{
    public:
    void Solution(vector<int> &nums)
    {
        int *lsarray = new int[nums.size()];
        if (lsarray==NULL)
        {
            return ;
        }
        else 
        {
            msort(nums,0,nums.size()-1,lsarray);
            free(lsarray);
        }
    }
    void merge(vector<int> &nums,int l,int mid,int r,int* &array)
    {
            int ls=l;
            int rs=mid+1;
            int j=l;
            for (int i=l;i<=r;i++) array[i]=nums[i];
            while (ls<=mid && rs<=r) 
            {
                while (ls<=mid && rs<=r && array[ls]<=array[rs]) nums[j++]=array[ls++];
                while (ls<=mid && rs<=r && array[ls]>array[rs])  nums[j++]=array[rs++];
            }
            while (ls<=mid) nums[j++]=array[ls++];
            while (rs<=r)  nums[j++]=array[rs++];
            return ;
    }
    void msort(vector<int> &nums,int l,int r,int* &array)
    {
        if (l<r)
        {
             int mid=l+((r-l)>>1);
             msort(nums,l,mid,array);
             msort(nums,mid+1,r,array);
             merge(nums,l,mid,r,array);
       
        }
        

        
    }
};
int main()
{
    vector<int> a{34,1,234,56,12};
    mergesort A;
    A.Solution(a);
    for (int i=0;i<a.size();i++)
    cout<<a[i]<<" ";

}