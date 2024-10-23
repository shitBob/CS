#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;
vector<int> dir={-1,0,1,0,-1};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(); //n行
        if (n==0) return 0;
        int m=grid[0].size(); //m列
        if (m==0) return 0;
        int maxarea=0;
        for (int i=0;i<n;i++)
        for (int j=0;i<m;j++)
            if (grid[i][j])
            {   int area=0;
                stack<pair<int,int>> s;
                s.push({i,j});
                while(!s.empty())
                {   
                    area++;
                    auto [x,y]=s.top();
                    s.pop();
                    for (int k=0;k<4;k++)
                    {
                        int dx=dir[k];
                        int dy=dir[k+1];
                        if (x+dx<n &&y+dy<m && grid[x+dx][y+dy])
                        {
                            grid[x+dx][y+dy]=0;
                            s.push({x+dx,y+dy});
                        }
                    }
                } 
                maxarea = maxarea>=area? maxarea:area;
            }


    return maxarea;
    }
   
};
int main()
{
    
}