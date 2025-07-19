#include <bits/stdc++.h>
#include <cstring>
int matrix[1024][1024];

void f(int p1, int p2, int sz) {
  if (sz == 1)
    return;

  int mid = sz / 2;

  for (int i = p1; i < p1 + mid; i++) {
    for (int j = p2; j < p2 + mid; j++) {
      matrix[i][j] = 0;
    }
  }

  // f(p1, p2, mid);
  f(p1 + mid, p2, mid);
  f(p1, p2 + mid, mid);
  f(p1 + mid, p2 + mid, mid);
}

int main() {

  using namespace std;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int sz = 2;
  for (int i = 1; i < n; ++i) {
    sz *= 2;
  }

  for (int i = 0; i < sz; i++)
    for (int j = 0; j < sz; j++)
      matrix[i][j] = 1;

  f(0, 0, sz);

  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz; j++) {
      cout << matrix[i][j];
      if (j != sz - 1)
        cout << ' ';
      else
        cout << endl;
    }
  }

  return 0;
}
