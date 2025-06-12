#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n,vector<int>(n,0)); // 0 초기화

    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    
    int dir =0 ; // 0 ,1 , 2, 3
    
    int x=0;
    int y=0;
    
    for(int i = 1; i<= n*n; i++)
    {
        answer[x][y]=i;
        
        int nx = x+dx[dir];
        int ny= y+dy[dir];
        
        if(nx<0 || ny < 0 || nx>=n || ny>=n || answer[nx][ny] !=0 )
        {
            dir= (dir + 1) % 4; // 오 -> 아래->왼 -> 위 순서로
            
            nx = x+dx[dir];
            ny= y+dy[dir];
        }
        
        x=nx;
        y=ny;
    }
    return answer;
}