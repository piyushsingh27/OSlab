	.file	"fork.c"
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
	subq	$16, %rsp
	movl	$10, -16(%rbp)
	movq	$0, -8(%rbp)
	call	fork@PLT
	movl	%eax, -12(%rbp)
	cmpl	$0, -12(%rbp)
	jns	.L2
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %edi
	call	exit@PLT
.L2:
	cmpl	$0, -12(%rbp)
	jne	.L3
	leaq	.LC1(%rip), %rax
	movq	%rax, -8(%rbp)
	movl	g_val(%rip), %ecx
	movl	-16(%rbp), %edx
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %edi
	call	exit@PLT
.L3:
	leaq	.LC3(%rip), %rax
	movq	%rax, -8(%rbp)
	addl	$10, -16(%rbp)
	movl	g_val(%rip), %eax
	addl	$100, %eax
	movl	%eax, g_val(%rip)
	movl	g_val(%rip), %ecx
	movl	-16(%rbp), %edx
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	g_val(%rip), %ecx
	movl	-16(%rbp), %edx
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
