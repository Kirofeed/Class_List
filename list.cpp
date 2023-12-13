#include "list.h"

List::List(const List &L)
{
    Clone(L);
}

void List::Erase() {
    City *p = First, *q;
    while (p!=nullptr)
    {
        q=p->Next;
        delete p;
        p=q;
    }
    First=nullptr;
}
void List::Clone(const List& L) {
    City *p = L.First, *r = nullptr, *q;
    while (p != nullptr) {
        q = new City;
        q->name = p->name;
        q->Next = nullptr;
        if (r != nullptr) {
            r->Next = q;
        }
        else {
            First = q;
        }
        r = q;
        p = p->Next;
    }

}


const List & List::operator = (const List &L)
{
    if (&L==this)
        return *this; // проверка на самоприсваивание
    Erase();
    Clone(L);
    return *this;
}
void List::InsertFirst(const int &element) {
    City *p = new City;
    p->name = element;
    p->Next = First;
    First = p;
}
void List::InsertLast(const int &element) {
    if (First != nullptr) {
        City *p = new City, *q = First;
        p->name = element;
        while (q->Next != nullptr) {
            q = q->Next;
        }
        q->Next = p;
        p->Next = nullptr;
    }
    else {
        City *p = new City;
        p->name = element;
        p->Next = nullptr;
        First = p;
    }
}

void List::ListPrint() const {
    City *p = First;
    while (p->Next != nullptr) {
        cout << p->name << "\t";
        p = p->Next;
    }
    cout << p->name << endl;
}