#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> edge[10001];
int low[10001];
int num[10001]; //num[node] -> dfs number
int in_stack[10001];
stack<int> stk;
vector<vector<int>> ans;
int vertex_num=0;

bool cmp(const vector<int> &a,const vector<int> &b){
    return a[0] < b[0];
}

void dfs(int node){
    stk.push(node);
    in_stack[node] = 1;
    num[node] = ++vertex_num;
    low[node] = vertex_num;
    
    for(auto next : edge[node]){
        if(!num[next]){
            dfs(next);
            low[node] = min(low[node],low[next]);
            
        } 
        else if(in_stack[next]){
            low[node] = min(low[node],num[next]);
        }
    }
    if(num[node]==low[node]){
        vector<int> scc;
        for(;;){
            int tmp = stk.top();
            stk.pop();
            in_stack[tmp]=0;
            
            scc.push_back(tmp);
            if(node==tmp) break;
        }
        sort(scc.begin(),scc.end());
        ans.push_back(scc);
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int v,e,tmp1,tmp2;
    cin >> v >> e;
    for(int i = 0;i<e;i++){
        cin >> tmp1 >> tmp2;
        edge[tmp1].push_back(tmp2);
    }
    for(int i =1;i<=v;i++){
        if(!num[i]) dfs(i);
        
    }
    cout << ans.size() << '\n';
    
    sort(ans.begin(),ans.end(),cmp);
    for(auto scc : ans){
        for(auto vertex:scc){
            cout << vertex << ' ';
        }
        cout << "-1\n";
    }
    
    

    return 0;
}