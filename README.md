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
3.快速打开终端 shift+control+t
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
gcc -c
选项：-Wall 编译过程显示警告信息。
编写程序的过程：1.vim编写程序2.gcc编译成可以执行的二进制文件。3。执行 ./*.out文件。
```

## c语言编程

```text
1. c语言的代码需要写在*.c文件里面。
2. c语言的项目可以由多个*.c文件组成，c文件里面由函数组成，c程序由一堆函数组成，c语言项目里面有且只有一个入口函数。（mian函数）
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
//int 是函数的返回值的类型， mian是该函数的名字，因为函数的名字是mian，所以定义的同时是一个入口函数。
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
在c语言中可以通过可以通过变量使用内存的空间，变量指向内存中地址，地址上保存的值就是该变量被赋值的值。
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

符合数据类型

```tex
数组、指针、结构体、联合、枚举。
```

通过sizeof打印变量和常量所占用的字节数:demo/01var.c

## 信息的表示

```text
(unsigned) char a; 给a变了所在的地址分配了一个字节的空间，表示范围是0-255;
signed char a;分配的空间是-128-127；
```

查看ascii表；

```text
man ascii;
其中字符'0'(48)和0是不一样的。
可以在char中存放int类型（0-127）；
```

demo02/uc.c:在char中存放超过范围的整形数字。
