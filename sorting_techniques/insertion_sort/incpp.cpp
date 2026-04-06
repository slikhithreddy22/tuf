#include <iostream>
#include <vector>
using namespace std;

void insertion_sort_asc(vector<int> &arr) {
  for (int i = 1; i < arr.size(); i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
  for (int x : arr) {
    std::cout << x << " ";
  }
  std::cout << endl;
}

void insertion_sort_dsc(vector<int> &arr) {
  for (int i = 1; i < arr.size(); i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && key > arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
  for (int x : arr) {
    cout << x << " ";
  }
  cout << endl;
}
int main() {
  vector<int> arr = {5, 2, 4, 6, 1, 3};
  insertion_sort_asc(arr);
  insertion_sort_dsc(arr);
  return 0;
}
