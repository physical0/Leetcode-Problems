#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // First Attempt, 179/987 cases successful (O(N) / O(N^2))
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> hashmap;
        map<int, int> history;
        int hisIndex = 0;
        int amount = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (!(hashmap.find(s[i]) != hashmap.end()))
            {
                amount++;
            }
            else
            {
                hisIndex++;
                amount = 1;
            }
            hashmap[s[i]] = i;
            history[hisIndex] = amount;
        }

        auto [maxKey, maxValue] = *max_element(
            history.begin(), history.end(),
            [](const auto &p1, const auto &p2)
            {
                return p1.second < p2.second;
            });
        return maxValue;
    }
};