#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// id_list_len�� �迭 id_list�� �����Դϴ�.
// report_len�� �迭 report�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.

    int* answer = (int*)malloc(sizeof(int) * id_list_len);
    memset(answer, 0, sizeof(int) * id_list_len);

    // �� �̿��ڰ� �Ű� ���� Ƚ���� ������ �迭
    int sum[id_list_len];
    memset(sum, 0, sizeof(sum));

    // �� �̿��ڰ� �Ű��� ����� �������� ǥ���� �迭
    // �Ű� ���� ��� ��� ��ġ�� ���� 1�� �Ѵ�.
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