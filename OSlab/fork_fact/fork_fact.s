	.file	"fork_fact.c"
	.text
	.globl	g_val
	.data
	.align 4
	.type	g_val, @object
	.size	g_val, 4
g_val:
	.long	100
	.section	.rodata
.LC0:
	.string	"fork failed"
.LC1:
	.string	"Child"
.LC2:
	.string	"%s   %d   %d"
.LC3:
	.string	"Parent"
	.align 8
.LC4:
	.string	"\n Enter the number to find factorial:"
.LC5:
	.string	"%d"
	.align 8
.LC6:
	.string	"\n Factorial of number %d is: %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$10, -24(%rbp)
	movq	$0, -16(%rbp)
	call	fork@PLT
	movl	%eax, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jns	.L2
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %edi
	call	exit@PLT
.L2:
	cmpl	$0, -20(%rbp)
	jne	.L3
	leaq	.LC1(%rip), %rax
	movq	%rax, -16(%rbp)
	movl	g_val(%rip), %ecx
	movl	-24(%rbp), %edx
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %edi
	call	exit@PLT
.L3:
	leaq	.LC3(%rip), %rax
	movq	%rax, -16(%rbp)
	addl	$10, -24(%rbp)
	movl	g_val(%rip), %eax
	addl	$100, %eax
	movl	%eax, g_val(%rip)
	movl	g_val(%rip), %ecx
	movl	-24(%rbp), %edx
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-36(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	$1, -32(%rbp)
	jmp	.L4
.L5:
	movl	-28(%rbp), %eax
	imull	-32(%rbp), %eax
	movl	%eax, -28(%rbp)
	addl	$1, -32(%rbp)
.L4:
	movl	-36(%rbp), %eax
	cmpl	%eax, -32(%rbp)
	jle	.L5
	movl	-36(%rbp), %eax
	movl	-28(%rbp), %edx
	movl	%eax, %esi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	g_val(%rip), %ecx
	movl	-24(%rbp), %edx
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
