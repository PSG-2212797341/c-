#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// 例1：输入三个值后，将其按从小到大的顺序打印出来。
// 方法：先将a与b、c相比较，使最大值为a，然后将b、c相比，其大者放入b中储存。
/* int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d%d%d",&a,&b,&c);           //这里输入的时候需要每次写一个数字后需要一个空格才能运行，不然连在一起系统可能会判定为一个数。
    if(a < b)
    {
        int d = a;                      //利用中间变量用来交换两个数时的一个桥梁。
        a = b;
        b = d;
    }
    if(a < c)
    {
        int d = a;
        a = c;
        c = d;
    }
    if(b < c)
    {
        int d = b;
        b = c;
        c = d;
    }
    printf("%d %d %d",a,b,c);
    return 0;
} */

//例2：打印出数字1-100之间为3的倍数的数字。
/* int main()
{
    int i = 0;
    for(i = 1; i <= 100; i++)
    {
        if(i%3 == 0)
        {
            printf("%d ",i);
        }
    }
    return 0;
} */

//例3：求两个数的最大公约数。
// 方法：辗转相除法：将两个数m、n进行取余数得到一个r，然后将r赋值给m、N中的最大值，后用m、n其最小值再进行取余数运算，直到余数为0为止。
/* int main()
{
    int m = 0;
    int n = 0;
    int r = 0;
    printf("请输入两个数：");
    scanf("%d%d",&m,&n);
    while (r = m%n)
    {
        m = n;
        n = r;
    }
    printf("最大公约数为：%d ",n);
    return 0;
} */

//例4：打印出1000-2000年之间为闰年的年份。
/* int main()
{
    int i = 0;
    for(i = 1000; i <= 2000; i++)
    {
        if((i%4 == 0 && i%100 != 0) || i%400 == 0)          //条件1：能被4整除但不能被100整除；条件2：能被400整除。
        {
            printf("%d ",i);
        }
    }
    return 0;
}  */

// 例5：打印100-200之间的所有素数（只能被1和它本身整除的数）
// 方法：试除法：最最最差的方法 -- 优化的话可以参考《素数求解的n种境界》
/* int main()
{
    int i = 0;
    int j = 0;
    for(i = 100; i < 200; i++)
    {
        for(j = 2; j < i; j++)              //因为素数只能被1和它本身（i）整除，那么就不能被2 - i-1范围内的任意一个数整除，则此处产生2 - i-1之间的数。
        {
            if (i%j == 0)
            {
                break;                      //如果被整除了，那么这个数不是素数。
            }
        }
        if (j == i)                         //此处表示i只能被它本身整除，所以是素数。
        {
            printf("%d ",i);
        }   
    }
    return 0;
} */

// 例6：数出1-100之间包含数字9的数。
// 方法：两种情况：1、9在十位上，则/9会商9；2、9在个位上，则%10会余9。
/* int main()
{
    int i = 0;
    int num = 0;
    for(i = 1; i <= 100; i++)
    {
        if (i%10 == 9)
        {
            num++;
        }
        else if (i/10 == 9)
        {
            num++;
        }
    }
    printf("%d",num);
    return 0;
} */

//例7：计算1/1-1/2+1/3-...-1/100的值。
/* int main()
{
    int i = 0;
    double num = 0.0;                   //因为下面num中储存的数为小数，所以此处设为double。
    int f = 1;
    for ( i = 1; i <= 100; i++)
    {
        num += f*1.0/i;                 //a/b若两端都为整数则得到的是为整数。
        f = -f;                         //通过f、-f的方法得到+、-的符号。
    }
    printf("%lf",num);                  //打印浮点数使用%lf。
    return 0;
} */

//例8：求十个整数的最大值。
// 方法：用这十个数的第一个数与其他的9个数一一比较，如果小于其他数则将最大数的那个数赋值给我的第一个数，一直把九个数比完，最大数就出来了。
/* int main()
{
    int i = 0;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int max = arr[0];
    int sz = sizeof(arr)/sizeof(arr[0]);
    for(i = 1; i < sz; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("max = %d",max);
    return 0;
} */

// 例9：打印乘法9*9的口诀表：
/* int main()
{
    int i = 0;
    int j = 0;
    for(i = 1; i <= 9; i++)                 //打印9行。
    {
        for(j = 1; j<=i; j++)               //打印9列。
        {
            printf("%d*%d=%-2d ",i,j,i*j);      //%-2d：打印的时候会打印两位数字，如果不够两位用空格补齐。“-”的作用为左对齐，默认为右对齐。
        }
        printf("\n");                       //打印完一行后换行。
    }
    return 0;
} */

//例10：写一个猜数字的小游戏。
void load()
{
    printf("菜单：\n");
    printf("0、退出游戏\n");
    printf("1、开始游戏\n");
}

void game()
{
    int ret = 0;
    int guess = 0;
    ret = rand()%100+1;
    while (1)
    {
        printf("您觉得计算机给出的两位数是：");
        scanf("%d",&guess);
        if(guess > ret)
        {
            printf("提示：猜大了！！！\n");
        }
        else if(guess < ret)
        {
            printf("提示：猜小了！！！\n");
        }
        else
        {
            printf("提示：恭喜您，猜对了！！！\n");
            break;
        }
        printf("\n");
    }
}

int main()
{
    
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        load();
        printf("请选择：");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("已退出游戏");
            break;
        default:
            printf("输入错误，请重新选择\n");
            break;
        }
        printf("\n");
    } while (input);
    return 0;
}
