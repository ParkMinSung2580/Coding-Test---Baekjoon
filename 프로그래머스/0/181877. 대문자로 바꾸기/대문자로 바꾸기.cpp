#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    int count = myString.length();
        
    while(count--){
        if(myString[count] > 96)
        {
            myString[count] -= 32;
        }
    }
    answer = myString;
    return answer;
}