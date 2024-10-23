#include <iostream>
#include <vector>
using namespace std;
class Solution {
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.size()==0) return 0;
        int num=0;
        for (int i=0;i<isConnected.size();i++)
            if (isConnected[i][i]==1)
                {   
                    isConnected[i][i]=0; 
                    num++;
                    search(i,isConnected);
                }
        return num;
               
    }
    void search(int aim,vector<vector<int>>& isConnected)
    {
       for (int i=0;i<isConnected[aim].size();i++)
            {
                if (isConnected[i][i] && isConnected[aim][i]==1)
                    {
                        isConnected[i][i]=0;
                        search(i,isConnected);
                    }
            }
    }
};
int main()
{

}