#include<iostream>
#include"BigInteger.h"

int main() {
	 BigInteger bg3("689");
  BigInteger bg1_mul("17");
  BigInteger bgg_mul = bg3*bg1_mul;
  bgg_mul.printBigInteger();

  BigInteger bg("1500");
  BigInteger bg1("25");
  BigInteger bgg = bg1-bg;
  bgg.printBigInteger();

  std::cout<<std::endl;
  BigInteger bg_sum("78923556");
  BigInteger bg1_sum("7895544");
  BigInteger bggg = bg1_sum + bg_sum;
  bggg.printBigInteger();

  return 0;
}
