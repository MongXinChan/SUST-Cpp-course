	.arch armv8-a
	.file	"fdemo3.c"
	.text
	.section	.rodata
	.align	3
.LC1:
	.string	"Student_id:%d\tinfo:%s\n"
	.text
	.align	2
	.global	_Z11disp_struct3Stu
	.type	_Z11disp_struct3Stu, %function
_Z11disp_struct3Stu:
.LFB0:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	x19, [sp, 16]
	.cfi_offset 19, -16
	mov	x19, x0
	ldr	w0, [x19]
	add	x1, x19, 4
	mov	x2, x1
	mov	w1, w0
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	bl	printf
	nop
	ldr	x19, [sp, 16]
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 19
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	_Z11disp_struct3Stu, .-_Z11disp_struct3Stu
	.align	2
	.global	main
	.type	main, %function
main:
.LFB1:
	.cfi_startproc
	stp	x29, x30, [sp, -16]!
	.cfi_def_cfa_offset 16
	.cfi_offset 29, -16
	.cfi_offset 30, -8
	mov	x29, sp
	sub	sp, sp, #2080
	.cfi_def_cfa_offset 2096
	str	xzr, [sp, 1024]
	adrp	x0, :got:__stack_chk_guard
	ldr	x0, [x0, :got_lo12:__stack_chk_guard]
	ldr	x1, [x0]
	str	x1, [sp, 2072]
	mov	x1, 0
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	add	x0, sp, 1040
	mov	x3, x1
	mov	x1, 1028
	mov	x2, x1
	mov	x1, x3
	bl	memcpy
	mov	x0, sp
	add	x1, sp, 1040
	mov	x2, 1028
	bl	memcpy
	mov	x0, sp
	bl	_Z11disp_struct3Stu
	mov	w0, 0
	mov	w1, w0
	adrp	x0, :got:__stack_chk_guard
	ldr	x0, [x0, :got_lo12:__stack_chk_guard]
	ldr	x3, [sp, 2072]
	ldr	x2, [x0]
	subs	x3, x3, x2
	mov	x2, 0
	beq	.L4
	bl	__stack_chk_fail
.L4:
	mov	w0, w1
	add	sp, sp, 2080
	.cfi_def_cfa_offset 16
	ldp	x29, x30, [sp], 16
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.rodata
	.align	3
.LC0:
	.word	3
	.string	"NAZHA"
	.zero	1018
	.text
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
