#include <iostream>
using namespace std;

#define DATE 202211 //YYYYMM

class Medecine
{
public:
    string name = "";
    int price = 0;
    int quantity = 0;
    bool isPrescriptionNeeded = 0;
    int expirationDate = 0; //YYYYMM

    void add ();
    void out();
};
class Pharmacy
{
    int size = 0;
    Medecine* medecine = new Medecine[size]; //асортимент ліків
    public:
        void addMed();//додавання ліків 
        void delMed();//видалення ліків
        void recalculation();//видалення прострочений ліків
        void sale();//знижка на всі ліки на 10% 
        void cheapest();//виведення найдишевших 
        void outAll();//виведення всіх ліків, які є
        void del(int i); 
};

int main(){
    Pharmacy a;
    int input;
    
    while(1){
        cout << "addMed (1), delMed (2), recalculation (3), sale (4), cheapest (5), outAll (6)\ninp: ";
        cin >> input;
        switch (input)
        {
            case 1: a.addMed(); break;
            case 2: a.delMed(); break;
            case 3: a.recalculation(); break;
            case 4: a.sale(); break;
            case 5: a.cheapest(); break;
            case 6: a.outAll(); break;
            default: return 0;
        }
    }
}
void Medecine::add()
{
    cout << "Name: ";
    cin >> name;
    cout << "Price: ";
    cin >> price;
    cout << "Quantity: ";
    cin >> quantity;
    cout << "IsPrescriptionNeeded: ";
    cin >> isPrescriptionNeeded;
    cout << "expirationDate (YYYYMM):";
    cin >> expirationDate;
    cout << "added \n\n";
}
void Medecine::out()
{
    cout << "Name: ";
    cout << name << endl;
    cout << "Price: ";
    cout << price << endl;
    cout << "Quantity: ";
    cout << quantity << endl;
    cout << "IsPrescriptionNeeded: ";
    cout << isPrescriptionNeeded << endl;
    cout << "expirationDate (YYYYMM): ";
    cout << expirationDate << endl << endl;
}

void Pharmacy::addMed()
{
    size++;
    Medecine* temp = new Medecine[size];
    for(int i = 0; i<size-1;i++){
      temp[i] = medecine[i];
    }
    delete[] medecine;
    medecine = temp;
    medecine[size-1].add();
}
void Pharmacy::delMed()
{
    int i = 0;
    bool isFound = 0;
    string name;
        cout << "find and delete: ";
        cin >> name;
    while(i <= size){
        if (i == size && !isFound){
            cout << "not found " << name <<endl;
        }
        if(medecine[i].name == name){
            isFound = 1;
            del(i);
            cout << "\tdeleted " << name << endl;
        }
        i++;
    }
}
void Pharmacy::recalculation()
{
    int i = 0;
    cout << "Recalculation:" << endl;
    while(i <= size){
        if(medecine[i].expirationDate <= DATE){
            cout << "\tdeleted " << medecine[i].name << endl;   
            del(i);
        }
        i++;
    }
}
void Pharmacy::sale()
{
    int i = 0;
    while(i < size){
        medecine[i].price *= 0.9;
        i++;
    }
}
void Pharmacy::outAll()
{
    int i = 0;
    cout << "\nHere: " << endl;
    while(i < size){
        medecine[i].out();
        i ++;
    }
}
void Pharmacy::cheapest()
{
   int min = medecine[0].price;
   for(int i = 1;i < size; i++){
     if(min > medecine[i].price){
      min = medecine[i].price;
      cout << min << endl;
    }
   }
   for(int i =0;i<size;i++){
     if(medecine[i].price == min)
      medecine[i].out();
    }
}
void Pharmacy::del(int i){
    size --;
    for(int j = i; j<size; j++){
        medecine[j] = medecine[j + 1];
    }
 }