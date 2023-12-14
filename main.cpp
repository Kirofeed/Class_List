#include "list.cpp"

using namespace std;

int main() {
    List Cities;
    Cities.InsertLast(0);
    Cities.InsertLast(2);
    Cities.InsertLast(3);
    Cities.InsertLast(4);
    Cities.InsertLast(5);
    Cities.InsertLast(6);
    Cities.ListPrint();
    Cities.Delete_by_Info(0);
    Cities.ListPrint();

}