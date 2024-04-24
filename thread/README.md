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

# 2.std::lock()
# 3.std::lock_guard()

# 4.std::scoped_lock()

# 5.std::shared_lock()

# 6.std::unique_lock()
