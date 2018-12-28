#include <iostream>
#include <sstream>
#include "BST.h"
#include "Coordinate.h"

using namespace std;


int main() {
    BST<string, Coordinate> CityData;
    int times = 0;
    cin >> times;
    string read;
    string city;
    int x, y = 0;

    for (int i = 0; i < times; ++i) {
        getline(cin, read);
        istringstream iss(read);
        iss >> city;
        iss >> x;
        iss >> y;
        Coordinate *p = new Coordinate(x,y);
        CityData.insert(city, *p);

        // Initialize
        read = "";
        city = "";
        delete p;
        p = NULL;
        iss.clear();
    }

    int judge = 0;
    while (1) {
        getline(cin, read);
        istringstream iss(read);
        iss >> judge;
        if (judge == 0) {
            iss >> city;
            CityData.remove(city);

            // Initialize
            judge = 0;
            iss.clear();
        }else if (judge == 1){
            iss >> city;
            iss >> x;
            iss >> y;
            Coordinate *p = new Coordinate(x,y);
            CityData.insert(city, *p);

            // Initialize
            city = "";
            x = 0;
            y = 0;
            delete p;
            p = NULL;
            judge = 0;
            iss.clear();
        } else if (judge == 2) {
            iss.clear();
            judge = 0;
            break;
        }
    }

    char sortC;
    cin >> sortC;

    int distance = 0;
    cin >> x >> y >> distance;
    Coordinate *p = new Coordinate(x,y);

    CityData.print();
    preorder1(CityData.getRoot(), sortC);
    preorder2(CityData.getRoot(), *p, distance);

    delete p;
    p = NULL;

    return 0;
}