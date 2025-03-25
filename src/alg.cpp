// Copyright 2023 Your Name

#include <algorithm>

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) ++count;
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
        count += (right - left) * (right - left + 1) / 2;
        break;
      }
      int left_val = arr[left];
      int right_val = arr[right];
      while (left < len && arr[left] == left_val) ++left;
      while (right >= 0 && arr[right] == right_val) --right;
      count += (left - (left_val == arr[left] ? left : left - 1)) * 
               ((right_val == arr[right] ? right : right + 1) - right);
    } 
    else if (sum < value) ++left;
    else --right;
  }
  return count;
}

int binarySearch(int *arr, int left, int right, int target) {
  int result = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      result = mid;
      right = mid - 1; // Ищем первое вхождение
    } 
    else if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
  }
  return result;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    if (target < arr[i]) continue;
    int first = binarySearch(arr, i + 1, len - 1, target);
    if (first != -1) {
      while (first <= len - 1 && arr[first] == target) {
        ++count;
        ++first;
      }
    }
  }
  return count;
}
