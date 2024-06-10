#include <bits/stdc++.h>
using namespace std;

struct Trie {
  const static int N = 26;
  const static char base_char = 'a'; // 'A' for 'A','B','C'
  struct TrieNode {
    int nxt[N];
    bool is_end;
    int cnt;
    TrieNode() {
      for (int i = 0; i < N; i++) {
        nxt[i] = -1;
      }
      is_end = false;
      cnt = 0;
    }
  };
  inline int get(char c) {
    return c - base_char;
  }
  vector<TrieNode> tree;
  Trie() {
    tree.push_back(TrieNode());
  }
  void insert(string &s) {
    int p = 0;
    tree[p].cnt++;
    for (int i = 0; i < s.size(); i++) {
      if (tree[p].nxt[get(s[i])] == -1) {
        tree.push_back(TrieNode());
        tree[p].nxt[get(s[i])] = tree.size() - 1;
      }
      p = tree[p].nxt[get(s[i])];
      tree[p].cnt++;
    }
    tree[p].is_end = true;
  }
  bool is_prefix(const string &s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      if (tree[p].nxt[get(s[i])] == -1) {
        return false;
      }
      p = tree[p].nxt[get(s[i])];
    }
    return true;
  }
  bool find(const string &s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      if (tree[p].nxt[get(s[i])] == -1) {
        return false;
      }
      p = tree[p].nxt[get(s[i])];
    }
    return tree[p].is_end;
  }
} trie;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}