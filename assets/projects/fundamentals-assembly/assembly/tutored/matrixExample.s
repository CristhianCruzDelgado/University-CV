nFil = 3
nCol = 5

#Lista de variables
# - entero
#s0 --- valor
# - direccion
#s1 --- primer elemento matriz
# - variables de iteracion
#s2 --- f
#s3 --- c
# - constantes
#s4 --- numero de filas
#s5 --- numero de columnas
# - podructo de variables de iteracion
#t0 --- indice

    .data
matriz: .word   11,12,13,14,15,21,22,23,24,25,31,32,33,34,35

str_valor:  .asciiz "\nmat["  << f << "," << c << "] = "
str_fin:    .asciiz "\nTermina el programa\n"
    .text
# ___1___
# int main() {
main:
#   int numFil = 3;
    li $s4,nFil
#   int numCol = 5;
    li $s5,nCol
#   int mat[numFil][numCol] = {
#     { 11, 12, 13, 14, 15},
#     { 21, 22, 23, 24, 25},
#     { 31, 32, 33, 34, 35},
#   };
    la $s1,matriz

    move $s2,$zero
    move $s3,$zero
#   for(int f = 0; f < numFil; f++) {
for_fila:

    blt $s2,$s4,for_columna
    b fin
#     for(int c = 0; c < numCol; c++) {
for_columna:
#       int valor = mat[f][c];
        mult $t0,$s2,$s4
        lw $s0,$t0($s1)
#       std::cout << "\nmat["  << f << "," << c << "] = " << valor;
        li $v0,4
        la $a0,str_valor
        syscall
        li $v0,5
        la $a0,$s0
        syscall

        addi $s3,$s3,1
        blt $s3,$s5,for_columna
        addi $s2,$s2
        b for_fila
#     }
#   }
fin:
#   std::cout << "\nTermina el programa\n";
    li $v0,4
    la $a0,str_fin
    syscall
# }
    li $v0,10
    syscall
