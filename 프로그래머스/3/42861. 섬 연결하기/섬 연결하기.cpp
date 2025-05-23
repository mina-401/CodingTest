#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> parent;


int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); // 경로 압축
}

void unite(int a,int b)
{
    a=find(a);
    b=find(b);
    
    if(a!=b) parent[b]=a;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    parent.resize(n);
    for (int i = 0; i < n; ++i) parent[i] = i; //초기화
    
    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    });
    
    

    for(vector<int> cost : costs)
    {
        int i=cost[0];
        int j=cost[1];
        int c=cost[2];
        
        int Parent_i=find(i);
        int Parent_j=find(j);
        
        if(false == (Parent_i==Parent_j))
        {
            parent[Parent_j]=Parent_i;
            answer+=c;
        }
     
    }
    
    return answer;
}