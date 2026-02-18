#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string FormatString(int input)
{
    int minute = input / 60;
    int second = input % 60;
    
    string m = (minute < 10 ? "0" : "") + to_string(minute);
    string s = (second < 10 ? "0" : "") + to_string(second);
    
    return m + ":" + s;
}

int FormatInterger(string input)
{
    size_t pos = input.find(':');
   
    int minute = std::stoi(input.substr(0, pos));
    int second = std::stoi(input.substr(pos + 1));
    
    return (minute * 60) + second;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    //Max 99:99 Min 00:00
    //: 단위로 나눠서 판별해야한다. 한자리수 Interger변환, 인티저 값을 string으로 다시 format해줘야함.
    
    int video_len_Int = FormatInterger(video_len);
    int currentPos = FormatInterger(pos);
    int op_Start_Int = FormatInterger(op_start);
    int op_End_Int = FormatInterger(op_end);
    
    if(currentPos >= op_Start_Int && currentPos < op_End_Int)
        currentPos = op_End_Int;
    
    for(auto cm : commands)
    {
        if(cm == "next")
        {
            currentPos = clamp(currentPos + 10,0,video_len_Int);
        }
        else if(cm == "prev")
        {
            currentPos = clamp(currentPos - 10,0,video_len_Int);
        } 
        
        if(currentPos >= op_Start_Int && currentPos <= op_End_Int)
        {   
            currentPos = op_End_Int;
        }
    }
    
    return FormatString(currentPos);   
}