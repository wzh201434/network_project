#include <condition_variable>
#include <deque>
#include <mutex>
#include <optional>

using namespace std;
class BlockDeque {
    // 阻塞队列
    // 生产者、消费者模型
    std::deque<int> data;
    std::mutex mtx;
    std::condition_variable cv;
    // bool close_;
  public:
    void push(int value);
    optional<int> pop();
    // BlockDeque() : close_(false) {};
    BlockDeque() = default;
    ~BlockDeque() = default;
};