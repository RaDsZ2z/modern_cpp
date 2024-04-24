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

# 6.std::shared_lock()
