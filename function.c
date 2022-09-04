#include<stdio.h>
#include<math.h>                    //引用自己写的头文件要用引号引起来。
// 一、函数的分类：
// 1、库函数：（学习可以参考下面网站）：系统自带的函数，引用时需要头文件。
// C语言手册：https://zh.cppreference.com
// C语言文档：https://cplusplus.com/doc/tutorial/introduction/

// 2、自定义函数：
// 例如：写一个函数可以用来交换两个整形的值。
/* void change(int x,int y)                                //如果函数没有返回值那么函数名前加上void；如果有返回值，返回值是什么类型就在函数名前设置相同的类型。
{                                                       //因为定义一个变量后会在内存中找到一个地方储存它，并且它自己有独立的地址，所以上面定义的x\y，下面定义的a\b，都有自己独立的地址，虽然a\b的值是传过来给x\y。但是地址并没有过来，所以在x\y这里值是交换过，但是值只会保存在x\y的地址中。而非a\b。所以下面a\b的值不会改变。
    int tmp = 0;
    tmp = x;
    x = y;
    y = tmp;
}

void change2(int* x,int* y)                             //  int main()
{                                                       //  {
    int tmp = 0;                                        //    int a = 0;            
    tmp = *x;                                           //    int* pa =&a;          将a的地址取出来放在的指针变量pa里面
    *x = *y;                                            //    *pa = 20;             *pa：表示通过a的地址找到a这个值。
    *y = tmp;                                           //    return 0; 
}                                                       //  }   

int main()
{
    int a = 10;
    int b = 20;
    printf("a = %d b = %d\n",a,b);
    change(a,b);                                       
    printf("函数change:  a = %d b = %d\n",a,b);                      //此时会发现a、b的值并没有发生改变。
    change2(&a,&b);                                       
    printf("函数change2:  a = %d b = %d\n",a,b);                     //此时会发现a、b的值发生改变。
    return 0;
} */

// 二、函数参数：
// 1、实际参数（实参）：真实传给函数的参数，无论实参是什么类型的值，在函数调用时都必须要有确定的值，便于传给形参。
// 2、形式参数（形参）：函数名后括号里面的变量，形式参数只有在被使用的时候才会被分配空间，使用后就会被销毁。所以形参只能在函数内有效。

//三、函数调用：
// 1、传值调用：当实参传给形参的时候，形参是实参的一份临时拷贝，对形参的修改是不会改变实参的。
// 2、传地址调用：是吧函数外部创建变量的内部地址传递给函数参数的一种调用函数的方式，可以让函数和函数外边的数据联系起来，也就是函数内部可以直接操作函数外部的变量。

// 一、二、三、举个栗子：
// 1、打印100-200之间所有的素数。
// 1、2的方法：把里面的一层循环写成一个函数就可以。
/* int if_pri_num(int n)
{
    int j = 0;
    for(j = 2;j <= sqrt(n);j++)
    {
        if(n%j == 0)
        {
            return 0;
            break;
        }
        return 1;
    }
}

int main()
{
    int i = 0;
    for(i = 100; i <= 200; i++)
    {
        if(if_pri_num(i) == 1)
        {
            printf("%d ",i);
        }
    }
    return 0;
} */

// 2、打印1000-2000年中的闰年。
/* int is_leap_year(int n)
{
    if((n%4 == 0 && n%100 !=0) || (n%400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int year = 0;
    int num = 0;
    for(year = 1000; year <=2000; year++)
    {
        if(is_leap_year(year) == 1)
        {
            printf("%d ",year);
            num++;
        }
    }
    printf("%d",num);
    return 0;
} */

// 3、使用二分查找的方法在一个有序的数组中查找具体的某个数字。
/* int bin_sea(int arr[],int k,int sz)
{
    int left = 0;
    int right = sz - 1;
    while (left <= right)
    {
        int mid = (left+right)/2;
        if(arr[mid]  < k)
        {
            left = mid + 1;
        }
        else if(arr[mid] > k)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return 1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int sz = sizeof(arr)/sizeof(arr[0]);            //求数组的元素个数不能在函数里面去求，如果在函数里面求的话：因为下面传上来的是数组的第一个元素的地址，所以需要指针来接收，那么这里的arr[]是一个指针变量，那么通过sizeof()计算指针的大小得到要么4/8（取决于是w32/w64）。而后面的sizeof(arr[0])：得到的是一个int型的大小为4；随意结果并不是元素的个数。
    int k = 7;
    int c = bin_sea(arr,k,sz);                      //数组传参的时候并不会所有的元素地址都会传过去。只是会把数组的第一个元素地址传过去。
    if (c == 1)
    {
        printf("找不到这个元素");
    }
    else
    {
        printf("找到了，这个数字的下标为：%d",c);
    }
    return 0;
} */

// 4、写一个函数，每次调用一下这个函数会使num+1。
/* void add(int* p)
{
    (*p)++;                     //++的优先级非常高，所以用括号扩起来，不然++会作用在p上。
}

int main()
{
    int num = 0;
    add(&num);                          //因为函数可以改变函数外的变量，所以采用传地址的方法。
    printf("num = %d\n",num);
    add(&num);
    printf("num = %d\n",num);
    add(&num);
    printf("num = %d\n",num);
    return 0;
} */

// 四、函数的链式访问。
/* int main()
{
    printf("%d",printf("%d",printf("%d",43)));             //print()函数：返回值是打印字符的个数，为整形。
// →  printf("%d",printf("%d",2));                        //首先最里面的会打印  43  两个数字，打印字符个数为2，那么返回值也会为2.
// →  printf("%d",1);                                     //然后中间的会打印  2  一个数字，打印字符个数为1，那么返回值也会为1.
// →  1                                                   //然后最后的会打印  1  一个数字，打印字符个数为1，那么返回值也会为1.
// →  打印值为：4321
    return 0;
} */

// 五、函数的声明和定义：（类似于前端开发中的引用自己写的css文件/JS文件的路径）和（自己写的css文件/JS文件）。
// 1、声明：告诉编译器有一个函数叫什么，参数是什么，返回类型是什么，但存在不存在，声明不管；并且函数声明出现在函数的使用前，要满足先声明后使用；函数的声明需要放在头文件中。
// 2、定义：是指函数的具体实现，交代函数的功能实现。
// 函数声明：下面这种写法类似前端开发中的行内JS。
/* int add(int x,int y);

int main()
{
    int a = 10;
    int b = 20;
    int sum = 0;
// 函数调用：
    sum = add(a,b);
    printf("sum = %d",sum);
    return 0;
}

// 函数定义：
int add(int x,int y)
{
    int z = z = x + y;
    return z;
} */