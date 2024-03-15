# 1.标准库
```cpp
#include <iostream>
#include <type_traits>
using namespace std;
int main()
{
    cout << is_same_v<int, int> << '\n';
    cout << is_same_v<int, double> << '\n';
}
```
# 2.类模板变量模板
```cpp
#include <iostream>
using namespace std;
template <typename T1, typename T2>
struct _is_same
{
    constexpr static bool value = false;
};

template <typename T>
struct _is_same<T, T>
{
    constexpr static bool value = true;
};

template <typename T1, typename T2>
constexpr static bool _is_same_v = _is_same<T1, T2>::value;
int main()
{
    cout << _is_same<int, int>::value << '\n';
    cout << _is_same<int, void>::value << '\n';

    cout << _is_same_v<int, int> << '\n';
    cout << _is_same_v<int, void> << '\n';
}
```
# 3.变量模板
```cpp
#include <iostream>
using namespace std;
template <typename T1, typename T2>
constexpr static bool _is_same_v = false;

template <typename T>
constexpr static bool _is_same_v<T, T> = true;

int main()
{
    std::cout << _is_same_v<char, char> << '\n';
    std::cout << _is_same_v<char, int> << '\n';
}
```

参考：mq-b
