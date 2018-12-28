#include<string.h>
#include<stack>
#include<vector>

int tim;

int lo[100005];
int disc[100005];
bool instack[100005];
bool visited[100005];
int cc;
int comp[100005];
int info[100005];
stack<int> st;

vector<int> adj[100005];
set<int> adj2[100005];

void dfs(int cur) {
    if (visited[cur])return;
    visited[cur]=instack[cur]=true;
    st.push(cur);
    lo[cur]=disc[cur]=tim++;
    for (int ni: adj[cur]) {
        if (instack[ni]) {
            lo[cur]=min(lo[cur],disc[ni]);
        } else if (!visited[ni]) {
            dfs(ni);
            lo[cur]=min(lo[cur],lo[ni]);
        }
    }

    if (lo[cur]==disc[cur]) {
        int ni =-1,ss= 0;
        do {
            ni = st.top();st.pop();
            comp[ni]=cc;
            instack[ni]=false;
            ss++;
        }while(ni != cur);
        info[cc]=ss;
        cc++;
    }
}

int main () {
  //main goes here :p
  return 0;
}
