#include <coroutine>
#include <iostream>
struct promise;
struct coroutine : std::coroutine_handle<promise>
{
    using promise_type = ::promise;
};
struct promise
{
    int result{};
    coroutine get_return_object()
    {
        return {coroutine::from_promise(*this)};
    }
    std::suspend_always initial_suspend() noexcept { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void return_void() {}
    void unhandled_exception() {}
};
struct X
{
    ~X() { std::puts("~X()"); }
};
coroutine f()
{
    std::puts("begin");
    X x;
    co_return;
}
int main()
{
    coroutine result = f();
    std::puts("main");
    result.resume();
}
