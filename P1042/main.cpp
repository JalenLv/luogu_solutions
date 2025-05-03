#include <iostream>
#include <string>
using namespace std;

bool is_end(int w, int l, int p) {
  return (w >= p || l >= p) && abs(w - l) >= 2;
}

void f(string s, int p) {
  int w_cnt = 0, l_cnt = 0;
  for (char c : s) {
    if (c == 'W') {
      ++w_cnt;
    } else {
      ++l_cnt;
    }

    if (is_end(w_cnt, l_cnt, p)) {
      cout << w_cnt << ":" << l_cnt << endl;
      w_cnt = 0; l_cnt = 0;
    }
  }

  cout << w_cnt << ":" << l_cnt << endl;
}

int main() {
  string input;
  char c;
  while (cin >> c) {
    if (c == 'E') break;
    input += c;
  }

  f(input, 11);
  cout << endl;
  f(input, 21);

  return 0;
}
