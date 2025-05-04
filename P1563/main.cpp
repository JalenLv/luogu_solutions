#include <bits/stdc++.h>
using namespace std;

int n, m;
int inouts[100010];
string names[100010];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int inout;
    cin >> inout;
    inouts[i] = (inout == 0) ? 1 : -1;
    cin >> names[i];
  }

  int ans_index = 0;
  for (int i = 0; i < m; ++i) {
    int lr, s;
    cin >> lr >> s;
    lr = (lr == 1) ? 1 : -1;
    ans_index += lr * inouts[ans_index] * s;
    ans_index %= n;
    while (ans_index < 0) {
      ans_index += n;
    }
  }

  cout << names[ans_index] << endl;

  return 0;
}
