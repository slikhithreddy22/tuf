#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

int delete_ele(vector<int> &arr, int n) {
  int result = arr[0];
  arr[0] = arr[n - 1];
  arr.pop_back();
  heapify(arr, n - 1, 0);
  return result;
}

int main() {
  vector<int> arr = {3, 2, 1, 5, 6, 4};
  int n = arr.size();
  for (int i = (n / 2) - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }
  int ans = 0;
  int k = 2;
  for (int i = 0; i < k; i++) {
    ans = delete_ele(arr, n - i);
  }
  cout << ans;
}
