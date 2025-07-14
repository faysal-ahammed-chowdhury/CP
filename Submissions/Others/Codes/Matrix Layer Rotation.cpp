#include <iostream>
using namespace std;

int n, m;
int a[305][305];

void rotate(int r) {
  int first_row = 1, last_row = n;
  int first_col = 1, last_col = m;

  while (true) {
    if (first_col > last_col) break;
    if (first_row > last_row) break;

    int mod = (2 * (last_row - first_row)) + (2 * (last_col - first_col));
    if (mod == 0) break;
    int it = r % mod;
    // cout << it << '\n';
    while (it--) {
      int val1 = a[first_row][first_col];
      int val2 = a[first_row][last_col];
      int val3 = a[last_row][first_col];
      int val4 = a[last_row][last_col];


      for (int j = first_col; j < last_col; j++) {
        a[first_row][j] = a[first_row][j + 1];
      }

      for (int i = last_row; i > first_row; i--) {
        a[i][first_col] = a[i - 1][first_col];
        if (i - 1 == first_row) {
          a[i][first_col] = val1;
        }
      }

      for (int j = last_col; j > first_col; j--) {
        a[last_row][j] = a[last_row][j - 1];
        if (j - 1 == first_col) {
          a[last_row][j] = val3;
        }
      }

      for (int i = first_row; i < last_row; i++) {
        a[i][last_col] = a[i + 1][last_col];
        if (i + 1 == last_row) {
          a[i][last_col] = val4;
        }
      }
    }

    first_row++, last_row--;
    first_col++, last_col--;
    // break;
  }
}

int32_t main() {
  int r; cin >> n >> m >> r;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  rotate(r);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }


  return 0;
}
