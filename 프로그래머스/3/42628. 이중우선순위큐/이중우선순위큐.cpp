#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> split(string str){
    istringstream its(str);
    vector<string> a;
    string buffer;
    
    while(getline(its,buffer,' ')) a.push_back(buffer);
        
    return a;
}
class Queue{
public:
    vector<int> vec;
    
    void Sort()
    {
        sort(vec.begin(),vec.end(),greater<int>()); 
    }
    
    int Size()
    {
        return vec.size();
    }
    bool IsEmpty()
    {
        return vec.size()==0;
    }

    void Pop_front()
    {    
        vec.erase(vec.begin());
    }
    void Pop_back()
    {
        vec.erase(vec.end()-1);
    }
    
    void Push(int x)
    {
        vec.push_back(x);
    }
    
    int Front()
    {
        return vec[0];    
    }
    
    int Back()
    {
        return vec[vec.size() - 1];
    }
};

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    Queue q;
    
    for(string op : operations)
    {
        vector<string> OP=split(op);
        
        if(OP[0]=="I")
        {
            int x = stoi(OP[1]);
            q.Push(x);  
        
        }
        
        else if(OP[0]=="D")
        {     
            if(true == q.IsEmpty()) continue;
            
            if(OP[1]=="-1")
            {
               //cout<<"Min: "<<q.Back()<<" ";
                q.Pop_back();
                // 최솟값 삭제
            }
            else if(OP[1]=="1")
            {
                //cout<<"Max: "<<q.Front()<<" ";
                q.Pop_front();
                // 최댓값 삭제
            }
        }
        
        q.Sort();
    }
    
    if(q.IsEmpty())
    {
        answer.push_back(0);
        answer.push_back(0); 
    }
    else{
        answer.push_back(q.Front());
       answer.push_back(q.Back()); 
    }
       
 
    return answer;
}