#include <string>
#include <vector>
#include <map>


using namespace std;



vector<string> solution(vector<string> players, vector<string> callings) {
	vector<string> answer;

	map<string, int> rank_to_player;

	for (int i = 0; i < players.size(); i++) {
		rank_to_player[players[i]] = i;
	}

	for (string calling : callings) {
		int idx = 0;
		auto it = rank_to_player.find(calling);
		if (it != rank_to_player.end()) {
			idx = it->second;
			if (idx > 0) {
				// swap players[idx]와 players[idx-1]의 등수
				string prev_player = players[idx - 1];
				players[idx - 1] = players[idx];
				players[idx] = prev_player;
				rank_to_player[players[idx]] = idx;
				rank_to_player[players[idx - 1]] = idx - 1;
			}
		}
	}

	// players 벡터가 등수 순서이므로 그대로 answer에 복사
	answer = players;
	return answer;
}