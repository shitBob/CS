#include <iostream>
#include <vector>
class Solution {
public:
    int candy(std::vector<int>& ratings) {
      int left = 0;
      int right = 0;
      int count = 0 ;
      int n=ratings.size();
      if (n==1) return 1;
      for (int i=0 ;i<ratings.size();i++)
      {    
           if (i == 0)
           {
             if (ratings[i]<=ratings[i+1])
             {
                count ++;
                left =1 ;
             }
             if (ratings[i]>ratings[i+1])
             {
                int j=i+1;
                int r;
                right = 0 ;
                while (j<n && ratings[j]<= ratings[j-1]) {j++;}
                r=j-1;
                j--;
                for (j;j>i;j--)
                    {
                        if (ratings[j-1]>=ratings[j] && ratings [j+1]>=ratings[j])
                            {
                                count++;
                                right= 1;
                            }
                            if (ratings[j]>ratings[j+1])
                            {
                                right++;
                                count += right;
                                
                            }

                        }
                count += (right+1)>left ? (right+1) : left ; 
                i=r;
                left = 1 ;
                continue;
                       
             }
           }
           if (i == n-1)
           {
              if (ratings[i-1]>=ratings[i])
                count++;
              if (ratings[i-1]<ratings[i])
              {
                left++;
                count+=left;
              }
           } 


            
            if (i != 0  && i != n -1)
            {
                if (ratings[i-1]>=ratings[i] && ratings [i+1]>=ratings[i])
                {
                    count ++ ;
                    left = 1;
                    continue;
                    
                }
                if (ratings[i-1]<ratings[i] && ratings[i+1]>=ratings[i])
                {
                    left ++ ;
                     count += left ;
                     continue;
                }

                if (ratings[i+1]<ratings[i])
                {    
                      left= ratings[i-1]==ratings[i]? 1:left+1;
                      int j=i+1;
                        int r;
                        right = 0 ;
                        while (j<n && ratings[j]<= ratings[j-1]) {j++;}
                        r=j-1;
                        j--;
                        for (j;j>i;j--)
                        {   
                            if (j == n-1 )
                        {
                            if (ratings[j-1]>=ratings[j])
                            {
                                count++;
                                right =1 ;
                                continue;
                            }
                        }

                            if (ratings[j-1]>=ratings[j] && ratings [j+1]>=ratings[j])
                            {
                                count++;
                                right= 1;
                            }
                            if (ratings[j]>ratings[j+1])
                            {
                                right++;
                                count += right;
                                
                            }

                        }
                        count += (right+1)>left ? (right+1) : left ; 
                        i=r;
                        left = 1 ;
                        continue;

                }
                      
                       

                    
                
            }
      }
    return count ;
    }
};
int main()
{   
    int ratings[] = {2,1};
    Solution a;
    std::vector<int> vec(std::begin(ratings), std::end(ratings));
    std::cout<<a.candy(vec);
    return 0;
}