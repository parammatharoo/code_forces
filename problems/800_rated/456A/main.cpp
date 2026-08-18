#include <iostream>

int main() {
  int t = 0, a = 0, b = 0, counter = 0;

  std::cin >> t;

  for (int i = 0; i < t; i++) {
    a = 0, b = 0;
    std::cin >> a >> b;

    if (a > b || b > a) {
      std::cout << "Happy Alex" << std::endl;
      return 0;
    }
  }

  std::cout << "Poor Alex" << std::endl;

  return 0;
}
