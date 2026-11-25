# #include<iostream>
# int main(void) {
#     double numero,sumapos,sumaneg;
#     int cuentanum;

#     std::cout << "\nSum of positive and negative doubles.\n";
#     std::cout << "Enter positive and negative doubles (0 to exit):\n";
#     sumapos = 0;
#     sumaneg = 0;
#     cuentanum = 0;
#     do {
#         std::cin >> numero;
#         if (numero > 0 ) {
#             sumapos+=numero;
#             cuentanum++;
#         } else if ( numero < 0 ) {
#             sumaneg+=numero;
#             cuentanum++;
#         }
#     } while (numero != 0);
#     std::cout << "\nSum of positives = " << sumapos;
#     std::cout << "\nSum of negatives = " << sumaneg;
#     std::cout << "\nTotal numbers entered = " << cuentanum;
#     if (sumapos > -sumaneg)
#             std::cout << "\nThe positive numbers add up to more in absolute value";
#     else if (-sumaneg > sumapos)
#             std::cout << "\nThe negative numbers add up to more in absolute value";

#     std::cout << "\nEND OF PROGRAM.\n";
#     return(0);
# }
    .data
titulo: .asciiz "\nSum of positive and negative doubles.\n"
cadpet: .asciiz "Enter positive and negative doubles (0 to exit):\n"
cadsp:  .asciiz "\nSum of positives = "
cadsn:  .asciiz "\nSum of negatives = "
cadtot: .asciiz "\nTotal numbers entered = "
cadpos: .asciiz "\nThe positive numbers add up to more in absolute value"
cadneg: .asciiz "\nThe negative numbers add up to more in absolute value"
cadfin: .asciiz "\nEND OF PROGRAM.\n"

#Register file:
# $f4 --> 0.0;     			$s0 --> number count;
# $f20 --> number;
# $f22 --> sum of positives;
# $f24 --> sum of negatives;
# $f30 --> -$f24;

	.text

main:

# #include<iostream>
# int main(void) {
#     double numero,sumapos,sumaneg;
#     int cuentanum;
#     std::cout << "\nSum of positive and negative doubles.\n";
	li $v0,4
	la $s0,titulo
	syscall
#     std::cout << "Enter positive and negative doubles (0 to exit):\n";
	li $v0,4
	la $s0,cadpet
	syscall
#     sumapos = 0;
#     sumaneg = 0;
#     cuentanum = 0;
	li.d $f22,0.0
	li.d $f24,0.0
	move $s0,$zero
	li.d $f4,0.0
#     do {
do_while:
#         std::cin >> numero;
	li $v0,7
	syscall
	mov.d $f20,$f0
			c.eq.d $f20,$f4
			bc1t fin_while
#         if (numero > 0 ) {
positivo:	c.lt.d $f20,$f4
			bc1t negativo
#             sumapos+=numero;
	add.d $f22,$f20,$f22
#             cuentanum++;
	add $s0,$s0,1
	b do_while
#         } else if ( numero < 0 ) {
negativo:
#             sumaneg+=numero;
	add.d $f24,$f20,$f24
#             cuentanum++;
	add $s0,$s0,1
	b do_while
#         }
#     } while (numero != 0);
fin_while:
#     std::cout << "\nSum of positives = " << sumapos;
	li $v0,4
	la $s0,cadsp
	syscall
	li $v0,3
	mov.d $f12,$f22
	syscall
#     std::cout << "\nSum of negatives = " << sumaneg;
	li $v0,4
	la $s0,cadsn
	syscall
	li $v0,3
	mov.d $f12,$f24
	syscall
#     std::cout << "\nTotal numbers entered = " << cuentanum;
	li $v0,4
	la $s0,cadtot
	syscall
	li $v0,1
	move $a0,$s0
	syscall
	neg.d $f30,$f24
#     if (sumapos > -sumaneg)
if:			c.lt.d $f22,$f30
			bc1t else_if
#             std::cout << "\nThe positive numbers add up to more in absolute value";
	li $v0,4
	la $s0,cadpos
	syscall
#     else if (-sumaneg > sumapos)
else_if:	c.lt.d $f30,$f22
			bc1t fin
#             std::cout << "\nThe negative numbers add up to more in absolute value";
	li $v0,4
	la $s0,cadneg
	syscall
fin:
#     std::cout << "\nEND OF PROGRAM.\n";
	li $v0,4
	la $s0,cadfin
	syscall
#     return(0);
	li $v0,10
	syscall
