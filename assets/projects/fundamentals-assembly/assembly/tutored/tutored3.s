# dividendo --> $s0 | divisor --> $s1 | cociente --> $s2 | resto --> $s3

	.data
dividendo:	.asciiz "Enter the dividend: "
divisor:	.asciiz "Enter the divisor: "
error:		.asciiz "Error. Choose another number."
cociente:	.asciiz "Quotient: "
resto:		.asciiz "Remainder: "
	.text
main:
	#initialise variables
	move $s0,$zero
	move $s1,$zero

	#dividend
	#print the string
	li $v0,4
	la $a0,dividendo
	syscall
	#read an integer
	li $v0,5
	syscall
	#save the value
	move $s0,$v0

	#divisor
	#print the string
	li $v0,4
	la $a0,dividendo
	syscall
	#read an integer
	li $v0,5
	syscall
	#save the value
	move $s1,$v0

bucle:	beqz $s1
	#print the string
	li $v0,4
	la $a0,error
	syscall
	#read an integer
	li $v0,5
	syscall
	#save the value
	move $s1,$v0
	b bucle

	#initialise
	move $s2,$zero
	move $s3,$zero

	div $s2,$s0,$s1
	___ $s3,$s0,$s1
	bnez $s3,bloque_if
	b bloque_else

bloque_if:
	mtc1 $s2,$f20
	cvt.d.w

	#quotient
	#print the string
	li $v0,4
	la $a0,cociente
	syscall
	#print a double
	li $v,3
	la $a0,$f20-$f21
	syscall
	b fin

bloque_else:
	#quotient
	#print the string
	li $v0,4
	la $a0,cociente
	syscall
	#print an integer
	li $v0,1
	la $a0,$s2
	syscall
	b fin

fin:
	#remainder
	#print the string
	li $v0,4
	la $a0,resto
	syscall
	#print an integer
	li $v0,1
	la $a0,$s3
	syscall

	li $v0,10
	syscall
