#include <iostream>
#include <vector>
#include <map>

using namespace std;

// First Attempt
vector<int> twoSumBruteForce(vector<int> &nums, int target)
{
    vector<int> newSum;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                newSum.push_back(i);
                newSum.push_back(j);
                return newSum;
            }
        }
    }
    return newSum;
}

// Seen solution
vector<int> twoSumOptimized(vector<int> &nums, int target)
{
    vector<int> newSum;
    map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        int diff = target - nums[i];
        if (map.find(diff) != map.end())
        {
            newSum.push_back(map[diff]);
            newSum.push_back(i);
            return newSum;
        }
        map[nums[i]] = i;
    }
    return newSum;
}
