#include <iostream>
using namespace std;

class List {
protected:
    struct City {
        int name;
        City* Next;
    };
    City* First;

public:
    List(){First = nullptr;};
    List(const List &);
    void Erase();
    void Clone(const List& );
    const List & operator = (const List &);
    void InsertFirst(const int &);
    void InsertLast(const int &);
    void ListPrint() const;
    bool DeleteFirst();
    bool DeleteLast();
    void Delete_by_Info(const int& );
};
