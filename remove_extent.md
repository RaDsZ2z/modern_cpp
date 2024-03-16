

# 1.作用与用法

```cpp
//定义于 <type_traits>
template< class T >
struct remove_extent;
```
若 T 是某类型 X 的数组，则提供等于 X 的成员 typedef type ，否则 type 为 T 。注意若 T 是多维数组，则只移除第一维。

示例
```cpp
#include <iostream>    // std::cout
#include <type_traits> // std::is_same

int main()
{
    using T1 = int;
    using T2 = int[2];
    using T3 = int[2][2];
    using T4 = int[2][2][2];

    using U1 = std::remove_extent<T1>::type;
    using U2 = std::remove_extent<T2>::type;
    using U3 = std::remove_extent_t<T3>;
    using U4 = std::remove_extent_t<T4>;

    std::cout << typeid(T1).name() << '\n';
    std::cout << typeid(T2).name() << '\n';
    std::cout << typeid(T3).name() << '\n';
    std::cout << typeid(T4).name() << '\n';

    std::cout << '\n';

    std::cout << typeid(U1).name() << '\n';
    std::cout << typeid(U2).name() << '\n';
    std::cout << typeid(U3).name() << '\n';
    std::cout << typeid(U4).name() << '\n';
}
```
# 2.可能的实现
```cpp
template<class T>
struct remove_extent { typedef T type; };
 
template<class T>
struct remove_extent<T[]> { typedef T type; };
 
template<class T, std::size_t N>
struct remove_extent<T[N]> { typedef T type; };
```
# 3.扩展与变种
第二个模板的作用是使没有具体长度的数组类型T[]转化为T类型

顺便一提，声明多维数组时只有第一维的长度可以省略

如果没有第二个模板:
```cpp
#include <iostream>    // std::cout
#include <type_traits> // std::is_same

template <class T>
struct remove_extent
{
    typedef T type;
};

// template <class T>
// struct remove_extent<T[]>
// {
//     typedef T type;
// };

template <class T, std::size_t N>
struct remove_extent<T[N]>
{
    typedef T type;
};
int main()
{
    using T1 = int[5];
    using U1 = ::remove_extent<T1>::type;
    std::cout << std::is_same_v<T1, U1> << '\n';

    using T2 = int[];
    using U2 = ::remove_extent<T2>::type;
    std::cout << std::is_same_v<T2, U2> << '\n';
}
```

一个思考：可不可以让它的作用变成“若T是多维数组，则最多移除前两维”呢？
当然可以
```cpp
//添加以下两个模板
template <class T, std::size_t N>
struct remove_extent<T[][N]>
{
    typedef T type;
};

template <class T, std::size_t N, std::size_t M>
struct remove_extent<T[N][M]>
{
    typedef T type;
};
int main()
{
    using T = int[][5][6];
    using U = ::remove_extent<T>::type;

    using T1 = int[4][5][6];
    using U1 = ::remove_extent<T1>::type;

    std::cout << std::is_same_v<U, int[6]> << '\n';
    std::cout << std::is_same_v<U1, int[6]> << '\n';
    //若 T 与 T1 分别是 int[][5] 与 int[4][5]
    //则 U 与 U1 都为 int 可自行测试
}
```
参考 [cppreference](https://zh.cppreference.com/w/cpp/types/remove_extent)
