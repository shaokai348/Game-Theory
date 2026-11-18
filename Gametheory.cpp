#include <bits/stdc++.h>
using namespace std;

int n; //player count
double a; //alpha --> cost of creating an additional edge
vector<int> s(8); //initialise the bitmask --> players buy the edge to s[i] (meaning the players)
int full;

//results
double SocialOptimum, WorstNE; //basically selfish vs best possible case!
int neCount;
bool nonTreeNE; //more than 1 possible loops

//finds out the sum of distance from the 'start' (so whether or not if everything is connected)
int distSum(int start, int adj[]) {
    int dist[8];
    for (int v = 0; v < n; v++) dist[v] = -1;   // find out which has not reached yet
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        for (int v = 0; v < n; v++) {
            if ((adj[u] >> v & 1) and dist[v] == -1) {  //shift the graph left by (v+1) blocks so that it sees whether or not there is a path way to be node travelling to
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    int sum = 0;
    for (int v = 0; v < n; v++) {
        if (dist[v] == -1) return -1;           
        sum += dist[v];
    }
    return sum;
} //this is VERY useful as it gives us the sum of 1 node going to all other nodes (repeat this for all other nodes and you get the usage cost)

//builds a graph based on everyone's "creation cost"
void buildGraph(int adj[]){
  for (int i = 0; i<n; i++) adj[i]=0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        if (s[i] >> j & 1) { adj[i] |= 1 << j; adj[j] |= 1 << i; }
}
//more or less a very similar thig as the previous, basically reorganises the graph from a one way to a two way

double playerCost(int i) {
    int adj[8];
    buildGraph(adj);
    int d = distSum(i, adj);
    if (d < 0) return 1e18;
    return a * __builtin_popcount(s[i]) + d;
}
//find out the cost from one starting node, aka like from one road to all the others

bool isNash() {
    for (int i = 0; i < n; i++) {
        double cur = playerCost(i);
        int saved = s[i];
        for (int t = 0; t <= full; t++) {
            if (t >> i & 1) continue;           // cant buy edge to yourself
            s[i] = t;
            if (playerCost(i) < cur - 1e-9){
               s[i] = saved; 
               return false; 
              }
        }
        s[i] = saved;
    }
    return true;
}
// basically a brute force function to find out if the system is in nash equilibrium, aka one change by 1 player will not affect the entire group's 

// called once every player has chosen a strategy
void evaluate() {
    int adj[8];
    buildGraph(adj);
    int edges = 0, totalDist = 0;
    for (int i = 0; i < n; i++) {
        int d = distSum(i, adj);
        if (d < 0) return;                      //if the graph is disconnected we shall skip it
        totalDist += d;
        edges += __builtin_popcount(s[i]);
    }
    double social = a * edges + totalDist;
    SocialOptimum = min(SocialOptimum, social);       //find the social optimum over all graphs
    if (isNash()) {
        neCount++;
        WorstNE = max(WorstNE, social);
        if (edges != n - 1) nonTreeNE = true;   //in this case, a tree will be defined as if all the points are only connected once, ie only one possible loop
    }
}
//basically compares everything in the graph! see the most efficient AND the least efficient

void go(int i) {
    if (i == n) { evaluate(); return; }
    for (int t = 0; t <= full; t++) {
        if (t >> i & 1) continue;
        bool duplicate = false;                 // skip if j already bought edge j-i so there is no repeatss
        for (int j = 0; j < i; j++)
            if ((t >> j & 1) && (s[j] >> i & 1)) duplicate = true;
        if (duplicate) continue;
        s[i] = t;
        go(i + 1);
    }
}
//also another brute force algorithm that finds out all the possible strategies

int main() {
    for (n = 3; n <= 5; n++) {
        full = (1 << n) - 1;
        printf("\n=== n = %d ===\n", n);
        printf("Alpha  NE  nonTreeNE  optimum  WorstNE  PoA\n");
        for (a = 0.5; a <= 10.0 + 1e-9; a += 0.5) {
            SocialOptimum = 1e18; WorstNE = 0; neCount = 0; nonTreeNE = false;
            go(0);
            printf("%5.1f %5d  %9s  %7.1f  %7.1f  %.4f\n", a, neCount,
                   nonTreeNE ? "yes" : "no", SocialOptimum, WorstNE, WorstNE / SocialOptimum);
        }
    }
}
//yay our main functionnn done!!!