#include <iostream>

using namespace std;

void test1(){
    size_t v1 = 42;
    auto f =[v1] () mutable {return ++v1;};
    v1 = 0;
    auto j = f();
    cout << "test1 j=" << j << endl;

}

void test2(){
    size_t v1 = 42;
    auto f =[&v1] ()  {return ++v1;};
    v1 = 0;
    auto j = f();
    cout << "test2 j=" << j << endl;

}

void test3(){
    size_t v1 = 42;
    auto f =[v1] () mutable {return ++v1;};
    v1 = 0;
    auto j = f();
    cout << "test3 j=" << j << "    v1="<< v1 <<endl;
}

int main(){
    test1();
    test2();
    test3();
}