#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    // First Attempt, 11511/11511 cases successful, 3ms runtime (O(N))
    bool isPalindrome(int x)
    {
        std::string xstr = std::to_string(x);
        int m = xstr.length() / 2 - 1;
        int start = 0;
        for (int i = xstr.length() - 1; i > m; i--)
        {
            if (xstr[i] == xstr[start])
            {
            }
            else
            {
                return false;
            }
            start++;
        }
        return true;
    }
};
