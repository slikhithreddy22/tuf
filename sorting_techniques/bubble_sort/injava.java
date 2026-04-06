public static void bubble_sort_desc(int[] arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        arr[j] = arr[j] + arr[j + 1];
        arr[j + 1] = arr[j] - arr[j + 1];
        arr[j] = arr[j] - arr[j + 1];
      }
    }
  }
  printArray(arr);
}

public static void bubble_sort_asc(int[] arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        arr[j] = arr[j] + arr[j + 1];
        arr[j + 1] = arr[j] - arr[j + 1];
        arr[j] = arr[j] - arr[j + 1];
      }
    }
  }
  printArray(arr);
}

public static void printArray(int[] arr) {
  for (int x : arr) {
    System.out.print(x + " ");
  }
  System.out.println();
}

public static void main() {
  int[] arr = { 5, 2, 4, 6, 1, 3 };
  bubble_sort_asc(arr, 6);
  bubble_sort_desc(arr, 6);

}
