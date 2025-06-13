#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> results;
const string AEIOU = "AEIOU";
int len=AEIOU.length();

void dfs(int cnt, string str)
{
    if(cnt>=len) return;
     for(int i=0;i<len;i++)
    {
        results.push_back(str+AEIOU[i]);
        dfs(cnt+1,str+AEIOU[i]);
    }
}

int solution(string word) {
    int answer = 0;
    int cnt=0;
    
    dfs(cnt,"");
    
    
    answer=find(results.begin(), results.end(), word) - results.begin()+1;
    
    return answer;
}