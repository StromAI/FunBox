	.file	"code_3_1.c"
	.intel_syntax noprefix
	.text
	.p2align 4,,15
	.globl	b
	.type	b, @function
b:
.LFB0:
	.cfi_startproc
	mov	eax, 1
	ret
	.cfi_endproc
.LFE0:
	.size	b, .-b
	.p2align 4,,15
	.globl	test
	.type	test, @function
test:
.LFB1:
	.cfi_startproc
	xor	eax, eax
	ret
	.cfi_endproc
.LFE1:
	.size	test, .-test
	.ident	"GCC: (GNU) 4.8.3 20140911 (Red Hat 4.8.3-7)"
	.section	.note.GNU-stack,"",@progbits
