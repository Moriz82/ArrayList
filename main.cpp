#include <iostream>
#include "ArrayList.h"
using namespace std;

int main() {
    struct ArrayList<string> arrayList;
    arrayList.add("0");
    arrayList.add("1");
    arrayList.add("2");
    arrayList.add("3");
    arrayList.add("4");
    arrayList.add("5");
    arrayList.insert("not 0", 0);
    arrayList.remove(1);

    cout << arrayList.length << endl;
    cout << arrayList.get(0) << endl;
    cout << arrayList.find("5") << endl;
    cout << arrayList.get(1) << endl;
    cout << arrayList.size() << endl;
    cout << arrayList.toString() << endl;

    return 0;
}