/**
 ******************************************************************************
 * File Name          : CONSTANTS.h
 * Author			  : Xavier Halgand
 * Date               :
 * Description        :
 ******************************************************************************
 */
#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#define SAMPLERATE              48000
#define Fs             			((float)(SAMPLERATE))	// samplerate
#define Ts						(1.f/Fs)  // sample period
#define _2PI                    6.283185307f
#define _PI                    	3.14159265f

#define BUFF_LEN_DIV4           8 // number of samples in the audiobuffer for each channel <==> XX ms latency at 48kHz, tomas, was 400. Tried all the way down to 1 and no prob. 0 was the only value that did not work (and it shoulndt work with a zero size buffer so thats good).
// When I make the buffer absurdly small like this, it takes longer for the CME to be recognized. When the buffer is one, the CME is only recognized on startup, if I remove it and replug it, it wont be recognized. maybe because the CPU is too busy calculating samples!


#define BUFF_LEN_DIV2           (2*BUFF_LEN_DIV4)
#define BUFF_LEN                (4*BUFF_LEN_DIV4)  // Audio buffer length : count in 16bits half-words
#define VOL                     70 // initial output DAC volume
#define MAXVOL                  100 // maximal output DAC volume

#define SYSTICK_FREQ			500 // system tick interruption frequency in Hz
#define DEBOUNCE_TIME			500
#define PARAM_MAX				21 // maximal parameter index, starting at 0

#define MIDI_MAX				127.f 	// floating max value
#define MIDI_MAXi				127		// integer max value

#define _CCM_					__attribute__((section(".ccm"))) //

#if defined   (__GNUC__)        /* GNU Compiler */
    #define __ALIGN    __attribute__ ((aligned (4)))

#endif /* __GNUC__ */

/************************************************************************************/
#endif  /*__CONSTANTS_H__ */
