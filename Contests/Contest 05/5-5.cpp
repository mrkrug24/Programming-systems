#include <map>
#include <vector>
#include <iostream>
using namespace std;
const uint64_t MOD = 4294967161;

int main() {
    uint64_t r, c, v;
    map<uint64_t, vector<uint64_t>> rows;
    map<pair<uint64_t, uint64_t>, uint64_t> A, M;

    while(cin>>r>>c>>v){if(r==0 && c==0 && v==MOD){break;} A[{r, c}]=v;rows[c].push_back(r);}
    while(cin>>r>>c>>v){if(rows.find(r)!=rows.end()){for(auto i:rows[r]){M[{i, c}]+=v*A[{i, r}]; M[{i, c}]%=MOD;}}}
    for(auto i:M){if(i.second!=0){cout<<i.first.first<<' '<<i.first.second<<' '<< i.second<<endl;}}

    return 0;
}