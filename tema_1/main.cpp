#include <iostream>

#include "DynamicSet.h"

int main() {
    using namespace std;
    // Initialization test vectors
    int vector_1[] = {10, 101, 2, 47, 739, 582, 18, 134};
    int vector_2[] = {10, 101, 2, 47, 739, 582, 84, 3, 5};

    DynamicSet set1 = DynamicSet(vector_1, sizeof(vector_1)/4);
    DynamicSet set2 = DynamicSet(vector_2, sizeof(vector_2)/4);
    cout << "Printeaza multimile: " << endl;
    set1.printSet();
    set2.printSet();
    cout << endl;

    // Test sets operation
    DynamicSet result_set;
    result_set = set1 + set2;
    cout << "Reuniunea multimilor: " << endl;
    result_set.printSet();
    cout << endl;

    result_set = set1 * set2;
    cout << "Intersectia multimilor: " << endl;
    result_set.printSet();
    cout << endl;

    result_set = set1 - set2;
    cout << "Diferenta multimilor set1 - set2: " << endl;
    result_set.printSet();
    result_set = set2 - set1;
    cout << "Diferenta multimilor set2 - set1: " << endl;
    result_set.printSet();
    cout << endl;

    result_set = set1;
    cout << "Copierea multimilor (=): " << endl;
    result_set.printSet();
    cout << endl;

    result_set = DynamicSet(set2);
    cout << "Copierea multimilor (DynamicSet(set))" << endl;
    result_set.printSet();
    cout << endl;

    return 0;
}