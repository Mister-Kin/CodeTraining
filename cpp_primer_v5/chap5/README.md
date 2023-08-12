# 第五章：语句

## 练习5.1

> 什么是空语句？什么时候会用到空语句？

只含有一个单独的分号的语句是空语句。如：
```cpp
;
```
如果在程序的某个地方，语法上需要一条语句但是逻辑上不需要，此时应该使用空语句。（建议做好注释说明空语句作用）
```cpp
//重复读入数据直至到达文件末尾或某次输入的值等于sought
while (cin >> s && s != sought)
    ;
```

## 练习5.2

> 什么是块？什么时候会用到块？

用花括号括起来的语句和声明的序列就是块。
```cpp
{
    // ...
}
```
如果在程序的某个地方，逻辑上需要多条语句，而语法上只能容纳一条语句，此时应该使用块。
```cpp
while (val <= 10) {
    sum += val;
    ++val;
}
```

## 练习5.3

> 使用逗号运算符重写（参见4.10节，第140页）1.4.1节的 while 循环，使它不再需要块，观察改写之后的代码可读性提高了还是降低了。

```cpp
while (val <= 10)
    sum += val, ++val;
```
代码的可读性降低了。

## 练习5.4

> 说明下列例子的含义，如果存在问题，试着修改它。
```cpp
(a) while (string::iterator iter != s.end()) { /* . . . */ }
(b) while (bool status = find(word)) { /* . . . */ }
        if (!status) { /* . . . */ }
```

* (a) 这个循环试图用迭代器遍历string，但是变量的定义应该放在循环的外面，目前每次循环都会重新定义一个变量，明显是错误的。
* (b) 这个循环的 while 和 if 是两个独立的语句，if 语句中无法访问 status 变量，正确的做法是应该将 if 语句包含在 while 里面，

## [练习5.5](5_5.cpp)

> 写一段自己的程序，使用if else 语句实现把数字转换为字母成绩的要求。

## [练习5.6](5_6.cpp)

> 改写上一题的程序，使用条件运算符（参见4.7节，第134页）代替if else语句。

## 练习5.7

> 改写下列代码段中的错误。
```cpp
(a) if (ival1 != ival2)
        ival1 = ival2
    else
        ival1 = ival2 = 0;
(b) if (ival < minval)
        minval = ival;
        occurs = 1;
(c) if (int ival = get_value())
        cout << "ival = " << ival << endl;
    if (!ival)
        cout << "ival = 0\n";
(d) if (ival = 0)
        ival = get_value();
```

* (a) `ival1 = ival2` 后面少了分号。
* (b) 应该用花括号括起来。
* (c) `if (!ival)` 应该改为 `else`。
* (d) `if (ival = 0)` 应该改为 `if (ival == 0)`。

## 练习5.8

> 什么是“悬垂else”？C++语言是如何处理else子句的？

C++语言规定else与它最近的尚未匹配的if匹配。

## [练习5.9](5_9.cpp)

> 编写一段程序，使用一系列if语句统计从cin读入的文本中有多少元音字母。

## [练习5.10](5_10.cpp)

> 我们之前实现的统计元音字母的程序存在一个问题：如果元音字母以大写形式出现，不会被统计在内。编写一段程序，既统计元音字母的小写形式，也统计大写形式，也就是说，新程序遇到'a'和'A'都应该递增 aCnt 的值，以此类推。

## [练习5.11](5_11.cpp)

> 修改统计元音字母的程序，使其也能统计空格、制表符、和换行符的数量。

## [练习5.12](5_12.cpp)

> 修改统计元音字母的程序，使其能统计以下含有两个字符的字符序列的数量：ff、fl和fi。

## 练习5.13

> 下面显示的每个程序都含有一个常见的编程错误，指出错误在哪里，然后修改它们。
```cpp
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++;
        case 'e': eCnt++;
        default: iouCnt++;
    }
(b) unsigned index = some_value();
    switch (index) {
        case 1:
            int ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size()-1;
            ivec[ ix ] = index;
    }
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1, 3, 5, 7, 9:
            oddcnt++;
            break;
        case 2, 4, 6, 8, 10:
            evencnt++;
            break;
    }
(d) unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```

* (a) 少了 break语句。
```cpp
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++; break;
        case 'e': eCnt++; break;
        default: iouCnt++; break;
    }
```
switch内部的控制流：如果某个case标签匹配成功，将从该标签开始往后顺序执行所有case分支，除非程序显式地中断了这一过程，比如添加break语句，否则直到switch的结尾处才会停下来。

* (b) 在 default 分支当中，ix 未定义。应该在外部定义ix。
```cpp
    unsigned index = some_value();
    int ix;
    switch (index) {
        case 1:
            ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = static_cast<int>(ivec.size())-1;
            ivec[ ix ] = index;
    }
```
* (c) case 后面应该用冒号而不是逗号。
```cpp
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1: case 3: case 5: case 7: case 9:
            oddcnt++;
            break;
        case 2: case 4: case 6: case 8: case 0:
            evencnt++;
            break;
    }
```
* (d) case 标签必须是整型常量表达式。
```cpp
    const unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```

## [练习5.14](5_14.cpp)

> 编写一段程序，从标准输入中读取若干string对象并查找连续重复出现的单词，所谓连续重复出现的意思是：一个单词后面紧跟着这个单词本身。要求记录连续重复出现的最大次数以及对应的单词。如果这样的单词存在，输出重复出现的最大次数；如果不存在，输出一条信息说明任何单词都没有连续出现过。例如：如果输入是：
```
how now now now brown cow cow
```
> 那么输出应该表明单词now连续出现了3次。

本题编程中使用了`std::pair`，`std::pair`是类模板，提供在一个单元存储两个相异类型对象的途径。
```cpp
template<
    class T1,
    class T2
> struct pair;
```
总共有两个成员对象：first和second。

示例：`std::pair<std::string, float>("aa", 1.1);`

## 练习5.15

> 说明下列循环的含义并改正其中的错误。
```cpp
(a) for (int ix = 0; ix != sz; ++ix) { /* ... */ }
    if (ix != sz)
        // . . .
(b) int ix;
    for (ix != sz; ++ix) { /* ... */ }
(c) for (int ix = 0; ix != sz; ++ix, ++sz) { /*...*/ }
```
修正如下：
```cpp
(a) int ix;
    for (ix = 0; ix != sz; ++ix)  { /* ... */ }
    if (ix != sz)
    // . . .
(b) int ix;
    for (; ix != sz; ++ix) { /* ... */ }
(c) for (int ix = 0; ix != sz; ++ix) { /*...*/ } //如果首次判断ix不等于sz，执行++sz将导致死循环。
```

## 练习5.16

> while 循环特别适用于那种条件不变、反复执行操作的情况，例如，当未达到文件末尾时不断读取下一个值。for 循环则更像是在按步骤迭代，它的索引值在某个范围内依次变化。根据每种循环的习惯各自编写一段程序，然后分别用另一种循环改写。如果只能使用一种循环，你倾向于使用哪种呢？为什么？

```cpp
// while循环读取输入
int i;
while ( cin >> i )
    // ...

// for循环读取输入
for (int i = 0; cin >> i;)
    // ...

// for循环遍历
for (int i = 0; i != size; ++i)
    // ...

// while循环遍历
int i = 0;
while (i != size)
{
    // ...
    ++i;
}
```
如果只能用一种循环，我会更倾向使用while循环，因为while的代码可读性更强。

## [练习5.17](5_17.cpp)

> 假设有两个包含整数的vector对象，编写一段程序，检验其中一个vector对象是否是另一个的前缀。为了实现这一目标，对于两个不等长的vector对象，只需挑出长度较短的那个，把它的所有元素和另一个vector对象比较即可。例如，如果两个vector对象的元素分别是0、1、1、2 和 0、1、1、2、3、5、8，则程序的返回结果为真。

## 练习5.18

> 说明下列循环的含义并改正其中的错误。
```cpp
(a) do
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    while (cin);
(b) do {
        // . . .
    } while (ival = get_response()); // 应该将ival 定义在循环外
(c) do {
        ival = get_response();
    } while (ival); // 应该将ival 定义在循环外
```
修正如下：
```cpp
(a) do { // 应该添加花括号
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    }while (cin);
(b) int ival;
    do {
        // . . .
    } while (ival = get_response()); // 应该将ival 定义在循环外
(c) int ival;
    do {
        ival = get_response();
    } while (ival); // 应该将ival 定义在循环外
```

## [练习5.19](5_19.cpp)

> 编写一段程序，使用do while 循环重复地执行下述任务：首先提示用户输入两个string对象，然后挑出较短的那个并输出它。

## [练习5.20](5_20.cpp)

> 编写一段程序，从标准输入中读取string对象的序列直到连续出现两个相同的单词或者所有的单词都读完为止。使用while循环一次读取一个单词，当一个单词连续出现两次时使用break语句终止循环。输出连续重复出现的单词，或者输出一个消息说明没有任何单词是连续重复出现的。

## [练习5.21](5_21.cpp)

> 修改5.5.1节（第171页）练习题的程序，使其找到的重复单词必须以大写字母开头。

## 练习5.22

> 本节的最后一个例子跳回到 begin，其实使用循环能更好的完成该任务，重写这段代码，注意不再使用goto语句。
```cpp
// 向后跳过一个带初始化的变量定义是合法的
begin:
    int sz = get_size();
    if (sz <= 0) {
        goto begin;
    }
```

用 `for` 循环修改效果如下：
```cpp
for (int sz = get_size(); sz <=0; sz = get_size())
    ;
```

## [练习5.23](5_23.cpp)

> 编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。

## [练习5.24](5_24.cpp)

> 修改你的程序，使得当第二个数是0时抛出异常。先不要设定catch子句，运行程序并真的为除数输入0，看看会发生什么？

## [练习5.25](5_25.cpp)

> 修改上一题的程序，使用try语句块去捕获异常。catch子句应该为用户输出一条提示信息，询问其是否输入新数并重新执行try语句块的内容。

异常处理（try-throw-catch）：
- 将错误处理代码和正常代码分离开：传统的错误处理代码中都会使用一系列的 if-else 条件判断来处理错误。这些条件判断代码和错误处理代码会混在正常的程序流中，降低代码的可读性和可维护性。使用 try/catch 块则能够将错误处理与正常流程分开。
- 个人理解：更像是一个高级goto语法。

大致的使用形式：
```cpp
try
{
    // 被保护的代码
    throw  // 抛出异常
}
catch ()
{
    // 异常处理
}
```
