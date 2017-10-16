#include<iostream>
#include"BigInteger.h"

int main() {
	BigInteger res("159");
	BigInteger res1("7");
	BigInteger reso = res%res1;
	reso.printBigInteger();

	 BigInteger bg31("687892452");
  BigInteger bg1_mul1("0");
  BigInteger bgg_mul1 = bg31/bg1_mul1;
  bgg_mul1.printBigInteger();

	 BigInteger bg3("123");
  BigInteger bg1_mul("210");
  BigInteger bgg_mul = bg3*bg1_mul;
  bgg_mul.printBigInteger();

  BigInteger bg("1500");
  BigInteger bg1("25");
  BigInteger bgg = bg1-bg;
  bgg.printBigInteger();

  BigInteger b("999");
  BigInteger b1("1000");
  std::cout<<(b > b1) <<" " <<(b< b1) <<" " <<(b == b1);;

  std::cout<<std::endl;
  BigInteger bg_sum("78923556");
  BigInteger bg1_sum("7895544");
  BigInteger bggg = bg1_sum + bg_sum;
  bggg.printBigInteger();

  return 0;
}
