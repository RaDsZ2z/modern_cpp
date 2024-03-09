# 1.cpp库
```cpp
#include <iostream>
#include <type_traits>
using namespace std;

int main()
{

    cout << is_void<void>::value << '\n';
    cout << is_void<int>::value << '\n';

    cout << is_void_v<void> << '\n';
    cout << is_void_v<int> << '\n';
}
```
# 2.类模板 变量模板
```cpp
#include <iostream>
using namespace std;

template <typename T>
class _is_void
{
public:
    static constexpr bool value = false;
};

template <>
class _is_void<void>
{
public:
    static constexpr bool value = true;
};

template <typename T>
constexpr bool _is_void_v = _is_void<T>::value;
int main()
{
    cout << _is_void<void>::value << '\n';
    cout << _is_void<int>::value << '\n';

    cout << _is_void_v<void> << '\n';
    cout << _is_void_v<int> << '\n';
}


```
# 3.变量模板
```cpp
#include <iostream>
using namespace std;

template <typename T>
constexpr bool _is_void_v = false;

template <>
constexpr bool _is_void_v<void> = true;

int main()
{
    cout << _is_void_v<void> << '\n';
    cout << _is_void_v<int> << '\n';
}
```
