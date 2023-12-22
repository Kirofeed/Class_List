#include <iostream>
using namespace std;

class List {
private:
    struct City {
        string name;
        City *Next;
    };
    City *First;

public:
    List() { First = nullptr; };

    List(const List &);

    void Erase();

    void Clone(const List &);

    const List &operator=(const List &);

    void InsertFirst(const string &);

    void InsertLast(const string &);

    void ListPrint() const;

    bool DeleteFirst();

    bool DeleteLast();

    void Delete_by_Info(const string &);

    int Find_by_Info(const string &);

    void ForEach(void(string &));
    void ForEach(void(string )) const;
};