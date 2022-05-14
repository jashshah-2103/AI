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
void bfsr(){
    
    if(q1.empty()){
        return;
    }
    int i=q1.front();
    q1.pop();
    cout<<i<<" ";
    
    for(auto it :v[i]){
        if(visited[it]==0){
            q1.push(it);
            visited[it]=1;
        }
    }
    bfsr();
    
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
    for(int i=1;i<7;i++){
        
        if(visited[i]==0){
            
            visited[i]=1;
            q1.push(i);
            bfsr();
            
        }
        
    }

    cout<<"\n\n";

   
    for(int i=0;i<N;i++)
         visited[i] = 0;

    DFS(2);
}

