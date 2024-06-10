#include <bits/stdc++.h>
using namespace std;

bool ans;
int a, b, c;

void fun(int match, int score1, int score2, int score3) {
  if (match == 4) {
    if (a == score1 and b == score2 and c == score3) {
      ans = true;
    }
    return;
  }
  if (match == 1) {
    fun(match + 1, score1 + 3, score2 + 0, score3 + 0);
    fun(match + 1, score1 + 0, score2 + 3, score3 + 0);
    fun(match + 1, score1 + 1, score2 + 1, score3 + 0);
  }
  if (match == 2) {
    fun(match + 1, score1 + 3, score2 + 0, score3 + 0);
    fun(match + 1, score1 + 0, score2 + 0, score3 + 3);
    fun(match + 1, score1 + 1, score2 + 0, score3 + 1);
  }
  if (match == 3) {
    fun(match + 1, score1 + 0, score2 + 3, score3 + 0);
    fun(match + 1, score1 + 0, score2 + 0, score3 + 3);
    fun(match + 1, score1 + 0, score2 + 1, score3 + 1);
  }
}

int cs = 0;
void solve() {
  cin >> a >> b >> c;
  ans = false;
  fun(1, 0, 0, 0);
  cout << "Case " << ++cs << ": ";
  cout << (ans ? "perfectus\n" : "invalidum\n");
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}