#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len�� �迭 lottos�� �����Դϴ�.
// win_nums_len�� �迭 win_nums�� �����Դϴ�.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(sizeof(int) * 2);
    int blank_count = 0;
    int win_count = 0;

    for (int i = 0; i < lottos_len; i++)
    {
        if (lottos[i] == 0)
        {
            blank_count++;
        }
        else
        {
            for (int j = 0; j < lottos_len; j++)
            {
                if (lottos[i] == win_nums[j])
                {
                    win_count++;
                }
            }
        }
    }

    answer[0] = 7 - (win_count + blank_count);
    answer[1] = 7 - win_count;

    if (answer[0] == 7)
    {
        answer[0] = 6;
    }

    if (answer[1] == 7)
    {
        answer[1] = 6;
    }

    return answer;
}