#include <iostream>
#include <string>
#include <vector>

int column_finder(std::string my_string);

void my_input(std::vector<std::vector<char>> &matrix) {

  for (int i = 0; i < matrix.size(); i++) {

    for (int j = 0; j < matrix[0].size(); j++) {
      std::cin >> matrix[i][j];
    }
  }
}

void checker(std::vector<std::vector<char>> &matrix) {

  int row = 0, column = 0;
  int max = 0, final = 0;
  int starting = 0;

  for (int i = 0; i < matrix.size(); i++) {

    max = 0;
    starting = 0;

    for (int j = 0; j < matrix[0].size(); j++) {

      if (matrix[i][j] == '#') {

        if (max == 0) {
          starting = j;
        }

        max++;

        if (max > final) {
          final = max;
          row = i + 1;

          column = starting + (max / 2) + 1;
        }

      } else {

        max = 0;
      }
    }
  }

  std::cout << row << " " << column << std::endl;
}

int main() {

  int t = 0, m = 0, n = 0;

  std::cin >> t;

  for (int i = 0; i < t; i++) {

    std::cin >> m >> n;

    std::vector<std::vector<char>> matrix;

    matrix.resize(m, std::vector<char>(n));

    my_input(matrix);

    checker(matrix);
  }

  return 0;
}
