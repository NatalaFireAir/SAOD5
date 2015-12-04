#include "catalog.h"

using namespace std;

int main() {
    Catalog catalog;

    catalog.fileIn();
    catalog.outList();

    catalog.sort();
    catalog.outList();
    return 0;
}

