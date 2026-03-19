#include <iostream>
using namespace std;

bool odd(int n) { return (n & 1); }
bool powerOfTwo(int n) { return (n & (n - 1)) == 0; }
void swap(int x, int y) {
  cout << "The x and y before : " << x << " " << y << endl;
  x = x ^ y;
  y = x ^ y;
  x = x ^ y;
  cout << "The x and y after : " << x << " " << y << endl;
}
int main() {
  int a = 12, b = 25;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "a & b = " << (a & b) << endl;
  cout << "a | b = " << (a | b) << endl;
  cout << "a ^ b = " << (a ^ b) << endl;
  cout << "~a = " << (~a) << endl; // complement of any  number n is ~n = -(n+1)
  cout << "right shift of 3 = " << (3 >> 1)
       << endl; // right shift means moving all operators to right binary of 3
                // is 0011 so moving right by 1 is 0001 = 1
  cout << "left shift of 3 = " << (3 << 1)
       << endl; // left shift mean moving all opertors to left so moving left by
                // 1 is 0110 = 6
  cout << "checking whether 9 is odd : " << odd(9) << endl;
  cout << "checking whether 4 is odd : " << odd(4) << endl;
  cout << "checking whether 4 is powerOfTwo : " << powerOfTwo(4) << endl;
  cout << "checking whether 9 is powerOfTwo : " << powerOfTwo(9) << endl;
  cout << "swapping, x = 4 and y = 5 : " << endl;
  swap(4, 5);
  // so if z is 10 make it as 5 or if z is 5 make it as 10
  int z = 5;
  z = (10 ^ (5 ^ z));
  cout << "z : " << z << endl;
  // a+b = (a^b)+2(a&b)
  // a+b = (a|b)+(a&b)
}
