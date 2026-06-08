#include <string>
#include <vector>

using namespace std;

int limit(int schedule) {
    int h = schedule / 100;
    int m = schedule % 100;
    m += 10;
    if (m >= 60) {
        h += 1;
        m -= 60;
    }
    return h * 100 + m;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    int staff = schedules.size();

    //startday부터 10분 이내에 출근한 직원 수 구하기,
    //단 토,일은 제외  == 6,7 제외

    for (int i = 0; i < staff; i++) {
        vector<int> logs = timelogs[i];

        int ok = 0;
        int day = startday;

        for (int t = 0; t < logs.size(); t++) {

            if (day == 6 || day == 7) {
                day = (day % 7) + 1;
                continue;
            }

            //출근 인정시간 내에 도착함
            if (limit(schedules[i]) >= logs[t])
            {

                ok++;
            }
            day = (day % 7) + 1;
        }

        if (5 == ok) {
            answer++;
        }
    }

    return answer;
}