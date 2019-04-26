//Tag: backtracking

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define X first
#define Y second
#define pb push_back
#define mp make_pair

int N;

bool solveUtil(vvi& sol, int col);

bool isSafe(vvi& sol, int x, int y){
    for(int i = 0;i < y;i++)if(sol[x][i])return false;
    for(int i = x, j = y;i >= 0 && j >= 0;i--, j--)if(sol[i][j])return false;
    for(int i = x, j = y;i < N && j >= 0;i++, j--)if(sol[i][j])return false;
    return true;
}

void solve(){
    vvi sol(N, vi(N, 0));

    if(solveUtil(sol, 0)){
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "No Solution\n";

}

bool solveUtil(vvi& sol, int col){
    if(col >= N)
        return true;
    for(int i = 0;i < N;i++){
        if(isSafe(sol, i, col)){
            sol[i][col] = 1;
            if(solveUtil(sol, col + 1))
                return true;
            sol[i][col] = 0;
        }
    }
    return false;
}

int main(void)
{
    cin >> N;
    solve();
}
