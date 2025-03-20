/*  Freescale sample code  */


/* here we test the thinner console print */
/* printf is too large for MC56F8006 */
#include "console.h"
#include "stdio.h"

#include "derivative.h" /* include peripheral declarations */

#include "Qcode.h"
#include "fir.h"
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
    uint16_t a, b;
    uint32_t c;
    a = 0x1000;
    b = 0x0001;
    Q115operationsTest(a,b);
    fflush_console();
	
    return(0);
}





