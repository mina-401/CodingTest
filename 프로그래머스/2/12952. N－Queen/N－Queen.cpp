#include <string>
#include <vector>
#include <cmath>

using namespace std;

int Chess[12];
int answer = 0;

bool IsMove(int depth)
{
    for(int i=0;i<depth;i++)
    {
        // 같은 열에 있음 또는 대각선에 있음
        if(Chess[depth] == Chess[i] || abs(Chess[depth]-Chess[i])==depth-i) return false;
        
    }
    return true;
}
void dfs(int n, int depth)
{
    if(depth==n)
    {
        answer++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        Chess[depth]=i;
        if(IsMove(depth)==true){
            dfs(n,depth+1);
        }
        
    }
}
int solution(int n) { 
    dfs(n,0);
    return answer;
}