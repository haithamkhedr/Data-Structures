#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using std::string;
using std::vector;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

ull hash_fn(const string & str, int l, int r,const ull x= 263,const ull p =1000000007 ){
    ull hash = 0;
    for(int i = r; i >=l; --i){
        hash = (hash * x + str[i]) % p;
    }
    return hash;
}
vector<ull> preComputeHashes(const string &str, int P){
    static const ull x = 263;
    static const ull prime = 1000000007;
    ull xP = 1 ;
    for (int i = 0; i < P; ++i) {
        xP = (xP * x) % prime;
    }
    vector<ull> hashes(str.size() - P + 1);
    hashes.back() = hash_fn(str,(int)str.size() - P, (int)str.size() - 1,x,prime);
    for(int i = (int)(str.size() - P -1); i >=0; --i){
        long long hash = ((hashes[i+1] * x) % prime + str[i] - (str[i + P] * xP) % prime);
        hash = hash + prime;
        hashes[i] = hash % prime ;
    }
    return hashes;
}
std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    int P =(int) s.length();
    ull pHash = hash_fn(s,0,P - 1);
    vector<ull> tHashes = preComputeHashes(t,P);
    std::vector<int> ans;
    for (int i = 0; i < (int)tHashes.size(); ++i) {
        if(pHash != tHashes[i])
            continue;
        else{
            bool match = true;
            for(int j = i; j < i+P ; ++j){
                if(t[j] != s[j-i]){
                    match = false;
                }
            }
            if(match){
                ans.push_back(i);
            }
        }
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
