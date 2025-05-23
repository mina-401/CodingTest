#include <string>
#include <vector>

using namespace std;
 int answer = 0;
    
void DFS(vector<int> numbers,int idx, int sum, int target)
{
    if(idx==numbers.size())
    {
        if(sum == target) answer++;
        return;
    }
    
    DFS(numbers,idx+1,sum+numbers[idx],target);
    DFS(numbers,idx+1,sum-numbers[idx],target);
}


int solution(vector<int> numbers, int target) {
   
    DFS(numbers,0,0,target);
    
    return answer;
}