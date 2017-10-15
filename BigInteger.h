#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include "ListNode.h"
class BigInteger {
 private:
    ListNode Number;
	int length;
 public:
    BigInteger();
    BigInteger(const std::string& number);
    void printBigInteger();
    BigInteger& operator=(const BigInteger& obj);
    friend BigInteger operator+(const BigInteger& bgi1,const BigInteger& bgi2);
    friend BigInteger operator-(const BigInteger& bgi1,const BigInteger& bgi2);
	friend BigInteger operator*(const BigInteger& bgi1,const BigInteger& bgi2);
	friend BigInteger operator/(const BigInteger& bgi1,const BigInteger& bgi2);
	friend bool operator>(BigInteger& bgi1, BigInteger& bgi2);
	friend bool operator<(BigInteger& bgi1, BigInteger& bgi2);
	friend bool operator==(BigInteger& bgi1, BigInteger& bgi2);
};
#endif