#include <functional>
#include <future>
#include <iostream>
#include <utility>
#include <vector>

// An easier example - calculate sum
// Run it with 
// g++ -O0 -g async.cc -o output/async && cd ./output && ./async
#define N 10

static std::mutex s_MeshesMutex;
struct Timer {
  std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
  std::chrono::duration<float> duration;

  // constructor
  Timer() {
    start = std::chrono::high_resolution_clock::now();
  }

  // destructor
  ~Timer() {
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;

    float ms = duration.count() * 1000.0f;
    std::cout << "Timer took " << ms << "ms" << std::endl;
  }
};

void sumPartial(long long &sum, int start, int end) {
  // return start * ... * end
  long long addition = 0;
  for (int i = start; i <= end; ++i) {
    addition += i;
  }

  std::lock_guard<std::mutex> lock(s_MeshesMutex);
  sum += addition;
  // std::cout << "Start: " << start << " End: " << end << " Times: " << times
  // << " Sum: " << sum << std::endl;
}

long long sumAsync(int n) {
  // Divide into N groups
  long long sum = 1;
  std::vector<std::pair<int, int>> groups;
  groups.reserve(N);

  int step = (n + 9) / 10;
  for (int i = 0; i < N; ++i) {
    if ((i + 1) * step < n) {
      groups.emplace_back(std::pair<int, int>{i * step + 1, (i + 1) * step});
    } else {
      groups.emplace_back(std::pair<int, int>{i * step + 1, n});
      break;
    }
  }

  std::vector<std::future<void>> futures;
  for (const auto &group : groups) {
    futures.push_back(std::async(std::launch::async, sumPartial, std::ref(sum),
                                 group.first, group.second));
  }
  for (auto& future : futures) {
    future.wait();
  }
  return sum;
}

long long sumSync(int n) {
  if (n <= 0)
    return -1;
  long long sum = 1;
  for (int i = 1; i <= n; ++i) {
    sum += i;
  }
  return sum;
}

int main() {
  {
    Timer timer;
    std::cout << sumSync(100000000) << std::endl;
  }

  {
    Timer timer;
    std::cout << sumAsync(100000000) << std::endl;
  }
}