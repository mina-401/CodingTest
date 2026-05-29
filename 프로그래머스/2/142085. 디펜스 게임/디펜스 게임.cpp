#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    if(k>=enemy.size()) return enemy.size();
    
    int low=1;
    int high=enemy.size();
    
    while(low<=high){
        int mid=(low+high)/2;
        vector<int> temp(enemy.begin(),enemy.begin()+mid); //중간씩 탐색
        
        sort(temp.rbegin(),temp.rend()); //내림차순 정렬해야함
        
        long long sum=0; //지금까지 쓴 병사 갯수 확인
        
        for(int i=k;i<temp.size();i++) sum+=temp[i]; 
        
        
        if(n-sum>=0)
        {
            //버틸수있음. 
            low=mid+1;
            answer=mid;
        }
        else{
            high=mid-1;
        }
        
    }
    
    
    
    return answer;
}