#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    int eraseOverlapIntervals(std::vector<vector<int>>& intervals) {

        std::sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){return a[0]<b[0]});
        int count =0;
        int right=intervals[0][1];
        for (int i=1;i<intervals.size();i++)
        {
            if (intervals[i][0]>=right)
            {
                right=intervals[i][1];
                continue;
            }
            else 
            {
                count++;
                right= min(intervals[i][1],right);
            }

        }
        return count;
        

        

        


    }
};
