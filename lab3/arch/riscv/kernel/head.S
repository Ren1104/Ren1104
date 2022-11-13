.extern start_kernel
.extern _traps
    .section .text.init
    .globl _start
_start:
#-----------------------
# set stvec = _traps
	la t0, _traps
	csrw stvec, t0
#------------------------
# set sie[STIE] = 1
	addi t0, zero, 32
	csrw sie, t0
#-------------------------
# set first time interrupt
	rdtime a0
	li t0,20000000
	mv a7,x0
	mv a6,x0
	add a0,a0,t0
	mv a1,x0
	mv a2,x0
	mv a3,x0
	mv a4,x0
	mv a5,x0
	ecall
#-------------------------
# set sstatus[SIE] = 1
	csrsi sstatus, 2
	
	la sp, boot_stack_top
	call mm_init
	call task_init
	j start_kernel
	
    .section .bss.stack
    .globl boot_stack
boot_stack:
    .space 4096 # <-- change to your stack size

    .globl boot_stack_top
boot_stack_top:
