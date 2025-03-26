// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int pairsFound = 0;
  for (int idx1 = 0; idx1 < len - 1; idx1++) {
    for (int idx2 = idx1 + 1; idx2 < len; idx2++) {
      if (arr[idx1] + arr[idx2] == value) pairsFound++;
    }
  }
  return pairsFound;
}

int countPairs2(int *arr, int len, int value) {
  int pairsFound = 0;
  int upperBound = len - 1;
  while (upperBound > 0 && arr[upperBound] > value) {
    upperBound--;
  }
  for (int current = 0; current < len; current++) {
    for (int reverseIdx = upperBound; reverseIdx > current; reverseIdx--) {
      if (arr[current] + arr[reverseIdx] == value) pairsFound++;
    }
  }
  return pairsFound;
}

int findOccurrences(int *array, int start, int end, int target) {
  int firstPos = -1;
  int low = start, high = end;
  while (low <= high) {
    int middle = low + (high - low) / 2;
    if (array[middle] >= target) {
      high = middle - 1;
      if (array[middle] == target) firstPos = middle;
    } else {
      low = middle + 1;
    }
  }
  if (firstPos == -1) return 0;
  int lastPos = firstPos;
  low = firstPos;
  high = end;
  while (low <= high) {
    int middle = low + (high - low) / 2;
    if (array[middle] <= target) {
      low = middle + 1;
      if (array[middle] == target) lastPos = middle;
    } else {
      high = middle - 1;
    }
  }
  return lastPos - firstPos + 1;
}

int countPairs3(int *arr, int len, int value) {
  int totalPairs = 0;
  for (int pos = 0; pos < len; pos++) {
    int complement = value - arr[pos];
    totalPairs += findOccurrences(arr, pos + 1, len - 1, complement);
  }
  return totalPairs;
}
