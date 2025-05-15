#include <bits/stdc++.h>
using namespace std;

int a[510], b[510], c[510];
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

  len_c = max(len_a, len_b);
  for (int i = 0; i < len_c; ++i) {
    int tmp = a[i] + b[i];
    c[i] += tmp % 10;
    c[i+1] += tmp / 10;
  }
  for (int i = 0; i < len_c; ++i) {
    c[i+1] += c[i] / 10;
    c[i] %= 10;
  }
  if (c[len_c] != 0) { len_c += 1; }

  for (int i = len_c - 1; i >= 0; --i) {
    cout << c[i];
  }
  cout << endl;

  return 0;
}
