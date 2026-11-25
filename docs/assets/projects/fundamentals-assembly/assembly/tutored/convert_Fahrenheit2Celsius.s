# Program that converts degrees Fahrenheit to Celsius
# Uses the formula C = (F - 32)/1.8
	.data
str_pideF:	.asciiz	"Enter degrees Fahrenheit (integer): "
str_celsius:	.asciiz	"Temperature in degrees Celsius: "
factor:		.float	1.8
	.text
main:
	# Print the prompt for Fahrenheit
	li	$v0,4
	la	$a0,str_pideF
	syscall
	# Wait for an integer to be entered
	li	$v0,5
	syscall
	move	$s0,$v0    	# Store the value read in saved register $s0
	# Convert the integer to float
	mtc1	$s0,$f20	# $f20 = $s0
	cvt.s.w	$f22,$f20	# $f22 = $f20
	# Perform the calculation
	li.s	$f4,32.0	# $f4 = 32.0
	sub.s	$f24,$f22,$f4	# $f24 = $f22 - $f4
	l.s	$f4,factor	# $f4 = 1.8
	div.s	$f24,$f24,$f4	# $f24 = $f24 / $f4
	# Print the result after a message
	li	$v0,4
	la	$a0,str_celsius
	syscall
	# Print the result
	li	$v0,2
	mov.s	$f12,$f24
	syscall
	# End the program
	li	$v0,10
	syscall
