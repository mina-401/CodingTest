#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    
    
    for(int i=0;i<priorities.size();i++){
        q.push({i,priorities[i]}); //(0,2),(1,1),(2,3),(3,2) 
        pq.push(priorities[i]); //3,2,2,1
    }
    
    while(1)
    {
        pair<int,int> front=q.front();
        q.pop();
        
        //q 프로세스에서 가장 우선순위가 높다.
        if(front.second==pq.top())
        {
            // 현재 프로세스가 찾고 있는 프로세스 번호
            if(front.first==location)
            {
                break;
            }
            else
            {
                pq.pop();
                answer++;
            }
                
        }
        //다시 대기 프로세스로
        else
        {
           q.push({front.first,front.second});
        }
    }
    return answer;
}