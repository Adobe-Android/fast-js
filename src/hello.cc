#include <iostream>
#include <chrono>
#include <thread>
#include <nan.h>

using namespace v8;
using namespace std::literals::chrono_literals;

NAN_METHOD(hello) {
  // Change the desired level of accuracy
  std::cout.precision(10);
  auto time_start = std::chrono::high_resolution_clock::now();
  int count = 0;
  for (int i = 0; i < 1'000'000'000; i++) {
    count = i;    
  }
  // slows things down to make it easier to measure
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  auto time_end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = time_end - time_start;
  std::cout << "hello from c++\n";
  std::cout << "c++ loop time (milliseconds): " << std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start).count() << "ms\n";
  std::cout << "c++ loop time (nanoseconds): " << std::chrono::duration_cast<std::chrono::nanoseconds>(time_end - time_start).count() << "ns\n";
}

NAN_MODULE_INIT(init) {
  Nan::SetMethod(target, "hello", hello);
}

NODE_MODULE(hello, init);
