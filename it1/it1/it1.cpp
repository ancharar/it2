#include <iostream>
#include <fstream>
#include <string>
#include "Header1.h"
using namespace std;

int main() {
    Array<const char*> arr;
    arr.pushBack("1");
    arr.pushBack("2");
    arr.pushBack("3");
    arr.pushBack("4");
    arr.pushBack("5");
    arr.pushBack("8");

    for (auto it = arr.begin(); it != arr.end(); ++it) {
        int val = stoi(*it);
        cout << val + factorial(val) << endl;
    }

    return 0;
}