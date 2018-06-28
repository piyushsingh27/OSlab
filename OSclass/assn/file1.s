	.file	"file1.c"
	.text
	.comm	external,4,4
	.globl	fglobal
	.data
	.align 4
	.type	fglobal, @object
	.size	fglobal, 4
fglobal:
	.long	10
	.comm	internal,4,4
	.globl	ninternal
	.bss
	.align 4
	.type	ninternal, @object
	.size	ninternal, 4
ninternal:
	.zero	4
	.local	variable
	.comm	variable,4,4
	.local	svariable
	.comm	svariable,4,4
	.data
	.align 4
	.type	ivariable, @object
	.size	ivariable, 4
ivariable:
	.long	10
	.section	.rodata
.LC0:
	.string	"External variable : %d"
.LC1:
	.string	"\nInternal variable : %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	external(%rip), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	internal(%rip), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	call	function@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
.LC2:
	.string	"Global variable : %d"
	.align 8
.LC3:
	.string	"Static global(to the file) = %d"
	.text
	.globl	scope_function
	.type	scope_function, @function
scope_function:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	external(%rip), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	variable(%rip), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	scope_function, .-scope_function
	.data
	.align 4
	.type	slocal.2260, @object
	.size	slocal.2260, 4
slocal.2260:
	.long	50
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
