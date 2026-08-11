#include <iostream>
#include <vector>

void my_input(std::vector<std::vector<int>> &matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      std::cin >> matrix[i][j];
    }
  }
}

void checker(std::vector<std::vector<int>> &matrix) {
  int row = 0, column = 0, max = 1, final = 0;
  int starting = 0;

  for (int i = 0; i < matrix.size(); i++) {
    starting = 0;
    max = 1;
    for (int j = 0; j < matrix[0].size() - 1; j++) {
      if (matrix[i][j] == matrix[i][j + 1]) {
        max++;
        if (max > final) {
          final = max;
          row = i + 1;
          column = starting + max / 2 + 1;
        }
      } else {
        max = 1;
        starting = j + 1;
      }
    }
  }
  std::cout << row << " " << column << std::endl;
}

int main() {
  int t = 0, m = 0, n = 0, row = 0, column = 0;
  std::cin >> t;

  for (int i = 0; i < t; i++) {
    m = 0, n = 0, row = 0, column = 0;
    std::cin >> m >> n;

    std::vector<std::vector<int>> matrix;
    matrix.resize(m, std::vector<int>(n));

    my_input(matrix);
    checker(matrix);
  }

  return 0;
}
