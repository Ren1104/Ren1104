//clock.c

unsigned long TIMECLOCK = 20000000;

unsigned long get_cycles(){
	unsigned long res;
	
	__asm__ volatile(
			"rdtime %[res]"
			:[res] "=r" (res)
			:
		: "memory"
		);
	return res;
}

void clock_set_next_event(){	
	unsigned long next = get_cycles() + TIMECLOCK;
	sbi_ecall(0x0,0x0,next,0,0,0,0,0);
}
