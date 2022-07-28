#include <string>
#include <vector>
#include <cstring>
using namespace std;

string solution(int n) {
    string answer = "";
    vector<string> temp;
    //remainder
    int r;

    while (n > 0)
    {
        r = n % 3;
        if (r == 0)
        {
            temp.push_back("4");
            n -= 1;
        }
        else
        {
            temp.push_back(to_string(r));
        }
        n /= 3;
    }

    return answer;
}