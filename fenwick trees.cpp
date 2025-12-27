#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int i, int v) {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }

    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

    int findKth(int k) {
        int pos = 0;
        for (int i = 17; i >= 0; i--) {
            int next = pos + (1 << i);
            if (next <= n && bit[next] < k) {
                k -= bit[next];
                pos = next;
            }
        }
        return pos + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> H(N);
    vector<int> P(N);

    for (int i = 0; i < N; i++) cin >> H[i];
    for (int i = 0; i < N; i++) cin >> P[i];

    vector<int> order(N, -1);

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);

    // Sort by height (shortest to tallest)
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return H[a] < H[b];
    });

    Fenwick fw(N);

    for (int i = 1; i <= N; i++)
        fw.update(i, 1);

    for (int id : idx) {
        int pos = fw.findKth(P[id] + 1);
        order[pos - 1] = id + 1;   
        fw.update(pos, -1);     
    }

    for (int i = 0; i < N; i++)
        cout << order[i] << " ";

    return 0;
}
