/**
 * PLATOTERM for Atari Cartridges
 *
 * Author: Thomas Cherryhomes <thom.cherryhomes at gmail dot com>
 *
 * I/O Functions
 */

#include <serial.h>
#include <stdbool.h>
#include <atari.h>
#include "io.h"
#include "protocol.h"

extern bool running;

static struct ser_params params = {
  SER_BAUD_1200,
  SER_BITS_8,
  SER_STOP_1,
  SER_PAR_NONE,
  SER_HS_HW
};

static uint8_t ch=0;
static uint8_t io_res;
static uint8_t recv_buffer[2048];
static uint16_t recv_buffer_size=0;

extern padPt TTYLoc;

extern unsigned char io_handler_load();

uint8_t xoff_enabled=false;


/**
 * io_init() - Set-up the I/O
 */
void io_init(void)
{
  io_handler_load();
  io_res=ser_install(atrrdev_ser);
  if (io_res!=SER_ERR_OK)
    {
      running=false;
      return;
    }
  
  io_baud(SER_BAUD_1200);
}

/**
 * io_send_byte(b) - Send specified byte out
 */
void io_send_byte(uint8_t b)
{
  ser_put(b);    
}

/**
 * io_main() - The IO main loop
 */
void io_main(void)
{
  // Drain primary serial FIFO as fast as possible.
  while ((ser_get(&ch)!=SER_ERR_NO_DATA) && (recv_buffer_size<2048))
    {
      recv_buffer[recv_buffer_size++]=ch;
      if ((recv_buffer_size>96) && (xoff_enabled==false))
	io_xoff();
    }

  if (recv_buffer_size>0)
    {
      ShowPLATO((padByte *)recv_buffer,recv_buffer_size);
      if (xoff_enabled==true)
	io_xon();
      recv_buffer_size=0;
    }
  
}

/**
 * io_done() - Called to close I/O
 */
void io_done(void)
{
  ser_close();
  ser_uninstall();
}

/**
 * io_baud - set baud rate
 */
void io_baud(unsigned char new_baud)
{
  ser_close();

  TTYLoc.x=0;
  
  switch(new_baud)
    {
    case SER_BAUD_1200:
      ShowPLATO("1200",4);
      params.baudrate=SER_BAUD_1200;
      break;
    case SER_BAUD_2400:
      ShowPLATO("2400",4);
      params.baudrate=SER_BAUD_2400;
      break;
    case SER_BAUD_4800:
      ShowPLATO("4800",4);
      params.baudrate=SER_BAUD_4800;
      break;
    case SER_BAUD_9600:
      ShowPLATO("9600",4);
      params.baudrate=SER_BAUD_9600;
      break;
    }

  ShowPLATO(" baud",5);
  
  TTYLoc.x=0;
  TTYLoc.y-=16;
  
  ser_open(&params);
  
}

/**
 * io_xon - send XON
 */
void io_xon(void)
{
  io_send_byte(XON);
  xoff_enabled=false;
}

/**
 * io_xoff - send XON
 */
void io_xoff(void)
{
  io_send_byte(XOFF);
  xoff_enabled=true;
}
