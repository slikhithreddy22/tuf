#include <iostream>
#include <vector>
using namespace std;

void bubble_sort_asc(vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr.size() - i - 1; j++) {
      if (arr[j + 1] < arr[j]) {
        swap(arr[j + 1], arr[j]);
      }
    }
  }
  for (int x : arr) {
    cout << x << " ";
  }
  cout << endl;
}

void bubble_sort_dsc(vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr.size() - i - 1; j++) {
      if (arr[j + 1] > arr[j]) {
        swap(arr[j + 1], arr[j]);
      }
    }
  }
  for (int x : arr) {
    cout << x << " ";
  }
  cout << endl;
}
int main() {
  vector<int> arr = {5, 2, 4, 6, 1, 3};
  bubble_sort_asc(arr);
  bubble_sort_dsc(arr);
}
