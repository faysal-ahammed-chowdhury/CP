#include <bits/stdc++.h>
using namespace std;

const int N = 11;
int n, a[N][N];

bool is_safe(int row, int col) {
  for (int i = 1; i <= row; i++) {
    if (a[i][col]) return false;
  }

  for (int i = row, j = col; i >= 1 and j >= 1; i--, j--) {
    if (a[i][j]) return false;
  }

  for (int i = row, j = col; i >= 1 and j <= n; i--, j++) {
    if (a[i][j]) return false;
  }

  return true;
}

void print() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j]) {
        cout << 'Q';
      }
      else {
        cout << '.';
      }
    }
    cout << '\n';
  }
  cout << '\n';
}

void fun(int i) {
  if (i == n + 1) {
    print();
    return;
  }

  for (int j = 1; j <= n; j++) {
    if (is_safe(i, j)) {
      a[i][j] = 1;
      fun(i + 1);
      a[i][j] = 0;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  fun(1);

  return 0;
}