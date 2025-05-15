#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_LEN = 100;

struct big_int {
  int a[MAX_LEN];
  int len;

  int &operator[] (int i) { return a[i]; }
};

void init(big_int &a, int b) {
  a[0] = b;
  int i = 0;
  while (a[i] != 0 && i < MAX_LEN) {
    a[i+1] += a[i] / 10;
    a[i] %= 10;
    a.len += 1;
    ++i;
  }
}

big_int mult(big_int &a, big_int &b) {
  big_int retVal = {};

  retVal.len = a.len + b.len;
  for (int i = 0; i < b.len; ++i) {
    for (int j = 0; j < a.len; ++j) {
      retVal[i+j] += a[j] * b[i];
    }
  }
  for (int i = 0; i < retVal.len; ++i) {
    retVal[i+1] += retVal[i] / 10;
    retVal[i] %= 10;
  }
  while (retVal[retVal.len-1] == 0) { retVal.len -= 1; }

  return retVal;
}

big_int add(big_int &a, big_int &b) {
  big_int retVal = {};

  retVal.len = max(a.len, b.len);
  for (int i = 0; i < retVal.len; ++i) {
    int tmp = a[i] + b[i];
    retVal[i] += tmp % 10;
    retVal[i+1] += tmp / 10;
  }
  for (int i = 0; i < retVal.len; ++i) {
    retVal[i+1] += retVal[i] / 10;
    retVal[i] %= 10;
  }
  if (retVal[retVal.len] != 0) { retVal.len += 1; }

  return retVal;
}

void print(big_int &a) {
  for (int i = a.len-1; i >= 0; --i) {
    cout << a[i];
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  big_int result = {};
  big_int i_factorial = {};
  init(i_factorial, 1);
  for (int i = 1; i <= n; ++i) {
    big_int tmp = {};
    init(tmp, i);
    i_factorial= mult(i_factorial, tmp);
    result = add(result, i_factorial);
  }
  print(result);

  return 0;
}
