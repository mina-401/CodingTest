#include <string>
#include <vector>

using namespace std;



bool IsEqual(vector<vector<int>> arr)
{
    
    int size= arr.size();
   for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[i][j] != arr[i][j + 1] || arr[i][j] != arr[i + 1][j] || arr[i][j] != arr[i + 1][j + 1]) return false; 
        }
    }
    
    return true; 
}

vector<int> Div(int size,vector<vector<int>> arr)
{
    
    vector<int> answer(2, 0); // 0 인덱스 : 0갯수, 1인덱스: 1갯수
    
    // 내부가 원소 하나 
    if (1==size) {
        answer[arr[0][0]] += 1; 
        return answer;
    }
    
    // 내부가 같은 숫자로만 이루어짐
    if (true == IsEqual(arr)) {
        answer[arr[0][0]] += 1;
        return answer;
    }
    else
    {
        int half = arr.size()/2;
     
        vector<vector<int>> LeftTop(half,vector<int>(half,0)); // 내부 왼쪽 위
        vector<vector<int>> RightTop(half,vector<int>(half,0)); // 내부 오른쪽 위
        vector<vector<int>> LeftBottom(half,vector<int>(half,0)); // 내부 왼쪽 아래
        vector<vector<int>> RightBottom(half,vector<int>(half,0)); // 내부 오른쪽 아래

        vector<int> result;

        for(int i=0;i<half;i++)
        {
            for(int j=0;j<half;j++)
            {
                LeftTop[i][j]=arr[i][j];
                LeftBottom[i][j]=arr[i][j+half];
                RightTop[i][j]=arr[i+half][j];
                RightBottom[i][j]=arr[i+half][j+half];
            }
        }

        result=Div(half,LeftTop);
        answer[0]+=result[0];
        answer[1]+=result[1];

        result=Div(half,LeftBottom);
        answer[0]+=result[0];
        answer[1]+=result[1];

        result=Div(half,RightTop);
        answer[0]+=result[0];
        answer[1]+=result[1];

        result=Div(half,RightBottom);
        answer[0]+=result[0];
        answer[1]+=result[1];


        return answer;
    }
        
   
}

vector<int> solution(vector<vector<int>> arr) {
    
 
    vector<int> result;
    
    result = Div(arr.size(),arr);
    return result;
}