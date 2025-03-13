# 1.
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
[参考：求值顺序](https://zh.cppreference.com/w/cpp/language/eval_order)
# 2.
Q：`1.`中输出顺序的问题是“未指明”的，那它和“实现定义”有什么区别？
A：实现定义要求编译器给出文档
