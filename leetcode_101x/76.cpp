#include <iostream>
#include <vector>
#include<string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
       if (s.length()<t.length())
            return "";
       int need[123] = {};
       int count[123] = {};
       int l=0;
       int r=0;
       int bestl=0;
       int bestr=0;
       int minlen=1e7;
       int neednum=0;

       for (int i=0;i<t.length();i++)
       {    
            if (need[(int)t[i]]==0) neednum++;
            ++need[(int)t[i]];
       }
       
       while (r<s.length())
       {
            count[(int)s[r]]++;
            if (need[(int)s[r]]!=0 && count[(int)s[r]]==need[(int)s[r]]) neednum--;
            
            while (l<r && (count[(int)s[l]]>need[(int)s[l]]||need[(int)s[l]]==0 ) )
               count[(int)s[l++]]--;

            if (neednum==0 && r-l<minlen)
            {
                minlen=r-l+1;
                bestl=l;
                bestr=r;
            } 
            r++;
       }
    return neednum==0?  s.substr(bestl,minlen):"";


    }
};
int main()
{
    string a="ab";
    Solution t;
    cout<<t.minWindow("a","b");
}