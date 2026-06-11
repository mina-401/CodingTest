#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;

	unordered_map<string, int> yearning_map;
	for (int i = 0; i < name.size(); i++) {
		yearning_map[name[i]] = yearning[i];
	}

	for (vector<string> photo_item : photo) {

		int total_yearning = 0;
		for (string person : photo_item) {
			if (yearning_map.find(person) != yearning_map.end()) {
				total_yearning += yearning_map[person];
			}
		}
		answer.push_back(total_yearning);	

	}

    return answer;
}