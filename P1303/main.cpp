#include <bits/stdc++.h>
using namespace std;

int a[2010], b[2010], c[4020];
int len_a, len_b, len_c;

int main() {
  string s;
  cin >> s;
  len_a = s.length();
  for (int i = len_a - 1; i >= 0; --i) {
    a[(len_a - 1) - i] = s[i] - '0';
  }
  cin >> s;
  len_b = s.length();
  for (int i = len_b - 1; i >= 0; --i) {
    b[(len_b - 1) - i] = s[i] - '0';
  }

  len_c = len_a + len_b;
  for (int i = 0; i < len_b; ++i) {
    for (int j = 0; j < len_a; ++j) {
      c[i+j] += a[j] * b[i];
    }
  }
  for (int i = 0; i < len_c; ++i) {
    c[i+1] += c[i] / 10;
    c[i] %= 10;
  }
  while (c[len_c-1] == 0) { len_c -= 1; }

  for (int i = max(len_c - 1, 0); i >= 0; --i) {
    cout << c[i];
  }
  cout << endl;

  return 0;
}
