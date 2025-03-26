// Copyright

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
        count += (right - left + 1) * (right - left) / 2;
        break;
      }
      int temp_left = left;
      int temp_right = right;
      while (arr[temp_left] == arr[left]) temp_left++;
      while (arr[temp_right] == arr[right]) temp_right--;
      count += (temp_left - left) * (right - temp_right);
      left = temp_left;
      right = temp_right;
    }
    else if (sum < value) left++;
    else right--;
  }
  return count;
}

int binarySearch(int *arr, int left, int right, int value) {
  int result = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] >= value) {
      if (arr[mid] == value) result = mid;
      right = mid - 1;
    }
    else left = mid + 1;
  }
  return result;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (i > 0 && arr[i] == arr[i-1]) continue;
    int target = value - arr[i];
    int pos = binarySearch(arr, i + 1, len - 1, target);
    if (pos != -1) {
      count++;
      while (pos + 1 < len && arr[pos] == arr[pos+1]) {
        count++;
        pos++;
      }
    }
  }
  return count;
}
