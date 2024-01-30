#include <iostream>

using namespace std;

void MUL(int src, int dst, int *pro)
{
    bool sign = ((src ^ dst) < 0); // 判断符号

    int res = 0; // 结果
    int muled = abs(src); // 被乘数
    int mul = abs(dst); // 乘数

    for (int i = 10; i >= 0; i--) { // 类似贪心算法, 移位求解
        if ((1 << i) <= dst) {
            res = res + muled << i;
            mul = mul - (1 << i);
        }
    }
    sign ? (*pro = -res) : (*pro = res);
}

void DIV(int src, int dst, int *quo, int *rem)
{
    bool sign = ((src ^ dst) < 0); // 判断符号

    int res = 0; // 结果
    int dived = abs(src); // 被除数
    int div = abs(dst); // 除数

    for (int i = 10; i >= 0; i--) {
        if (dived >> i >= dst) {  // 类似贪心算法，移位求解
            res = res + (1 << i);
            dived = dived - (div << i);
        }
    }

    sign ? (*quo = -res) : (*quo = res);
    *rem = dived;
}

// test
int main()
{
    int src, dst;
    int* pro = (int*)malloc(sizeof(int));
    int* quo = (int*)malloc(sizeof(int));
    int* rem = (int*)malloc(sizeof(int));

    printf("请输入 src: ");
    scanf("%d", &src);
    printf("请输入 dst: ");
    scanf("%d", &dst);

    MUL(src, dst, pro);
    printf("积为 %d\n", *pro);
    DIV(src, dst, quo, rem);
    printf("商为 %d，余数为 %d\n", *quo, *rem);
    return 0;
}

