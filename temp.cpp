#include <iostream>
using namespace std;

int main(int x) {
    if(x==0) return 0;
    cout<<"Jai Shree Ram ";
    x--;
    return main(8);
}