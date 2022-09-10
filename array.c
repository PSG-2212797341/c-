#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include"array.h"
// 一、一维数组：
// 1、数组的创建：
// int arr[10];             int --- 存放整型；   arr --- 数组名；   [10] --- 这里的10为数组的大小，里面放多少个元素，[]里面必须写常量表达式，不能是变量。

// 2、数组的初始化：在数组的创建同时给数组的内容一些合理的值。
/* int main()
{
    int arr[5] = {1,2,3};           //前面给了五个元素的空间，这里赋值只给了三个，后面两个值会默认初始化为0 --- 不完全初始化。
    char arr2[5] = {'a','b','c'};     //也是不完全初始化,后面两个值默认初始化为0。
    char arr3[5] = "abc";            //存放字符串的时候最后一位有一个\0。
    char arr4[] = "abcdef";         //会根据初始化的值来确定数组的大小。
    printf("%d",sizeof(arr4));      //sizeof(arr4)计算arr4所占空间的大小，单位为字节，属于操作符。
    printf("%d",strlen(arr4));      //strlen(arr4)求字符串长度：'\0'之前有多少个字符，是库函数，引用的时候需要头文件。
    return 0;
} */

// 3、一维数组的使用。（内存的存放是连续的）
// 操作符：[]：下标引用操作符。
// 例：打印出数组arr1[]里面的元素，每次只能打印一个。
/* int main()
{
    int arr[5] = {1,2,3,4,5};
    int i = 0;
    int sz = sizeof(arr)/sizeof(arr[0]);            //求数组的长度（之前写过）。
    for(i = 0; i < sz; i++)
    {
        printf("%d ",arr[i]);                       //用下标访问数组中的元素，下标起始数为0。
    }
    return 0;
} */

// 二、二维数组： --- 可以想象成为n行的一维数组。
// 1、二维数组的创建和初始化：跟一维数组类似。
/* int main()
{
    int arr[3][4];          //[3]：3行； [4]：4列；
    int arr2[3][4] = {1,2,3,4};      //表示第一行：1、2、3、4；后面的3行默认初始值为0；
    int arr3[3][4] = {{1,2},{3,4}};  //表示第一行：1、2、0、0；第二行：3，4，0，0；后面两行默认初始值为0。
    int arr4[][4] = {{1,2},{3,4}};   //表示第一行：1、2、0、0；第二行：3，4，0，0；后面两行默认初始值为0。--- 这里行号可以省略，列号不能省，不然会报错。
    printf("%d",arr2[0][0]);
    return 0;
} */

// 2、二维数组的使用：（内存的存放也是连续的）
// 例：打印出数组arr1[]里面的元素。
/* int main()
{
    int arr3[3][4] = {{1,2},{3,4}};
    int i = 0;
    for ( i = 0; i < 3; i++)
    {
        int j = 0;
        for ( j = 0; j < 4; j++)
        {
            printf("%d ",arr3[i][j]);
        }
        printf("\n");
    }
    return 0;
} */

// 三、数组作为函数参数：
// 例如：实现一个冒泡排序函数将一个整形数组排序（从小到大）。
// 冒泡排序：先把第1个数与后面的数一一比较，如果前者大于后者（要满足从小到大），就将两数交换，直到这个数不再大于后面的数/大于到后面没有数为止，此时，完成第一个数的冒泡排序，然后面的所有数都按次方式进行。
/* void bubbling(int arr[], int sz)
{
    int i = 0;
    for( i = 0 ; i < sz - 1 ; i++)          //满足我数组里面前（sz - 1）个元素能够排序，因为这里排完之后，最后一个元素的位置默认就确定了。
    {
        int j = 0;
        int k = 1;                          //这个的设置目的是：防止在循环次数结束之前已经按顺序排列时，循环不会停止，还会继续进行下去，避免浪费多余的时间。
        for(j = 0 ; j < sz - 1 - i; j++)          //减少我不必要比较的次数，因为每次排序的时候总会每个元素找到自己最终排序的位置，那么就会少比较一次（就像我10个元素，只需要比九次就可以确定所有元素的位置）。
        {
            if(arr[j] < arr[j+1])               //如果前者大于后者，交换两个数的位置。
            {
                int tem = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tem;
                k = 0;                      //如果没有完成顺序排列，那么，不好意思，循环继续，若完成，那么就该走人了。
            }
        }
        if(k == 1)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {2,1,3,5,4,6,8,9,7,0};          //10个元素。
    int sz = sizeof(arr)/sizeof(arr[0]);        //在函数外求出元素个数，因为数组传参的时候只会吧第一个元素的地址传过去，此时在函数内求数组的元素个数，就会报错。
    int i = 0;
    bubbling(arr,sz);
    for( i = 0 ; i<sz ; i++)
    {
        printf("%d ",i);
    }   
    return 0;
} */

// 四、数组名：
/* int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("%p\n",&arr);                    
    printf("%p\n",&arr[0]);                 //对数组和数组的第一个元素进行取地址，发现两个值是相等的。
    printf("%d\n",*arr);                    //对数组进行解引用得到的值是数组首元素。
} */                                           //结论：数组名就是数组首元素的地址。有两种情况除外：1、sizeof(数组名)：意义是计算整个数组的大小，（）内单独放一个数组名，数组名表示整个数组；   2、&数组名：意义是取出的整个数组的地址。数组名表示整个数组。

// 五、小游戏：
// 1、井字旗：
/* void menu()         //菜单函数：给玩家选择是开始玩游戏还是不玩游戏
{
    printf("菜单:\n");
    printf("0、退出游戏\n");
    printf("1、开始游戏\n");
    printf("\n");
}

void InitBoard(char board[ROW][COL], int row, int col)      //初始化棋盘：将数组里面的内容先填充为我想要的内容，便于之后的利用。
{
    int i = 0;
    int j = 0;
    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void DisplayBoard(char board[ROW][COL], int row, int col)       //打印棋盘
{
    int i = 0;
    for ( i = 0; i < row; i++)
    {
        int j = 0;
        for ( j = 0; j < col; j++)              //先打印棋盘的每一行（以 '字符' + '|' 的格式打印），
        {
            printf(" %c ",board[i][j]);
            if (j < col-1)                      //最后一行不打印'|'。
            {
                printf("|");
            }
        }
        printf("\n");                           
        if (i < row - 1)                        //先打印棋盘的每一列（以 '---' + '|' 的格式打印），
        {
            for ( j = 0; j < col; j++)
            {
                printf("---");
                if (j < col - 1)                //最后一行不打印'|'。
                {
                    printf("|");
                }
            }   
            printf("\n");
        }
    }
     printf("\n");
}

void PlayerMove(char board[ROW][COL],int row,int col)       //玩家移动落子的函数。
{
    int x = 0;
    int y = 0;
    printf("玩家下棋：\n");
    while (1)
    {
        printf("请输入要放入棋子的坐标：");
        scanf("%d%d",&x,&y);
        if (x>=1 && x<=row || y>=1 && y<=col)               //玩家落棋子的范围在行：1 - row；列：1 - col。的范围里面
        {
            if (board[x-1][y-1] == ' ')             //判断玩家落子的地方有没有棋子，有的话就换个地方。
            {
                board[x-1][y-1] = '*';
                break;
            }
            else
            {
                printf("此位置已有棋子,请重新输入要放入棋子的坐标！\n");
                printf("\n");
            }
        }
        else
        {
            printf("输入坐标错误,请重新输入\n");
            printf("\n");
        }
    }
}

void ComputerMove(char board[ROW][COL],int row,int col)     //电脑走旗。
{
    int x = 0;
    int y = 0;
    printf("电脑下棋：\n");
    while (1)
    {
        x = rand() % ROW;
        y = rand() % COL;                   //这里将电脑落子的位置用（1 - row）和（1 - col）的随机数来确定。
        if (board[x][y] == ' ')             //判断电脑落子的地方有没有棋子，有的话就换个地方。
        {
            board[x][y] = '$';
            break;
        }
    }   
}

int IsFair(char board[ROW][COL],int row,int col)    //判断棋盘是否被放满了（看一下数组内还有没有空格）。
{
    int i = 0;
    int j = 0;
    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

char IsWin(char board[ROW][COL],int row,int col)            //用来判断谁赢了
{
    int i = 0;
    for ( i = 0; i < row; i++)              //竖三列的元素相同
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
        {
            return board[i][0];
        }     
    }
    for ( i = 0; i < col; i++)              //横三行的元素相同
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
        {
            return board[1][i];
        }     
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')         //左上到右下的元素相同
        {
            return board[1][1];
        }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] != ' ')         //左下到右上的元素相同
        {
            return board[1][1];
        }
    if (1 == IsFair(board,ROW,COL))         //判断元素是否把数组占满（返回'Q'），如果没占满（返回'C'）那就继续落子。
    {
        return 'Q';
    } 
    return 'c';
}

void game()                     //整个游戏的实现。
{
    char ret = 0;
    char board[ROW][COL] = {0};             //创建棋盘，将玩家和电脑下棋的棋子储存在数组中。
    InitBoard(board,ROW,COL);               //初始化棋盘：将数组里面的内容先填充为我想要的内容，便于之后的利用。
    DisplayBoard(board,ROW,COL);            //打印棋盘，将棋盘打印出来便于玩家观看。
    while (1)                               //一直重复玩家下棋，电脑下棋的过程，直到出现有一方获胜或者出现平局为止。
    {
        PlayerMove(board,ROW,COL);          //玩家下棋。
        DisplayBoard(board,ROW,COL);        //打印棋盘。
        ret = IsWin(board,ROW,COL);         //判断谁获胜或者是否出现平局。
        if (ret != 'c')                     //如果出现上述两种情况，那么退出循环，打印出谁获胜在屏幕上，游戏结束。
        {
            break;
        }
        ComputerMove(board,ROW,COL);        //玩家下棋。
        DisplayBoard(board,ROW,COL);        //打印棋盘。
        ret = IsWin(board,ROW,COL);         //判断谁获胜或者是否出现平局。
        if (ret != 'c')                     //如果出现上述两种情况，那么退出循环，打印出谁获胜在屏幕上，游戏结束。
        {
            break;
        }
    }
    if (ret == '*')                         //下面三条判断谁赢还是平局。
    {
        printf("玩家获胜\n");
    }
    else if (ret == '#')
    {
        printf("电脑获胜\n");
    }
    else
    {
        printf("平局\n");
    }
}

void text()
{     
    int input = 0;
    srand((unsigned int) time(NULL));       //使用随机数函数之前，需要调用srand()函数，不然会报错；而里面的随机数起点的参数由time()函数实现，但是time()函数里面的参数类型是time_t类型，所以需要unsigned int强制转换为整形类型来使用。
    do
    {
        menu();                             //菜单函数。
        printf("请选择：");
        scanf("%d",&input);
        switch (input)
        {
        case 0:
            printf("游戏已退出\n");
            break;
        case 1:
            game();
            break;
        default:
            printf("输入错误。\n");
            break;
        }
        printf("\n");
    } while (input);
    
}

int main()          //主函数
{
    text();
    return 0;
} */