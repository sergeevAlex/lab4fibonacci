#include "fibonacci.h"
#include <iostream>
using namespace std;

template<typename T>
void fibonacci<T>::nextFibonacci(T& a, T& b) {
    cout << '*';
    T c = a+b;
    a = b;
    b = c;
}

template<typename T>
void fibonacci<T>::previuosFibonacci(T& a, T& b) {
    cout << '*';
    T p = b - a;
    b = a;
    a = p;
}

template<typename T>
T fibonacci<T>::calcFibonacci(T& a, T& b, int shift) {
    while(shift-- > 0){
        nextFibonacci(a,b);
    }
    while(shift++ > -1){
        previuosFibonacci(a,b);
    }
    return b;
}

template<typename T>
fibonacci<T>::fibonacci(int size) {
    length = size;
    a = 0;
    b = 1;
}

template<typename T>
fibonacci<T>::fibonacci(int size,T f, T s) {
    length = size;
    a = f;
    b = s;
}

template<typename T>
T fibonacci<T>::at(int index) {
    switch(index){
        case 0: return a;
        case 1: return b;
        default: {
            T a = this->a;
            T b = this->b;
            return calcFibonacci(a,b,index);
        }
    }
}

template<typename T>
void fibonacci<T>::resize(int size) {
    length = size;
}

template<>
inline void fibonacci<string>::nextFibonacci(string &a, string &b) {
    cout << "*";
    string c = a.append(b);
    a = b;
    b = c;
}

template<>
inline void fibonacci<string>::previuosFibonacci(string &a, string &b) {
    cout << "*";
    string p = p.erase(0,a.length());
    b = a;
    a = p;
}

template<>
inline fibonacci<string>::fibonacci(int size){
    length = size;
    a = "a";
    b = "b";
}


//template<>
//void fibonacci::nextFibonacci<string>(string &a, string &b) {
//    cout << "*";
//    string c = a.append(b);
//    a = b;
//    b = c;
//}