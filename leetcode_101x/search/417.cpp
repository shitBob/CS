#include<iostream>
#include<vector>
using namespace std;
vector<int> dir={-1,0,1,0,-1};
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        if (m==0) return vector<vector<int>>();
        int n=heights[0].size();
        int **flag=new int*[m];
        for (int i=0;i<m;i++)
        {
             flag[i]=new int[n];
             for (int j=0;j<n;j++)
             flag[i][j]=0;
        }

        // 判断太平洋 
        for (int i=0;i<n;i++)
            flag[0][i]=1;
        for (int i=0;i<m;i++)
            flag[i][0]=1;
        
        for (int i=0;i<n;i++)
            rainreachsea(0,i,heights,flag);
        for (int i=0;i<m;i++)
            rainreachsea(i,0,heights,flag);
        


         int **flag1=new int*[m];
        for (int i=0;i<m;i++)
        {
             flag1[i]=new int[n];
             for (int j=0;j<n;j++)
             flag1[i][j]=0;
        }

        // 判断大西洋
        for (int i=0;i<n;i++)
            flag1[m-1][i]=1;
        for (int i=0;i<m;i++)
            flag1[i][n-1]=1;
        
         
        for (int i=0;i<n;i++)
            rainreachsea(m-1,i,heights,flag1);
        for (int i=0;i<m;i++)
            rainreachsea(i,n-1,heights,flag1);



        vector<vector<int>> ans ;
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                if (flag[i][j]&& flag1[i][j])
                    ans.push_back(vector<int>{i,j});
        free(flag);
        free(flag1);


        return ans;  

    }
    void rainreachsea(int x,int y,vector<vector<int>> & heights,int **flag)
        {
            if (flag[x][y]==1)
            {    int m=heights.size();
                int n=heights[0].size();
                for (int i=0;i<4;i++)
                {
                    int dx=dir[i];
                    int dy=dir[i+1];
                    if (x+dx>=0&&x+dx<m &&y+dy>=0&&y+dy<n)
                        if (heights[x][y]<=heights[x+dx][y+dy] && flag[x+dx][y+dy]==0)
                            {
                                flag[x+dx][y+dy]=1;
                                rainreachsea(x+dx,y+dy,heights,flag);
                            }
                          
                    
                }
               
            }
        
        }
};
int main()
{

}