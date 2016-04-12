#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include <string>
#include <cstring>
#include <iostream>

int main(){
    int value = 1000000000;
    string numWithCommas = to_string(value);
    int insertPosition = numWithCommas.length() - 3;
    while (insertPosition > 0) {
        numWithCommas.insert(insertPosition, ",");
        insertPosition-=3;
    }
    cout<<numWithCommas;
    return 0;
}