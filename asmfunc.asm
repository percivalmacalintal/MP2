section .data
var dd 255.0

section .text
bits 64
default rel
global imgCvtGrayFloatToInt

imgCvtGrayFloatToInt:
	movss xmm0, [var]
L1:	
	movss xmm1, [rdx]
	mulss xmm1, xmm0
	cvtss2si rax, xmm1
	mov [r8], al
	add rdx, 4
	inc r8
	LOOP L1
	ret