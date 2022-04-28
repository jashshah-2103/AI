#include <bits/stdc++.h>
using namespace std;

int const N=10;
int visited[10];
vector<int> v[N] ;

void BFS (int i){
    
    queue<int> q;
    cout<<i<<" ";
    visited[i]=1;
    q.push(i);
    
    while(!q.empty()){
        i=q.front();
        q.pop();
        
        for(auto it:v[i]){
            if(visited[it]!=1){
                cout<<it<<" ";
                visited[it]=1;
                q.push(it);
            }
        }
        
        
    }
    
}

void DFS(int i){
    if(visited[i]==1){
        return;
    }
    cout<<i<<" ";
    visited[i]=1;
    for(auto n:v[i]){
        DFS(n);
    }
}

int main()
{
    
    v[1].push_back(2);
    v[1].push_back(4);
    v[2].push_back(1);
    v[2].push_back(3);
    v[2].push_back(5);
    v[3].push_back(2);
    v[3].push_back(6);
    v[5].push_back(2);
    v[5].push_back(6);
    v[6].push_back(3);
    v[6].push_back(5);
    v[4].push_back(1);

    BFS(3);

    cout<<"\n\n";

   
    for(int i=0;i<N;i++)
         visited[i] = 0;

    DFS(2);
}

