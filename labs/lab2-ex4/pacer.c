#include <avr/io.h>
#include "pacer.h"

#define SEC_TO_MILL 1000
#define TIMER_PRESCALE 1024  // 2^10
#define DELAY_T(DELAY) (DELAY * (F_CPU / TIMER_PRESCALE) / SEC_TO_MILL)


static uint16_t pacer_period;

/* Initialise the pacer module.  */
void pacer_init (uint16_t pacer_frequency)
{
    /* TODO: initialise timer/counter peripheral the
       same way as in lab2/lab2-ex2/timer.c but also calculate 
       the timer/counter value from the pacer frequency */
    TCCR1A = 0x00; 
    TCCR1B = 0x05; 
    TCCR1C = 0x00;

    pacer_period = DELAY_T((1 / pacer_frequency) * SEC_TO_MILL);
}


/* Pace a while loop.  */
void pacer_wait (void)
{
    /* TODO: Implement the same way as the timer_delay () function 
       lab2-except reset TCNT1 after the while loop. */
    while (TCNT1 < pacer_period) continue;
    TCNT1 = 0;
}
