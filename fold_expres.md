形参包 和 折叠表达式
# 1.不定参数输出
```cpp
#include <iostream>
using namespace std;
template <typename... Args>
void f(Args... args)
{
    ((cout << args << ' '), ...);
}
int main()
{
    f(114, "514", 114.514);
}
```
# 2.加减法
```cpp
#include <iostream>
using namespace std;
template <typename... Args>
int add1(Args... args)
{
    // 一元右折叠
    return (args + ...);
    // return 1+(2+3)
}

template <typename... Args>
int add2(Args... args)
{
    //  二元左折叠
    return (10 + ... + args);
    // return ((10 + 1) + 2) + 3
}

template <typename... Args>
int sub1(Args... args)
{
    // 一元左折叠
    return (... - args);
    // return (1-2)-3
}

template <typename... Args>
int sub2(Args... args)
{
    // 二元右折叠
    return (args - ... - 10);
    // return 1 - (2 - (3 - 10))
}

int main()
{
    cout << add1(1, 2, 3) << '\n'; //6
    cout << add2(1, 2, 3) << '\n'; //16
    cout << sub1(1, 2, 3) << '\n'; //-4
    cout << sub2(1, 2, 3) << '\n'; //-8
}
```

# 3.common_type_t 自适应返回值
```cpp
// 茴香豆的茴有四种写法
#include <iostream>
using namespace std;

template <typename... Args, typename RT = common_type_t<Args...>>
RT f1(Args... args)
{
    return (args + ...);
}

template <typename... Args>
common_type_t<Args...> f2(Args... args)
{
    return (args + ...);
}

template <typename... Args>
auto f3(Args... args) -> common_type_t<Args...>
{
    return (args + ...);
}

template <typename... Args>
auto f4(Args... args) -> common_type_t<decltype(args)...>
{
    return (args + ...);
}
int main()
{
    cout << f1(1, 2, 3) << '\n';
    cout << f2(1, 2, 3.3) << '\n';
    cout << f3(1.1, 2, 3) << '\n';
    cout << f4(1, 2.2, 'a') << '\n';
}
```

参考：mq-b
