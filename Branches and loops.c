#include<stdio.h>               //调用库函数所需要引入的头部文件。(库函数像打印用的printf)
#include<string.h>
#include<windows.h>
#include<stdlib.h>

//分支（branch）语句
// 一、if语句：
// 1.if-else语句基础：
/* int main(){                 //main函数是主函数，是程序的入口，并且只能存在一个；int表示main函数调用返回一个整形值。与后面的return 0 对应。
    int age = 20;
    if(age<18)
        printf("未成年\n");
    else if (age>=18 && age<28)  //这个地方不能写出 18 <= age <= 28,因为运行的时候会先判断 18 <=age 是假（0）是真（1），再判断下一个（从左到右）！！！
    {
        printf("成年\n");   
    }                           //如果想执行多条输出语句，应该使用代码块{}将其包裹起来
    else                        //if-else语句中的else可以省略。                   
        printf("老不死\n");
    return 0;
}; */

// 2.悬空else：
/* int main()
{
    int a = 0;
    int b = 2;
    if(1 == a)                 //这样写可以避免出现赋值（=）和判断相等（==）之间弄错（“左变右值”自己弄错的话软件并不会帮你发现错误），弄错的话软件会提示错误。
        {
            if(2 == b)
                printf("hehe\n");
            else               //else会与离它最近的同一层if匹配，所以这样写第一个if就没有else与它对应，所以写代码时需要注意。
                printf("haha\n");
        }
    return 0;
} */

// 3.练习：输出1-100之间的奇数。
/* int main()
{
    int a = 1;
    while (a <= 100)
    {
        if (a % 2 == 1)
            printf("%d ",a);    //%d -- 打印整形十进制数据；\n -- 换行；
            a++;                
    }
    return 0;
} */



// 二、switch语句：（常用于多分支选择的情况）
// 1.switch语句基础：如输入数字1-7后，会输出星期一-星期天。
/* int main()
{
    int a = 0;
    scanf("%d",&a);
    switch (a)                  //若a值输入为1，则运行case 1 ：中的语句，以此类推。且a必须为整型表达式。
    {
    case 1 :                    //case为选择的入口；且case后面必须为整型常量表达式。
        printf("星期一");
        break;                  //break为选择的出口，可以存在也可以不存在，看情况而定。但最后一个break最好加上，增强代码的复用性。
    case 2 :
        printf("星期二");
        break;
    case 3 :
        printf("星期三");
        break;
    case 4 :
        printf("星期四");
        break;
    case 5 :
        printf("星期五");
        break;
    case 6 :
        printf("星期六");
        break;
    case 7 :
        printf("星期天");
        break;
    default:                    //默认值：如果输入的值没有case表达式与其对应，则运行default里面的表达式，不过，default和case的位置可以交换，但出于习惯，最好写在后面，而且default只能存在一个。
        printf("输入错误");
    }
    return 0;
} */

// 2.练习：计算m、n的值。
/* int main()
{   
    int n = 1;
    int m = 2;
    switch (n)                      //n = 1
    {       
        case 1:
            m++;                   //m = m++ = m + 1 = 3
        case 2:
            n++;                  //n = n++ = n + 1 = 2
        case 3:
            switch (n)           //n = 2      switch语句可以嵌套使用。
            {
                case 1:
                    n++;
                case 2:             
                    m++;        //m = m++ = m + 1 = 4
                    n++;        //n = n++ = n + 1 = 3
                    break;      //跳出switch语句。
            }
        case 4:
            m++;                //m = m++ = m + 1 = 5
            break;              //跳出switch语句。
        default:
            break;
    }
    printf("m = %d, n = %d", m, n);         //分别打印出m、n的值为5、3。
    return 0;
} */





//循环（loop）语句
// 一、while循环：
//1、while语句基础：在屏幕上打印1-10的数字。
// 方法一：
/* int main()
{
    int a = 1;
    while (a <= 10)                     //while后面的表达式如果为真，就会执行下面的代码/代码块，为假就不会执行。
    {
        if (a == 5)
        {
            break;                     //无论后面还会循环多少次，break会直接跳出循环。此时打印的值为：1、2、3、4.
        }
        printf("%d ",a);
        a++;
    }
    return 0;
} */

// 方法二：
/* int main()
{
    int a = 1;
    while (a <= 10)                     
    {
        a++;
        if (a == 5)
        {
            continue;                     //continue会终止循环中本次循环后面的代码，会直接进行下一次循环（如果循环条件成立），这里如果a=5时，后面就不会打印出5来，而会走上去进行下一次的判断、循环；此时打印的值为：1、2、3、4、6、7、8、9、10.
        }
        printf("%d ",a);
    }
    return 0;
} */

// 2、EOF(EOF为文件结束标志,也就是\n)常见的作用。
// 有问题的写法：假如输入密码123456 -- 但其实输入密码是123456\n。
/* int main()
{
    int ch = 0;                         //创建一个变量用来储存下面接收到的字符Y/N
    char password[20] = {0};            
    printf("请输入密码：");             //用来储存用户输入的密码
    scanf("%s",password);               //用户输入密码,但是像scanf/getchar这样的输入函数读取数据会一个函数一个函数的去读取，所以scanf先来读取，会把用户输入的123456获取过去，然后就只剩下了\n.
    printf("是否确认(Y/N):");           
    ch = getchar();                     //接收用户Y输入的Y/N,因为上面输入的数据中还存在一个\n,所以这里会读取它，导致ch中已经有内容了。
    if (ch == "Y")                      //判断用户输入的是Y/N，因为上面被写内容进去了，所以会直接显示确认失败。
    {
        printf("确认成功");
    }
    else
    {
        printf("确认失败");
    } 
    return 0;
}  */                                      //所以会出现BUG的原因就是密码后面多了一个结束符号（\n）。

// 解决方法：                           //可以把\n在输入Y/N之前读取出去。
/* int main()
{
    int ch = 0; 
    int gh = 0;                       
    char password[20] = {0};            
    printf("请输入密码：");             
    scanf("%s",password);               
    while((gh =  getchar()) != '\n')                //可以一直读取字符直到能够读取到'\n',这里只可以使用单引号,不然后面的代码不运行。
    {
        ; 
    }
    printf("是否确认(Y/N):");           
    ch = getchar();                     
    if (ch == "Y")                      
    {
        printf("确认成功");
    }
    else
    {
        printf("确认失败");
    } 
    return 0;
}  */ 

// 3.while语句里面的continue
/* int main()
{
    int ch = 0;
    while ((ch = getchar()) != '\n')                //getchar()每次只会获取一个字符。
    {
        if (ch < '0' || ch > '9')
        {
            continue;
        }
        else
        {
            putchar(ch);
        }  
    }
    return 0;                                       //只输出1-9的数字，而其他都不会输出。
} */



// 二、for循环（使用最多）
// 1.for循环基础：
// 如：打印1-10的数字。
//int i = 0;
//int main()
//{
//    for ( i = 1;/* 初始化 */  i <= 10;/* 判断部分 */  i++/* 调整部分 */)
//    {
//        printf("%d ",i);
//    }
//    return 0;
//}                                   //与while相比，for循环的初始化、判断部分、调整部分比较集中，便于以后的修改。

// 2.for循环中的break：
// 如：打印1-10的数字。
/* int i = 0;
int main()
{
    for ( i = 1;  i <= 10;  i++)
    {
        if (i == 5)
        {
            break;                  //break的作用和if、while里面的作用一样（直接跳出循环），此处打印的值为：1、2、3、4。
        }
        printf("%d ",i);
    }
    return 0;
} */

// 3.for循环中的continue：
// 如：打印1-10的数字。
/* int i = 0;
int main()
{
    for ( i = 1;  i <= 10;  i++)        //建议修改变量在此处修改，不要再循环体内修改，防止会出现死循环的情况。
    {
       if (i == 5)
       {
        continue;               //break的作用和if、while里面的作用一样（跳过本次，执行下面），此处打印的值为：1、2、3、4、6、7、8、9、10。
       }
        printf("%d ",i);
    }
    return 0;
} */                               //与while循环相比，不会出现死循环的情况。

// 4.常见的for循环：
// 例1：
/* int main()
{
    for (;;)                    //初始化、调整、判断都可以省略，但是判断部分如果被省略就变成恒为真。
    {
        printf("2\n");          //这里就会一直打印2，陷入死循环。
    }
    return 0;
} */

//例2：
/* int main()
{
    int a = 0;
    int b = 0;
    for(a = 0; a < 10; a++)
    {
        for ( b = 0; b < 10; b++)
        {
            printf("2\n");                  //正常情况会打印100个2，但是如果把两个for循环里面的a = 0/b = 0省略掉，则会只打印10个2（因为进入循环后，b会达到10时才会结束掉第一个循环，此时b = 10，当下一个进入时，b没有被重新赋值，此时b = 10 ！< 10,所以会跳出循环，不再打印，），所以一般情况下不要随便省略。
        }    
    }
    return 0;
} */

// 5.一道公司的面试题目：
// 问：循环要循环多少次
/* int main()
{
    int a = 0;
    int b = 0;
    for(a = 0, b = 0; b = 0; a++, b++)          //这里判断条件为：b = 0; 此时，b被赋值为0，而0为假，所以循环直接出去，一次循环都没得。（所以要注意出题人的小心思哦！）
    {
        b++;
    }
    return 0;
} */



// 三、do...while循环：
//基础：打印1-10的数字：(break、continue的作用与for循环和while循环一样，不再说明)
/* int main()
{
    int a = 0;
    do
    {
       printf("%d ",a);
       a++;
    } while (a <= 10); 
    return 0;
}  */                          //先执行，后判断。





// 循环练习：
// 例1：计算n的！               
//方法：因为：n！ = 1*2*3*...*n,所以可以创建一个从1 --- n的数，然后让他们相乘。
/* int main()
{
    int i = 0;                              //创建一个变量用来产生每次增加1的数。
    int n = 0;                              //创建一个变量来表示是几的阶乘。
    int a = 1;                              //创建一个变量用来储存n!等于多少。
    scanf("%d",&n);                         //用户输入想要计算几的阶乘。
    for ( i = 1; i <= n; i++)               //用来产生1 --- n的数。
    {
        a = a * i;                          //用来使1 --- n的数依次相乘。
    }
    printf("%d\n",a);                       //用来显示n!等于多少。
    return 0;
} */

//例2：计算：1！+2！+3！+...+10！
// 方法：分别算出1！、2！、3！、...、10！的值，然后使其想加。
// 算法1：
/* int main()
{
    int i = 0;                              //创建一个变量用来产生每次增加1的数。
    int n = 0;                              //创建一个变量来表示是几的阶乘。
    int a = 1;                              //创建一个变量用来储存n!等于多少。
    int sum = 0;                            //用于求1！、2！、3！、...、10！的值。
    for ( n = 1; n <= 10; n++)               //使用for循环来创建1-10的阶乘。
    {
        a = 1;                              //用来使储存n！的值从1！开始相加。
        for ( i = 1; i <= n; i++)               //产生n的阶乘
        {
            a = a * i;                          //用来使1 --- n的数依次相乘。
        }
        sum = sum + a;
    }
    printf("%d\n",sum);                       //用来显示n!等于多少。
    return 0;
} */

// 算法2：                                  //算法1每次开始算会重复计算之前算过的阶乘，使其重复的计算过多，且：1！* 2 = 2！ * 3 = 3！ * ... * 10 = 10！，所以每次只需要在前面的阶乘上乘以n就可以得到后面的阶乘，这样会减少一层的循环量。
/*  int main()
 {
    int i = 0;                              //创建一个变量用来产生每次增加1的数。
    int n = 0;                              //创建一个变量来表示是几的阶乘。
    int a = 1;                              //创建一个变量用来储存n!等于多少。
    int sum = 0;                            //用于求1！、2！、3！、...、10！的值。
    for ( n = 1; n <= 10; n++)               //使用for循环来创建1-10的阶乘。
    {
        a = a * n;                          //在原来的阶乘上面乘以n就得到下一个阶乘。
        sum = sum + a;
    }
    printf("%d\n",sum);                       //用来显示n!等于多少。
    return 0;
} */

// 例3：在一个有序的数组中查找具体的某个数字。
// 算法1：从前往后用每一个数组里面的元素与我需要查找的数字做比较，查找最坏的情况下需要查找n次，但此方法弊端在于如果数组里面的元素数量很大，那么查找起来会十分困难，代码执行效率很低。
/* int main()
{
    int a = 0;
    int b = 11;                              //查找数组中数字7的位置 
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int gs = sizeof(arr)/sizeof(arr[0]);    //sizeof(arr)/sizeof(arr[0]):获取数组的长度的方法之一。
    for(a = 0; a < gs; a++)                 //数组中元素的下标的最大值会比数组中元素个数的值小1，那么这里就已经把数组中的所有数都拿来比较过。
    {
        if(b == arr[a])                     //如果查找的数字7与数组中的某一个元素的值相等。
        {
            printf("找到了,该元素的下标为:%d",a);
        //  printf("%d" ,arr[a]);           arr[a]:数组中元素的大小。
        //  printf("%d" ,a);                a：数组中元素的下标，而且是从0开始的。
            break;                          //跳出循环
        }
    }
    if(b > gs)
    {
        printf("找不到");
    }
    return 0;
} */

// 算法2：使用二分法进行查找，就是每次查找会干掉一半的元素，通常情况下与方法1比较，大大的的缩短了查询的次数（执行方法：因为想要控制数组里面的元素最方便的方法就是用元素的下标来控制，所以最开始用数组中最左边元素的下标(为了书写方便定为left)和最右边元素的下标(为了书写方便定为right)的下标平均值(为了书写方便定为mid)来作为最开始数组的中间值，用mid下标在数组中对应的那个数(arr[mid])与我想要的那个数(a)进行比较：如果arr[mid] > a,说明想要的那个数在arr[mid]的左边，则可以用此时的mid来代替right，left不变，再进行下一次判断；如果arr[mid] < a,同理就在左边。此时就可以用mid来代替left，而right不变，再进行下一次判断；如果相等，那么此时的arr[mid]就是我想要的a的值）.
/* int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};                 //创建一个数组。
    int a = 20;                                          //假如我想要查找这个数组里面7的位置。
    int left = 0;                                       //左下标
    int right = sizeof(arr)/sizeof(arr[0]) - 1;         //右下标
    while (left <= right)                               //循环终止的条件：因为在运行的过程中，左右下标会+1/-1的相互靠近的运行，那就会出现相隔很近时，如果上下标其中一个+1/-1时，上下标会交错开来，此时，这中间就不会存在我需要的a值了，所以结束条件为：left <= right。
    {
        int mid = (left + right)/2;                         //下标的中间值
        if(arr[mid] > a)
        {
            right = mid - 1;                                 //这里-1在我的理解里面是为了两端的元素可以被查找到，因为如果这里-1去掉，1-9的数字查找的次数会比有-1的查找次数要少一次，但是有个BUG，就是两端的数字无论如何都查不到(不信的话可以在纸上试一下哦)，所以这里还是建议-1)加上哦。(下面的+1也同理哈！)
        }
        else if(arr[mid] < a)
        {
            left = mid + 1;
        }
        else
        {
            printf("找到了，下标为：%d",mid);
            break;
        }
    }
    if (left > right)                               
    {
        printf("找不到");
    }
    return 0;
} */

//例4：编写一段代码，演示多个字符从两端移动，向中间汇聚（如：welcome to bit!!!!!）
//方法：可以使用两个数组，一个数组（此处定为arr1[]）放我想要显示的字符，一个数组（此处定为arr2[]）放等量的字符（如：*******************），然后每次从arr1[]中取出头（left）、尾（right）两个元素（可以使用下标来控制）覆盖掉arr2[]中的头、尾两个元素，然后分别++/--，得到第二对元素进行替换，直到全部替换完毕！
/* int main()
{
    char arr1[] = "welcome to bit!!!!!!";
    char arr2[] = "********************";
    int left = 0;
    int right = strlen(arr1) - 1;               //strlen()函数可以计算出数组的长度，需要引入头文件(#include<string.h>)遇到\0会暂停，而使用：sizeof(arr)/sizeof(arr[0])计算字符串时需要注意最后面会存在一个\0，该方法计算时会将这个也计算进去。
    while (left <= right)                       //暂停原理跟例3的方法2一样。
    {
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        printf("%s\n",arr2);
        Sleep(1000);                            //停留1000毫秒（1s钟），该函数需要头文件（#include<windows.h>）
        system("cls");                          //system()是一个会执行系统命令的一个函数，而cls命令会清空屏幕，该函数需要头文件（#include<stdlib.h>）
        left++;
        right--;
    }
    
    return 0;
} */

//例5：编写一段代码，模拟用户登陆的情景，输入密码如果密码正确则提示登陆成功（而且只能登陆三次），如果密码三次都输入错误则退出程序。
/* int main()
{
    int i = 0;
    char passward[20] = {0}; 
    for(i = 0; i < 3; i++)
    {
        
        printf("请输入密码：");
        scanf("%s",passward);
        if(strcmp(passward,"123456") == 0)                              //比较两个字符串是否相等不能使用 == ；应该使用库函数strcmp(),如果两字符串相等：返回值为0；前者大：返回值＞1；前者小：返回值<1;该函数需要引入头文件（#include<string.h>）
        {
            printf("登陆成功\n");
            break;
        }
        else
        {
            printf("密码错误\n");
        }
    }
    system("cls");
    if(i == 3)
    {
        printf("输入密码错误次数过多，请那身份证件到柜台办理手续");
    }
    return 0;
} */

//自动关机
/* int main()
{
    char input[20] = {0};
    system("shutdown -s -t 600");                 //shutdown：关机命令；-s -t 600：设置关机 时间关机 600秒后关机；
    printf("您的电脑将在10分钟后关机,如果输入:我是猪,就会取消关机\n请输入:");
    scanf("%s",&input);
    while (1)
    {
        if (strcmp(input,"我是猪") == 0);
        {
            system("shutdown -a");              //-a：取消关机。
            break;
        }
    }
    return 0;
} */
