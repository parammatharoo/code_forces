#include <iostream>

int main() {
  int l = 0, a = 0, b = 0;
  int p = 0, n = 0;

  std::cin >> l;

  for (int i = 0; i < l; i++) {
    a = 0, b = 0;

    std::cin >> a >> b;
    if (a > b) {
      p++;
    } else if (a < b) {
      n++;
    }
  }

  if (p >= n && p != 0)
    std::cout << "Happy Alex" << std::endl;
  else
    std::cout << "Poor Alex" << std::endl;

  return 0;
}
