#include <iostream>

#ifdef PR_DEBUG
#define LOG(x)                                                                 \
  std::cout << x << std::endl; // If we are in debug mode, LOG(x) means print
                               // out to console
#else
#define LOG(x) // If not in debug mode, LOG(x) is nothing.
#endif

int main() { LOG("Hello"); }