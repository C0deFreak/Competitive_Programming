#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    // učitava graf
    vector<vector<pair<int, long long>>> adj(n + 1);
    // udaljenost točaka na obali
    vector<long long> obala(n, 0);
    for (int i = 1; i < n; i++) {
        long long weight;
        cin >> weight;
        // od svijetionika A do B trebat će nam delta to dvoje (jer će se put od 0 -> A pokratit)
        obala[i] = obala[i - 1] + weight;

        adj[i].push_back({i - 1, weight});
        adj[i - 1].push_back({i, weight});
    }
    // spaja svaku točku na ROOT
    for (int i = 0; i < n; i++) {
        long long weight;
        cin >> weight;

        adj[n].push_back({i, weight});
        adj[i].push_back({n, weight});
    }

    // Dijkstra s početkom na hub
    vector<long long> dist(n + 1, LLONG_MAX);

    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<>
    > minHeap;

    dist[n] = 0;
    minHeap.push({0, n});

    while (!minHeap.empty()) {
        auto [currDist, currNode] = minHeap.top();
        minHeap.pop();

        if (currDist > dist[currNode]) continue;

        for (auto neighbour : adj[currNode]) {
            int nextNode = neighbour.first;
            long long weight = neighbour.second;

            if (dist[currNode] + weight < dist[nextNode]) {
                dist[nextNode] = dist[currNode] + weight;
                minHeap.push({dist[nextNode], nextNode});
            }
        }
    }

    // upit za min cijenu
    vector<int> ans;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        /* ako brod ikada treba ići u HUBa, udaljenost od A i B biti će kao od HUBa do A + od HUBa do B, obala nam služi 
        u slučaju da nam se hub ne isplati koristiti u kojem je slučaju najjeftinije samo ići od svjetionika do svijetionika*/
        ans.push_back(min(dist[a] + dist[b], llabs(obala[a] - obala[b])));
    }
    for(int a:ans) cout << a << endl;
    return 0;
}
