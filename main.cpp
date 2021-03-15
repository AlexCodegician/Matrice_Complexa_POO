#include <iostream>
#include <fstream>
#include "complex.h" //adaugare clase
#include "numar_complex.h"
#include "matrice.h"

using namespace std;
//citirea din fisier

int main()
{
    matrice m1, m2, m3, m4;//m3 suma m4 produs
    int oks=0, okp=0;
    int switch1=1;
    while(switch1 != 0)
    {
        cout<<"Matrice de numere complexe"<<endl;
        cout<<"1. Citire matrice 1: "<<endl;//din fisier 1 2 3 sau tastatura
        cout<<"2. Citire matrice 2: "<<endl;
        cout<<"3. Suma matrici: intre 1 si 2 "<<endl;
        cout<<"4. Produs matrici: intre 1 si 2 "<<endl;
        cout<<"0. Exit "<<endl;
        cin>>switch1;
        switch(switch1)
        {
        case 1:
            {
                int z;
                cout<<"1. Pentru citirea de la tastatura apasati"<<endl;
                cout<<"2. Pentru citirea din fisier 1"<<endl;
                cout<<"3. Pentru citirea din fisier 2"<<endl;
                cout<<"4. Pentru citirea din fisier 3"<<endl;
                cin>>z;
                switch(z)
                {
                    case 1:{m1.set_matrice(); break;}
                    case 2:{m1.set_matrice_txt1(); break;}
                    case 3:{m1.set_matrice_txt2(); break;}
                    case 4:{m1.set_matrice_txt3(); break;}
                    default: cout<<"Ati introdus valoare gresita!"<<endl;
                }
                cout<<"Matrice 1 este"<<endl;
                m1.show_matrice();
                break;
            }
        case 2:
            {
                int z;
                cout<<"1. Pentru citirea de la tastatura apasati"<<endl;
                cout<<"2. Pentru citirea din fisier 1"<<endl;
                cout<<"3. Pentru citirea din fisier 2"<<endl;
                cout<<"4. Pentru citirea din fisier 3"<<endl;
                cin>>z;
                switch(z)
                {
                    case 1:{m2.set_matrice(); break;}
                    case 2:{m2.set_matrice_txt1(); break;}
                    case 3:{m2.set_matrice_txt2(); break;}
                    case 4:{m2.set_matrice_txt3(); break;}
                    default: cout<<"Ati introdus valoare gresita!"<<endl;
                }
                cout<<"Matrice 1 este"<<endl;
                m2.show_matrice();
                break;
            }
        case 3:
            {
                m3=m1+m2;
                oks=1;
                cout<<"Suma matricelor 1 si 2 este"<<endl;
                m3.show_matrice();
                break;
            }
        case 4:
            {
                m4=m1*m2;
                okp=1;
                cout<<"Produsul matricelor 1 si 2 este"<<endl;
                m4.show_matrice();
                break;
            }
        case 0:
            {
                cout<<"Iesire"<<endl;
                break;
            }
        default: cout<<"Ati introdus valoare gresita!"<<endl;
        }
    }

    return 0;
}
