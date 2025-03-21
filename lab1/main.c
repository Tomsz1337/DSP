/*  Freescale sample code  */


/* here we test the thinner console print */
/* printf is too large for MC56F8006 */
#include "console.h"
#include "stdio.h"

#include "derivative.h" /* include peripheral declarations */
#include "qCode.h"
#include "iir.h"
/* this macro attempt to enable watchdog module */
#if	defined (COP_CTRL)
	#define EnableWatchdog \
		COP_CTRL |= (0x2);
#elif defined ( COPCTL )
	#define EnableWatchdog \
		COPCTL |= (0x2);
#else
	#define EnableWatchdog	\
	__ConsoleWrite(0, " no watchdog enable procedure\n", 29);
#endif // #define EnableWatchdog

/* this macro attempt to disable watchdog module */
#if	defined (COP_CTRL)
	#define DisableWatchdog \
		COP_CTRL &= ~(0x2);
#elif defined ( COPCTL )
	#define DisableWatchdog \
		COPCTL &= ~(0x2);
#else
	#define DisableWatchdog	\
	__ConsoleWrite(0, " no watchdog disable procedure\n", 30);
#endif // #define DisableWatchdog


int main(void)
{ 
	/*
    uint16_t a,b;
    a = 0x0201;
    b = 0x2104;
    
    printf("a = %X\n", a);
    printf("b = %X\n", b);
    printf("Q115add = %lX\n", Q115add(a,b));
    printf("Q115sub = %lX\n", Q115sub(a,b));
    printf("Q115mul = %lX\n", Q115mul(a,b));
    printf("Q115div = %lX\n", Q115div(a,b));
    */
	
	int32_t result = 0;
	int i;
	float data[16] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	
	
	IIR_Init();
	for(i = 0; i<3; i++)
	{
		result = IIR_filter_TOP(data[i]);
		printf("IIR response: %ld\n\r", result);
	}
	
	
    fflush_console();
	
    return(0);
}











