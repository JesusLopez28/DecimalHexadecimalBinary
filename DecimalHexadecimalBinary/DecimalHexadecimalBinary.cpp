#include <iostream>
#include "DecimalHexadecimalBinary.h"
using namespace std;

int main(){
    string number;
    int opc = 1, election;
    cout << "----------Calculadora de binario, hexadecimal, decimal----------" << endl;
    cout << "Jesus Alejandro Lopez Rosales-22110104-2|O\n\n" << endl << endl;
    system("pause");
    system("cls");

    while (opc == 1) {
        cout << "-----MENU-----" << endl;
        cout << "Que desea convertir?" << endl;
        cout << "1.- Decimal" << endl;
        cout << "2.- Hexadecimal" << endl;
        cout << "3.- Binario" << endl;
        cout << "Elije una opcion: ";
        cin >> election;
        system("cls");

        if (election == 1) {
            cout << "Ingrese el numero decimal a convertir: ";
            cin >> number;
            Converter c(number);
            cout << "Convertido a hexadecimal: " << c.DecimalToHexadecimal() << endl;
            cout << "Convertido a binario: " << c.DecimalToBinary() << endl;
        }
        else if (election == 2) {
            cout << "Ingrese el numero hexadecimal a convertir (En mayusculas): ";
            cin >> number;
            Converter c(number);
            cout << "Convertido a decimal: " << c.HexadecimalToDecimal() << endl;
            cout << "Convertido a binario: " << c.HexadecimalToBynary() << endl;
        }
        else if (election == 3) {
            cout << "Ingrese el numero binario a convertir: ";
            cin >> number;
            Converter c(number);
            cout << "Convertido a decimal: " << c.BinaryToDecimal() << endl;
            cout << "Convertido a hexadecimal: " << c.BinaryToHexadecimal() << endl;
        }
        else {
            cout << "Entrada INVALIDA" << endl;
        }

        system("pause");
        system("cls");
        cout << "Desea convertir otro numero:" << endl;
        cout << "1.-Si" << endl;
        cout << "0.-No" << endl;
        cout << "Elige una opcion: ";
        cin >> opc;
        system("cls");
    }
    system("cls");
    cout << "Gracias por usar el programa. FIN" << endl;
    return 0;
}