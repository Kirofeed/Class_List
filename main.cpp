#include "list.cpp"

using namespace std;

int main() {
    List Cities;
    Cities.InsertLast(123);
    Cities.InsertLast(23);
    Cities.InsertLast(43);
    Cities.InsertLast(121323);
    Cities.DeleteLast();
    Cities.ListPrint();

}