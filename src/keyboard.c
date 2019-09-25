/**
 * PLATOTERM for Atari Cartridges
 *
 * Author: Thomas Cherryhomes <thom.cherryhomes at gmail dot com>
 *
 * Keyboard functions
 */

#include <stdint.h>
#include <stdbool.h>
#include <peekpoke.h>
#include <conio.h>
#include <serial.h>
#include "keyboard.h"
#include "protocol.h"
#include "plato_key.h"
#include "key.h"
#include "io.h"
#include "touch.h"

extern padBool TTY;
#pragma zpsym("TTY")
extern void click();
extern padPt TTYLoc;
extern bool running;

static uint8_t lastkey,key;
static uint8_t tty_ch;

/**
 * keyboard_out - If platoKey < 0x7f, pass off to protocol
 * directly. Otherwise, platoKey is an access key, and the
 * ACCESS key must be sent, followed by the particular
 * access key from PTAT_ACCESS.
 */
void keyboard_out(uint8_t platoKey)
{
  if (platoKey==0xff)
    return;
  
  if (platoKey>0x7F)
    {
      Key(ACCESS);
      Key(ACCESS_KEYS[platoKey-0x80]);
      return;
    }
  Key(platoKey);
  return;
}

/**
 * keyboard_main - Handle the keyboard presses
 */
void keyboard_main(void)
{
  key=PEEK(764);
    if (PEEK(0xD01F)==5 && key != lastkey)
    {
      if (key==45)
	{
	  ShowPLATO("TTY Mode",8);
	  TTY=true;
	}
      else if (key==10)
	{
	  ShowPLATO("PLATO Mode",10);
	  TTY=false;
	}
      else if (key==12)
	{
	  keyboard_out_tty(0x0D);
	  keyboard_out_tty(0x0A);
	}
      else if (key==22)
	{
	  running=false;
	}
      else if (key==31)
	io_baud(SER_BAUD_1200);
      else if (key==30)
	io_baud(SER_BAUD_2400);
      else if (key==24)
	io_baud(SER_BAUD_4800);
      else if (key==48)
	io_baud(SER_BAUD_9600);
      else if (key==62)
	io_xoff();
      else if (key==47)
	io_xon();
      else if (key==1)
	{
	  touch_done();
	  touch_init(atrjoy_mou);
	  ShowPLATO("JOYSTICK",8);
	}
      else if (key==63)
	{
	  touch_done();
	  touch_init(atrami_mou);
	  ShowPLATO("AMIGA",5);
	}
      else if (key==23)
	{
	  touch_done();
	  touch_init(atrami_mou);
	  ShowPLATO("ST",2);
	}
      else if (key==40)
	{
	  touch_done();
	  touch_init(atrtrk_mou);
	  ShowPLATO("TRAKBALL",8);
	}
      else if (key==5)
	{
	  touch_done();
	  touch_init(atrtt_mou);
	  ShowPLATO("TABLET",6);
	}
      
      TTYLoc.y-=16;
      POKE(764,255);
    }
  else if (TTY)
    {
      if (kbhit())
	{
	  tty_ch=cgetc();
	  if (tty_ch==0x9B) // ATASCII EOL, send CR/LF
	    {
	      keyboard_out_tty(0x0D);
	    }
	  else if (tty_ch==0x7E) // ATASCII BS, send ASCII BS
	    {
	      keyboard_out_tty(0x08);
	    }
	  else
	    {
	      keyboard_out_tty(tty_ch);
	    }
	}
    }
  else if (key!=lastkey)
    {
      click();
      keyboard_out(key_to_pkey[key]);
      POKE(764,255);
    }
  lastkey=key;
}

/**
 * keyboard_out_tty - keyboard output to serial I/O in TTY mode
 */
void keyboard_out_tty(char ch)
{
  io_send_byte(ch);
}
