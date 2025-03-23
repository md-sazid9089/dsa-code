#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--){
    int n, k;
    cin >> n >> k;
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int count1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[i] + b[j] == k) {
                count1++;
            }
        }
    }

    cout << count1 << endl;
  }
    return 0;
}
