#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    // 비동의 --- 동의
    //1 2 3 (4) 5 6 7
    // 3 2 1 0 1 2 3

	//성격유형
	// R T C F J M A N
	// R,T 중 하나 선택
	// C,F 중 하나 선택
	// J,M 중 하나 선택
	// A,N 중 하나 선택
	
	
	map<int,int> score_map = {
		{1, 3}, //1: first에 3점
		{2, 2}, //2: first에 2점
		{3, 1}, //3: first에 1점
		{4, 0}, //4: 점수 없음
		{5, 1}, //5: second에 1점
		{6, 2}, //6: second에 2점
		{7, 3}  //7: second에 3점

	};
	map<char, int> type_score_map;

	type_score_map['R'] = 0;
	type_score_map['T'] = 0;
	type_score_map['C'] = 0;
	type_score_map['F'] = 0;
	type_score_map['J'] = 0;
	type_score_map['M'] = 0;
	type_score_map['A'] = 0;
	type_score_map['N'] = 0;

    int n = survey.size();

    for (int i = 0; i < n; i++)
    {
		string survey_item = survey[i];

		char first = survey_item[0];
		char second = survey_item[1];

		int choice = choices[i]; //1~7
		
		int score = score_map[choice]; // choice에 따른 점수

		if (choice < 4) {
			//first에 점수 부여
			type_score_map[first] += score;
			
		}
		else if (choice > 4) {
			//second에 점수 부여
			type_score_map[second] += score;
		}
    }

	// R,T 중 하나 선택
	if (type_score_map['R'] >= type_score_map['T']) {
		answer += 'R';
	}
	else {
		answer += 'T';
	}

	// C,F 중 하나 선택
	if (type_score_map['C'] >= type_score_map['F']) {
		answer += 'C';
	}
	else {
		answer += 'F';
	}

	// J,M 중 하나 선택
	if (type_score_map['J'] >= type_score_map['M']) {
		answer += 'J';
	}
	else {
		answer += 'M';
	}

	// A,N 중 하나 선택
	if (type_score_map['A'] >= type_score_map['N']) {
		answer += 'A';
	}
	else {
		answer += 'N';
	}

    return answer;
}