#include <iostream>
#include <set>
using namespace std;

// Attempt Reformated
bool isPathCrossing(string path)
{
    float plane_x = 0;
    float plane_y = 0;
    set<pair<int, int>> visit;
    visit.insert({0, 0});

    for (int i = 0; i < path.length(); i++)
    {
        char direction = path[i];
        if (direction == 'N')
        {
            plane_y += 1;
        }
        else if (direction == 'S')
        {
            plane_y -= 1;
        }
        else if (direction == 'E')
        {
            plane_x += 1;
        }
        else if (direction == 'W')
        {
            plane_x -= 1;
        }

        if (!visit.insert({plane_x, plane_y}).second)
        {
            cout << "True";
            return true;
        }
    }
    cout << "False";
    return false;
}

int main()
{

    string path = "NESW";
    string path2 = "NESS";

    cout << "Test path 1: " << path << endl;
    cout << "Path crossed twice: " << isPathCrossing(path) << endl;

    cout << "Test path 2: " << path2 << endl;
    cout << "Path crossed twice: " << isPathCrossing(path2);

    return 0;
}
