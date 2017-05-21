#include <iostream>
#include "fibonacci.h"
#include "fibonacci.cpp"
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {

//    fibonacci<int> f(4);

//    for(auto it = f.cbegin(); it != f.cend(); ++it){
//        cout << *it << endl;
//    }

//    cout << binary_search(f.cbegin(),f.cend(), 3);


//
//    string s = "abbab";
//    string s1 = "bab";
//
//    s.erase(0,s1.length());
//    cout << s;
///    fibonacci<int> fi(-100,11,10);
//
//
//
//
//    for(auto it = fi.cbegin(); it != fi.cend(); ++it){
//        cout << *it << endl;
//    }
//
//    vector<int> ve(10);
//    for(auto it = f.cbegin(); it != f.cend(); ++it){
//        ve.push_back(*it);
//    }
//    std::sort(fi.cbegin(),fi.cend());


    vector<int> vt(10);

        fibonacci<int> fib(10,-9,2);

    for(auto it = fib.cbegin();it!= fib.cend();++it){
        cout << *it << endl;
    }

    for(auto it= fib.cbegin();it!=fib.cend();++it){
        vt.push_back(*it);
    }

    sort(vt.begin(),vt.end());
    cout << "Sorted vector:" << endl;

    for(auto tt = vt.cbegin(); tt!=vt.cend();++tt){
        cout << '[' << *tt << "] ";
    }


    cout << '\n' << " SEARCH -121: " <<     binary_search(vt.begin(),vt.end(),-1221);


    return 0;
}