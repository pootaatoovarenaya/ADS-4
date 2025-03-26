// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++)
      for (int j = 0; j < len; j++)
      if (i != j)
          if (arr[i]+arr[j] == value)
            k++;
  return k / 2;
}
int countPairs2(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    for (int j = len - 1; j > i; j--) {
      if (i != j) {
        if (arr[i]+arr[j] == value) {
          k++;
        }
      }
    }
  }
  return k;
}
int bin(int *arr, int l, int r, int x) {
  int il = l, jp = r, mid = 0; bool f = 0;
  while (il <= jp)  {
      mid = (il + jp) / 2;
      if (arr[mid] == x) {
          return bin(arr, l, mid - 1, x) + bin(arr, mid + 1, r, x) + 1;
      }
      if (x < arr[mid])
          jp = mid - 1;
      else
          il = mid + 1;
  }
  return 0;
}
int countPairs3(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
      k += bin(&arr[i + 1], 0 , len - i, value - arr[i]);
  }
  return k;
}
