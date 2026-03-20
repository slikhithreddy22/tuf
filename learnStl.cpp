#include <bits/stdc++.h>
#include <deque>
#include <map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// The c++ stl divided into 4 parts
// 1.Algorithms
// 2.Containers
// 3.Functions
// 4.Iterators
// --------------------------------------------------------------------------
// 1.functions
// while defining function we need to take care of 2 things return type and
// function name the return type must be mentioned if there infront of function
// name else keep it as void
void printMyName(string s) { cout << "The name is " << s << endl; }
int sumOf(int x, int y) { return x + y; }
void printLines(string s) {
  const std::string red("\033[1;31m");
  const std::string green("\033[1;32m");
  const std::string reset("\033[0m");
  cout << green << "---------------------- " << s << " ----------------------"
       << reset << endl;
}

// Pairs
void explainPairs() {
  pair<int, int> p = {1, 3};
  cout << p.first << " " << p.second << endl;
  pair<pair<int, int>, int> q = {{1, 2}, 3};
  cout << q.first.first << " " << q.first.second << " " << q.second << endl;
  pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
  cout << arr[1].second << endl;
}

// Vectors
void explainVectors() {
  vector<int> v;
  v.push_back(2); // First create the object and then add it to the v or else if
                  // object is ther then copy or move it to the container
  v.emplace_back(2); // Just constructs the object directly inside the container
  // There is no such effect difference between the push_back and emplace_back.
  // if we are appending an int but if we are doing it with pair<int,int> p then
  // for push_back it will create that object and appends it, but for the
  // emplace_back the pair is constructed in the vector
  vector<pair<int, int>> vec;
  vec.push_back({1, 3});
  vec.emplace_back(1, 3);

  vector<int> v1(5, 100); // {100,100,100,100,100}
  vector<int> v2(5);      // {0,0,0,0,0}
  vector<int> v3(5, 20);  // {20,20,20,20,20}
  vector<int> v4(v3);    // if we want to copy one container to other just write
                         // like this now the content in v3 and v4 are same
  cout << v4[2] << endl; // accesing the array
  vector<int> V = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  vector<int>::iterator it =
      V.begin(); // the v.begin give the address of first element ** it wont
                 // give the element, it will give the address
  cout << *(it)
       << endl; // To print the value in that address, star mean value at
  // now the 'it' is at address of 1 but if we do it = it+2 then it will be on
  // address of 2nd element.
  vector<int>::iterator it2 =
      V.end(); // here it will not reference to the last element 4 but it will
               // give the address of the last element + 1 so lets say if the
               // address of V[3] = 1000 then it will return 1004
  vector<int>::reverse_iterator it3 =
      V.rend(); // This will point to the front of the first index (not th value
                // at first index)
  vector<int>::reverse_iterator it4 =
      V.rbegin(); // Here it will start at exactly address of last element but
                  // if we increase then it will come to front like for now it
                  // is at V[3] so if we do it++ then it will go to V[2]
  cout << "Printing an array using for loop and iterators" << endl;
  for (vector<int>::iterator it = V.begin(); it != V.end(); it++) {
    cout << *(it) << " ";
  }
  cout << endl; // butttttttttttttttt no one wants to write the vector<int>::__
                // bla bla shit so
  for (auto it = V.begin(); it != V.end(); it++) {
    cout << *(it) << " ";
  }
  cout << endl; // this is gud but not that much sooooooooooooooooooooooooo

  for (auto it : V) { // this is called for-each loop
    cout << it << endl;
  }

  V.erase(
      V.begin() +
      1); // if there is only one param then delete the element in that position
  // if you want to delete more elements then
  V.erase(V.begin() + 1,
          V.begin() + 3); // if you want to delete the only 2nd and 3rd index
                          // then keep the second param next to it, so we kept
                          // it to 4th index.

  V.insert(V.begin(), 123); // if the insert has only 2 params then (pos,val)
  V.insert(V.begin() + 1, 2, 10); // inserting 10 2 times at position 2

  // lets say there is vector and you want to insert that into the another
  // vector.
  vector<int> copy(2, 50); // {50,50}
  V.insert(V.begin(), copy.begin(), copy.end());

  cout << "The size of a vector : " << V.size()
       << endl; // to get size of a vector
  V.pop_back(); // to pop the last most element
  V.clear();    // erases the entire vector
  cout << "The vector is empty : " << V.empty()
       << endl; // return boolean, true if vector was empty else false
}

void explainList() { // list is same as vector but it will give front operations
                     // as well
  list<int> ls;
  ls.push_back(2);
  ls.emplace_back(3);
  ls.push_front(1);
  ls.emplace_front(0);
}

void explainDeque() { // same as list
  deque<int> dq;
}

void explainStack() {
  stack<int> st;
  st.push(1);    // {1}
  st.push(2);    // {2,1}
  st.push(3);    // {3,2,1}
  st.push(3);    // {3,3,2,1}
  st.emplace(5); // {5,3,3,2,1}

  cout << "Top element is " << st.top() << endl; // prints 5
  st.pop();
  cout << "Top element is " << st.top() << endl; // print 3
  cout << "The size of stack is " << st.size() << endl;
  cout << "Is the stack is empty " << st.empty() << endl;
  stack<int> st1, st2;
  st1.swap(st2);
}

void explainQueue() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.emplace(0);

  cout << "Top last element is " << q.back() << endl;
  cout << "for first element it is q.front() so now " << q.front() << endl;
  q.pop();
}

// set : sorted && unique
// multiset : sorted && non unique
// unordered set : non sorted && unique

void explainMap() {
  map<int, int> mpp;
  mpp[1] = 1;
  mpp.emplace(2, 2);
  mpp.insert({3, 3});
}
int main() {
  printLines("1.Functions");
  printMyName("Likhith Reddy");
  cout << "The sum of 2 and 3 is " << sumOf(2, 3) << endl;
  printLines("1.Functions");
  printLines("2.Pairs");
  explainPairs();
  printLines("2.Pairs");
  printLines("3.Vectors");
  explainVectors();
  printLines("3.Vectors");

  return 0;
}
