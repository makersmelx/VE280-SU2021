#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>

using namespace std;
int main()
{
    map<string, int> Tamako;
    pair<string, int> something("lhs", 1234);
    something.second = 114;
    Tamako.insert(something);
    Tamako["mochi"] = 12345;
    cout << "Not find: " << (Tamako.find("zzz") == Tamako.end()) << endl;
    cout << "Find: " << Tamako.find("lhs")->second << endl;
    cout << "erase(k) return value: " << Tamako.erase("mochi") << endl;
    cout << "erase(k) return value: " << Tamako.erase("mochi") << endl;
    return 0;
}