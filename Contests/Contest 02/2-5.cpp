#include <iomanip>
#include <iostream>
using namespace std;

class BinaryNumber
{
public:
    string bin;

    BinaryNumber(const string &s) {bin = s;}

    operator string () const {return bin;}

    const BinaryNumber &operator++() {
        int i = bin.length();
        
        while (bin[i] != '0' && i >= 0) {bin[i] = '0'; i--;}

        if (i >= 0 ) {bin[i] = '1';} 
        else {bin = '1' + bin;}

        return *this;
    }
};