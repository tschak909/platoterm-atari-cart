/**
 * Font definitions for font memories M0 and M1
 */

#ifndef FONT_H
#define FONT_H

#include <stdint.h>

// Thanks to Nick Shcherbyna for a table saver!
#define FONTPTR(a) (((i << 1) + i) << 1)

uint8_t FONT_SIZE_X=5;
uint8_t FONT_SIZE_Y=6;

uint8_t font[]={
  0x00,0x00,0x00,0x00,0x00,0x00,    /* SPACE 0x20 */
  0x40,0x40,0x40,0x00,0x40,0x00,    /* ! 0x21 */
  0xA0,0xA0,0x00,0x00,0x00,0x00,    /* " 0x22 */
  0x50,0xF8,0x50,0xF8,0x50,0x00,   /* # 0x23 */
  0x20,0x70,0xC0,0x30,0xE0,0x40,    /* $ 0x24 */
  0x90,0x30,0x60,0xC0,0x90,0x00,    /* % 0x25 */
  0x20,0x50,0x60,0x90,0x68,0x00,   /* & 0x26 */
  0x40,0x40,0x00,0x00,0x00,0x00,    /* ' 0x27 */
  0x20,0x40,0x40,0x40,0x40,0x20,    /* ( 0x28 */
  0x40,0x20,0x20,0x20,0x20,0x40,    /* ) 0x29 */
  0x50,0x60,0xF0,0x60,0xA0,0x00,    /* * 0x2a */
  0x00,0x00,0x20,0x70,0x20,0x00,    /* + 0x2b */  
  0x00,0x00,0x00,0x20,0x20,0x40,    /* , 0x2c */
  0x00,0x00,0xE0,0x00,0x00,0x00,    /* - 0x2d */
  0x00,0x00,0x00,0x00,0x40,0x00,    /* . 0x2e */
  0x10,0x30,0x60,0xC0,0x80,0x00,    /* / 0x2f */
  0x70,0x90,0x90,0x90,0xE0,0x00,    /* 0 0x30 */
  0x20,0x60,0x20,0x20,0x70,0x00,    /* 1 0x31 */
  0x60,0x90,0x20,0x40,0xF0,0x00,    /* 2 0x32 */
  0xE0,0x10,0x60,0x10,0xE0,0x00,    /* 3 0x33 */
  0x20,0x60,0xA0,0xF0,0x20,0x00,    /* 4 0x34 */
  0xF0,0x80,0xE0,0x10,0xE0,0x00,    /* 5 0x35 */
  0x60,0x80,0xE0,0x90,0x60,0x00,    /* 6 0x36 */
  0xF0,0x10,0x20,0x40,0x40,0x00,    /* 7 0x37 */
  0x60,0x90,0x60,0x90,0x60,0x00,    /* 8 0x38 */
  0x60,0x90,0x70,0x10,0x60,0x00,    /* 9 0x39 */
  0x00,0x00,0x40,0x00,0x40,0x00,    /* : 0x3a */
  0x00,0x20,0x00,0x00,0x20,0x40,    /* ; 0x3b */
  0x10,0x20,0x40,0x20,0x10,0x00,    /* < 0x3c */
  0x00,0xF0,0x00,0xF0,0x00,0x00,    /* = 0x3d */
  0x80,0x40,0x20,0x40,0x80,0x00,    /* > 0x3e */
  0xE0,0x10,0x60,0x00,0x40,0x00,    /* ? 0x3f */  
  0x60,0x90,0xB0,0xB0,0x80,0x60,   /* @ 0x40 */
  0x60,0x90,0xF0,0x90,0x90,0x00,   /* A 0x41 */
  0xE0,0x90,0xE0,0x90,0xE0,0x00,   /* B 0x42 */
  0x70,0x80,0x80,0x80,0x70,0x00,   /* C 0x43 */
  0xE0,0x90,0x90,0x90,0xE0,0x00,   /* D 0x44 */
  0xF0,0x80,0xE0,0x80,0xF0,0x00,   /* E 0x45 */
  0xF0,0x80,0xE0,0x80,0x80,0x00,   /* F 0x46 */
  0x60,0x80,0xB0,0x90,0x60,0x00,   /* G 0x47 */
  0x90,0x90,0xF0,0x90,0x90,0x00,   /* H 0x48 */
  0x70,0x20,0x20,0x20,0x70,0x00,   /* I 0x49 */
  0x30,0x10,0x10,0x10,0xE0,0x00,   /* J 0x4a */
  0x90,0xA0,0xC0,0xA0,0x90,0x00,   /* K 0x4b */
  0x80,0x80,0x80,0x80,0xF0,0x00,   /* L 0x4c */
  0x90,0xF0,0xD0,0x90,0x90,0x00,   /* M 0x4d */
  0x90,0xD0,0xB0,0x90,0x90,0x00,   /* N 0x4e */
  0x60,0x90,0x90,0x90,0x60,0x00,   /* O 0x4f */
  0xE0,0x90,0x90,0xE0,0x80,0x00,   /* P 0x50 */
  0x60,0x90,0x90,0x90,0x60,0x30,   /* Q 0x51 */
  0xE0,0x90,0x90,0xE0,0x90,0x00,   /* R 0x52 */
  0x70,0x80,0x60,0x10,0xE0,0x00,   /* S 0x53 */
  0x70,0x20,0x20,0x20,0x20,0x00,   /* T 0x54 */
  0x90,0x90,0x90,0x90,0x60,0x00,   /* U 0x55 */
  0x90,0x90,0x90,0xA0,0x40,0x00,   /* V 0x56 */
  0x90,0x90,0xD0,0xF0,0x90,0x00,   /* W 0x57 */
  0x90,0x90,0x60,0x90,0x90,0x00,   /* X 0x58 */
  0x90,0x90,0x70,0x20,0x40,0x00,   /* Y 0x59 */
  0xF0,0x20,0x40,0x80,0xF0,0x00,   /* Z 0x5a */
  0x70,0x40,0x40,0x40,0x40,0x70,    /* [ 0x5b */
  0x80,0xC0,0x60,0x30,0x10,0x00,   /* \ 0x5c */ 
  0xE0,0x20,0x20,0x20,0x20,0xE0,    /* ] 0x5d */
  0x40,0xA0,0x00,0x00,0x00,0x00,   /* CIRCUMFLEX ^ 0x5e*/
  0x00,0x00,0x00,0x00,0xF0,0x00,    /* _ 0x5f */
  0x80,0x40,0x00,0x00,0x00,0x00,   /* GRAVE ACCENT ` 0x60 */
  0x00,0x70,0x90,0x90,0X70,0x00,    /* a 0x61 */
  0x80,0xE0,0x90,0x90,0xE0,0x00,    /* b 0x62 */
  0x00,0x70,0x80,0x80,0x70,0x00,    /* c 0x63 */
  0x10,0x70,0x90,0x90,0x70,0x00,    /* d 0x64 */
  0x00,0x70,0xA0,0xC0,0x70,0x00,    /* e 0x65 */
  0x30,0x40,0xF0,0x40,0x40,0x00,    /* f 0x66 */
  0x00,0x70,0x90,0x70,0x10,0x60,    /* g 0x67 */
  0x80,0xE0,0x90,0x90,0x90,0x00,    /* h 0x68 */
  0x20,0x00,0x60,0x20,0x20,0x00,    /* i 0x69 */
  0x10,0x00,0x30,0x10,0x10,0xE0,    /* j 0x6a */
  0x80,0xA0,0xC0,0xA0,0x90,0x00,    /* k 0x6b */
  0x60,0x20,0x20,0x20,0x70,0x00,    /* l 0x6c */
  0x00,0x90,0xF0,0x90,0x90,0x00,    /* m 0x6d */
  0x00,0xE0,0x90,0x90,0x90,0x00,    /* n 0x6e */
  0x00,0x60,0x90,0x90,0x60,0x00,    /* o 0x6f */
  0x00,0xE0,0x90,0x90,0xE0,0x80,    /* p 0x70 */
  0x00,0x70,0x90,0x90,0x70,0x10,    /* q 0x71 */
  0x00,0xE0,0x90,0x80,0x80,0x00,    /* r 0x72 */
  0x00,0x70,0xC0,0x30,0xE0,0x00,    /* s 0x73 */
  0x40,0xF0,0x40,0x40,0x30,0x00,    /* t 0x74 */
  0x00,0x90,0x90,0x90,0x70,0x00,    /* u 0x75 */
  0x00,0x90,0x90,0xA0,0x40,0x00,    /* v 0x76 */
  0x00,0x90,0x90,0xF0,0x90,0x00,    /* w 0x77 */
  0x00,0x90,0x60,0x60,0x90,0x00,    /* x 0x78 */
  0x00,0x90,0x90,0x70,0x20,0x40,    /* y 0x79 */
  0x00,0xF0,0x20,0x40,0xF0,0x00,    /* z 0x7a */
  0x30,0x20,0x40,0x40,0x20,0x30,   /* { 0x7b */
  0x40,0x40,0x40,0x40,0x40,0x40,   /* | 0x7c */
  0xC0,0x40,0x20,0x20,0x40,0xC0,   /* } 0x7d */
  0x68,0xB0,0x00,0x00,0x00,0x00,   /* ~ 0x7e */
  0x00,0x70,0x50,0x70,0x00,0x00,   /* BOX 0x7f */
  0x00,0x00,0x00,0x00,0x00,0x00,   /* SPACE 0xa0 */
  0x00,0x10,0x20,0x40,0x80,0x00,   /* / 0xa1 */
  0x00,0xF0,0x00,0xF0,0x00,0xF0,   /* EQUIVALENT 0xa2 */
  0x00,0x00,0x00,0x00,0x68,0xB0,   /* LOW TILDE 0xa3 */
  0x20,0x70,0x80,0x70,0x20,0x00,   /* ASSIGN 0xa4 */
  0x20,0xF0,0x20,0xF0,0x40,0x00,   /* NOT EQUAL 0xa5 */
  0x00,0x20,0x70,0x20,0x20,0x00,   /* UP ARROW 0xa6 */
  0x00,0x00,0x20,0xF0,0x20,0x00,   /* RIGHT ARROW 0xa7 */
  0x00,0x20,0x20,0x70,0x20,0x00,   /* DOWN ARROW 0xa8 */
  0x00,0x00,0x40,0xF0,0x40,0x00,   /* LEFT ARROW 0xa9 */
  0x00,0x50,0x20,0x50,0x00,0x00,   /* MULTIPLY 0xaa */
  0xF0,0x80,0x60,0x80,0xF0,0x00,   /* SIGMA 0xab */
  0x00,0x20,0x50,0x88,0xF8,0x00,   /* DELTA 0xac*/
  0x00,0x90,0x90,0x60,0x00,0x00,   /* UNION 0xad*/
  0x00,0x60,0x90,0x90,0x00,0x00,   /* INTERSECT 0xae */
  0x00,0x60,0x00,0x60,0x00,0x00,   /* DIVIDE 0xaf */
  0x00,0x50,0xA0,0x70,0x00,0x00,   /* ALPHA 0xb0 */
  0x20,0x50,0xA0,0x90,0xE0,0x80,   /* BETA 0xb1 */
  0x20,0x40,0x20,0x50,0x70,0x00,   /* DELTA 0xb2 */
  0x80,0x40,0x20,0x50,0x90,0x00,   /* LAMBDA 0xb3 */
  0x00,0x00,0x50,0x50,0x60,0x80,   /* MU 0xb4 */
  0x08,0x78,0xD0,0x50,0x50,0x00,   /* PI 0xb5 */
  0x00,0x20,0x50,0x50,0xA0,0x80,   /* RHO 0xb6 */
  0x30,0x40,0xA0,0xA0,0x40,0x00,   /* SIGMA 0xb7 */
  0x00,0x00,0x90,0xB0,0x60,0x00,   /* OMEGA 0xb8 */
  0x20,0x40,0x80,0x40,0x20,0xE0,   /* LESS THAN OR EQUAL 0xb9 */
  0x80,0x40,0x20,0x40,0x80,0xE0,   /* GREATER THAN OR EQUAL 0xba */
  0x20,0x50,0x70,0x50,0x20,0x00,   /* THETA 0xbb */
  0x30,0x60,0xA0,0x60,0x30,0x00,   /* l-embed 0xbc */
  0x00,0x60,0x90,0x60,0x00,0x00,   /* DEGREE 0xbd */
  0xC0,0x60,0x50,0x60,0xC0,0x00,   /* r-embed 0xbe */
  0xC0,0xA0,0x50,0x50,0xA0,0xC0,    /* ANSWER ARROW 0xbf */
  0xF8,0x20,0x40,0x40,0x20,0xF8,   /* COPYRIGHT 0xc0 */
  0x50,0x00,0x00,0x00,0x00,0x00,   /* DIERESIS 0xc1 */
  0x00,0x70,0x50,0x70,0x00,0x00,   /* BOX 0xc2 */
  0x00,0x00,0x20,0x00,0x00,0x00,   /* INTERPUNCT 0xc3 */
  0x20,0x70,0xF8,0x70,0x20,0x00,   /* DIAMOND 0xc4 */
  0x00,0x50,0x20,0x50,0x00,0x00,   /* MULTIPLY 0xc5 */
  0x10,0x20,0x00,0x00,0x00,0x00,   /* ACUTE ACCENT 0xc6 */
  0x00,0x00,0x00,0x08,0x10,0x00,   /* CEDILLA 0xc7 */
  0x10,0x20,0x00,0x00,0x00,0x00,   /* HACEK 0xc8 */
  0x20,0x70,0xF8,0x70,0x20,0x00,   /* DIAMOND 0xc9 */
  0x20,0x20,0x20,0x20,0x20,0x20,   /* | 0xca */
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00
};

uint8_t fontm23[768];

#endif
