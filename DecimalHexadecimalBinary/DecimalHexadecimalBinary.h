#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Converter{
private:
	string number;

public:
	Converter(string n);
    string HexadecimalToDecimal();
    string HexadecimalToBynary();
    string DecimalToHexadecimal();
    string DecimalToBinary();
    string BinaryToDecimal();
    string BinaryToHexadecimal();
};

Converter::Converter(string n){
	this->number = n;
}

string Converter::HexadecimalToDecimal(){
    int len = number.size();
    int base = 1;
    int dec_val = 0;
    string result;
    for (int i = len - 1; i >= 0; i--) {
        if (number[i] >= '0' && number[i] <= '9') {
            dec_val += (int(number[i]) - 48) * base;
            base = base * 16;
        }
        else if (number[i] >= 'A' && number[i] <= 'F') {
            dec_val += (int(number[i]) - 55) * base;
            base = base * 16;
        }
    }
    result = to_string(dec_val);
	return result;
}

string Converter::HexadecimalToBynary(){
    string n = number, result;
    char* num = const_cast<char*>(n.c_str());
    long int i = 0;
    int j = 0;

    while (num[i]) {

        switch (num[i]) {
        case '0':
            result += "0000";
            break;
        case '1':
            result += "0001";
            break;
        case '2':
            result += "0010";
            break;
        case '3':
            result += "0011";
            break;
        case '4':
            result += "0100";
            break;
        case '5':
            result += "0101";
            break;
        case '6':
            result += "0110";
            break;
        case '7':
            result += "0111";
            break;
        case '8':
            result += "1000";
            break;
        case '9':
            result += "1001";
            break;
        case 'A':
            result += "1010";
            break;
        case 'B':
            result += "1011";
            break;
        case 'C':
            result += "1100";
            break;
        case 'D':
            result += "1101";
            break;
        case 'E':
            result += "1110";
            break;
        case 'F':
            result += "1111";
            break;
        default:
            cout << "\nEntrada INVALIDA "
                << num[i];
        }
        i++;
    }

    while (result[j] == '0') j++;
    result.erase(0, j);
    return result;
}

string Converter::DecimalToHexadecimal(){
    char hexaDeciNum[100];
    string result;
    int n = stoi(number);
    int i = 0;
    while (n != 0) {
        int temp = 0;
        temp = n % 16;
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        n = n / 16;
    }
    for (int j = i - 1; j >= 0; j--)
        result += hexaDeciNum[j];
    return result;
}

string Converter::DecimalToBinary(){
    int binaryNum[32];
    string result;
    int n = stoi(number);
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) 
        result += to_string(binaryNum[j]);
    return result;
}

string Converter::BinaryToDecimal(){
    string result;
    int n = stoi(number);
    int dec_value = 0;
    int base = 1;

    int temp = n;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }
    result = to_string(dec_value);
    return result;
}

string Converter::BinaryToHexadecimal(){
    string result;
    int len = number.length(), check = 0;
    int num = 0, sum = 0, mul = 1;
    vector<char> ans;
    for (int i = len - 1; i >= 0; i--) {
        sum += (number[i] - '0') * mul;
        mul *= 2;
        check++;
        if (check == 4 || i == 0) {
            if (sum <= 9)
                ans.push_back(sum + '0');
            else
                ans.push_back(sum + 55);
            check = 0;
            sum = 0;
            mul = 1;
        }
    }
    len = ans.size();
    for (int i = len - 1; i >= 0; i--)
        result += ans[i];
    return result;
}
