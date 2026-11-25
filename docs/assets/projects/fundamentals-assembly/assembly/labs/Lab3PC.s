# PR3 solution, academic year 23-24. Computer Principles
# Matrix handling with functions
# Author: Cristhia Adoney Cruz Delgado
# Last modified: 03/04/24

# typedef struct {
#   int nFil;
nFil = 0		# Offset of the field within the structure
#   int nCol;
nCol = 4		# Offset of the field within the structure
#   float elementos[];
elementos = 8	# Offset of the field within the structure
# } structMat;
#

sizeF = 4	# Number of bytes in a float
LF = 10		# Line feed character

	.data

#structMat mat1
mat1:	.word	6
		.word	6
		.float	11.11, 12.12, 13.13, 14.14, 15.15, 16.16,
		.float	21.21, 22.22, 23.23, 24.24, 25.25, 26.26,
		.float	31.31, 32.32, 33.33, 34.34, 35.35, 36.36,
		.float	41.41, 42.42, 43.43, 44.44, 45.45, 46.46,
		.float	51.51, 52.52, 53.53, 54.54, 55.55, 56.56,
		.float	61.61, 62.62, 63.63, 64.64, 65.65, 66.66

#structMat mat2
mat2:	.word	7
		.word	10
		.float	-36.886, -58.201,  78.671,  19.092, -50.781,  33.961, -59.511, 12.347,  57.306,  -1.938,
		.float	-86.858, -81.852,  54.623, -22.574,  88.217,  64.374,  52.312, 47.918, -83.549,  19.041,
		.float	4.255, -36.842,  82.526,  27.394,  56.527,  39.448,  18.429, 97.057,  76.933,  14.583,
		.float	67.79 ,  -9.861, -96.191,  32.369, -18.494, -43.392,  39.857, 80.686, -36.87 , -17.786,
		.float	30.073,  89.938,  -6.889,  64.601, -85.018,  70.559, -48.853, -62.627, -60.147,  -5.524,
		.float	84.323, -51.718,  93.127, -10.757,  32.119,  98.214,  69.471, 73.814,   3.724,  57.208,
		.float	-41.528, -17.458, -64.226, -71.297, -98.745,   7.095, -79.112, 33.819,  63.531, -96.181

# structMat mat3
mat3:	.word	1
		.word	8
		.float	-36.52,  35.3 ,  79.05, -58.69, -55.23, -19.44, -88.63, -93.61

# structMat mat4
mat4:	.word	16
		.word	1
		.float	-90.57, -65.11, -58.21, -73.23, -89.38, -79.25,  16.82,  66.3
		.float	-96.14, -97.16, -24.66,   5.27, -33.5 , -13.09,  27.13, -74.83

# structMat mat5
mat5:	.word	1
		.word	1
		.float	78.98

# structMat mat6
mat6:	.word	0
		.word	0
		.float	0.0

# float infinito = INFINITY;
infinito:	.word	0x7F800000

# Strings
str_titulo:		.asciiz	"\nStarting the matrix handling program with functions\n" #
str_menu:		.asciiz	"\n--Menu--\n(0) End the program\n(1) Change the working matrix\n(3) Change the value of an element\n(4) Swap an element with its opposite\n(7) Find the minimum\nEnter the chosen option: " #
str_errorOpc:	.asciiz	"\nError: invalid option\n" #
str_termina:	.asciiz	"\nThe program ends\n" #
str_elijeMat:	.asciiz	"\nChoose the working matrix (1..6): " #
str_numMatMal:	.asciiz	"Invalid working matrix number\n" #
str_errorFil:	.asciiz	"Error: invalid dimension.  Invalid row number\n" #
str_errorCol:	.asciiz	"Error: invalid dimension.  Invalid column number\n" #
str_indFila:	.asciiz	"\nRow index: " #
str_indCol:		.asciiz	"Column index: " #
str_nuevoValor:	.asciiz	"New value for the element: " #
str_valMin:		.asciiz	"\nThe minimum value is at (" #
str_conValor:	.asciiz	") with value " #
str_matTiene:	.asciiz	"\n\nThe matrix has dimension " #

 	.text

# Register file: [print_mat]
# Integers, saved on the stack...
# matrix 		 --> $s7
# matrix elements --> $s6
# number of rows --> $s0
# number of columns --> $s1
# f				 --> $s2
# c 			 --> $s3
# Integers, temporary...
# operation accumulator --> $t0

# void print_mat(structMat* mat) {
print_mat:
	addi $sp,$sp,-24 		# push 6 registers
	sw $s0,0($sp)
	sw $s1,4($sp)
	sw $s2,8($sp)
	sw $s3,12($sp)
	sw $s6,16($sp)
	sw $s7,20($sp)
	move $s7,$a0 	    	# argument
#   int nFil = mat->nFil;
	lw $s0,nFil($s7)
#   int nCol = mat->nCol;
	lw $s1,nCol($s7)
#   float* elem = mat->elementos;
	la $s6,elementos($s7)
#   std::cout << "\n\nThe matrix has dimension " << nFil << 'x' << nCol << '\n';
	li $v0,4
	la $a0,str_matTiene
	syscall
	li $v0,1
	move $a0,$s0
	syscall
	li $v0,11
	li $a0,120 # 'x'
	syscall
	li $v0,1
	move $a0,$s1
	syscall
	li $v0,11
	li $a0,10 # '\n'
	syscall
	move $s2,$zero
	b for_fila
#   for(int f = 0; f < nFil; f++) {
for_fila:
		move $s3,$zero
		blt $s2,$s0,for_columna
		b for_fila_fin
#     for(int c = 0; c < nCol; c++) {
for_columna:
			bge $s3,$s1,for_columna_fin
#       std::cout << elem[f*nCol + c] << ' ';
			mul $t0,$s2,$s1
			add $t0,$s4,$s3
			mul $t0,$t0,sizeF 	# add one column
			add $t0,$t0,$s6 	# address of the column IN THE MATRIX
			li $v0,2
			l.s $f12,0($t0) 	# load the element at that address
			syscall
			li $v0,11
			li $a0,32 			# ' '
			syscall
			addi $s3,$s3,1
			b for_columna
#     }
for_columna_fin:
#     std::cout << '\n';
			li $v0,11
			li $a0,10 			# '\n'
			syscall
			mul $t0,$s1,sizeF 	# add one row
			add $s6,$s6,$t0 	# address of the row IN THE MATRIX
			addi $s2,$s2,1
			b for_fila
#   }
for_fila_fin:
#   std::cout << '\n';
		li $v0,11
		li $a0,10 			# '\n'
		syscall
		b for_fin
for_fin:
	b print_mat_fin
print_mat_fin:
	lw $s0,0($sp) 			# pop 6 registers
	lw $s1,4($sp)
	lw $s2,8($sp)
	lw $s3,12($sp)
	lw $s6,16($sp)
	lw $s7,20($sp)
	addi $sp,$sp,24
	jr $ra
# }

# Register file: [change_elto]
# Integers, temporary...
# matrix         --> $t7
# matrix elements --> $t6
# operation accumulator --> $t0
# row index      --> $t1
# column index   --> $t2
# number of columns --> $t3
# Floats, temporary...
# value          --> $f16

# void change_elto(structMat* mat, int indF, int indC, float valor) {
change_elto:
	move $t7,$a0 			# arguments
	move $t1,$a1
	move $t2,$a2
	mov.s $f16,$f12

	la $t6,elementos($t7)	# required

#   int numCol = mat->nCol;
	lw $t3,nCol($t7)
#   mat->elementos[indF*numCol + indC] = valor;
	mul $t0,$t1,$t3 		# operations
	add $t0,$t2,$t0
	mul $t0,$t0,sizeF 		# multiply by the size of a float
	add $t0,$t0,$t6 		# add the element offset within the matrix
	s.s $f16,0($t0) 		# store the value at the address
	b change_elto_fin
change_elto_fin:
	jr $ra
# }

# Register file: [swap]
# Integers, temporary...
# element 1 address --> $t0
# element 2 address --> $t1
# Floats, temporary...
# element 1 value --> $f16
# element 2 value --> $f17

# void swap(float* e1, float* e2) {
swap:
	move $t0,$a0 			# arguments
	move $t1,$a1
#   float temp1 = *e1;
	l.s $f16,0($t0)
#   float temp2 = *e2;
	l.s $f17,0($t1)
#   *e1 = temp2;
	s.s $f16,0($t1)			# store the value at the address
#   *e2 = temp1;
	s.s $f17,0($t0)			# store the value at the address
	b swap_fin
swap_fin:
	jr $ra
# }

# Register file: [intercambia]
# Integers, temporary...
# matrix         --> $t7
# matrix elements --> $t6
# operation accumulator --> $t0, $t8, $t9
# number of rows --> $t1
# number of columns --> $t2
# row index      --> $t3
# column index   --> $t4

# void intercambia(structMat* mat, int indF, int indC) {
intercambia:
	addi $sp,$sp,-4 	# push 1 register
	sw $ra,0($sp)
	move $t7,$a0 		# arguments
	move $t3,$a1
	move $t4,$a2
#   int nFil = mat->nFil;
	lw $t1,nFil($s7)
#   int nCol = mat->nCol;
	lw $t2,nCol($s7)
#   float* datos = mat->elementos;
	la $t6,elementos($s7)
#   float* e1 = &datos[indF*numCol + indC];
	mul $t0,$t3,$t2 	# operations
	add $t0,$t0,$t4
	mul $t0,$t0,sizeF 	# multiply by the size of a float
	add $t0,$t0,$t6 	# add the element offset within the matrix
#   float* e2 = &datos[(numFil - indF - 1)*numCol + (numCol - indC - 1)];
	addi $t3,$t3,-1 	# operations
	sub $t8,$t1,$t3
	mul $t8,$t8,$t2

	addi $t4,$t4,-1
	sub $t9,$t2,$t4

	add $t8,$t8,$t9
	mul $t8,$t8,sizeF 	# multiply by the size of a float
	add $t8,$t8,$t6 	# add the element offset within the matrix
#   swap(e1, e2);
	move $a0,$t0
	move $a1,$t8
	jal swap
	b intercambia_fin
intercambia_fin:
	lw $ra,0($sp)
	addi $sp,$sp,4		# pop 1 register
	jr $ra
# }

# std::tuple<float, int, int> find_min(structMat* mat) {
find_min:
#   int numCol = mat->nCol;
#   int numFil = mat->nFil;
#   float* datos = mat->elementos;
#   float min = infinito;
#   int fmin = -1;
#   int cmin = -1;
#   for(int f = 0; f < numFil; f++) {
#     for(int c = 0; c < numCol; c++) {
#       float valor = datos[f * numCol + c];
#       if (valor < min) {
#         min = valor;
#         fmin = f;
#         cmin = c;
#       }
#     }
#   }
#   return {min, fmin, cmin};
find_min_fin:
# }

# Register file: [main]
# Integers, saved...
# option         --> $s0
# matrizT        --> $s7
# row index      --> $s2
# column index   --> $s3
# minimum row    --> $s4
# minimum column --> $s5
# Integers, temporary...
# || conditions  --> $t0-$t6
# Floats, saved...
# value          --> $f20
# minimum value  --> $f21

# int main() {
main:
#   std::cout << std::fixed << std::setprecision(8);  // Ignore
#   std::cout << "\nStarting the matrix handling program with functions\n";
	li $v0,4
	la $a0,str_titulo
	syscall
#   structMat* matTrabajo = &mat1;
	la $s7,mat1
	b while
#   while(true) {
while:
#     print_mat(matTrabajo);
		move $a0,$s7
		jal print_mat
#     std::cout <<
#     "(0) End the program\n"
#     "(1) Change the working matrix\n"
#     "(3) Change the value of an element\n"
#     "(4) Swap an element with its opposite\n"
#     "(7) Find the minimum\n"
#     "\nEnter the chosen option: ";
		li $v0,4
		la $a0,str_menu
		syscall
#     int opcion;
		move $s0,$zero
#     std::cin >> opcion;
		li $v0,5
		syscall
		move $s0,$v0
		b if_Opc0
#
#	  // Option 0 ////////////////////////////////////////////////////////////
#     if(opcion == 0) {
if_Opc0:	beqz $s0,fin_while
			b if_Opc1
#       break;
#     }
#
#     // Option 1 ////////////////////////////////////////////////////////////
#     if(opcion == 1) {
if_Opc1:	bne $s0,1,if_Opc3y4
#       std::cout << "\nChoose the working matrix (1..6): ";
			li $v0,4
			la $a0,str_elijeMat
			syscall
#       int matT;
			move $s1,$zero
#       std::cin >> matT;
			li $v0,5
			syscall
			move $s7,$v0
			b if_MatT1
#       if (matT == 1) {
if_MatT1:		bne $s7,1,if_MatT2
#         matTrabajo = &mat1;
				la $s7,mat1
#         continue;  // back to the start of the loop
				b while
#       }
#       if (matT == 2) {
if_MatT2:		bne $s7,2,if_MatT3
#         matTrabajo = &mat2;
				la $s7,mat2
#         continue;  // back to the start of the loop
				b while
#       }
#       if (matT == 3) {
if_MatT3:		bne $s7,3,if_MatT4
#         matTrabajo = &mat3;
				la $s7,mat3
#         continue;  // back to the start of the loop
				b while
#       }
#       if (matT == 4) {
if_MatT4:		bne $s7,4,if_MatT5
#         matTrabajo = &mat4;
				la $s7,mat4
#         continue;  // back to the start of the loop
				b while
#       }
#       if (matT == 5) {
if_MatT5:		bne $s7,5,if_MatT6
#         matTrabajo = &mat5;
				la $s7,mat5
#         continue;  // back to the start of the loop
				b while
#       }
#       if (matT == 6) {
if_MatT6:		bne $s7,6,if_errorMatT
#         matTrabajo = &mat6;
				la $s7,mat6
#         continue;  // back to the start of the loop
				b while
#       }
if_errorMatT:
#       std::cout << "Invalid working matrix number\n";
			li $v0,4
			la $a0,str_numMatMal
			syscall
#       continue;  // back to the start of the loop
			b while
#     }
#
#     // Options 3 and 4 //////////////////////////////////////////////////////////
#     if(opcion == 3 || opcion == 4) {
if_Opc3y4:	seq $t0,$s0,3
			seq $t1,$s0,4
			or $t2,$t0,$t1
			beqz $t2,if_Opc7
#       std::cout << "\nRow index: ";
			li $v0,4
			la $a0,str_indFila
			syscall
#       int indFil;
			move $s2,$zero
#       std::cin >> indFil;
			li $v0,5
			syscall
			move $s2,$v0
#       if ((indFil < 0) || (indFil >= matTrabajo->nFil)) {
if_errorFil:    slt $t3,$s2,$zero
			    lw $t4,nFil($s7)
			    sge $t5,$s2,$t4
			    or $t6,$t3,$t5
			    beqz $t6,continuar_Opc3y4_1
#         std::cerr << "Error: invalid dimension. Invalid row number\n";
			    li $v0,4
			    la $a0,str_errorFil
			    syscall
#         continue;  // back to the start of the loop
			    b while
#       }
continuar_Opc3y4_1:
#       std::cout << "Column index: ";
			li $v0,4
			la $a0,str_indCol
			syscall
#       int indCol;
			move $s3,$zero
#       std::cin >> indCol;
			li $v0,5
			syscall
			move $s3,$v0
#       if ((indCol < 0) || (indCol >= matTrabajo->nCol)){
if_errorCol:    slt $t3,$s3,$zero
			    lw $t4,nCol($s7)
			    sge $t5,$s2,$t4
			    or $t6,$t3,$t5
			    beqz $t6,continuar_Opc3y4_2
#         std::cerr << "Error: invalid dimension. Invalid column number\n";
				li $v0,4
				la $a0,str_errorCol
				syscall
#         continue;  // back to the start of the loop
				b while
#       }
continuar_Opc3y4_2:
			b if_Opc3
#       if (opcion == 3) {
if_Opc3:		bne $s0,3,if_Opc4
#         std::cout << "New value for the element: ";
				li $v0,4
				la $a0,str_nuevoValor
				syscall
#         float valor;
				li.s $f20,0.0
#         std::cin >> valor;
				li $v0,6
				syscall
				mov.s $f20,$f0
#         change_elto(matTrabajo, indFil, indCol, valor);
				move $a0,$s7
				move $a1,$s2
				move $a2,$s3
				mov.s $f12,$f20
				jal change_elto
				b continuar_Opc3y4_3
#       }
#       if(opcion == 4) {
if_Opc4:		bne $s0,4,if_Opc7
#         intercambia(matTrabajo, indFil, indCol);
				move $a0,$s7
				move $a1,$s2
				move $a2,$s3
				jal intercambia
				b continuar_Opc3y4_3
#       }
#       continue;
continuar_Opc3y4_3:
			b while
#     }
#
#     // Option 7 ////////////////////////////////////////////////////////////
#     if(opcion == 7) {
if_Opc7:	bne $s0,7,if_errorOpc
#       float valorMin;
			li.s $f21,0.0
#       int filaMin;
			move $s4,$zero
#       int columnaMin;
			move $s5,$zero
#       std::tie(valorMin, filaMin, columnaMin) = find_min(matTrabajo);

#       std::cout << "\nThe minimum value is at (" << filaMin << ',' << columnaMin <<") with value " << valorMin;
			li $v0,4
			la $a0,str_valMin
			syscall

			li $v0,4
			la $a0,str_conValor
			syscall

			li $v0,11
			li $a0,32 # ' '
			syscall
#       continue;
			b while
#     }
#
#     // Invalid option /////////////////////////////////////////////////////
if_errorOpc:
#     std::cout << "Error: opcion incorrecta\n";
			li $v0,4
			la $a0,str_errorOpc
			syscall
			b fin_while
#   }
fin_while:
#   std::cout << "\nThe program ends\n";
	li $v0,4
	la $a0,str_termina
	syscall
# }
	li $v0,10
	syscall
