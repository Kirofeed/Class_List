#include "list.h"

List::List(const List &L)
{
    Clone(L);
    this->First = L.First;
}

void List::Erase() {
    const City *p = First, *q;
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
        delete q;
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
void List::InsertFirst(const string &element) {
    City *p = new City;
    p->name = element;
    p->Next = First;
    First = p;
}
void List::InsertLast(const string &element) {
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
bool List::DeleteFirst() {
    if (First == nullptr) {
        return false;
    }
    City *p = First;
    First = First->Next;
    delete p;
    return true;
}
bool List::DeleteLast() {
    if (First == nullptr) {
        return false;
    }
    if (First->Next == nullptr) {
        // если в списке всего один элемент
        delete First;
        First = nullptr;
        return true;
    }
    City *q = First;
    City *prev = nullptr;
    while (q->Next != nullptr) {
        prev = q;
        q = q->Next;
    }
    delete q;
    prev->Next = nullptr;
    return true;
}
void List::Delete_by_Info(const string& element) {
    City *p = First, *r = nullptr;
    while (p != nullptr) {
        if (r == nullptr) {
            if (p->name == element) {
                First = p->Next;
                delete p;
                p = First;
            }
            else {
                r = p;
                p = p -> Next;
            }
        }
        else {
            if (p->name == element) {
                r->Next = p->Next;
                delete p;
                p = r->Next;
            }
            else {
                r = p;
                p = p->Next;
            }
        }
    }
}
int List::Find_by_Info(const string& element) {
    try {
        int counter = 1;
        City *q;
        q = First;
        if (First == nullptr) {
            throw "List is empty";
        } else {
            while (q != nullptr) {
                if (q->name == element) {
                    return counter;
                } else {
                    counter++;
                    q = q->Next;
                }
            }
        }
        return counter;
    }
    catch (const char *error_message) {
        cerr << "Error: " << error_message;
        exit(EXIT_FAILURE);
    }

}

void List::ForEach (void Fun (string&)) {
    City* P = First;

    if (P == nullptr) {
        cout << "список пуст" << endl;
        return;
    }

    while (P != nullptr) {
        Fun(P->name);
        P = P->Next;
    }
}
void List::ForEach(void Fun (string)) const {
    City* P = First;

    if (P == nullptr) {
        cout << "список пуст" << endl;
        return;
    }

    while (P != nullptr) {
        Fun(P->name);
        P = P->Next;
    }
}
