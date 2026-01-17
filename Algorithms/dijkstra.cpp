#include <bits/stdc++.h>
using namespace std;

// graf tipa 1:[[2, 2], [3, 2]] - 1 se spaja s 2 i 3, potrebno mu je 2h i 2h da pređe
void dijkstra(int start, const vector<vector<pair<int, int>>>& graph) {
    // Na početku je svaki vertice ne istražen, tako da je default vrijeme beskonačno, oblika vertice:{edge}
    vector<int> dist(graph.size(), numeric_limits<int>::max());
    // do verticea od kojeg počinjemo treba nam 0h
    dist[start] = 0;
    // minHeap, top je uvijek najmanji element, da je samo priority_queue<pair<int, int>> bio bi max (zadnji element je najveći)
    // priority_queue<T, container(default vector<T>), compare(default <T>)
    // ocdje nam vector treba samo zato kako bismo stavili greater jer je to 3. po redu
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    // dodava  početak
    pq.push({0, start});

    // algo će iskušati svaki put koji je manji od najmanjeg što smo dosada našli (nema potrebe provjeravt ako je manji)
    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        // ako je udaljenost koju smo pronašli zadnju veća od najmanje nema potrebe provjeravat susjede jer će svakako biti manji
        if (currentDist > dist[currentNode]) continue;

        // prolazimo kroz svaki vertice što graniči s trenutnim
        for (const auto& neighbor : graph[currentNode]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            // do tog idućeg verticea treba nam koliko do trenutnog + udaljenost između ta dva
            if (dist[currentNode] + weight < dist[nextNode]) {
                dist[nextNode] = dist[currentNode] + weight;
                // dodavamo ih u provjerene, ali idući od kojeg ćemo početi biti će onaj do kojeg nam je najmanje trebalo
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}