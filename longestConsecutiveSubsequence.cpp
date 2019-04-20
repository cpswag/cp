/* Problem Description:



*/

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define TRvi(it, c) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define inf 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
#define scan(x) scanf("%d",x)
#define ll long long
#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define LSOne(x) x&(-x)
#define debug(x) cout << #x << " " << x << endl;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<int> longestSubsequence(int *arr, int n){
	// Write your code here
    map<int, bool> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]] = true;
    int maxLen = -1, startAt=-1;
    for (int i = 0; i < n; i++){
        if (mp[arr[i]]){
          int cnt = 0;
          int tempVal = arr[i];
          while(mp[tempVal++]) cnt++;
          if (maxLen < cnt) { maxLen = cnt; startAt = arr[i];}
        }
    }
    vector<int> ans;
    for (int i = startAt; i < startAt + maxLen; i++) {ans.push_back(i);}
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif

    int arr[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6 };
    int size = 13;
    vector<int> v = longestSubsequence(arr,size);
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
 }
