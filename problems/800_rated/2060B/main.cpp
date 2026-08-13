#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int t = 0, n = 0, m = 0, previous = 0;
  int found = 0;

  std::cin >> t;

  std::vector<std::vector<int>> result(t);
  std::vector<std::vector<int>> my_v;

  for (int i = 0; i < t; i++) {
    n = 0, m = 0;
    previous = 2001;
    my_v.clear();

    // inputing size of vector
    std::cin >> n >> m;

    // resizing vector
    my_v.resize(n, std::vector<int>(m));

    // input vector
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        std::cin >> my_v[j][k];
      }
    }

    // sorting each sub array of vector
    for (int j = 0; j < n; j++) {
      std::sort(my_v[j].begin(), my_v[j].end());
    }
    // checking for permutation
    for (int j = 0; j < n * m; j++) {

      found = 0;

      for (int k = 0; k < n; k++) {

        if (!my_v[k].empty() && j == my_v[k][0]) {

          if (j < n) {
            // First round: create permutation
            result[i].push_back(k + 1);
          } else {
            // Later rounds must follow the same permutation
            if (result[i][j % n] != k + 1) {
              found = -1;
              break;
            }
          }

          my_v[k].erase(my_v[k].begin());

          found = 1;
          break;
        }
      }

      if (found == 0 || found == -1) {
        result[i].clear();
        result[i].push_back(-1);
        break;
      }
    }

    // printing value of result
    for (int i = 0; i < t; i++) {
      for (int j = 0; j < result[i].size(); j++) {
        std::cout << result[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  return 0;
}
