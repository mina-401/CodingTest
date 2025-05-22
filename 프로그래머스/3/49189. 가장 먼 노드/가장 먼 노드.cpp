#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> Graph[n+1];
    vector<int> Dist(n+1, -1);
    queue<int> Queue;
        
        
    for(vector<int> e : edge)
    {
        Graph[e[0]].push_back(e[1]);
        Graph[e[1]].push_back(e[0]);
        
    }
    
    Dist[1]=0;
    Queue.push(1);
    
    while(!Queue.empty())
    {
        int Cur=Queue.front();
        Queue.pop();
        
        for (int Next : Graph[Cur]) {
            if (Dist[Next] == -1) {
                Dist[Next] = Dist[Cur] + 1;
                Queue.push(Next);
            }
        }
    }
    
    int MaxNode=*max_element(Dist.begin(),Dist.end());
    
    for(int i=1;i<n+1;i++)
    {
        if(MaxNode == Dist[i])
        {
            answer ++;
        }
    }
    
    return answer;
}