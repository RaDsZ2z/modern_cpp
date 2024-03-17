[cppreference](https://zh.cppreference.com/w/cpp/utility/functional/reference_wrapper)

std::reference_wrapper 是包装引用于可复制、可赋值对象的类模板。它常用作将引用存储入无法正常保有引用的标准容器（类似 std::vector ）的机制。

辅助函数 std::ref 与 std::cref 常用于生成 std::reference_wrapper 对象。
```cpp
int main()
{
    std::vector<int> a = {1, 2, 3};
    std::vector<std::reference_wrapper<int>> b{a.begin(), a.end()};
    std::vector<decltype(std::ref(a[0]))> c{a.begin(), a.end()};
    std::vector<decltype(std::cref(a[0]))> d{a.begin(), a.end()};
    a[0] = 4;
    std::cout << b[0] << ' ' << c[0] << ' ' << d[0];
}

int main()
{
    int x = 0;
    std::vector<std::reference_wrapper<int>> b{x};
    std::vector<decltype(std::ref(x))> c{x};
    std::vector<decltype(std::cref(x))> d{x};
    x = 4;
    std::cout << b[0] << ' ' << c[0] << ' ' << d[0];
}
```
