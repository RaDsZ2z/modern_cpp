# 1.关于求值顺序
Q：`a++ + ++a`是[ub](https://en.cppreference.com/w/cpp/language/ub)吗？  
A：是的。  

```cpp
#include <cstdio>
 
int a() { return std::puts("a"); }
int b() { return std::puts("b"); }
int c() { return std::puts("c"); }
 
void z(int, int, int) {}
 
int main()
{
    z(a(), b(), c());       // 允许全部 6 种输出排列
}
```
Q：上面代码的输出顺序是什么？  
A：任意顺序。  

Q：`(a(), b(), c())`又输出什么  

A：`a\nb\nc`，逗号运算符求值顺序是从左到右  

参考：  

[1.求值顺序](https://zh.cppreference.com/w/cpp/language/eval_order)  

[2.内建的逗号运算符](https://zh.cppreference.com/w/cpp/language/operator_other#.E5.86.85.E5.BB.BA.E9.80.97.E5.8F.B7.E8.BF.90.E7.AE.97.E7.AC.A6)

# 2.未指明 和 实现定义
Q：`1.`中输出顺序的问题是“未指明”的，那它和“实现定义”有什么区别？  
A：实现定义要求编译器给出文档

# 3.表达式返回左值

Q：`(check(mid) ? l : r) = mid`可以修改`l`或`r`的值，等号左边返回的是左值吗？

A：TODO
