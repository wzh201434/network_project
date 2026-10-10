#include "block_deque.h"

void BlockDeque::push(int value) {
    std::lock_guard<std::mutex> lock(mtx);
    data.push_back(value);
    cv.notify_one();
}
optional<int> BlockDeque::pop() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this]() { return !data.empty(); });
    if (data.empty()) {
        return std::nullopt;
    }
    int value = data.front();
    data.pop_front();
    return value;
}