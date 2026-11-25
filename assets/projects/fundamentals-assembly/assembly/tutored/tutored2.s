notes:

s.s $f20, 4.5
mov.s $f20,$f22

li $t0,2
li.s $f4, 3.5
mtc1 $t0,$f6
cvt.s.w $f6,$f6

c.eq.s $f8, $f10 #equal
  le
  lt
bc1t etiqueta
bc1f etiqueta

exercise:

ask for 2 integers 8 ( dividend, divisor )
if remainder 0, show the result
if remainder !0, convert to float and show the result
divisor !0

			C++

#include <iostream>

int main () {
  int dividendo{0};
  int divisor{0};
  std::cout << "Enter the dividend\n";
  std::cin >> dividendo;
  std::cout << "Enter the divisor\n";
  std::cin >> divisor;
  while (divisor == 0) {
    std::cout << "Error. Choose another number\n";
    std::cin >> divisor;
  }
  cociente = dividendo / divisor;
  if ( ) {
    std::cout << "Quotient " << cociente << std::endl;
    std::cout << "Remainder " << resto << std::endl;
  }
