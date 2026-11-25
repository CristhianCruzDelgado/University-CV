# PR2 Computer Principles
# Author: Cristhian Adoney Cruz Delgado
# Date: 7/03/2024

# Register file
# $s0 -> speed
# $s1 -> time
# $s2 -> maximum speed
# $s3 -> maximum time
# $s4 -> answer
# $f20 -> maximum distance
# $f22 -> speed as double
# $f24 -> metres

	.data
cadtit: .asciiz "\nPR2 Maximum distance calculation. Enter a value less than or equal to 0 to finish.\n"
cadvel: .asciiz "\nSpeed (km/h)? "
cadtie: .asciiz "\nTime (seconds)? "
cadmxv: .asciiz "\nSpeed of the vehicle that covered the longest distance (km/h): "
cadmxt: .asciiz "\nTime taken to cover it (s): "
cadmxd: .asciiz "\nDistance covered (m):  "
cadcon: .asciiz "\nRun again? (0 to exit, any other integer to continue): "
cadfin: .asciiz "\nEND OF PROGRAM.\n"

	.text
# #include<iostream>
# int main(void) {
main:
#     int vel,tiempo,max_v = 0,max_t = 0,respuesta;
	move $s2,$zero
	move $s3,$zero
#     float maxdist = 0;
	li.d $f20,0.0
#     std::cout << "\nPR2 Maximum distance calculation. Enter a value less than or equal to 0 to finish.\n";
	li $v0,4
	la $a0,cadtit
	syscall
#     do {
do_while:
#         do {
do_while_true:
#             std::cout << "\nSpeed (km/h)? ";
		li $v0,4
		la $a0,cadvel
		syscall
#             std::cin >> vel;
		li $v0,3
		syscall
		move $s0,$v0
#             if (vel <= 0) break;
if1:		blez $s0,fin_do_while_true
#             std::cout << "\nTime (seconds)? ";
		li $v0,4
		la $a0,cadtie
		syscall
#             std::cin >> tiempo;
		li $v0,3
		syscall
		move $s1,$v0
#             if (tiempo<=0) break;
if2:		blez $s1,fin_do_while_true
#             // convert km/h to metres per second
#             float velf = float(vel) * (1000.0/3600.0);
#             float metros = velf * float(tiempo);
#             if (metros >= maxdist) {
if3:		c.lt.d $f24,$f20
		bc1t do_while_true
#                 maxdist = metros;
		mov.d $f20,$f24
#                 max_v = vel;
		move $s2,$s0
#                 max_t = tiempo;
		move $s3,$s1
#             }
#         } while (true);
while_true:
		b do_while_true
fin_do_while_true:
#         std::cout << "\nSpeed of the vehicle that covered the longest distance (km/h): "
	li $v0,4
	la $a0,cadmxv
	syscall
#         << max_v;
	li $v0,1
	move $a0,$s2
	syscall
#         std::cout << "\nTime taken to cover it (s): "
	li $v0,4
	la $a0,cadmxt
	syscall
#         << max_t;
	li $v0,1
	move $a0,$s3
	syscall
#         std::cout << "\nDistance covered (m):  "
	li $v0,4
	la $a0,cadmxd
	syscall
#         << maxdist;
	li $v0,2
	mov.d $f12,$f20
	syscall
#         std::cout << "\nRun again? (0 to exit, any other integer to continue): ";
	li $v0,4
	la $a0,cadcon
	syscall
#         std::cin >> respuesta;
	li $v0,3
	syscall
	move $s4,$v0
#     } while (respuesta != 0);
while:
	bnez $s4,do_while
#     std::cout << "\nEND OF PROGRAM.\n";
	li $v0,4
	la $a0,cadfin
	syscall
	li $v0,10
	syscall
# }
