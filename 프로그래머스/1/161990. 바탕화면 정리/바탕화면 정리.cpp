#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> point ={51,51,-1,-1 };

    for (int y = 0; y < wallpaper.size(); y++)
    {
        // 초기화 {INT_MAX, INT_MAX, INT_MIN, INT_MIN};
        
        
        int len = wallpaper[y].size();

        for (int x = 0; x < len; x++)
        {
            if (wallpaper[y][x] == '#')
            {
                
                
                if (x < point[1]) point[1] = x;
                if (x > point[3]) point[3] = x;
                if (y < point[0]) point[0] = y;
                if (y > point[2]) point[2] = y;
            }
        }
    }

    // x2, y2는 +1 
    point[2]++;
    point[3]++;

    return point;
}