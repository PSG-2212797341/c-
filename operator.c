#include<stdio.h>
// 一、算数操作符：+  -  *  /  %
/* int main()
{
    int a = 10 / 3;             // /:返回值是商 3；如果操作符两边是整数，那么执行整数除法，只要有浮点数（小数）就执行浮点数（小数）除法。
    int b = 10 / 3;             // %:返回值是余数 1；这个操作符两边必须为整数，其他几个操作符两边可以为整数或者是浮点数。
    printf("a = %d\n",a);
    printf("b = %d\n",b);
    return 0;
} */

// 二、移位操作符：（移动的是二进制位，并且是整数）（但是不要移动的位数不可以为负数，这种做法是未定义的。）
// 1、>>：右移操作符：对于正整数来说，右移一位就除以2。
// （1）算术右移（通常情况都是这种）：右边丢弃，左边补原符号位（二进制位最高位0表示正数，1表示负数）。
// （2）逻辑右移：右边丢弃，左边补0。
// 如（正整数16）：整数的二进制位表示有：源码、反码、补码（储存到内存中），但正整数三码相同。
/* int main()
{
    int a = 16;                     //16写成二进制：00000000 00000000 00000000 00001000
    int b = a >> 1;                 //向右移动一位： 00000000 00000000 00000000 00001000
    return 0;            //右边丢弃，左边补原符号位：00000000 00000000 00000000 00000100            -->  b值为 8 
} */

// 如（负整数-1）：
/* int main()
{
    int a = -1;                     //-1写成二进制（源码）：10000000 00000000 00000000 00000001   -->   反码（符号位不变，其他位1变0，0变1）：11111111 11111111 11111111 11111110   -->   补码（反码 + 1）：11111111 11111111 11111111 11111111
    int b = a >> 1;                 //向右移动一位：  11111111 11111111 11111111 11111111
    return 0;            //右边丢弃，左边补原符号位： 11111111 11111111 11111111 11111111          -->   发现变化后与之前反码一样，所以这里b的值还是-1。
} */

// 2、<<：左移操作符：对于正整数来说，右移一位就乘以2。
// 只有逻辑左移：左边丢弃，右边补0。
// 如（正整数16）：
/* int main()
{
    int a = 16;                     //16写成二进制： 00000000 00000000 00000000 00001000
    int b = a << 1;                 //向右移动一位：00000000 00000000 00000000 00001000
    return 0;            //右边丢弃，左边补原符号位： 00000000 00000000 00000000 00010000            -->  b值为 32 
} */

// 三、位操作符：&（按位与）、|（按位或）、^（按位异或）   -->   按二进制位。
/* int main()
{
    int a = 1;
    int b = 2;
    int c = a & b;
    // a：00000000 00000000 00000000 00000001
    // b：00000000 00000000 00000000 00000010
    // c：00000000 00000000 00000000 00000000   -->   只有同时为1时才会变为1，其余都是0。   -->   c = 0
    int d = a | b;
    // a：00000000 00000000 00000000 00000001
    // b：00000000 00000000 00000000 00000010
    // d：00000000 00000000 00000000 00000011   -->   只有同时为0时才会变为0，其余都是1。   -->   d = 3
    int e = a ^ b;
    // a：00000000 00000000 00000000 00000001
    // b：00000000 00000000 00000000 00000010
    // e：00000000 00000000 00000000 00000011   -->   相同为0、相异为1。   -->   e = 3
    return 0;
} */

// 例：面试题
// 题目：交换a = 3 和 b = 5两个int变量的值，但是不能使用第三个变量。
// 方法一：加减法（缺点：当数据值很大的时候，会出现溢出的情况）
/* int main()
{
    int a = 3;
    int b = 5;
    a = a + b;   -->   a = 8
    b = a - b;   -->   b = 3
    a = a - b;   -->   a = 5
    return 0;
} */

//方法二：使用异或的方法（缺点：可读性差）
/* int main()
{
    int a = 3;
    int b = 5;
    a = a ^ b;
    // a：00000000 00000000 00000000 00000011   -->   a = 3
    // b：00000000 00000000 00000000 00000101   -->   b = 5
    // a：00000000 00000000 00000000 00000110   -->   a = 6
    b = a ^ b;
    // a：00000000 00000000 00000000 00000110   -->   a = 6
    // b：00000000 00000000 00000000 00000101   -->   b = 5
    // b：00000000 00000000 00000000 00000011   -->   b = 3
    a = a ^ b;   
    // a：00000000 00000000 00000000 00000110   -->   a = 6
    // b：00000000 00000000 00000000 00000011   -->   b = 3
    // a：00000000 00000000 00000000 00000101   -->   a = 5
    return 0;
} */

// 例：练习题
// 题目：求一个整数储存在内存中的二进制1的个数。    
// 方法一：采用 %2 得到最后一位，/2 不要最后一位的方法（商和余数的值都跟这个整数的二进制位的每一位都对应），不过当值为负数时，就不能使用此方法了。
/* int main()
{
    int num = 0;
    int count = 0;
    scanf("%d",&num);               
    while (num)                     //如果还没有为0，那么还能够找到下一个1，那就继续找。
    {
        if(num % 2 == 1)              
        {
            count++;                 
        }
        num = num / 2;              
    }
    printf("1的个数为:%d",count);
    return 0;
} */  

// 方法二：使用 num & 1 的方法，如果返回值是 0，那么 num 的最低位是 0；如果返回值是 1，那么 num 的最低位是 1；第 32 位 & 过之后，num 就向 右移动一位，此时就是第 31 位 & ……… 直到第 1 位 &。
// 例如：以3为例。
//     3：00000000 00000000 00000000 00000011
//     1：00000000 00000000 00000000 00000001           此时：count = 1
// 3 & 1：00000000 00000000 00000000 00000001

// 3 >> 1：00000000 00000000 00000000 00000011
//     1：00000000 00000000 00000000 00000001           此时：count = 2
// 3 & 1：00000000 00000000 00000000 00000001

//  3 >> 2：00000000 00000000 00000000 00000011
//     1：00000000 00000000 00000000 00000001           此时：3 & 1 != 1，那么我的count就不再增加。
// 3 & 1：00000000 00000000 00000000 00000000
/* int main()
{
    int num = 0;
    int count = 0;
    int i = 0;
    scanf("%d",&num);
    for ( i = 0; i < 32; i++)
    {
        if (((num >> i) & 1) == 1)          //每次 & 后把 num 向右移动 i 位。（注意 i 从 0 开始）
        {
            count++;
        }
    }
    printf("%d",count);
    return 0;
} */

// 四、逻辑操作符：
// （1）&&：(逻辑与)两个都为真才算是真   --->   如果左边的结果是假，那么右边的就不会运行。
// （2）||：(逻辑或)两个都为假才算是假   --->   如果左边的结果是真，那么右边的就不会运行。
// 例：计算a、b、c、d的值。
/* int main()
{
    int i = 0, a = 0, b = 2, c = 3, d = 4;
    i = a++ && ++b && d++;                  //&&左边的 a++ 的 a 为 0 的时候左边已经为假，那么右边的就不会再执行，随后a自增，所以a、b、c、d的值分别为：1、2、3、4。
    printf("%d %d %d %d",a,b,c,d);
    return 0;
} */

// 五、条件操作符：exp1 ？ exp2 ：exp3   --->   如果exp1为真，那么就执行exp2，否则就执行exp3。
// 例：
/* int main()
{
    int a = 0;
    int b = 0;
    b = (a > 5 ? 3 : -3);
    printf("%d",b);
    return 0;
} */

// 六、结构成员：
// 例：
/* struct stu                      //创建一个结构体类型   ---   struct stu
{
    char name[20];
    int age;
    char id[20];
};

int main()
{
    int a = 0;
    struct stu s1 = {"张三",20,"2019010305"};          //使用了struct stu这个类型创建了一个学生对象s1，并初始化。
    struct stu* ps = &s1;

    printf("%d\n",ps->age);    //   --->    等价于：printf("%d\n",（*ps）.age);
    printf("%s\n",ps->name);   //   --->    等价于：printf("%s\n",（*ps）.name);   --->   使用：结构体指针->成员名 的方式来访问。

    printf("%s\n",s1.name);
    printf("%d\n",s1.age);
    printf("%s\n",s1.id);                           //使用：结构体.成员名 的方式来访问。
    return 0;
} */

// 七、隐式类型转换：
// （1）c的整形算数运算总是至少以缺省整型类型的精度来进行的，为了获取这个精度，表达式中的字符和短整型操作数在使用之前被转换为普通整型，这种转换称为整形提升。
// （2）整型提升的意义：表达式的整型运算要在CPU相应的器件里面进行，CPU内整型运算器的操作数的字节长度一般就是int的字节长度，同时也是CPU的通用寄存器的长度，
//                      因此，即使是两个char类型的相加，在CPU执行时实际上也要转换为CPU内整型操作数的标准长度，通用CPU是难以直接实现两个8比特字节直接
//                      相加运算，所以，表达式中各种长度可能小于int长度的整形值，都必须转换为int或者是unsigned int，然后才能送入CPU去执行运算。
// （3）整型提升的方法：按照变量的数据类型的符号位来提升的（正数补0，负数补1）。
// 例：
int main()
{
    char a = 3;
    // 00000000 00000000 00000000 00000011   --->   3是一个整数，那么存放在内存里面就会是32个比特位。
    //                            00000011   --->   而char只能存放一个字节，那么就会发生截断，会保留最右边的那个字节。
    char b = 127;
    // 00000000 00000000 00000000 01111111   --->   127是一个整数，那么存放在内存里面就会是32个比特位。
    //                            01111111   --->   而char只能存放一个字节，那么就会发生截断，会保留最右边的那个字节。
    char c = a + b;
    // 00000000 00000000 00000000 00000011   --->   a 运算是需要进行整型运算，所以需要整型提升，而最高位为正，所以补0
    // 00000000 00000000 00000000 01111111   --->   b 运算是需要进行整型运算，所以需要整型提升，而最高位为正，所以补0
    // 00000000 00000000 00000000 10000010   --->   c   
    //                            10000010   --->   c 而char只能存放一个字节，那么就会发生截断，会保留最右边的那个字节。 
    printf("%d",c);
    // 11111111 11111111 11111111 10000010   --->   c（存放在内存中，而最高位为负数，所以这里是补码） 运算是需要进行整型运算，所以需要整型提升，而最高位为正，所以补0
    // 11111111 11111111 11111111 10000001   --->   c（反码） = （补码） - 1
    // 10000000 00000000 00000000 01111110   --->   c（原码） = （反码）符号位不变，其它位取反。
    // 打印的值为：-126
    return 0;
}