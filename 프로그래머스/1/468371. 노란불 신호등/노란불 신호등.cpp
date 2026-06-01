#include <string>
#include <vector>

using namespace std;

// 최대공약수를 구하는 함수 (유클리드 호제법)
int gcd(int a, int b)
{
    while (b)
    {
        int t = a % b; 
        a = b;         
        b = t;         
    }

    return a;
}

// 최소공배수(LCM)를 구하는 함수
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int solution(vector<vector<int>> signals)
{
    // 모든 신호등 주기의 최소공배수를 저장할 변수
    int limit = 1;

    // 모든 신호등 순회
    for (vector<int> v : signals)
    {
        // 한 신호등의 전체 주기
        int sum = v[0] + v[1] + v[2];

        // 현재 limit와 해당 신호등 주기의 최소공배수 계산
        limit = lcm(limit, sum);
    }

    // 1초부터 limit 직전까지 확인
    for (int i = 1; i <= limit; i++)
    {
        // 현재 시간이 모든 신호등이 노란불인지 여부
        bool yellow = true;

        // 모든 신호등 검사
        for (int j = 0; j < signals.size(); j++)
        {
            // 현재 신호등의 전체 주기
            int cycle = signals[j][0] + signals[j][1] + signals[j][2];

            // 현재 시간이 노란불 구간에 있는지 확인하기 위한 값
            int temp = (i - signals[j][0]) % cycle;

            // 노란불 구간에 포함되면 다음 신호등 검사
            if (temp > 0 && temp <= signals[j][1])
                continue;

            yellow = false;
        }

        if (yellow)
            return i;
    }
    return -1;
}