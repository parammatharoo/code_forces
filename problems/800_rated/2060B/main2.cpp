#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int t = 0, n = 0, m = 0;
  int found = 0;

  std::cin >> t;

  std::vector<std::vector<int>> result(t);
  std::vector<std::vector<int>> my_v;

  for (int i = 0; i < t; i++) {

    n = 0;
    m = 0;
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

          // First round: create permutation
          if (j < n) {
            result[i].push_back(k + 1);
          }

          // Later rounds: must follow same permutation
          else {
            if (result[i][j % n] != k + 1) {
              found = -1;
              break;
            }
          }

          // Remove the card that was played
          my_v[k].erase(my_v[k].begin());

          found = 1;
          break;
        }
      }

      // No cow can play this card OR
      // cow doesn't match the required permutation
      if (found != 1) {
        result[i].clear();
        result[i].push_back(-1);
        break;
      }
    }
  }

  // printing value of result
  for (int i = 0; i < t; i++) {

    for (int j = 0; j < result[i].size(); j++) {
      std::cout << result[i][j] << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}
