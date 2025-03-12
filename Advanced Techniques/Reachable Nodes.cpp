#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
 
using namespace std;
const int maxN = 50001;
 
bitset<maxN> reachable[maxN];
 
 
 
int main() {
    int N, M;
    cin >> N >> M;
 
    vector<int> in(N+1, 0);
    vector<int> graph[N+1];
    queue<int> q;
 
    for (int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        graph[b].push_back(a); //reverse graph
        in[a]++;
    }
 
    for (int i = 1; i <= N; i++) {
        if (in[i] == 0) {
            reachable[i].set(i);
            q.push(i);
        }
    }
 
    while (!q.empty()) {
        int current = q.front();
        q.pop();
 
        for (int neighbor : graph[current]) {
            reachable[neighbor] |= reachable[current];
            in[neighbor]--;
 
            if (in[neighbor] == 0) {
                reachable[neighbor].set(neighbor);
                q.push(neighbor);
            }
        }
    }
 
    for (int i = 1; i <= N; i++) {
        cout << reachable[i].count() << " ";
    }
    cout<<endl;
 
    return 0;
}