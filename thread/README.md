std::lock

std::lock_guard

std::scoped_lock

对第一个锁传递参数std::adopt_lock，与对后两个锁传递该参数行为是不同的(?
# 1.std::mutex
```cpp
mutex.lock()
mutex.unlock()
mutex.try_lock()
```

# 2.std::lock_guard()

# 3.std::lock()
“它能一次性锁住多个互斥量，并且没有死锁风险”


# 4.std::scoped_lock()
“它通常比裸调用std::lock更好”

# 5.std::unique_lock()
拥有lock unlock 成员函数
对构造函数使用参数 std::adopt_lock 和 std::defer_lock
```cpp
//1.
std::mutex m;
int main() {
    m.lock();
    std::unique_lock<std::mutex>lock{ m,std::adopt_lock };
}
//2.
std::mutex m;
int main() {
    std::unique_lock<std::mutex>lock{ m,std::adopt_lock };
    lock.lock();
}
```
使用 std::defer_lock 构造函数不上锁，要求构造之后上锁

使用 std::adopt_lock 构造函数不上锁，要求在构造之前互斥量上锁

默认构造会上锁，要求构造函数之前和构造函数之后都不能再次上锁
# 6.std::shared_lock()
