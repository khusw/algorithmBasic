/*
    STL Map Basic Usage
*/

#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main() {
    map<int, string> m;

    map<int, string>::iterator iter;

    m.insert(make_pair(8, "apple"));
    m.insert(make_pair(4, "banana"));
    m.insert(make_pair(6, "mango"));
    m.insert(make_pair(2, "lemon"));

    cout << " ---- iterator ---- " << '\n';
    for (iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << " " << iter->second << '\n';
    }

    map<int, string>::const_iterator citer;

    cout << " ---- const iterator ---- " << '\n';
    for (citer = m.cbegin(); citer != m.cend(); citer++) {
        cout << citer->first << " " << citer->second << '\n';
    }

    map<int, string>::reverse_iterator riter;

    cout << " ---- reverse iterator ---- " << '\n';
    for (riter = m.rbegin(); riter != m.rend(); riter++) {
        cout << riter->first << " " << riter->second << '\n';
    }

    map<int, string>::const_reverse_iterator criter;

    cout << " ---- const reverse iterator ---- " << '\n';
    for (criter = m.crbegin(); criter != m.crend(); criter++) {
        cout << criter->first << " " << criter->second << '\n';
    }

    map<int, string> m2;

    m2.emplace(make_pair(99, "java"));
    m2.emplace(make_pair(22, "cobol"));

    pair<map<int, string>::iterator, bool> Pair;

    Pair = m2.emplace(make_pair(33, "c"));

    cout << Pair.first->first << '\n';

    map<int, string>::iterator iter3;
    iter3 = m2.emplace_hint(m2.end(), make_pair(42, "react"));
    cout << iter3->first << " " << iter3->second << '\n';

    return 0;
}