#include <algorithm>
#include <iostream>

int main() {
  int k = 0, max = 1, final = 1;
  char my_arr[16];

  // input k
  std::cin >> k;

  // input panel
  for (int i = 0; i < 16; i++) {
    std::cin >> my_arr[i];
  }

  // sorting panel
  std::sort(my_arr, my_arr + 16);

  // checking for most frequent character in panel
  for (int i = 0; i < 15; i++) {
    if (my_arr[i] == my_arr[i + 1] && my_arr[i] != '.') {
      max++;
      if (max > final) {
        final = max;
      }
    } else {
      max = 1;
    }
  }

  /* on the basis of most frequent panel
     chck what ever it's YES or NO
  */
  if (final > k * 2) {
    std::cout << "NO" << std::endl;
  } else
    std::cout << "YES" << std::endl;

  return 0;
}
