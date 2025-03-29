#include <stdio.h>
#include <stdbool.h>

struct Solution {
  int value;  // 価値
  int weight; // 重量
  char baggage[20]; // 荷物の名称
};

const int num = 6; // 荷物の総個数
int limit_weight = 8; // 最大重量
struct Solution object[6] = {
  {700, 4, "A"}, 
  {400, 3, "B"}, 
  {800, 5, "C"}, 
  {1000, 6, "D"}, 
  {450, 2, "E"}, 
  {500, 1, "F"}
};

int main(void) {
    // 重量 i までの最大価値を記録する配列
    int dp[9] = {0};
    bool chosen[6][9]; // 荷物が選ばれたか追跡する配列
    for (int i = 0; i < num; i++) {
        for (int w = 0; w <= limit_weight; w++) {
            chosen[i][w] = false;
        }
    }

    // 全ての荷物についてループ
    for (int i = 0; i < num; i++) {
        // 重い荷物から逆順に dp を更新する
        for (int w = limit_weight; w >= object[i].weight; w--) {
            if (dp[w - object[i].weight] + object[i].value > dp[w]) {
                dp[w] = dp[w - object[i].weight] + object[i].value;
                // 荷物が選ばれたことを追跡
                for (int k = 0; k < num; k++) {
                    chosen[k][w] = chosen[k][w - object[i].weight]; // これまで選ばれた荷物を引き継ぐ
                }
                chosen[i][w] = true; // 現在の荷物を選択したとマーク
            }
        }
    }

    // 最大価値を出力
    printf("Optimal Solution Value: %d\n", dp[limit_weight]);

    // 選ばれた荷物を出力
    printf("Chosen baggage: ");
    for (int i = 0; i < num; i++) {
        if (chosen[i][limit_weight]) {
            printf("%s ", object[i].baggage);
        }
    }
    printf("\n");

    return 0;
}
