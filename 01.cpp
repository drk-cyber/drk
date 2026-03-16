#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>

class solution1
{
    public:
    vector<int>twosum(vector<int>&nums,int target) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    return {i,j};
                }
            }
        }
        return {};
    }
};

class solution2
{
    public:
    vector<int>twosum(vector<int>&nums,int target)
    {
        int n=nums.size();
        unordered_map<int,int>hashtable;
        for(int i=0;i<n;i++)
        {
            auto it=hashtable.find(target-nums[i]);
            if(it!=hashtable.end())//找到了
            {
                return {it->second,i};
            }
            hashtable[nums[i]]=i;
        }
        return {};
    }
};

int main()
{
    vector<int>nums={1,3,5,6,9};
    int target=10;
    solution2 sol;
    vector<int> result=sol.twosum(nums,target);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}