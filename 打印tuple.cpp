#include <iostream>
#include <tuple>
using namespace std;

template <typename... Args>
void print(tuple<Args...> &tp)
{
    [&]<size_t... I>(index_sequence<I...>)
    {
        ((cout << get<I>(tp) << ' '), ...);
    }(make_index_sequence<sizeof...(Args)>());
}
int main()
{
    tuple<int, double, string> tp{114, .514, "114514"};
    print(tp);
}
