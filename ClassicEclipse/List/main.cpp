#include <iostream>
#include "LList.h"
#include "CList.h"
#include "Dlist.h"
#include "Pair.h"
using namespace std;


void CatList (LList<int>& L1, LList<int>& L2);
void Gather (LList<int>& L1, LList<int>& L2);
void Josehus (CList<int>& Cir, int& StuNum, int& StartNUm);
void StuOut(CList<int>& Cir, int& StartNum);

void catFunc(DList<KVpair<int, int>>& func1, DList<KVpair<int, int>>& func2);
void Print(DList<KVpair<int, int>>& func);
void EPrint(DList<KVpair<int, int>>& func);

int main (void) {
    LList<int> L1;
    for (int i=1; i<=9; i++){
        L1.append(i);
    }
    LList<int> L2;
    for (int i=0; i<10; i+=2){
        L2.append(i);
    }
    CatList(L1, L2);

    //Josehus problem
    int StuNum,StartNum = 0;
    CList<int> CL1;
    cout << endl << " Please input the amount of the students." << endl;
    cin >> StuNum;
    cout << " Please enter the start number." << endl;
    cin >> StartNum;
    Josehus(CL1, StuNum, StartNum);


    // 稀疏多项式相加
    DList<KVpair<int, int>> F_x;
    DList<KVpair<int, int>> G_x;

    KVpair<int, int> it;

    int num1,num2;
    int i,k,v;

    cin>>num1>>num2;
    for(i=0;i<num1;i++)
    {
        cin>>k>>v;
        it.setcoeft(k);
        it.setIndex(v);
        F_x.append(it);
    }

    for(i=0;i<num2;i++)
    {
        cin>>k>>v;
        it.setcoeft(k);
        it.setIndex(v);
        G_x.append(it);
    }

    Print(F_x);
    Print(G_x);

    catFunc(F_x, G_x);
    F_x.sort();

    Print(F_x);
    EPrint(F_x);

    return 0;
}

void CatList (LList<int>& L1, LList<int>& L2){
    L1.moveToEnd();
    L1.prev();
    L2.moveToEnd();
    L2.prev();
    if (L1.getValue() >= L2.getValue()){
        Gather(L1, L2);
        L1.moveToStart();
        cout << "L1: ";
        for (int i=0; i<L1.length(); i++){
            cout << L1.getValue() << " ";
            L1.next();
        }
    }else{
        Gather(L2, L1);
        L2.moveToStart();
        cout << "L2: ";
        for (int i=0; i<L2.length(); i++){
            cout << L2.getValue() << " ";
            L2.next();
        }
    }
}

void Gather (LList<int>& L1, LList<int>& L2){
    L1.moveToStart();
    L2.moveToStart();
    int i = 0;
    while(1){
        if(L1.getValue() > L2.getValue()){
            L1.insert(L2.getValue());
            L2.next();
            i++;
        }else{
            L1.next();
        }
        if(i == L2.length())
            break;
    }
}

void Josehus(CList<int>& Cir, int& StuNum, int& StartNum){
    for (int i=1; i<=StuNum; i++)
        Cir.append(i);
    Cir.moveToStart();
    while(Cir.length() != 0){
        StuOut(Cir, StartNum);
    }
}

void StuOut(CList<int>& Cir, int& StartNum){
    for (int i=1; i<StartNum; i++)
        Cir.next();
    StartNum = Cir.getValue();
    cout << Cir.remove() << " : ";
}




void catFunc(DList<KVpair<int, int>>& func1, DList<KVpair<int, int>>& func2) {
    int time = 0;
    int pos = 0;
    int length = func2.length();
    for (func1.moveToStart(); time<func1.length(); func1.next()){
        for (func2.moveToStart(); pos<length; func2.next()) {
            if (func1.getValue().getIndex() == func2.getValue().getIndex()) {
                func1.getValue().setcoeft(func1.getValue().coeffeicient() + func2.getValue().coeffeicient());
                func2.remove();
                pos--;
            }
            pos++;
            if (func1.getValue().getIndex() == 0)
                func1.remove();
        }
        pos = 0;
        time++;
    }
    for (func2.moveToStart();func2.length()>0;) {
        func1.insert(func2.remove());
    }
}

void Print(DList<KVpair<int, int>>& func) {
    int time = 1;
    for (func.moveToStart(); time<func.length(); func.next()) {
        cout << func.getValue().coeffeicient() << "x^" << func.getValue().getIndex() << '+';
        time++;
    }
    cout << func.getValue().coeffeicient() << "x^" << func.getValue().getIndex() << endl;
}

void EPrint(DList<KVpair<int, int>>& func) {
    int time = 1;
    func.moveToEnd();
    func.prev();
    for (; time<func.length(); func.prev()) {
        cout << func.getValue().coeffeicient() << "x^" << func.getValue().getIndex() << '+';
        time++;
    }
    cout << func.getValue().coeffeicient() << "x^" << func.getValue().getIndex() << endl;
}

