# 第二章：变量和基本类型

## 练习2.1

> 类型 int、long、long long 和 short 的区别是什么？无符号类型和带符号类型的区别是什么？float 和 double的区别是什么？

C++ 规定 `short` 和 `int` 至少16位，`long` 至少32位，`long long` 至少64位。
带符号类型能够表示正数、负数和 0 ，而无符号类型只能够表示 0 和正整数。
通常，单精度`float`用1个字表示（4个字节，32bit），双精度`double`用2个字表示（8个字节，64bit）。

用法（类型的选择）：
* 如果确认数据是非负的，那么就使用 `unsigned` 无符号类型。
* 一般使用 `int` 做整数运算，`short` 因为太小在实际中用的少，`long` 通常和 `int` 有着相同的大小。如果数据非常大，可以使用 `long long` 。
* 算术表达式不用 `char` 或 `bool` ，这二者只建议用于存放字符或布尔值。因为`char`在某些机器上是有符号的，在另一些机器上是无符号型的，则使用 `char` 进行运算容易出问题。如果需要较小的整数，就明确指定 `signed char` 或者 `unsigned char`。
* 执行浮点运算时用 `double` ，因为 `float` 通常精度不够而且双精度浮点数和单精度浮点数的计算代价相差无几。

参考：
* [What are the criteria for choosing between short / int / long data types?](https://isocpp.org/wiki/faq/newbie#choosing-int-size)
* [Difference between float and double](http://stackoverflow.com/questions/2386772/difference-between-float-and-double)

### float有效位理解
IEEE规定`float`为32bit，尾数用23位存储，加上隐含的小数点前的1位1，2^(23+1) = 16777216。因为 10^7 < 16777216 < 10^8，所以说单精度浮点数的有效位数是7位（能保证7位有效数字，当然，并非说第8位一定是非有效数字，它也有可能是准确的）。
```c
#include <stdio.h>

int main()
{
    float i = 12345678.76348;
    float j = 46857.9874;
    printf("%f\n%f\n%.3f\n%.8f", i, j, j, j);
    return 0;
}
```
输出：
```
12345679.000000
46857.988281
46857.988
46857.98828125
```

从以上数据可以看出，第八个数字之后就不精确了。另外，要注意，有效数字的位数与指定输出的小数位数（%.7f，保留7位有效数字）是两码事，如第三第四个输出，这个是程序指定的输出格式，和类型本身能够存储的精度不是一回事。

## 练习2.2

> 计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

使用 `double` 或 `float` 。

## 练习2.3

> 读程序写结果。
```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

输出：
```
32
4294967264 // -32=(-1)×2^32+4294967264
32
-32
0
0
```

### 类型转换的总结
- 非布尔类型转换布尔类型时，0转换成false，非0则true（包括负数）。
- 布尔值转换非布尔类型时，false转换为0，true则1。
- 浮点数转换整数时，仅保留小数点之前的部分（即整数部分，小数部分直接截断），这是精度损失；当浮点数表示的值大过整型值，会发生溢出。
- 整数转浮点数时，小数部分记为0。不会发生溢出，但当整数值数据较大时，转换浮点数可能会发生精度丢失。例如，`int` 有31bit用来拓展精度，`float` 只有24bit，即当int值大于2^24或者小于-2^24时，转换`float`就会精度丢失。
- 给无符号类型赋值超过其表示范围时，实际值是初始值对无符号类型表示数值总数取模后的余数。8bit的`unsigned char`表示0-255，赋值超出范围时，实际值为该值对256取模后的余数。因此将-1赋给8bit的`unsigned char`时，结果值为255。
- 赋给带符号类型一个超出范围的值时，结果是未定义的。此时，程序可能工作、可能崩溃、也可能生成垃圾数据。

**无符号类型和有符号类型计算，结果为负数时，结果值的计算方法**

给定一个正整数p，任意一个整数n，一定存在等式n=kp+r

其中k、r是整数，且0<=r<p，称k为n除以p的商，r为n除以p的余数。

定义取模运算：a % p（或a mod p），表示a除以p的余数。

**实际运用场景**：将-1赋给8bit的`unsigned char`时，结果值为255。
计算过程：-1=(-1)×256+255

二进制表示的本质：用补码表示，先看原码（符号位为1，数值位只有一个1）对原码取反加1（符号位不变），转换成补码后，所有位都是1。

### 类型转换的使用场景总结
- 不要混用带符号类型和无符号类型：表达式中含有这两种类型时，带符号数会自动转换成无符号数（此时，一个负数转换成无符号数后，真值将很大）。
- 循环中的判断条件慎用无符号数：无符号数表示范围为正整数，不会小于0，尤其是当循环的临界条件是0时。如以下代码，就是死循环，当u=0时，循环条件依然满足，继续执行，--u就是-1，但无符号数只能表示整数，-1被自动地转换成一个合法的无符号数，即正整数。

```cpp
for (unsigned u = 10; u >= 0; --u)
    std::cout << u << std::endl;
```

解决方式：
1. 用有符号类型
2. 用while语句，代码如下。
3. 类似while语句，将for语句的--u置于cout语句中。
4. 2和3本质上就是保证u不会变为-1。

```cpp
unsigned u = 11;
while (u > 0)
{
    --u;
    std::cout << u << std::endl;
}
```

## [练习2.4](2_4.cpp)

> 编写程序检查你的估计是否正确，如果不正确，请仔细研读本节直到弄明白问题所在。

## 练习2.5

> 指出下述字面值的数据类型并说明每一组内几种字面值的区别：
- (a) 'a', L'a', "a", L"a"
- (b) 10, 10u, 10L, 10uL, 012, 0xC
- (c) 3.14, 3.14f, 3.14L
- (d) 10, 10u, 10., 10e-2

(a): 字符字面值，宽字符字面值，字符串字面值，宽字符串字面值。

(b): 十进制整型，十进制无符号整型，十进制长整型，十进制无符号长整型，八进制整型，十六进制整型。

(c): double, float, long double

(d): 十进制整型，十进制无符号整型，double, double

P.S. 要注意'a'和"a"不一样，"a"包含两个字符，字母和空字符（字符串字面值是由常量字符构成的数组，编译器会在字符串结尾处添加一个空字符'\0'）。

## 练习2.6

> 下面两组定义是否有区别，如果有，请叙述之：
```cpp
int month = 9, day = 7;
int month = 09, day = 07;
```

第一行定义的是十进制整型。
第二行定义的是八进制整型，但是 month 变量无效，因为八进制没有 9 。

## 练习2.7

> 下述字面值表示何种含义？它们各自的数据类型是什么？
- (a) "Who goes with F\145rgus?\012"
- (b) 3.14e1L
- (c) 1024f
- (d) 3.14L

(a): Who goes with Fergus?(换行)，string 类型：\145转为二进制001100101，ASCII表查询为e；\012转为二进制000001010，ASCII表查询为转义字符\n，即换行。

(b): long double

(c): 无效，因为后缀 f 只能用于浮点字面量，而 1024 是整型。

(d): long double

参考：
* [ASCII Code](https://www.ascii-code.com/)
* [ASCII Table](http://www.asciitable.com/)

转义序列的格式：
- 反斜杠\后面跟着八进制的数字超过3个时，只有前三个与\构成转义序列。例如"\1234"表示两个字符，字符\123和字符4
- \x会用到后面所有数字，例如"\x1234"表示一个16bit的字符，这种16bit字符一般都是与扩展字符集使用（用前缀表示，如u8啥的）。

## [练习2.8](2_8.cpp)

> 请利用转义序列编写一段程序，要求先输出 2M，然后转到新一行。修改程序使其先输出 2，然后输出制表符，再输出 M，最后转到新一行。

```cpp
#include <iostream>

int main()
{
    std::cout << "\062\115\012";
    std::cout << "\062\t\115\012";
    return 0;
}
```

## 练习2.9

> 解释下列定义的含义，对于非法的定义，请说明错在何处并将其改正。
- (a) std::cin >> int input_value;
- (b) int i = { 3.14 };
- (c) double salary = wage = 9999.99;
- (d) int i = 3.14;

(a): 应该先定义再使用。
```cpp
int input_value = 0;
std::cin >> input_value;
```

(b): 用列表初始化内置类型的变量时，如果存在丢失信息的风险，则编译器将报错。
```cpp
double i = { 3.14 };
```

(c): 在这里 wage 是未定义的，应该在此之前将其定义。
```cpp
double wage;
double salary = wage = 9999.99;
```
或者
```cpp
double wage, salary = wage = 9999.99;
```

(d): 不报错，但是小数部分会被截断。
```cpp
double i = 3.14;
```

## 练习2.10

> 下列变量的初值分别是什么？
```cpp
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}
```

`global_int` 是全局变量，所以初值为 0 。
`local_int` 是局部变量并且没有初始化，它的初值是未定义的。
`global_str` 和 `local_str` 是 string 类的对象，该对象定义了默认的初始化方式，即初始化为空字符串。

**P.S. 要养成良好习惯，初始化每个内置类型的变量，避免这种未定义造成程序运行故障（无法预计的故障）。**

## 练习2.11

> 指出下面的语句是声明还是定义：
- (a) extern int ix = 1024;
- (b) int iy;
- (c) extern int iz;

```
(a): 定义
(b): 定义
(c): 声明
```

## 练习2.12

> 请指出下面的名字中哪些是非法的？
- (a) int double = 3.14;
- (b) int _;
- (c) int catch-22;
- (d) int 1_or_2 = 1;
- (e) double Double = 3.14;

`(a)`, `(c)`, `(d)` 非法。

标识符由**字母、数字和下划线**组成。开头必须是**字母或下划线**。（C++中用户自定义的标识符，**不能连续出现两个下划线，不能以下划线紧连大写字母开头**）

## 练习2.13

> 下面程序中 j 的值是多少？
```cpp
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```

`j` 的值是 `100` ，局部变量 `i` 覆盖了全局变量 `i` 。

## 练习2.14

> 下面的程序合法吗？如果合法，它将输出什么？
```cpp
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
    sum += i;
std::cout << i << " " << sum << std::endl;
```

合法。输出是 ` 100 45 ` 。

## 练习2.15

> 下面的哪个定义是不合法的？为什么？
- (a) int ival = 1.01;
- (b) int &rval1 = 1.01;
- (c) int &rval2 = ival;
- (d) int &rval3;

`(b)` 和 `(d)` 不合法，`(b)` 引用必须绑定在对象上，`(d)` 引用必须初始化。

**引用（左值引用）只能绑定在对象上，而且必须初始化。**

## 练习2.16

> 考察下面的所有赋值然后回答：哪些赋值是不合法的？为什么？哪些赋值是合法的？它们执行了哪些操作？
```
int i = 0, &r1 = i; double d = 0, &r2 = d;
- (a) r2 = 3.14159;
- (b) r2 = r1;
- (c) i = r2;
- (d) r1 = d;
```

```
(a): 合法。给 d 赋值为 3.14159。
(b): 合法。会执行自动转换（这里的自动转换不是指改变原有类型，int->double，先转换再赋值）。
(c): 合法。会发生小数截断。
(d): 合法。会发生小数截断。
```

## 练习2.17

> 执行下面的代码段将输出什么结果？
```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```

输出：
```
10 10
```

## 练习2.18

> 编写代码分别改变指针的值以及指针所指对象的值。

```cpp
int a = 0, b = 1;
int *p1 = &a, *p2 = p1;

// change the value of a pointer.
p1 = &b;
// change the value to which the pointer points
*p2 = b;
```

## 练习2.19

> 说明指针和引用的主要区别

1. 引用是另一个对象的别名（但不是对象），而指针本身就是一个对象。
2. 引用必须初始化，并且一旦定义了引用就无法再绑定到其他对象。而指针无须在定义时赋初值，也可以重新赋值让其指向其他对象。

## 练习2.20

> 请叙述下面这段代码的作用。
```cpp
int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
```

让指针 `pi` 指向 `i`，然后将 `i` 的值重新赋值为 42 * 42 (1764)。

## 练习2.21

> 请解释下述定义。在这些定义中有非法的吗？如果有，为什么？
```
int i = 0;
(a) double* dp = &i;
(b) int *ip = i;
(c) int *p = &i;
```

```
(a): 非法。不能将一个指向 `double` 的指针指向 `int` 。
(b): 非法。不能将 `int` 变量赋给指针。
(c): 合法。
```

## 练习2.22

> 假设 p 是一个 int 型指针，请说明下述代码的含义。
```cpp
if (p) // ...
if (*p) // ...
```
`if (p) // ...`  判断 p 是不是一个空指针,
`if (*p) // ...` 判断 p 所指向的对象的值是不是为 0

## 练习2.23

> 给定指针 p，你能知道它是否指向了一个合法的对象吗？如果能，叙述判断的思路；如果不能，也请说明原因。

不能，因为首先要确定这个指针是不是合法的，才能判断它所指向的对象是不是合法的。

书本P47，指针具有4种状态，指向对象只是状态之一。

## 练习2.24

> 在下面这段代码中为什么 p 合法而 lp 非法？
```cpp
int i = 42;
void *p = &i;
long *lp = &i;
```

`void *` 是（从C语言那里继承过来的，这句话存疑，暂未查证），可以指向任何类型的对象（即可以存放任意对象的地址）。而其他指针类型必须要与所指对象严格匹配。

注意，`void *`不是空指针，空指针是null pointer，不指向任何对象，字面值常用`nullptr`。

## 练习2.25

> 说明下列变量的类型和值。
- (a) int* ip, i, &r = i;
- (b) int i, *ip = 0;
- (c) int* ip, ip2;

```
(a): ip是一个指向int的指针（块作用域内不赋初值），i是一个int（块作用域内不赋初值）, r是i的引用（同上）。
(b): i是int（块作用域内不赋初值），ip是一个空指针（不指向任何对象）。
(c): ip是一个指向int的指针（块作用域内不赋初值）, ip2是一个 int（块作用域内不赋初值）。
```

作用域：全局作用域（global scope）和块作用域（block scope），一般块作用域习惯称为局部作用域。

面对一条复杂的指针或引用的声明语句时，从右往左阅读：
```cpp
int ival = 1024;
int *pi = &ival;
int **ppi = &pi; // ppi是指向指针的指针
int **ppi = 0// 为访问最原始的对象，需要两次解引用 **ppi
int *&r = pi // 从右往左阅读，&r是一个引用，*说明r引用的是指针，int类型则具体说明了r引用的是int指针。
```

## 练习2.26

> 下面哪些语句是合法的？如果不合法，请说明为什么？
```cpp
const int buf;      // 不合法, const 对象必须初始化
int cnt = 0;        // 合法
const int sz = cnt; // 合法
++cnt; ++sz;        // ++sz不合法, const 对象不能被改变
```

## 练习2.27

> 下面的哪些初始化是合法的？请说明原因。
```cpp
int i = -1, &r = 0;         // 不合法, r必须引用一个对象（非常量引用的初始值必须是一个对象）
int *const p2 = &i2;        // 合法
const int i = -1, &r = 0;   // 合法，常量引用可以非常量的对象、绑定字面值、一般表达式
const int *const p3 = &i2;  // 合法
const int *p1 = &i2;        // 合法
const int &const r2;        // 不合法, r2是引用，引用没有顶层 const（引用只是对象的别名）
const int i2 = i, &r = i;   // 合法
```

## 练习2.28

> 说明下面的这些定义是什么意思，挑出其中不合法的。
```cpp
int i, *const cp;       // 不合法，cp未初始化，const指针必须初始化（指针常量要初始化）
int *p1, *const p2;     // 不合法，p2未初始化，const指针必须初始化
const int ic, &r = ic;  // 不合法，ic未初始化，const int必须初始化
const int *const p3;    // 不合法，p3未初始化，const指针必须初始化
const int *p;           // 合法。一个指针，指向 const int（常量指针）
```

**一个常量对象必须初始化，一旦初始化其值就不能再改变。**

## 练习2.29

> 假设已有上一个练习中定义的那些变量，则下面的哪些语句是合法的？请说明原因。
```cpp
i = ic;     // 合法, 常量赋值给普通变量
p1 = p3;    // 不合法, p3是一个指向int常量的常量指针常量，p1是指向int变量的指针。指向const的指针，不能给普通指针赋值。
p1 = &ic;   // 不合法, 普通指针不能指向常量
p3 = &ic;   // 不合法, p3是常量指针常量，是一个常量，无法改变常量的值。
p2 = p1;    // 不合法，p2是指针常量，无法改变常量的值。
ic = *p3;   // 不合法, 虽然对p3解引用是一个int常量，但ic本身就是一个int常量，无法改变常量的值。
```

常量指针不能赋值给普通指针，因为它是指向常量（存储着常量的地址），如果允许赋值给普通指针，就意味着可以通过其他指针修改那个常量。不过可以赋值给另一个常量指针，因为它们都是指向常量，都是底层const。

而指针常量（const指针）是可以给普通指针赋值的。

引用的类型必须与其所引用的对象的类型一致，指针的类型必须与其所指对象的类型一致。但有例外情况（例如允许一个指向常量的指针指向一个非常量对象，当然，仅限于常量和非常量的区别，不是指int和double这种类型区别）。

**例外情况的解释：**
指向常量的指针或引用，并未规定所指的对象必须是一个常量。所谓的「指向常量」，只是规定不能通过指针或引用来改变对象的值（并未规定那个对象的值不能改变，这个值可以通过其他渠道改变）。通俗点讲：就是指针或引用“自以为是”，觉得自己指向了常量，所以会自觉地不去改变所指对象的值。

## 练习2.30

> 对于下面的这些语句，请说明对象被声明成了顶层const还是底层const？
```cpp
const int v2 = 0; int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```

v2是顶层const，v1是普通int；p1是普通指针，r1是对v1的引用；p2是底层const，p3既是顶层const也是底层const，r2是底层const。

- 顶层const：表示任意对象是常量，对任意数据类型都适用。顶层const指本身就是常量，常量只能初始化，不能被赋值。
- 底层const：表示所指或所引用对象是常量，只与指针、引用等复合类型的基本类型部分有关。（用于声明引用的const都是底层const）。拷贝时，要求两个对象具有相同的底层const或者两个对象之间的数据类型可以转换（非常量可以转常量）。

常量表达式是指值不会改变，在编译过程中就能得到计算结果的表达式。

constexpr类型声明的变量是由编译器验证变量的值是否是一个常量表达式。用constexpr声明的对象会把它置为顶层const，比如constexpr int *q = nullptr就相当于int *const q = nullptr。

## 练习2.31

> 假设已有上一个练习中所做的那些声明，则下面的哪些语句是合法的？请说明顶层const和底层const在每个例子中有何体现。
```cpp
r1 = v2; // 合法，顶层const在拷贝时不受影响
p1 = p2; // 不合法，p2是底层const，如果要拷贝必须要求p1也是底层const
p2 = p1; // 合法，int* 可以转换成const int*
p1 = p3; // 不合法，p3是一个底层const，p1不是
p2 = p3; // 合法，p2和p3都是底层const，拷贝时忽略掉顶层const
```

## 练习2.32

> 下面的代码是否合法？如果非法，请设法将其修改正确。
```
int null = 0, *p = null;
```
非法。（书本P49）把int变量直接赋给指针是错误的操作，即使int变量的值恰好等于0也不行。
修正方式1：
```
int null = 0, *p = 0;
```
修正方式2：
```cpp
const int null = 0, *p = &null;
```

## 练习2.33

> 利用本节定义的变量，判断下列语句的运行结果。
```cpp
a=42; // a 是 int
b=42; // b 是一个 int,(ci的顶层const在拷贝时被忽略掉了)
c=42; // c 也是一个int
d=42; // d 是一个 int *，所以语句非法
e=42; // e 是一个 const int *，所以语句非法
g=42; // g 是一个 const int 的引用，引用都是底层const，所以不能被赋值
```

**类型别名（typedef和using）**
```cpp
typedef double wages
using wages=double
// 注意指针和类型别名的应用
typedef char *pstring;
const pstring cstr = 0; // cstr是指向char的指针常量。注意不要理解成 cosnt char *cstr = 0，这是错误的，const在这里是修饰整个类型，应该是顶层const。
const pstring *ps; // ps是一个指针（实际就是指针的指针），它的对象是指向char的指针常量。
```

**auto关键字（让编译器通过初始值推断类型）**
- auto定义的变量必须有初值。
- auto一般会忽略掉顶层const，同时底层const会保留下来（若希望推断出的auto类型一个顶层const，明确指出const auto）。
- 引用的类型也可以设为auto，例如`auto &a=i`，但注意顶层const依然是会被忽略，`auto &b=42`是错误的，`const auto &b=42`才是正确的。

## [练习2.34](2_34.cpp)

> 基于上一个练习中的变量和语句编写一段程序，输出赋值前后变量的内容，你刚才的推断正确吗？如果不对，请反复研读本节的示例直到你明白错在何处为止。

## [练习2.35](2_35.cpp)

> 判断下列定义推断出的类型是什么，然后编写程序进行验证。
```cpp
const int i = 42;
auto j = i; const auto &k = i; auto *p = &i;
const auto j2 = i, &k2 = i;
```

j 是 int，k 是 const int的引用，p 是const int *，j2 是const int，k2 是 const int 的引用。

验证依靠hint即可（鼠标悬停在变量上），无需编译。


## [练习2.36](2_36.cpp)

> 关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值。
```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
```
a、b、c都是int类型，d是int &类型，即引用，绑定到a。
程序结束时的值：a、b、c、d都为4。

**decltype关键字（让编译器分析表达式来得到类型，不计算表达式的值）**
- 变量是否需要赋初值，看类型，如int可以不赋初值，引用必须要初值。
- decltype使用的表达式是一个变量时，则返回该变量的类型（包括顶层const和引用）。
- decltype使用的表达式不是一个变量时，则返回表达式结果的类型。

**decltype返回引用类型的情况：**
1. decltype(variable)时，variable本身是一个引用，返回引用类型。
2. 双层括号decltype((variable))返回的结果永远是引用类型。
3. decltype(表达式为解引用操作，如*p)，返回引用类型（解引用指针操作，得到指针所指的对象，还能给这个对象赋值）。

```cpp
int i = 42, *p = &i, &r = i;
decltype(r) a = i;   // a是引用，绑定到变量i
decltype(r + 0) b;   // b是int，b是一个未初始化的int
decltype((i)) c = i; // c是引用，绑定到变量i
decltype(*p) d = i;  // d是引用，绑定到变量i
```

## 练习2.37

> 赋值是会产生引用的一类典型表达式，引用的类型就是左值的类型。也就是说，如果 i 是 int，则表达式 i=x 的类型是 int&。根据这一特点，请指出下面的代码中每一个变量的类型和值。
```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```
a、b、c都是int类型，d是int &类型，即引用，绑定到a。
a的值为3，b的值为4，c的值为3，d的值为3。

## 练习2.38

> 说明由decltype 指定类型和由auto指定类型有何区别。请举一个例子，decltype指定的类型与auto指定的类型一样；再举一个例子，decltype指定的类型与auto指定的类型不一样。

- decltype依据类型决定是否需要赋初值，auto必须要有初值。
- decltype处理顶层const方式与auto不同，decltype会将顶层const保留起来，auto会忽略掉顶层const。

```cpp
int i = 0, &r = i;
// 相同 都是int
auto a = i;
decltype(i) b = i;

// 不同 d 是一个 int&
auto c = r;
decltype(r) d = r;
```

stackoverflow的[参考1](http://stackoverflow.com/questions/21369113/what-is-the-difference-between-auto-and-decltypeauto-when-returning-from-a-fun)和[参考2](http://stackoverflow.com/questions/12084040/decltype-vs-auto)有更多的讨论。

## 练习2.39

> 编译下面的程序观察其运行结果，注意，如果忘记写类定义体后面的分号会发生什么情况？记录下相关的信息，以后可能会有用。
```cpp
struct Foo { /* 此处为空  */ } // 注意：没有分号
int main()
{
    return 0;
}
```

提示应输入分号。

**关键字`class`和`struct`都可以用来定义数据类型（类）。**

## 练习2.40

> 根据自己的理解写出 Sales_data 类，最好与书中的例子有所区别。

```cpp
struct Sale_data
{
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double price = 0.0;
    //...
}
```

## 练习2.41

> 使用你自己的Sale_data类重写1.5.1节（第20页）、1.5.2节（第21页）和1.6节（第22页）的练习。眼下先把Sales_data类的定义和main函数放在一个文件里。

### 1.5.1节

```cpp
#include <iostream>
#include <string>

struct Sale_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sale_data book;
    double price;
    std::cin >> book.bookNo >> book.units_sold >> price;
    book.revenue = book.units_sold * price;
    std::cout << book.bookNo << " " << book.units_sold << " " << book.revenue << " " << price;

    return 0;
}
```

### 1.5.2节
```cpp
#include <iostream>
#include <string>

struct Sale_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sale_data book1, book2;
    double price1, price2;
    std::cin >> book1.bookNo >> book1.units_sold >> price1;
    std::cin >> book2.bookNo >> book2.units_sold >> price2;
    book1.revenue = book1.units_sold * price1;
    book2.revenue = book2.units_sold * price2;

    if (book1.bookNo == book2.bookNo)
    {
        unsigned totalCnt = book1.units_sold + book2.units_sold;
        double totalRevenue = book1.revenue + book2.revenue;
        std::cout << book1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if (totalCnt != 0)
            std::cout << totalRevenue / totalCnt << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;  // indicate failure
    }
}
```

### 1.6节

```cpp
#include <iostream>
#include <string>

struct Sale_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sale_data total;
    double totalPrice;
    if (std::cin >> total.bookNo >> total.units_sold >> totalPrice)
    {
        total.revenue = total.units_sold * totalPrice;

        Sale_data trans;
        double transPrice;
        while (std::cin >> trans.bookNo >> trans.units_sold >> transPrice)
        {
            trans.revenue = trans.units_sold * transPrice;

            if (total.bookNo == trans.bookNo)
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else
            {
                std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
                if (total.units_sold != 0)
                    std::cout << total.revenue / total.units_sold << std::endl;
                else
                    std::cout << "(no sales)" << std::endl;

                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }

        std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
        if (total.units_sold != 0)
            std::cout << total.revenue / total.units_sold << std::endl;
        else
            std::cout << "(no sales)" << std::endl;

        return 0;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;  // indicate failure
    }
}
```

## 练习2.42

> 根据你自己的理解重写一个Sales_data.h头文件，并以此为基础重做2.6.2节（第67页）的练习。


- [1.5.1节](2_42_1.cpp)
- [1.5.2节](2_42_2.cpp)
- [1.6节](2_42_3.cpp)
