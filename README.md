此仓库记录CPP模板相关的学习或者说是现代CPP相关的学习  

下面是一些杂项

# 1.string(_view)及其字面量

## 1.1.一些基本使用

```cpp
#include <iostream>
#include <string>
#include <string_view>

using namespace std::literals;                  // s
using namespace std::literals::string_literals; // sv
void f1(const char *c)
{
    std::cout << c << '\n';
}

void f2(std::string s)
{
    std::cout << s << '\n';
}

void f3(std::string_view s)
{
    std::cout << s << '\n';
}

int main()
{
    const char *c = "123";
    std::string s = "123"s;
    std::string_view sv = "123"sv;
    // 1.变量
    // f1
    f1(c);
    // f2
    f2(c);
    f2(s);
    // f3
    f3(c);
    f3(s);
    f3(sv);
    // 2.字面量
    // f1
    f1("123");
    // f2
    f2("123");
    f2("123"s);
    // f3
    f3("123");
    f3("123"s);
    f3("123"sv);
}
```

## 1.2.来看一段代码

```cpp
#include <iostream>
#include <string>
#include <string_view>

using namespace std::literals;                  // s
using namespace std::literals::string_literals; // sv

int main()
{
    std::string s = "123";
    std::string_view sv = s;
    std::cout << sv << '\n'; // 123
    s = "233";
    std::cout << sv << '\n'; // 233

    const char *cc = "123";
    sv = cc;
    std::cout << sv << '\n'; // 123
    cc = "233";
    std::cout << sv << '\n'; // 233
}
```

为什么std::string和const char *的行为不一样呢

看一下 s 和 cc 被赋值前后的地址

```cpp
#include <iostream>
#include <string>
#include <string_view>

using namespace std::literals;                  // s
using namespace std::literals::string_literals; // sv

int main()
{
    std::string s = "123";
    std::string_view sv = s;
    printf("%p\n", &s); // 0x16b84b088
    std::cout << sv << '\n'; // 123
    s = "233";
    printf("%p\n", &s); // 0x16b84b088
    std::cout << sv << '\n'; // 233

    std::cout << "------\n";

    const char *cc = "123";
    sv = cc;
    std::cout << sv << '\n'; // 123
    printf("%p\n", cc); // 0x1045b7ebc
    cc = "233";
    std::cout << sv << '\n'; // 233
    printf("%p\n", cc); // 0x1045b7ec4
}
```

这下应该明白了，std::string是在原地用“233”把"123"覆盖了

而const char * 在别处申请空间，放入字符串“233”然后把cc指向这个字符串

原来的字符串“123”还留在原地，sv拥有这个字符串的视图

[参考](https://blog.csdn.net/taosimin87/article/details/110629860)

# 2.reference_wrapper

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

[cppreference](https://zh.cppreference.com/w/cpp/utility/functional/reference_wrapper)

# 3.关于重载的一道题目

```cpp
template <typename T>
std::string puzzle(T input){
    if (input) {
        return "Lose!";
    } else if (!input) {
        return "Lose!";
    } else {
        return "Win!";
    }
}
```

如何返回`Win!`？

```cpp
//方法一
class A {
public:
	operator bool() {
		return false;
	}
	bool operator !() {
		return false;
	}
};
//方法二
class A {
public:
	operator bool() {
		cnt++;
		if (cnt == 1) return false;
		else return true;
	}
private:
	int cnt = 0;
}; 
```

