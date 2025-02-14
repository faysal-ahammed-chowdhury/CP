#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int pref[30005];
  int tree[30005][20];

  int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
  }

  void build(int n) {
    for (int i = 1; i <= n; i++) {
      tree[i][0] = pref[i];
    }
    for (int k = 1; k < 20; k++) {
      for (int i = 1; i + (1 << k) - 1 <= n; i++) {
        tree[i][k] = min(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]);
      }
    }
  }

  int query(int l, int r) {
    int k = log2_floor(r - l + 1);
    return min(tree[l][k], tree[r - (1 << k) + 1][k]);
  }

  int longestValidParentheses(string s) {
    int n = s.size();
    s = '.' + s;

    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + (s[i] == '(' ? 1 : -1);
    }

    build(n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        if (pref[i] == pref[j]) {
          int mn = query(j + 1, i);
          mn -= pref[j];
          if (mn >= 0) ans = max(ans, i - j);
        }
      }
    }
    return ans;
  }
};