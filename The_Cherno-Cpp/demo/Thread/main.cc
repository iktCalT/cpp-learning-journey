#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork() {
  using namespace std::literals::chrono_literals;

  std::cout << "Working thread id=" << std::this_thread::get_id() << std::endl;

  while (!s_Finished) {
    std::cout << "Working..." << std::endl;
    std::this_thread::sleep_for(1s);
  }
}

int main() { // main thread
  // create a thread object named "worker"
  std::thread worker(DoWork); // pass a function pointer
  
  std::cin.get();
  s_Finished = true;
  
  worker.join(); // main thread will wait for worker thread to finish its jobs
  std::cout << "Main thread id=" << std::this_thread::get_id() << std::endl;
  std::cout << "Finished" << std::endl;
}