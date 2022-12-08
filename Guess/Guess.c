#include <stdio.h>
#include <time.h>

int main()
{
    printf("Finger-guessing in C (c) 2022 goEval\n");
    printf("enter 0 or Ctrl-C to exit\n");
    // 以当前时间为随机数种子
    srand((unsigned)time(NULL));
    // 字符串数组
    char *str[3] = {"Rock", "Paper", "Scissors"};
    printf("How many times you want to play?");
    int times, win = 0, lose = 0, same = 0, played = 0;
    scanf_s("%d", &times);
    for (int i = 0; i < times; i++) {
        if (win > times / 2) {
            printf("\033[0m\033[1;32m%s\033[0m", "You win the whole game.\n");
            goto exit;
        }
        if (lose > times / 2) {
            printf("\033[0m\033[1;31m%s\033[0m", "You lose the whole game.\n");
            goto exit;
        }
        printf("1.Rock 2.Paper 3.Scissors\n");
        // 进行随机，通过取余来控制随机数在1-3之间
        int chooice, computer = rand() % 3 + 1;
        scanf_s("%d", &chooice);
        if (chooice > 3 || chooice < 1) {
            printf("\033[0m\033[1;31m%s\033[0m", "Invalid input.\n");
            goto exit;
        }
        played++;
        printf("%s vs %s\n", str[chooice - 1], str[computer - 1]);
        if (chooice == computer) {
            printf("\033[0m\033[1;33m%s\033[0m", "Same.\n");
            same++;
            continue;
        }
        // 进行输赢判断
        switch (chooice) {
        case 0:
            goto exit;
        case 1:
            if (computer == 2)
                goto lose;
            else
                goto win;
        case 2:
            if (computer == 3)
                goto lose;
            else
                goto win;
        case 3:
            if (computer == 1)
                goto lose;
            else
                goto win;
        }
        lose:
        printf("\033[0m\033[1;31m%s\033[0m", "You lose.\n");
        lose++;
        continue;
        win:
        printf("\033[0m\033[1;32m%s\033[0m", "You win.\n");
        win++;
        continue;
    }
    exit:
    printf("You played %d times, win %d times and lose %d times.\n", played, win, lose);
    return 0;
}
