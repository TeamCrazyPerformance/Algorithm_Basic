#include<stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int count = 0;
    int num = 666;

    while (1) {
        int a = 0;
        int cur = num;
        while (cur > 0) {
            int b = cur % 10;
            if (b == 6) {
                a++;
            }
            else {
                a = 0;
            }
            if (a == 3) {
                count++;
                break;
            }
            cur = cur / 10;
        }
        if (count == n) {
            break;
        }
        num++;
    }
    printf("%d\n", num);
}
