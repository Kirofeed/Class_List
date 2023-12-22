#include "list.cpp"

using namespace std;

void MegaFunk (string& str) {
    str = str + " is a big city";
}
void Funk (string str){
    cout << str << "\t";
}

int main() {
    List Cities;
    Cities.InsertLast("Minsk");
    Cities.InsertLast("Moscow");
    Cities.InsertLast("Warsaw");
    Cities.InsertLast("Paris");
    Cities.InsertLast("New-York");
    Cities.InsertLast("Berlin");
    Cities.InsertLast("Chili");
    Cities.ListPrint();
    Cities.Delete_by_Info("New-York");
    Cities.ListPrint();
    cout << Cities.Find_by_Info("Berlin") << endl;
    for (int i = 0; i < 3; ++i) {
        cout << endl;
    }
    Cities.ForEach(Funk);
    cout << endl << "Elements were not changed" << endl;
    Cities.ForEach(MegaFunk);
    Cities.ListPrint();
    cout << endl << "Elements were changed inside the Funktion" << endl;

}