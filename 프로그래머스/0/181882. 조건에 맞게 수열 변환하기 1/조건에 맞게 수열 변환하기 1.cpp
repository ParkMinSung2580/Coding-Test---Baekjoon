#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    /*for(int v : arr)
    {
        if(v >= 50 && v % 2 == 0)
            v = v / 2;
        if(v <= 50 && v % 2 != 0)
            v = v*2; 
    }*/
    
    for(int i =0; i < arr.size(); i++)
    {   
        if(arr[i] >= 50 && arr[i] % 2 == 0)
            arr[i] /= 2;
        else if(arr[i] <= 50 && arr[i] % 2 == 1)
            arr[i] *= 2;
    }
    answer = arr;
    return answer;
}