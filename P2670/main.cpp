#include <bits/stdc++.h>
using namespace std;

bool input[110][110];
int output[110][110];

int offset_x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int offset_y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool is_valid_coordinate(int x, int y, int n, int m) {
  return (x >= 0 && x < n) && (y >= 0 && y < m);
}

int main() {
  int n, m;
  cin >> n >> m;

  char c = '0';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> c;
      if (c == '*') {
        input[i][j] = true;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < 8; ++k) {
        int x = i + offset_x[k];
        int y = j + offset_y[k];
        if (is_valid_coordinate(x, y, n, m) && input[x][y]) {
          ++output[i][j];
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (input[i][j]) {
        cout << '*';
      } else {
        cout << output[i][j];
      }
    }
    cout << endl;
  }

  return 0;
}
