#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 17;
vector<int> graph[MAX];
int answer = 0;

void DFS(int sheep, int wolf, int current, vector<int>& info, vector<int> nextNodes) {
    if (info[current] == 0) sheep++; // 양
    else wolf++; // 늑대

    if (wolf >= sheep) return; // 게임 오버 조건
    answer = max(answer, sheep); // 최대 양 갱신

    // 현재 노드에서 갈 수 있는 노드들을 nextNodes에 넣음
    vector<int> candidates = nextNodes;
    // current 노드는 제거하고, children 추가
    candidates.erase(remove(candidates.begin(), candidates.end(), current), candidates.end());
    for (int child : graph[current]) {
        candidates.push_back(child);
    }

    for (int next : candidates) {
        DFS(sheep, wolf, next, info, candidates);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
    }

    DFS(0, 0, 0, info, {});

    return answer;
}
