#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<vector<int> >& edges, int distanceThreshold) {
   vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    
    for (const vector<int>& edge : edges) {
        int from = edge[0];
        int to = edge[1];
        int weight = edge[2];
        dist[from][to] = weight;
        dist[to][from] = weight;
    }

    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int minCities = INT_MAX;
    int minCity = -1;

  
    for (int i = 0; i < n; i++) {
        int reachableCities = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= distanceThreshold)
                reachableCities++;
        }
        if (reachableCities <= minCities) {
            minCities = reachableCities;
            minCity = i;
        }
    }

    return minCity;
}
   
}

//do not modify the below code
int main()
{
    int n, m, distanceThreshold;
    cin >> n >> m >> distanceThreshold;
    vector<vector<int> > edges;
    for(int i = 1; i <= m; i ++)
    {
        int x, y, weight;
        cin >> x >> y >> weight;
        vector<int> f;
        f.push_back(x);
        f.push_back(y);
        f.push_back(weight);
        edges.push_back(f);
    }

    cout << solve(n, edges, distanceThreshold);
}
