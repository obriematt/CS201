	.file	"homework4.c"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC1:
	.string	"The total number of calls is %d.\n"
	.align 8
.LC3:
	.string	"The time taken is %f seconds.\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB27:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movl	$2, %ebx
	subq	$16, %rsp
	.cfi_def_cfa_offset 48
	.p2align 4,,10
	.p2align 3
.L3:
	cvtsi2sd	%ebx, %xmm1
	addl	$1, %ebx
	movsd	.LC0(%rip), %xmm0
	call	pow
	movsd	%xmm0, 8(%rsp)
	call	clock
	movq	%rax, %rbp
	call	clock
	movsd	8(%rsp), %xmm0
	movq	%rax, %r12
	movl	$.LC1, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	cvttsd2si	%xmm0, %edx
	subq	%rbp, %r12
	call	__printf_chk
	cvtsi2ssq	%r12, %xmm0
	movl	$.LC3, %esi
	movl	$1, %edi
	cvttss2siq	%xmm0, %rax
	cvtsi2ssq	%rax, %xmm0
	movl	$1, %eax
	divss	.LC2(%rip), %xmm0
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm0
	call	__printf_chk
	cmpl	$11, %ebx
	jne	.L3
	addq	$16, %rsp
	.cfi_def_cfa_offset 32
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE27:
	.size	main, .-main
	.text
	.p2align 4,,15
	.globl	track_cycles
	.type	track_cycles, @function
track_cycles:
.LFB28:
	.cfi_startproc
	rep ret
	.cfi_endproc
.LFE28:
	.size	track_cycles, .-track_cycles
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1075052544
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC2:
	.long	1232348160
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
