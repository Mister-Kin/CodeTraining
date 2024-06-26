# 第三章：字符串、向量和数组

## 练习3.1

> 使用恰当的using声明重做1.4.1节（第11页）和2.6.2节（第67页）的练习。

- [1.4.1](3_1_1.cpp)
- [2.6.2](3_1_2.cpp)

因为较为简单，每个小节就只写一个练习了。

using声明易造成名字冲突：
- 使用using声明，一般建议为每个名字做独立的using声明，例如`using std::cin`，不太建议使用整个命名空间，例如`using namespace std`，易造成名字冲突。
- 头文件不应包含using声明：易造成名字冲突。

## 练习3.2

> 编写一段程序从标准输入中一次读入一行，然后修改该程序使其一次读入一个词。

- [一次读入一行](3_2_1.cpp)
- [一次读入一个词](3_2_2.cpp)

## 练习3.3

> 请说明string类的输入运算符和getline函数分别是如何处理空白字符的。

- 类似 cin >> str 的读取，string对象会忽略开头的空白（空格符、换行符、制表符等）并从第一个真正的字符开始读起，直到遇见下一处空白为止。
- 类似 getline(cin, str) 的读取，string对象会从给定的输入流中读取内容，直到遇到换行符为止（换行符被读进来，但不会存放进对象）。

## 练习3.4

> 编写一段程序读取两个字符串，比较其是否相等并输出结果。如果不相等，输出较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。

- [比较大的](3_4_1.cpp)
- [长度大的](3_4_2.cpp)

## 练习3.5

> 编写一段程序从标准输入中读入多个字符串并将它们连接在一起，输出连接成的大字符串。然后修改上述程序，用空格把输入的多个字符串分隔开来。

- [无空格分隔](3_5_1.cpp)
- [空格分隔](3_5_2.cpp)

string对象操作的一些总结：
- **定义、初始化和基本操作看下面代码（书本见P76和P77）。**
- 关系运算符<、<=、>、>=比较规则：依次比较每个位置上的字符大小，若都一样时，则长度更长的字符串就更大。
- `string`和字符字面值和字符串字面值混在一条语句中，必须确保加法运算符「+」两侧至少有一个`string`对象（因为标准库可以将字面值转换为`string`对象，但不允许两个字面值直接相加）
- `size()`函数返回的是`string::size_type`类型的值，是无符号数。表达式中如果有`size()`，切记不要再使用`int`。如果需要定义变量存储`size()`函数，使用`auto`或`decltype`，例如`auto len = str.size()`
- **注意字符串字面值不是`string`对象，和`string`是不同的类型（因为需要兼容C）。**

```cpp
// 定义和初始化（等号是拷贝初始化，圆括号是直接初始化）
string s1;     //默认初始化为空串
string s2(s1); // s2是s1的副本
string s2 = s1; // 同上，不过是拷贝初始化
string s3 = ("hello"); // s3是字面值"hello"的副本（不包括字面值中的空字符）
string s3 = "hello"; // 同上
string s4(n, 'c'); // s4初始化为由n个字符c组成的串

// 基本操作
os << s; // 将s写到输出流os，返回os
is >> s; // 将输入流is读取字符串赋值给s，字符串以空白分割，返回is
getline(is, s); // 从输入流is读取一行赋值给s，返回is
s.empty(); // s为空返回true，否则返回false
s.size(); // 返回s中字符的个数
s[n]; // 返回s中第n个字符的引用，下标从0计起。
s1 + s2; // 返回s1和s2连接后的结果
s1 = s2; // 用s2的副本代替s1中原来的字符
s1 == s2; // 判断两个string对象是否相等，对字母大小写敏感
s1 != s2;
<, <=, >, >= ; // 利用字符在字典中的顺序进行比较，对字母大小写敏感
```

## [练习3.6](3_6.cpp)

> 编写一段程序，使用范围for语句将字符串内的所有字符用X代替。

**for范围语句中引用的理解：**
```cpp
for (auto &c : s)
    c = 'X';
// 等价于
for (auto itr = s.begin(); itr != s.end(); ++itr) {
    auto &c = *itr; // 每个迭代中用一个新引用绑定一个元素
    c = 'X';
}
```

## [练习3.7](3_7.cpp)

> 就上一题完成的程序而言，如果将循环控制变量的类型设为char将发生什么？先估计一下结果，然后实际编程进行验证。

字符串没有变化（因为c只是拷贝，即char，而非引用，即char &，所以无法改变字符串的）。
```cpp
string str("hello, world!");
for (char c : str)
    c = 'X';
```

## [练习3.8](3_8.cpp)

> 分别用while循环和传统for循环重写第一题的程序，你觉得哪种形式更好呢？为什么？

范围for语句更好，因为不需要直接操作索引，更简洁。

## 练习3.9

> 下面的程序有何作用？它合法吗？如果不合法，为什么？
```cpp
string s;
cout << s[0] << endl;
```

不合法。使用下标访问空字符串是非法的行为（通过下标访问不存在元素的行为会导致缓冲区错误buffer overflow，本质上就是下标越界，试图访问非法内存区域）。

**只能对确知已存在的元素执行下标操作：建议设下标类型为`decltype(str.size())`，这样可以确保下标不会小于0。写程序逻辑时，自己确保下标小于`str.size()`即可（或者使用范围for语句遍历更方便，能有效地确保下标合法，不会出现下标越界）。**

## [练习3.10](3_10.cpp)

> 编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分。

**C++标准库兼容C标准库**
C标准库头文件形如ctype.h，而在C++中，则是命名为cctype，即前面加一个c并且去除后缀.h。使用方式，标准库的名字可以在命名空间std找到。

## 练习3.11

> 下面的范围for语句合法吗？如果合法，c的类型是什么？
```cpp
const string s = "Keep out!";
for(auto &c : s){ /* ... */ }
```

要根据for循环体中的代码来看是否合法，s是常量，c是string对象中字符的引用（const char &）。因此如果for循环体中的代码重新给c赋值就会非法，如果不改变c的值，那么合法。
```cpp
cout << c;  // 合法
c = 'X';    // 不合法
```

## 练习3.12

> 下列vector对象的定义有不正确的吗？如果有，请指出来。对于正确的，描述其执行结果；对于不正确的，说明其错误的原因。
```cpp
vector<vector<int>> ivec;         // 在C++11当中合法，ivec的元素是vector对象
vector<string> svec = ivec;       // 不合法，类型不一样，ivec的元素是vector int，svec的元素是string
vector<string> svec(10, "null");  // 合法，svec有10个字符串："null"
```

## 练习3.13

> 下列的vector对象各包含多少个元素？这些元素的值分别是多少？
```cpp
vector<int> v1;         // 0个，无值
vector<int> v2(10);     // 10个，都是0
vector<int> v3(10, 42); // 10个，都是42
vector<int> v4{ 10 };     // 1个，10
vector<int> v5{ 10, 42 }; // 2个，10和42
vector<string> v6{ 10 };  // 10个，空串
vector<string> v7{ 10, "hi" };  // 10个，都是"hi"
```

初始化的括号区别：
- 圆括号：构造vector对象，即圆括号声明容量和初值。
- 花括号：列表初始化，用花括号的值作为元素初始值。（当提供的值不能用来列表初始化时，就会用来构造对象。如`vector<string> v1{10, "hi"};`，因为类型不同，所以构造成10个"hi"）

## [练习3.14](3_14.cpp)

> 编写一段程序，用cin读入一组整数并把它们存入一个vector对象。

**vctror对象能高效增长，在定义时设定其大小意义不大。开始时创建空vector，运行时再动态添加元素。**

## [练习3.15](3_15.cpp)

> 改写上题的程序，不过这次读入的是字符串。

## [练习3.16](3_16.cpp)

> 编写一段程序，把练习3.13中vector对象的容量和具体内容输出出来。检验你之前的回答是否正确，如果不对，回过头重新学习3.3.1节（第87页）知道弄明白错在何处为止。

## [练习3.17](3_17.cpp)

> 从cin读入一组词并把它们存入一个vector对象，然后设法把所有词都改写为大写形式。输出改变后的结果，每个词占一行。

## 练习3.18

> 下面的程序合法吗？如果不合法，你准备如何修改？
```cpp
vector<int> ivec;
ivec[0] = 42;
```

不合法（ivec是空vector对象，对其执行下标操作是非法行为）。修正方式：
```cpp
ivec.push_back(42);
```

## 练习3.19

> 如果想定义一个含有10个元素的vector对象，所有元素的值都是42，请列举出三种不同的实现方法，哪种方式更好呢？为什么？

```cpp
vector<int> ivec1(10, 42);
vector<int> ivec2{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
vector<int> ivec3;
for (int i = 0; i < 10; ++i)
    ivec3.push_back(42);
```
第一种方式最好。写法简洁。

## [练习3.20](3_20.cpp)

> 读入一组整数并把它们存入一个vector对象，将每对相邻整数的和输出出来。改写你的程序，这次要求先输出第1个和最后1个元素的和，接着输出第2个和倒数第2个元素的和，以此类推。

## [练习3.21](3_21.cpp)

> 请使用迭代器重做3.3.3节（第94页）的第一个练习。

迭代器的总结（本质上就是指针）：
- 类似于指针，解引用运算符*，可以获取迭代器指向的内容。
- 使用迭代器的循环体是用`!=`作为判断条件（像c或者java使用下标，多是用`<`）。因为C++中标准库容器的迭代器都定义了`==`和`!=`，而只有string和vector某些库才有下标运算符。
- 容器为空时，begin和end返回的是同一个迭代器（尾后迭代器）。
- 尾后迭代器指示的是不存在的“尾后”元素，实际并不指示某个元素，因此不能进行递增或者解引用操作。
- 只需读操作时，可用cbegin和cend函数。
- 箭头运算符是结合解引用和成员访问两个操作，即`it->men`等同于`(*it).men`。
- 使用了迭代器的循环体，不要向其所属的容器添加元素。例如，在循环体中向vector对象push_back，这会导致迭代器失效。（类似的，也不能在范围for循环中向vector对象添加元素）

## [练习3.22](3_22.cpp)

> 修改之前那个输出text第一段的程序，首先把text的第一段全都改成大写形式，然后输出它。

## [练习3.23](3_23.cpp)

> 编写一段程序，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值都变成原来的两倍。输出vector对象的内容，检验程序是否正确。

## [练习3.24](3_24.cpp)

> 请使用迭代器重做3.3.3节（第94页）的最后一个练习。

## [练习3.25](3_25.cpp)

> 3.3.3节（第93页）划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序并实现完全相同的功能。

## 练习3.26

> 在100页的二分搜索程序中，为什么用的是 mid = beg + (end - beg) / 2，而非 mid = (beg + end) / 2 ; ?

因为两个迭代器之间支持的运算符只有`-`和`>、>=、<、<=`，而没有`+` 。`end - beg` 相减的结果是之间的距离，将之除以2然后与beg相加，表示将beg移动到一半的位置。

迭代器运算的理解：迭代器可以加减一个数（包括加减复合赋值运算符），但两个迭代器之间的运算符只有`-`和`>、>=、<、<=`关系运算符。

## 练习3.27

> 假设txt_size是一个无参数的函数，它的返回值是int。请回答下列哪个定义是非法的？为什么？
```cpp
unsigned buf_size = 1024;
(a) int ia[buf_size];
(b) int ia[4 * 7 - 14];
(c) int ia[txt_size()];
(d) char st[11] = "fundamental";
```

- (a) 非法。纬度必须是一个常量表达式。
- (b) 合法。
- (c) 非法。txt_size返回的是int，不是constexpr int。
- (d) 非法。数组的大小应该是12，字符串字面值末尾还有个空字符'\0'。

## 练习3.28

> 下列数组中元素的值是什么？
```cpp
string sa[10];
int ia[10];
int main() {
	string sa2[10];
	int ia2[10];
}
```

sa的元素值全部为空字符串，ia的元素值全部为0。sa2的元素值全部为空字符串，ia2的元素没有被初始化，初值全部未定义。

## 练习3.29

> 相比于vector来说，数组有哪些缺点，请列举一些。

* 数组的大小是固定的，不能随意增加元素
* 不允许拷贝和赋值
* 没有像vector那样的API

## 练习3.30

> 指出下面代码中的索引错误。
```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
	ia[ix] = ix;
```

当ix等于10时，表达式ia[ix]属于未定义行为（UB），下标越界。

**通常将数组下标类型定义size_t，size_t定义在cstddef头文件，是一种机器相关的无符号类型，可以表示内存中任意对象的大小（因为被设计得足够大）。**

## [练习3.31](3_31.cpp)

> 编写一段程序，定义一个含有10个int的数组，令每个元素的值就是其下标值。

## [练习3.32](3_32.cpp)

> 将上一题刚刚创建的数组拷贝给另外一个数组。利用vector重写程序，实现类似的功能。

## 练习3.33

> 对于104页的程序来说，如果不初始化scores将会发生什么？

数组中所有元素的值将会未定义（有可能不是0，会有脏数据存在）。

## 练习3.34

> 假定p1和p2都指向同一个数组中的元素，则下面程序的功能是什么？什么情况下该程序是非法的？
```cpp
p1 += p2 - p1;
```

将p1移动到p2的位置，即指向同一个地址。只要p1、p2值合法，该程序任何情况下都合法。

## [练习3.35](3_35.cpp)

> 编写一段程序，利用指针将数组中的元素置为0。

**数组与指针的总结：**
- 数组名可以当作是首指针（编译器会自动将其转换成一个指向数组首元素的指针（函数传参、赋值给指针、表达式），但本质上数组名自身不是指针）
- 类似迭代器，也可以获取数组的首尾指针（假设数组int array[10]={xxx}。**类似尾迭代器，注意尾指针不指向具体元素，不能对其进行解引用或递增操作**）
  - `int *begin = array; int *end = &array[10];`
  - `int *begin = begin(array); int *end = end(array);` **begin和end函数定义在iterator头文件（数组不是类类型，没有类似vector迭代器那种成员函数）**
- 两个指针相减的结果类型是ptrdiff_t，是一种带符号类型，和size_t一样也定义在cstddef头文件。
- **只要指针指向数组元素（或者尾元素的下一位置，即尾指针），都可以执行下标运算（当然，需要保证运算后的指针也是指向同一数组或者尾指针）。像数组这种C++语言内置的下标运算允许处理负值，但像标准库类型string和vector则限定下标是无符号类型。**

```cpp
int *p = &array[2]; // p指向索引为2的元素
int j = p[1];       // p[1]等价于*(p+1)，即array[3]
int k = p[-2];      // 即array[0]
```

## [练习3.36](3_36.cpp)

> 编写一段程序，比较两个数组是否相等。再写一段程序，比较两个vector对象是否相等。

## 练习3.37

> 下面的程序是何含义，程序的输出结果是什么？
```cpp
const char ca[] = { 'h', 'e', 'l', 'l', 'o' };
const char *cp = ca;
while (*cp) {
    cout << *cp << endl;
    ++cp;
}
```

会将ca字符数组中的元素打印出来，但是因为没有空字符'\0'的存在，循环不会终止，会打印出来很多无意义脏数据。

## 练习3.38

> 在本节中我们提到，将两个指针相加不但是非法的，而且也没什么意义。请问为什么两个指针相加没什么意义？

**指针本质就是地址**，将两个指针相减可以表示两个指针(在同一数组中)的距离，将指针加上一个整数也可以表示移动这个指针到某一位置。**但是两个指针相加后的地址并没有逻辑上的意义。**

[参考资料](https://stackoverflow.com/questions/2935038/why-cant-i-add-pointers)

## [练习3.39](3_39.cpp)

> 编写一段程序，比较两个string对象。再编写一段程序，比较两个C风格字符串的内容。

**C标准库string函数（头文件cstring）**
- strlen(p) 返回p的长度，不计算空字符
- strcmp(p1,p2) 比较p1和p2，`p1==p2`则返回0；`p1>p2`则返回正值；`p1<p2`则返回负值
- strcat(p1,p2) p2附加到p1后，再返回p1
- strcpy(p1,p2) p2拷贝给p1，再返回p1

**注意这些函数的指针必须指向以空字符作为结束的数组**
```cpp
char ca[] = {'a', 'b'} // 没有以空字符结束。
cout << strlen(ca) << endl; // 严重错误，没有空字符，该函数有可能在内存中不断向前寻找，直至找到空字符。
// 修正方式：用字符串字面值给ca赋初值"ab"。
```

## [练习3.40](3_40.cpp)

> 编写一段程序，定义两个字符数组并用字符串字面值初始化它们；接着再定义一个字符数组存放前面两个数组连接后的结果。使用strcpy和strcat把前两个数组的内容拷贝到第三个数组当中。

## [练习3.41](3_41.cpp)

> 编写一段程序，用整型数组初始化一个vector对象。

## [练习3.42](3_42.cpp)

> 编写一段程序，将含有整数元素的vector对象拷贝给一个整型数组。

**使用数组初始化vector对象（不能用数组初始化数组；不能用vector对象初始化数组）**
```cpp
int array[] = {1, 2, 3, 4, 5};
vector<int> v(begin(array), end(array)); // 使用首尾指针
vector<int> subv(array + 1, array + 3); // 数组中的部分也可用来初始化
```

**混用string对象和C风格字符串**
- 允许使用以空字符结束的字符数组来初始化或赋值给string对象
- string对象的加法运算允许以空字符结束的字符数组作为其中一个运算对象（加法运算符「+」两侧至少有一个string对象）
- string复合赋值运算中允许以空字符结束的字符数组作为右侧运算对象
- string对象不能直接初始化指向字符的指针，需要使用成员函数`c_str`返回指针，如`const char *str = s.c_str();`

## [练习3.43](3_43.cpp)

> 编写3个不同版本的程序，令其均能输出ia的元素。版本1使用范围for语句管理迭代过程；版本2和版本3都使用普通for语句，其中版本2要求使用下标运算符，版本3要求使用指针。此外，在所有3个版本的程序中都要直接写出数据类型，而不能使用类型别名、auto关键字和decltype关键字。

## [练习3.44](3_44.cpp)

> 改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型。

## [练习3.45](3_45.cpp)

> 再一次改写程序，这次使用auto关键字。

**多维数组和指针的总结**
```cpp
// 多维数组本质上是数组的数组，初始化时内层嵌套的花括号也可去掉
int ia[2][2] = {{1, 2},
                {1, 3}};

// 使用范围for语句处理多维数组时，要将控制变量声明为引用类型（为避免编译器将其转换成指针）
for (auto &row : ia)
    for (auto &col : row)
        ;

// 定义指向多维数组的指针注意写法（手动写较易写错，建议使用auto或者decltype）
int *ip[2];          // 整型指针的数组
int(*ip)[2];         // 指针，指向含有2个整数的数组
int(&ip)[2] = ia[0]; // 引用，指向含有2个整数的数组
// 类型别名简化写法，下面两行等同于int(*ip)[2];
using int_array = int[2];
int_array *ip;
```
