#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
using namespace std;
template <class T>
void transverse(vector<T>& v)
{
    for (auto& i : v) {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> Tohru(100, 0);
    Tohru[0] = 1;
    Tohru[1] = 2;
    vector<int>::iterator itr = Tohru.erase(Tohru.begin());
    cout << *itr << endl;
    cout << (itr == Tohru.begin()) << endl;
    for (vector<int>::size_type ix = 0; ix != 10; ix++) {
        Tohru[ix] = ix;
    }
    for (int i = 0; i < 10; i++) {
        cout << Tohru[i] << " ";
    }
    cout << endl;
    vector<int> lhs(itr, itr + 10); // copy
    transverse(lhs);
    int a[] = { 1, 4, 5, 6, 7 };
    vector<int> lyl(a, a + sizeof(a) / sizeof(int));
    lyl.insert(lyl.begin(), 67);
    transverse(lyl);
    deque<int> ostrich(Tohru.begin(), Tohru.end());
    cout << ostrich[8] << endl;
    return 0;
}