#include <algorithm>
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int left_val = arr[left];
      int right_val = arr[right];
      int left_count = 0;
      int right_count = 0;
      while (left < len && arr[left] == left_val) {
        ++left;
        ++left_count;
      }
      while (right >= 0 && arr[right] == right_val) {
        --right;
        ++right_count;
      }
      count += left_count * right_count;
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    if (target < arr[i]) {
      continue;
    }
    auto range = std::equal_range(arr + i + 1, arr + len, target);
    count += range.second - range.first;
  }
  return count;
}
