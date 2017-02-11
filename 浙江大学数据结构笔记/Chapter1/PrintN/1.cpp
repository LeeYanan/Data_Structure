#include <stdio.h>

void Print_for(int N);
void Print_recur(int N);

int main()
{
	// 正常工作
	//Print_for(10000);
	// 当N去取 10,000 时，崩溃
	Print_recur(1000);
}

// for循环方法
// 推荐
void Print_for(int N)
{
    int i;
    for (i = 1; i <= N; i++)
    {
        printf("%d\n", i);
    }   
}

// 递归方法
// 缺点：占用大量内存，当N太大是会爆掉，且耗时间
// 不推荐
void Print_recur(int N)
{
    if (N)
    {
        Print_recur(N - 1);
        printf("%d\n", N);
    }
}