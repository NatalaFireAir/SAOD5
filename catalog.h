#ifndef CATALOG_H
#define CATALOG_H

#include <string>
#include <vector>

using namespace std;
class Catalog {
    //строка списка
    struct Data {
        string name;
        string address;
        unsigned int number;
    };
    int size;
    vector <Data> dataArray;
    Data **pointerArray;
public:
    void outList();
    void fileIn();
    void sort();
};

#endif // CATALOG_H
