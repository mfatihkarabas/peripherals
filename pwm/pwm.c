/* File: pwm.
 * Author: mfatihkarabas
 *
 * Precisions:
 *    Frequency: 1 Hz
 *    Duty:      % 1
 *
 * Limits:
 *    Frequency: 0 Hz - 4.295 GHz
 *    Duty:      % 0  - % 100
 */

/* Abbreviations
 * mfr: manufacturer
 * pct: percentage
 */


/* Manufacturer Confs. */
#define MFR_LIB xxx.h

#include <stdbool.h>
#include "MFR_LIB"

enum PwmEvents {

    SET_FREQ_CALLED= 0,
    GET_FREQ_CALLED,
    SET_DUTY_CALLED,
    GET_DUTY_CALLED,
    GET_PERIOD_CALLED,
    NB_OF_PWM_EVENTS
};
    
struct pwm {
    
    uint32_t freq_hz,
    uint8_t  duty_pct,
    PwmEvents latest_event,
    struct systick event_tick
};

/* BEGIN Create Objects */


/* END Create Objects */

uint32_t freq_hz (struct pwm p)
{
    p->event_tick = systick();
    p->event = GET_FREQ_CALLED;
    return (p->freq_hz);
}

uint32_t period_ms (struct pwm p)
{
    p->event_tick = systick();
    p->event = GET_PERIOD_CALLED;
    return (1/p->freq_hz);
}

uint8_t duty_pct (struct pwm p)
{
    p->event_tick = systick();
    p->event = GET_DUTY_CALLED;
    return (p->duty_pct);
}
