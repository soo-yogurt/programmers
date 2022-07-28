#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

double Distance(const int x1, const int y1, const int x2, const int y2);
void KeyNumber1_4_7(const int number, int* x, int* y, string* answer);
void KeyNumber3_6_9(const int number, int* x, int* y, string* answer);
void KeyNumber2_5_8_0(const int number, const string hand, int* l_x, int* l_y, int* r_x, int* r_y, string* answer);

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int l_x = -1, l_y = 0, r_x = 1, r_y = 0;


    for (unsigned int i = 0; i < numbers.size(); i++) {
        KeyNumber1_4_7(numbers.at(i), &l_x, &l_y, &answer);
        KeyNumber3_6_9(numbers.at(i), &r_x, &r_y, &answer);
        KeyNumber2_5_8_0(numbers.at(i), hand, &l_x, &l_y, &r_x, &r_y, &answer);
    }

    return answer;
}


double Distance(const int x1, const int y1, const int x2, const int y2)
{
    return ceil(sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)));
}

void KeyNumber1_4_7(const int number, int* x, int* y, string* answer)
{
    if (number == 1)
    {
        *x = -1;
        *y = 3;
        *answer += 'L';
    }
    else if (number == 4)
    {
        *x = -1;
        *y = 2;
        *answer += 'L';
    }
    else if (number == 7)
    {
        *x = -1;
        *y = 1;
        *answer += 'L';
    }
}

void KeyNumber3_6_9(const int number, int* x, int* y, string* answer)
{
    if (number == 3)
    {
        *x = 1;
        *y = 3;
        *answer += 'R';
    }
    else if (number == 6)
    {
        *x = 1;
        *y = 2;
        *answer += 'R';
    }
    else if (number == 9)
    {
        *x = 1;
        *y = 1;
        *answer += 'R';
    }
}
void KeyNumber2_5_8_0(const int number, const string hand, int* l_x, int* l_y, int* r_x, int* r_y, string* answer)
{
    double distance_L, distance_R;
    int x = 0, y;
    bool key = false;

    if (number == 2)
    {
        y = 3;
        key = true;
    }
    else if (number == 5)
    {
        y = 2;
        key = true;
    }
    else if (number == 8)
    {
        y = 1;
        key = true;
    }
    else if (number == 0)
    {
        y = 0;
        key = true;
    }

    if (key == true) {
        distance_L = Distance(x, y, *l_x, *l_y);
        distance_R = Distance(x, y, *r_x, *r_y);

        if (distance_L > distance_R)
        {
            *answer += 'R';
            *r_x = x;
            *r_y = y;
        }
        else if (distance_L < distance_R)
        {
            *answer += 'L';
            *l_x = x;
            *l_y = y;
        }
        else if (distance_L == distance_R)
        {
            if (hand == "left") {
                *answer += 'L';
                *l_x = x;
                *l_y = y;
            }
            else if (hand == "right")
            {
                *answer += 'R';
                *r_x = x;
                *r_y = y;
            }
        }
    }
}