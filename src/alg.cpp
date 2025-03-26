#include <stdio.h>
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (i > 0 && arr[i] == arr[i-1]) continue;
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
        while (j + 1 < len && arr[j] == arr[j+1]) j++;
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
      int left_count = 1;
      int right_count = 1;
      while (left + 1 < right && arr[left+1] == left_val) {
        left++;
        left_count++;
      }
      while (right - 1 > left && arr[right-1] == right_val) {
        right--;
        right_count++;
      }
      count += left_count * right_count;
      left++;
      right--;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}
int binarySearch(int *arr, int left, int right, int value) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      while (mid > left && arr[mid-1] == value) mid--;
      return mid;
    } else if (arr[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    if (i > 0 && arr[i] == arr[i-1]) continue;
    int target = value - arr[i];
    int pos = binarySearch(arr, i+1, len-1, target);
    if (pos != -1) {
      int j = pos;
      while (j < len && arr[j] == target) {
        count++;
        j++;
      }
    }
  }
  return count;
}
