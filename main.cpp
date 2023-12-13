#include "list.cpp"

using namespace std;

int main() {
    List Cities;
    Cities.InsertFirst(123);
    Cities.InsertFirst(23);
    Cities.InsertFirst(121323);
    Cities.ListPrint();
}