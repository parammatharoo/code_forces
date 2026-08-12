#include <iostream>
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
  int row = 0, column = 0, max = 1, final = 0, hc = 0, hr = 0;
  int starting = 0;

  for (int i = 0; i < matrix.size(); i++) {
    starting = 0;
    max = 1;

    for (int j = 0; j < matrix[0].size() - 1; j++) {
      if (matrix[i][j] == '#') {
        hr = i+1;
      }
      if (matrix[i][j] != '.' && matrix[i][j] == matrix[i][j + 1]) {
        max++;

        if (max > final) {
          final = max;
          row = i+1;
        }

      } else {
        max = 1;
      }
    }
  }

  std::string my_string;

  for (int i = 0; i < matrix[0].size(); i++) {
    my_string += matrix[row][i];
  }

  column = column_finder(my_string);

  std::cout << row << " " << column << std::endl;
}

int column_finder(std::string my_string) {
  int column = 0, max = 0, final = 0, helper = 0;

  for (int i = 0; i < my_string.size()-1; i++) {
    if (my_string[i] == '#') {
      helper = i+1;
    }

    if (my_string[i] != '.' && my_string[i] == my_string[i + 1]) {
      max++;
      if (max > final) {
        final = max;
        column = (i+1) - (max/2);
      }
    } else {
      max = 1;
    }
  }

  if (column == 0) {
    column = helper;
  }

  return column;
}

int main() {
  int t = 0, m = 0, n = 0, row = 0, column = 0;
  std::cin >> t;

  for (int i = 0; i < t; i++) {
    m = 0, n = 0, row = 0, column = 0;
    std::cin >> m >> n;

    std::vector<std::vector<char>> matrix;
    matrix.resize(m, std::vector<char>(n));

    my_input(matrix);
    checker(matrix);


  }

  return 0;
}
