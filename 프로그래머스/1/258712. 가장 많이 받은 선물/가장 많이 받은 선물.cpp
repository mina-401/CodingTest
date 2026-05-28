#include <string>
#include <vector>

using namespace std;


int find_index(const vector<string>& friends, const string& name) {
    for (int i = 0; i < (int)friends.size(); i++) {
        if (friends[i] == name) return i;
    }
    return -1;
}

int solution(vector<string> friends, vector<string> gifts) {

    int answer = 0;

	int friends_len = friends.size();
	int gifts_len = gifts.size();

    int give[51][51] = { };
    int gift_index[51] = { };
	int receive[51] = { };

	//선물 주고받은 횟수 계산
    for (const string& gift : gifts) {
        int space = gift.find(' ');
        string giver = gift.substr(0, space);
        string receiver = gift.substr(space + 1);

        int gi = find_index(friends, giver);
        int ri = find_index(friends, receiver);

        if (gi != -1 && ri != -1) give[gi][ri]++;
    }


    //선물지수 계산
    for (int i = 0;i < friends_len;i++)
    {
		for (int j = 0;j < friends_len;j++)
		{
			gift_index[i] += give[i][j];
			gift_index[j] -= give[i][j];
		}
    }

    //다음 달 받을 선물 카운트
    for (int i = 0;i < friends_len;i++)
    {
		for (int j = i+1;j < friends_len;j++)
		{

            if (give[i][j] > give[j][i])
            {
                receive[i] += 1;
            }

			else if (give[i][j] < give[j][i])
			{
				receive[j] += 1;
			}

            else 
			{
                if (gift_index[i] > gift_index[j])
                    receive[i] += 1;
                else if (gift_index[i] < gift_index[j])
                    receive[j] += 1;
			}
		}
    }

	for (int i = 0; i < friends_len; i++)
	{

        //최대 선물 받은 횟수
		if (receive[i] > answer)
			answer = receive[i];
	}



    return answer;
}