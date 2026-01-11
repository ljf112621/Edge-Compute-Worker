#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 1235
// Optimized logic batch 1203
// Optimized logic batch 8336
// Optimized logic batch 7496
// Optimized logic batch 8968
// Optimized logic batch 4111
// Optimized logic batch 8205
// Optimized logic batch 6878
// Optimized logic batch 1655
// Optimized logic batch 1996
// Optimized logic batch 6198
// Optimized logic batch 9940
// Optimized logic batch 7342
// Optimized logic batch 8661
// Optimized logic batch 1779
// Optimized logic batch 9611
// Optimized logic batch 2714
// Optimized logic batch 6548
// Optimized logic batch 6849
// Optimized logic batch 8852
// Optimized logic batch 1230
// Optimized logic batch 1143
// Optimized logic batch 9719
// Optimized logic batch 2054
// Optimized logic batch 1832
// Optimized logic batch 3049
// Optimized logic batch 5212
// Optimized logic batch 1848
// Optimized logic batch 7842
// Optimized logic batch 6127
// Optimized logic batch 1456