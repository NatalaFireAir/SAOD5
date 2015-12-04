#include <iostream>
#include <fstream>
#include <cstdlib>

#include "catalog.h"

using namespace std;

//чтение из файла
void Catalog::fileIn() {
    //первой строчкой в файле "data.txt" является число,
    //обозначающее количество записей в справочнике.
    //имя, адрес, телефонный номер считываются каждый с новой строки
    ifstream infile("data.txt");
    char sizeBuffer[14];
    char nameBuffer[20];
    char addressBuffer[40];
    char numBuffer[14];
    infile.getline(sizeBuffer, 14);
    size = atoi(sizeBuffer);
    while(infile.getline(nameBuffer, 20)) {
        Data *temp=new Data;
        infile.getline(addressBuffer, 40);
        infile.getline(numBuffer, 14);
        temp->name = nameBuffer;
        temp->address = addressBuffer;
        temp->number = atoi(numBuffer);
        dataArray.push_back(*temp);
    }
    pointerArray = new Data*[size];
    for (int i = 0; i < size; i++) {
        pointerArray[i] = &dataArray[i];
    }
}

// Вывод списка в консоль(dataArray: обращение к объектам через коллекцию объектов,
//                        pointerArray: обращение к объектам через массив указателей)
void Catalog::outList() {
    cout << "      dataArray:      \n";
    for (int i = 0; i < size; i++) {
        cout << (i+1) << "   ";
        cout << dataArray[i].name << "      "
           << dataArray[i].address << "       "
           << dataArray[i].number << "\n";
    }
    cout << "\n      pointerArray:   \n";
        for (int i = 0; i < size; i++) {
        cout << (i+1) << "   ";
        cout << pointerArray[i]->name << "      "
             << pointerArray[i]->address << "       "
             << pointerArray[i]->number << "\n";
    }
    cout << "\n\n";
}

//сортировка(шейкер) массива указателей на объекты: в порядке убывания адреса
void Catalog::sort() {
    int left = 0;
    int right = size-1;
    int k = size;
    do {
        for(int i = right; i > left; i--) {
            if (pointerArray[i-1]->address < pointerArray[i]->address) {
                swap(pointerArray[i-1], pointerArray[i]);
            }
            k = i;
        }
        left = k;
        for(int i = left; i < right; i++) {
            if (pointerArray[i]->address < pointerArray[i+1]->address) {
                swap(pointerArray[i], pointerArray[i+1]);
            }
            k = i;
        }
        right = k;
    } while (left < right);
}
