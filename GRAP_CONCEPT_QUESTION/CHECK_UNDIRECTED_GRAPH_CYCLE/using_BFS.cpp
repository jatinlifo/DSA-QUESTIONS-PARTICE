// Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether the graph contains any cycle or not. The Graph is represented as an adjacency list, where adj[i] contains all the vertices that are directly connected to vertex i.

// NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between vertex i and vertex j, both j will be adj[i] and i will be in adj[j].

// Examples:

// Input: adj = [[1], [0,2,4], [1,3], [2,4], [1,3]] 
// Output: 1
// Explanation: 

// 1->2->3->4->1 is a cycle.
// Input: adj = [[], [2], [1,3], [2]]
// Output: 0
// Explanation: 

// No cycle in the graph.
// Constraints:
// 1 ≤ adj.size() ≤ 105


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution{
    public:

    bool bfs(vector<vector<int>>& adj, int u, vector<bool>& visited) {

        queue<pair<int,int>> q;
        q.push({u,-1});
        visited[u] = true;

        while(!q.empty()){
            auto P = q.front();
            q.pop();
            int src = P.first;
            int parent = P.second;

            for(int &v : adj[src]){
                if(visited[v] == false){
                    visited[v] = true;
                    q.push({v,src});
                }else if(v != parent){
                    return true;
                }
            }
        }
        return false;

    }

    bool isCycle(vector<vector<int>>& adj, int V) {

        vector<bool> visited(V,false);

        for(int i=0; i<V; i++){
            
            if(!visited[i] && bfs(adj,i,visited)){
                return true;
            }
        }
        return false;
    }
};

int main () {
    
    int V, E;
    cout<<"Enter the number of vertices : ";
    cin>>V;
    cout<<"Enter the number of edges : ";
    cin>>E;

    vector<vector<int>> adj(V);
    cout<<"Enter edges : ";
    cout<<endl;

    

    for(int i=0; i<E; i++){
        int u,v;
        cout<<"Edge "<< i+1 <<" : ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;

    bool ans = obj.isCycle(adj,V);
    if(ans){
        cout<<"Yes Cycle is Present : ";
    }else{
        cout<<"Cycel is Not Present : ";
    }
    return 0;
}