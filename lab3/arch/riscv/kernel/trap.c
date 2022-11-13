//trap.c
#include "printk.h"
#include "clock.h"
#include "../include/proc.h"
void trap_handler(unsigned long scause, unsigned long sepc){
	int Trap_Flag = 0;
	if(scause >> 63 == 1){
		Trap_Flag = 1; //interrupt
	}
	if(Trap_Flag == 1){
		int ExCode = scause & 0b111;
		if(ExCode == 4){
			do_timer();
			clock_set_next_event();
		}else if (ExCode == 5){
			do_timer();
			clock_set_next_event();
		}
	}
}
