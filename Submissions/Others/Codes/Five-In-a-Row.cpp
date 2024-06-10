#include <bits/stdc++.h>
using namespace std;

char a[11][11];
int n;

int left(int row, int col) {
  int ans = 0;
  for (int j = col - 1; j >= 1; j--) {
    if (a[row][j] == 'X') ans++;
    else break;
  }
  return ans;
}

int right(int row, int col) {
  int ans = 0;
  for (int j = col + 1; j <= n; j++) {
    if (a[row][j] == 'X') ans++;
    else break;
  }
  return ans;
}

int up(int row, int col) {
  int ans = 0;
  for (int i = row - 1; i >= 1; i--) {
    if (a[i][col] == 'X') ans++;
    else break;
  }
  return ans;
}

int down(int row, int col) {
  int ans = 0;
  for (int i = row + 1; i <= n; i++) {
    if (a[i][col] == 'X') ans++;
    else break;
  }
  return ans;
}

int diagonal1(int row, int col) {
  row--, col++;
  int ans = 0;
  while (row >= 1 and col <= n) {
    if (a[row][col] == 'X') ans++;
    else break;
    row--, col++;
  }
  return ans;
}

int diagonal2(int row, int col) {
  row--, col--;
  int ans = 0;
  while (row >= 1 and col >= 1) {
    if (a[row][col] == 'X') ans++;
    else break;
    row--, col--;
  }
  return ans;
}

int diagonal3(int row, int col) {
  row++, col--;
  int ans = 0;
  while (row <= n and col >= 1) {
    if (a[row][col] == 'X') ans++;
    else break;
    row++, col--;
  }
  return ans;
}

int diagonal4(int row, int col) {
  row++, col++;
  int ans = 0;
  while (row <= n and col <= n) {
    if (a[row][col] == 'X') ans++;
    else break;
    row++, col++;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  n = 10;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == '.') {
        if (left(i, j) + right(i, j) + 1 >= 5) {
          cout << "YES\n";
          return 0;
        }
        if (up(i, j) + down(i, j) + 1 >= 5) {
          cout << "YES\n";
          return 0;
        }
        if (diagonal1(i, j) + diagonal3(i, j) + 1 >= 5) {
          cout << "YES\n";
          return 0;
        }
        if (diagonal2(i, j) + diagonal4(i, j) + 1 >= 5) {
          cout << "YES\n";
          return 0;
        }
      }
    }
  }

  cout << "NO\n";

  return 0;
}