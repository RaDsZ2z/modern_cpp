# 1.
`a++ + ++a`是[ub](https://en.cppreference.com/w/cpp/language/ub)吗？是的。  
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
上面代码的输出顺序是什么？任意顺序。  
[求值顺序](https://zh.cppreference.com/w/cpp/language/eval_order)
