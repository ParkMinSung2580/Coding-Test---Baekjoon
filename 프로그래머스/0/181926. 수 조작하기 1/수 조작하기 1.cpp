#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    int answer = 0;
    
    for(auto a : control)
    {
        switch(a)
        {
            case 'w':
                n++; break;
            case 'a':
                n -= 10; break;
            case 's':
                n--; break;
            case 'd':
                n += 10; break;
            default:
                break;
        }
    }
    return n;
}