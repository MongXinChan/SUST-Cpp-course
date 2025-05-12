	.file	"fdemo3.c"
	.option pic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0_zifencei2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.section	.rodata
	.align	3
.LC1:
	.string	"Student_id:%d\tinfo:%s\n"
	.text
	.align	1
	.globl	disp_struct
	.type	disp_struct, @function
disp_struct:
.LFB0:
	.cfi_startproc
	addi	sp,sp,-16
	.cfi_def_cfa_offset 16
	sd	ra,8(sp)
	sd	s0,0(sp)
	.cfi_offset 1, -8
	.cfi_offset 8, -16
	addi	s0,sp,16
	.cfi_def_cfa 8, 0
	mv	ra,a0
	lw	a5,0(ra)
	addi	a4,ra,4
	mv	a2,a4
	mv	a1,a5
	lla	a0,.LC1
	call	printf@plt
	nop
	ld	ra,8(sp)
	.cfi_restore 1
	ld	s0,0(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 16
	addi	sp,sp,16
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE0:
	.size	disp_struct, .-disp_struct
	.section	.rodata
	.align	3
.LC0:
	.word	3
	.string	"NAZHA"
	.zero	1018
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	addi	sp,sp,-64
	.cfi_def_cfa_offset 64
	sd	ra,56(sp)
	sd	s0,48(sp)
	.cfi_offset 1, -8
	.cfi_offset 8, -16
	addi	s0,sp,64
	.cfi_def_cfa 8, 0
	addi	sp,sp,-2032
	la	a5,__stack_chk_guard
	ld	a4, 0(a5)
	sd	a4, -24(s0)
	li	a4, 0
	lla	a4,.LC0
	addi	a5,s0,-1056
	mv	a3,a4
	li	a4,1028
	mv	a2,a4
	mv	a1,a3
	mv	a0,a5
	call	memcpy@plt
	li	a5,-4096
	addi	a5,a5,-16
	add	a5,a5,s0
	addi	a5,a5,2016
	addi	a4,s0,-1056
	li	a3,1028
	mv	a2,a3
	mv	a1,a4
	mv	a0,a5
	call	memcpy@plt
	li	a5,-4096
	addi	a5,a5,2016
	addi	a5,a5,-16
	add	a5,a5,s0
	mv	a0,a5
	call	disp_struct
	li	a5,0
	mv	a4,a5
	la	a5,__stack_chk_guard
	ld	a3, -24(s0)
	ld	a5, 0(a5)
	xor	a5, a3, a5
	li	a3, 0
	beq	a5,zero,.L4
	call	__stack_chk_fail@plt
.L4:
	mv	a0,a4
	addi	sp,sp,2032
	.cfi_def_cfa 2, 64
	ld	ra,56(sp)
	.cfi_restore 1
	ld	s0,48(sp)
	.cfi_restore 8
	addi	sp,sp,64
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
