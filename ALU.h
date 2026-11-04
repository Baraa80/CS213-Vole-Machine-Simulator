#ifndef ALU_H
#define ALU_H

#include <string>

using namespace std;

class ALU {
public:
    ALU();

    string addTwosComplement(const string& hex1 , const string& hex2 ) ;


    string addFloatingPoint(const string& hex1 , const string& hex2) ;

    string bitwiseOR(const string& hex1 , const string& hex2) ;

    
    string bitwiseAND(const string& hex1 , const string& hex2) ;

  
    string bitwiseXOR(const string& hex1 , const string& hex2) ;

    
    string rotateRight(const string& hexVal , int shiftTimes) ;
};

#endif 