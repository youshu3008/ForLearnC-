#include <iostream>
#include <vector>
#include <map>

using namespace std;
map<int, int> mp;

void dfs(int n, int m, vector<int>& result, int sum){
    if(mp.size() == n && sum == m){
        result.push_back(mp);
        mp.clean();
        return;
    }
    for(int i = 1; i < 7; i++){
        mp[i]++;
        sum += i;
        dfs(n,m,result,sum);
        sum -=i;
        mp[i]--;
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<int> result;
    map<int, int> mp;
    dfs(n,m,result,mp);
    
    
}
// 64 位输出请用 printf("%lld")