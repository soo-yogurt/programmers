#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// id_list_len은 배열 id_list의 길이입니다.
// report_len은 배열 report의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.

    int* answer = (int*)malloc(sizeof(int) * id_list_len);
    memset(answer, 0, sizeof(int) * id_list_len);

    // 각 이용자가 신고 받은 횟수를 저장할 배열
    int sum[id_list_len];
    memset(sum, 0, sizeof(sum));

    // 각 이용자가 신고한 대상이 누구인지 표시할 배열
    // 신고를 했을 경우 대상 위치의 값을 1로 한다.
    int data_box[id_list_len][id_list_len];
    memset(data_box, 0, sizeof(data_box));

    for (int i = 0; i < report_len; i++) {
        char* pos;
        pos = strtok(report[i], " ");
        int j;
        for (j = 0; j < id_list_len; j++) {
            if (strcmp(pos, id_list[j]) == 0)
            {
                break;
            }
        }

        pos = strtok(NULL, " ");

        int t;
        for (t = 0; t < id_list_len; t++)
        {
            if (strcmp(pos, id_list[t]) == 0)
            {
                break;
            }
        }
        data_box[j][t] = 1;
    }

    for (int i = 0; i < id_list_len; i++)
    {
        for (int j = 0; j < id_list_len; j++)
        {
            sum[i] += data_box[j][i];
        }
        for (int j = 0; j < id_list_len; j++)
        {
            if (sum[i] >= k && data_box[j][i] == 1)
            {
                answer[j] += 1;
            }
        }
    }


    return answer;
}