# Linux命令

## linux命令的基本格式

```text
命令名 [选项] [参数]
```

## liunx中常见的路径

```text
/ 代表根目录
～ 代表用户的根目录
cd 不带参数，回到用户的根目录。
cd - 返回用户上次所以在目录。
```

## man指令

```text
man man/ls等
man 还可用来查看库函数
man 3(章节，1代表的是shell指令) printf
man -M：指定手册文件的搜索路径，有的时候我们自己安装的软件是带有自己的帮助文件的，通常不在我们的MANPATH 里面，那么我们就可以手动指定man搜索的文件路径。
如 man -M /home/mysql/man mysql
```

## tar 解压或者压缩文件

```text
用法：tar [选项] 压缩/压缩的文件名称 解压或者压缩的文件
解压文件 tar -zxvf  *.tar.gz
压缩文件 tar -cvfz/j  *.tar.gz/.bz2  文件/目录
```

## 提高效率的方法

```text
1. 使用tab键补全命令或者文件
2. 使用history查看使用过的命令， history -c清除历史。
3.快速打开终端 shift+alt+t
alt+数字 切换终端
4.control+c 终止当前的命令的执行或废除已经输入的命令。
5.which 命令 :查看命令存在那个目录下
```

## vi

```text
命令模式下
:w 保存文件
编辑模式
i（insert）光标之前插入
a (append) 光标之后插入
o 下一行进行插入

一般模式下移动光标；
h(左)j(下)k(上)l(右)

w 每次移动一个单词
0 回到行首 $回到行尾
100gg 跳到指定行
gg 第一行
G 最后一行
删除 dh删除当前光标位置前的字符
x 删除光标所在的字符
dw 删除光标后面的单词
dd 删除当前行
d0 删除光标到之前的所有内容
d$ 删除光标之后的所有内容
5dd 删除光标所在位置后的五行（包含当前行）
dgg 删除到第一行(包含)
dG 删除到最后一行（包含）
ggdG 删除真个文件
u 撤销上次操作
复制操作：y替换上面的d
p粘贴到当前光标之后，P粘贴到当前的光标之前。

缩紧 =
    == 当前行和上一行对齐或者缩紧
    gg=G  全文缩进
    # 全文搜素光标下的单词，并高亮显示。
    % 跳到对应的括号上。
vimtutor 查看vim教程
```

## gcc编辑器

```text
将程序编译成可执行的二进制指令（*.c->*.out），使用 ./*.out执行文件。
用法：gcc hello.c 或者gcc hello.c -o  hello(编译后文件的名字)
gcc -std=c99 设定c语言的版本。
gcc -v
选项：-Wall 编译过程显示警告信息。
编写程序的过程：1.vim编写程序2.gcc编译成可以执行的二进制文件。3。执行 ./*.out文件。
```

## c语言编程

```text
1. c语言的代码需要写在*.c文件里面。
2. c语言的项目可以由多个*.c文件组成，c文件里面由函数组成，c程序由一堆函数组成，c语言项目里面有且只有一个入口函数。（main函数）
3. c语言的执行顺序：在同一个函数中，代码从上到下执行。
4. 程序的结束：main函数中没有return语句，执行到函数末尾，由return语句，执行到return语句。
5. 编码规范：1.一行只写一句代码。
            2.可以在代码中加入适当的空格空行，使代码看起来更加的清晰。
            3.使用缩进规则，使代码看起来更清晰。
            4.写代码时，对关键性代码需要加上注释。
6. c语言中有两种注释，单行注释（//...）和多行注释（/* ... */）
```

hello.c文件

```c
//引入printf函数所在的库文件
#include <stdio.h>
//int 是函数的返回值的类型， main是该函数的名字，因为函数的名字是main，所以定义的同时是一个入口函数。
int main()
{
    // 使用printf函数打印内容
    printf("hello world!");
    //函数的返回值
    return 0;
}
```

练习:
star.c :第一打印一个*，第二行打印* *，... 。
2_3.c :在终端中输出2+3的和。

## c语言中的变量

```text
在c语言中可以通过变量使用内存的空间，变量指向内存中地址，地址上保存的值就是该变量被赋值的值。
```

### 变量命名

```text
1. 不可以是中文
2. 以字母、_开始，后面可以用数字、字母，下划线。
3. 变量名区分大小写。
4. 非关键字（return、int ...）
5. 同一作用域不能存在同名变量。
6. 命名规范：my_money / myMoney
```

### 变量的类型（不同类型的变量在内存中分配的大小是不同的）

基本数据类型

```text
char :1byte(字节)
short int :2byte
int  :4byte
long int :8byte
float :4byte
double :8byte
```

复合数据类型

```text
数组、指针、结构体、联合、枚举。
```

通过sizeof打印变量和常量所占用的字节数:demo/01var.c

## 信息的表示

```text
(unsigned) char a; 给a变了所在的地址分配了一个字节的空间，表示范围是0-255;
signed char a;分配的空间是-128-127；
```
查看ascii表；

```text
man ascii;
其中字符'0'(48)和0是不一样的。
可以在char中存放int类型（0-127）；
```

demo02/uc.c  :在char中存放超过范围的整形数字。

## 进制转换

```text
四位2进制可以转换成以为16进制；
1101 -->  D;
```

## 定义变量需要初始化

```text
定义一个变量相当于在内存中绑定了一块空间，如果不进行初始化操作，变量中存放的值是不确定的。
int i=10;
```
##  格式化打印变量

```text
printf=print formmat;
变量中存储的二进制的数据，我们可以使用不同的格式符输出变量。
```

demo03/02_printf.c  格式化输出变量。
demo03/03_scanf.c   接受用户的输入并打印变量的值
demo03/big2low.c    将用户输入的大写字符转化成小写
demo03/area.c       用户输入矩形的长和宽，计算出矩形的面积
demo03/04_add.c     计算两个数的和
demo03/05_var.c     C语言中如何存一个负数的

## sizdeof运算符
sizeof(int)
sizeof(i)
sizeof(3.14)

## =(赋值运算符)

赋值运算两边的类型不一样，小字节赋值大字节，复制到低位，高位补0，大字节复制到小字节时，将大字节的低位赋值给小字节。将float类型复制int类型，会发生类型转换，将float转成int.

## +-*/%

运算的两边类型一致，那么运算的结果也是该类型。

int i=10/3;  //3

demo04/02apple.c 

运算符两边的类型不一样，现将类型转成一样的，然后运算的结果类型保持一致。一般会将会转成大类型的，如int * float,现将int 转为float，运算结果是float,有符号×无符号数，结果是无符号数。

## 符合运算符  += |= &=

a+=1;等价于 a=a+1;

## i++、i--、++i --i

i++  是先用后加
++i  是先加后用

demo04/increment.c

## 运算符的优先级 

运算符是有优先级的，如果不知道运算符的优先级，可以使用()来改变运算符的优先级。


i = (1+2)*3 //先运算加法，在运算乘法

```text
一目运算符：一个操作数 eg: +、-、++ 、--
二目运算符：两个操作数 +、-、*、/、%
三目运算符：三个操作数 a>b?a++:b++
```
liunx下查看运算符:man operator

demo04/second.c

## 位运算符（操作比特位）

& 同时为1时结果为1，其他情况结果为0
| 一个为1结果为1，同时为0结果为0
~ bit位上的1变为0,0变为1
^ 异或运算符 相同为0，不同为1
<< 低位补0
'>>' 有符号数高位补符号位，无符号数高位补0

demo04/bit.c


## 条件运算符

a>b?a++:b++

## 比较运算符

>、<、>=、<=、==、!==

## 逻辑运算符

&&、||、!

num >1 && num1<10

demo04/year.c

## 流程控制语句

1. if、else语句
2. for循环
 特例：死循环
```c
	for(;;)
```
3. break和continue

4. goto语句

	goto语句可以用来跳出双重for循环。
5. 输入输出缓存区
	
6. 数组
	1.内存中连续的大小为某一类型的空间。
	2.数组的声明 int a[10]

7. 数组的初始化
        数组和变量一样，如果不初始化，那么数组中存放的数字是随机的。
```text
        int a[3]={2}; //[2,0,0];
        int a[3]={1,2,3} //[1,2,3]
        int a[3]={[1]=1,[3]=2} //[1,0,3]
        int a[]={1,2,3} //[1,2,3]
```
8. 数组下标越界，编辑器保持沉默
        1.读写其他变量的值
        2.地址非法，段错误程序结束

9. 使用sizeof可以查看数组占用的字节数
```text
int a[] = {1,2,3};
sizeof(a)/sizeof(a[0]);//返回的是数组中元素的个数
```
10. 数组的地址

```text
a == &a //true
``
```
demo05/03_tinary.c 计算一个整形中包含的2进制1的个数
demo05/05_rand.c 生成随机数
demo05/06_9*9.c 99乘法表
demo05/07_for_2.c  双重for循环解决鸡兔同笼的问题
demo05/08_do_while.c do——while循环
demo05/09_goto.c  使用goto语句和if语句实现循环
demo05/10_buff.c  清理输出缓存区
demo05/11_scanf.c  清理输入缓存区
```
