#include <iostream>
#include <vector>

int main() {
  int t = 0, a = 0, b = 0, c = 0;

  std::cin >> t;
  std::vector<std::string> answer(t, "NO");

  for (int i = 0; i < t; i++) {
    a = 0, b = 0, c = 0;

    std::cin >> a >> b >> c;

    if (a + b >= 10) {
      answer[i] = "YES";
      continue;
    } else if (a + c >= 10) {
      answer[i] = "YES";
      continue;
    } else if (b + c >= 10) {
      answer[i] = "YES";
      continue;
    }
  }

  for (int i = 0; i < t; i++) {
    std::cout << answer[i] << std::endl;
  }

  return 0;
}
