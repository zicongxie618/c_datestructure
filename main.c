#include <stdio.h>

int main(void) {
    int a, b;

    printf("=== 简易计算器 ===\n");
    printf("请输入第一个整数: ");
    scanf("%d", &a);

    printf("请输入第二个整数: ");
    scanf("%d", &b);

    printf("\n--- 计算结果 ---\n");
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    if (b != 0)
        printf("%d / %d = %.2f\n", a, b, (float)a / b);
    else
        printf("除数不能为 0\n");

    printf("\n按 Enter 退出...");
    getchar();
    getchar();
    return 0;
}
