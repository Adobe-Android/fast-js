#include <iostream>
#include <chrono>
#include <thread>
#include <nan.h>

using namespace v8;
using namespace std::literals::chrono_literals;

NAN_METHOD(hello) {
  auto time_start = std::chrono::high_resolution_clock::now();
  int count = 0;
  for (int i = 0; i < 1'000'000'000; i++) {
    count = i;
    if (count == 999'999'999)
    {
      // Keeps the C++ compiler from being able to optimize away the for loop and just assign count to the value in the for loop - 1
      // Also forces a value to be checked on each iteration
      std::cout << "C++ count complete\n";
    }
    
  }
  auto time_end = std::chrono::high_resolution_clock::now();
  std::cout << "hello from C++\n";
  std::cout << "C++ loop time (nanoseconds, measured in C++): " << std::chrono::duration_cast<std::chrono::nanoseconds>(time_end - time_start).count() << "ns\n";
}

NAN_MODULE_INIT(init) {
  Nan::SetMethod(target, "hello", hello);
}

NODE_MODULE(hello, init);
