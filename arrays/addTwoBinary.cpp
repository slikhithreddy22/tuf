#include "iostream"
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
    string ans = "";
    int n = a.size() - 1;
    int m = b.size() - 1;
    cout << n << " " << m << endl;
    char carry = '0';
    while (n >= 0 && m >= 0) {
        if (a[n] == '0' && b[m] == '0') {
            if (carry == '1') {
                ans.push_back('1');
                carry = '0';
            } else {
                ans.push_back('0');
                carry = '0';
            }
            n--;
            m--;
        } else if (a[n] == '0' && b[m] == '1') {
            if (carry == '1') {
                ans.push_back('0');
                carry = '1';
            } else {
                ans.push_back('1');
                carry = '0';
            }
            n--;
            m--;
        } else if (a[n] == '1' && b[m] == '0') {
            if (carry == '1') {
                ans.push_back('0');
                carry = '1';
            } else {
                ans.push_back('1');
                carry = '0';
            }
            n--;
            m--;
        } else if (a[n] == '1' && b[m] == '1') {
            if (carry == '1') {
                ans.push_back('1');
                carry = '1';
            } else {
                ans.push_back('0');
                carry = '1';
            }
            n--;
            m--;
        }
    }
    while (n >= 0) {
        if (a[n] == '1' && carry == '1') {
            ans.push_back('0');
            carry = '1';
            n--;
        } else if (a[n] == '0' && carry == '1') {
            ans.push_back('1');
            carry = '0';
        } else {
            ans.push_back(a[n]);
        }
    }
    while (m >= 0) {
        if (b[m] == '1' && carry == '1') {
            ans.push_back('0');
            carry = '1';
            m--;
        } else if (b[m] == '0' && carry == '1') {
            ans.push_back('1');
            carry = '0';
        } else {
            ans.push_back(b[m]);
        }
    }
    if (carry == '1') {
        ans.push_back('1');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    cout << addBinary("1111", "1");
    return 0;
}
