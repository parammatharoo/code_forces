#include <algorithm>
#include <iostream>
#include <vector>

struct solver {
  int k, n;
  std::vector<int> index, value;
};

std::vector<int> answer(solver s) {
  int change = 0;

  std::vector<int> answer;

  while (s.value.size() != 0) {

    for (int i = 0; i < s.index.size(); i++) {
      change = 0;
      for (int j = 0; j < s.index.size() - 1; j++) {
        if (s.value[j] < s.value[j + 1]) {
          std::swap(s.value[j], s.value[j + 1]);
          std::swap(s.index[j], s.index[j + 1]);
          change = 1;
        }
        if (s.value[j] == s.value[j + 1]) {
          if (s.index[j] > s.index[j + 1]) {
            std::swap(s.index[j], s.index[j + 1]);
            change = 1;
          }
        }
      }

      if (!change) {
        break;
      }
    }

    if (s.value[0] <= s.k) {
      s.value.erase(s.value.begin());
      answer.push_back(s.index[0]);
      s.index.erase(s.index.begin());
    } else {
      s.value[0] -= s.k;
    }
  }

  return answer;
}

int main() {
  int t = 0;

  std::cin >> t;

  std::vector<std::vector<int>> result(t);

  for (int i = 0; i < t; i++) {
    solver s;

    std::cin >> s.n >> s.k;

    s.value.resize(s.n);
    result[i].resize(s.n);

    for (int j = 0; j < s.n; j++) {
      std::cin >> s.value[j];
      s.index.push_back(j + 1);
    }

    result[i] = answer(s);
  }

  for (int i = 0; i < t; i++) {
    for (int j = 0; j < result[i].size(); j++) {
      std::cout << result[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
