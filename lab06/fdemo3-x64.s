	.file	"fdemo3.c"
	.text
	.section	.rodata
.LC1:
	.string	"Student_id:%d\tinfo:%s\n"
	.text
	.globl	_Z11disp_struct3Stu
	.type	_Z11disp_struct3Stu, @function
_Z11disp_struct3Stu:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	16(%rbp), %eax
	leaq	20(%rbp), %rdx
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_Z11disp_struct3Stu, .-_Z11disp_struct3Stu
	.section	.rodata
	.align 32
.LC0:
	.long	3
	.string	"NAZHA"
	.zero	1018
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1040, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-1040(%rbp), %rax
	leaq	.LC0(%rip), %rdx
	movl	$128, %ecx
	movq	%rax, %rdi
	movq	%rdx, %rsi
	rep movsq
	movq	%rsi, %rdx
	movq	%rdi, %rax
	movl	(%rdx), %ecx
	movl	%ecx, (%rax)
	subq	$8, %rsp
	subq	$1032, %rsp
	movq	%rsp, %rax
	movq	%rax, %rdx
	leaq	-1040(%rbp), %rax
	movl	$128, %ecx
	movq	%rdx, %rdi
	movq	%rax, %rsi
	rep movsq
	movq	%rsi, %rax
	movq	%rdi, %rdx
	movl	(%rax), %ecx
	movl	%ecx, (%rdx)
	call	_Z11disp_struct3Stu
	addq	$1040, %rsp
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L4
	call	__stack_chk_fail@PLT
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
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
