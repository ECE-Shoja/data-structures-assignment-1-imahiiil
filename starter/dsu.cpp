#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

int findSet(int v) {
    while(v != parent[v])
        v = parent[v];
    return v;
}

void unionSet(int a, int b) {
    int rootA = findSet(a);
    int rootB = findSet(b);
    if(rootA == rootB) return;
    if(size[rootA] < size[rootB]){
        parent[rootA] = rootB;
        size[rootB] += size[rootA];
}

if(size[rootA] > size[rootB]){
    parent[rootB] = rootA;
    size[rootA] += size[rootB];
    
}
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    sz.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (q--) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == '+') {
            unionSet(a, b);
        } else if (type == '?') {
            if (findSet(a) == findSet(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
