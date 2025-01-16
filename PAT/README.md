# Programming Ability Test (PAT)

“程序设计类教学辅助教学平台”（Programming Teaching Assistant，亦简称 PTA）（依稀记得以前这玩意叫PAT），面向高校和社会的程序自动评测、开放式的教学辅助平台。

练习代码文件的仓库链接：[点击跳转](https://github.com/Mister-Kin/CodeTraining/tree/master/PAT)。

难点题解主要参考[PAT(tiny656)](https://github.com/tiny656/PAT)和[[PAT(枝桠)](https://gitee.com/branches/PAT)]

# [基础编程题目集](https://github.com/Mister-Kin/CodeTraining/tree/master/PAT/BasicProgrammingProblemSet)（[PTA平台](https://pintia.cn/problem-sets/14/exam/problems/type/6)）

## 函数题
### [6-1 简单输出整数](https://github.com/Mister-Kin/CodeTraining/blob/master/PAT/BasicProgrammingProblemSet/CodeCompletion/6-1-print_n.c)（[PTA平台](https://pintia.cn/problem-sets/14/exam/problems/type/6?problemSetProblemId=733)）
简单的`for`循环运用

### [6-2 多项式求值](https://github.com/Mister-Kin/CodeTraining/blob/master/PAT/BasicProgrammingProblemSet/CodeCompletion/6-2-multinomial_sum.c)（[PTA平台](https://pintia.cn/problem-sets/14/exam/problems/type/6?problemSetProblemId=734)）
先罗列多项式值，分析构成规律，再去考虑如何编写逻辑。（当年我是傻乎乎分开两个`for`循环处理，因此导致会导致部份用例运行超时）

### [6-3 简单求和](https://github.com/Mister-Kin/CodeTraining/blob/master/PAT/BasicProgrammingProblemSet/CodeCompletion/6-3-sum.c)（[PTA平台](https://pintia.cn/problem-sets/14/exam/problems/type/6?problemSetProblemId=735)）
`for`循环中应为`i<N`，注意`main`函数最后赋值的下标，即需要保持和`main`函数中`for`循环的条件一致。（当年是挺傻乎乎的）

### [6-4 求自定类型元素的平均](https://github.com/Mister-Kin/CodeTraining/blob/master/PAT/BasicProgrammingProblemSet/CodeCompletion/6-4-average.c)（[PTA平台](https://pintia.cn/problem-sets/14/exam/problems/type/6?problemSetProblemId=736)）
`for`循环中应为`i<N`，注意`main`函数最后赋值的下标，即需要保持和`main`函数中`for`循环的条件一致。

### [6-5 求自定类型元素的最大值](https://github.com/Mister-Kin/CodeTraining/blob/master/PAT/BasicProgrammingProblemSet/CodeCompletion/6-5-max_num.c)（[PTA平台](https://pintia.cn/problem-sets/14/exam/problems/type/6?problemSetProblemId=737)）
`for`循环中应为`i<N`，注意`main`函数最后赋值的下标，即需要保持和`main`函数中`for`循环的条件一致。

第一个MaxNum应该设为数组里的元素。如果设为0的话，当元素全为负数时，没法输出最大值。（也不知道我当年是怎么想出这种傻乎乎的逻辑）
