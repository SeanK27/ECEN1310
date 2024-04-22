	.file	"hello.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Welcome to ECEN 1310! Have you learned or experimented with C programming before? (y/n):"
.LC1:
	.string	"%c"
	.align 8
.LC2:
	.string	"That's awesome! But there is always so much more to learn!"
	.align 8
.LC3:
	.string	"No worries! This course will introduce you to the wonderful world of C and by the end of the course you will be a pro programmer!"
	.align 8
.LC4:
	.string	"Error! You must type in either y or n."
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-9(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movzbl	-9(%rbp), %eax
	cmpb	$121, %al
	jne	.L2
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L3
.L2:
	movzbl	-9(%rbp), %eax
	cmpb	$110, %al
	jne	.L4
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L3
.L4:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L3:
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L6
	call	__stack_chk_fail@PLT
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
