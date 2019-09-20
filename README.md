PLATOTERM Lite Version 1.3
==========================

About this test release
-----------------------

The Entire code-base has been brought up by starting from a skeleton implementation of PLATOTERM, and folding in precisely only the required functionality, testing each touch driver to make sure that it fits correctly within the 16K ROM address space.

The Serial driver has also had its input buffer drastically increased (to 2048 bytes), which should allow testing of higher speeds. There still is much work to be done, hopefully Mr. Atari's SIO changes can be folded in.

Baud rate selection is now possible by pressing SELECT-1, 2, 4, or 9 for 1200, 2400, 4800, or 9600 baud respectively.

Also to be done, are various initialization tasks (such as ensuring that page 6 isn't blown away, at Mr. Atari's request.)

About The Atari Lite Release
----------------------------

This is a special version of PLATOTERM, that has been re-organized to fit the code within approximately 16K of space, so that it can be fit onto a cartridge,

In order to do this, preferences was eliminated completely, and 1200 baud is the only data rate supported. But the upside is, you can flash this onto a cartridge.

Like the larger version, PLATOTERM requires a loaded R: handler. The cartridges are configured to load the DOS first, before jumping into the main program, so any handlers you wish to run, you should be sure they are loaded first (e.g with AUTORUN.SYS).

Since devices like the Atari 850 can autoboot their handler if no disk drive is present, they will also work with the cartridge version. Just be sure that the 850 interface is switched on, before poweron.

R-Verter users must ensure their handler is loaded, before starting PLATOTERM.

The only available hotkeys are:

* SELECT-T to switch to TTY mode.
* SELECT-P to switch to PLATO mode.
* SELECT-X will exit the cartridge to DOS.
* SELECT-RETURN to send a carriage return and a line feed.
* SELECT-1 to switch to 1200 baud.
* SELECT-2 to switch to 2400 baud.
* SELECT-4 to switch to 4800 baud.
* SELECT-9 to switch to 9600 baud.

Versions available:
-------------------

There are file and cartridge versions available for the following touch devices:

* Atari Joystick
* Atari CX77 Touch Tablet
* Atari CX80 Trak-Ball
* Atari ST Mouse
* Amiga Mouse

in addition, a ROM without any pointer device driver is also available.

What is PLATOTERM?
------------------

PLATOTERM is a terminal emulator to access CYBIS services now available
on the Internet utilizing a WIFI Modem.

For the purposes of this documentation. PLATO and CYBIS are interchangeable
names for the same platform.

What services are currently available to access via PLATOTERM?
--------------------------------------------------------------

As of writing this preliminary documentation (September 2019), there are
two major CYBIS systems running. CYBER1.ORG and IRATA.ONLINE.

WHAT IS PLATO? (aka CYBIS?)
---------------------------
(from the PLATO wikipedia page:)

PLATO (Programmed Logic for Automatic Teaching Operations), was the first
generalized computer-asisted instruction system. Starting in 1960, it ran
on the University of Illinois ILLIAC I computer. By the late 1970s, it
supported several thousand graphics terminals distributed worldwide, running
on nearly a dozen different networked mainframe computers. Many modern
concepts in multi-user computing were originally developed on PLATO, including
forums, message boards, online testing, e-mail, chat rooms, picture languages,
instant messaging, remote screen sharing, and multi-player games.

What is CYBER1.ORG?
-------------------

CYBER1.ORG is a CYBIS system initially set up in 2004, as a haven for
ex-PLATO users to experience a classic PLATO author experience.

CYBER1.ORG is home to many thousands of classic PLATO lessons and
notesfiles which have been restored from various sources, and have
been made available in the interests of preserving PLATO.

What is IRATA.ONLINE?
---------------------

IRATA.ONLINE is a CYBIS system that has been set up for the benefit of
the greater vintage computing community, in the interest to provide
a unique experience that can be accessed on a wide variety of
vintage computers with a bitmapped graphics display. To this end,
IRATA.ONLINE develops PLATOTERM for dozens of platforms, so that they
can access CYBIS systems, as well as provide a community and learning
infrastructure for vintage computing users of all types, in the hopes
that as a cohesive community, something unique can hopefully
emerge.

What is the connection between IRATA.ONLINE and CYBER1.ORG?
-----------------------------------------------------------

CYBER1.ORG and IRATA.ONLINE are independent of one another. With that said,
the reason IRATA.ONLINE and PLATOTERM exist, are because of the efforts of
CYBER1.ORG to not only preserve a running PLATO system, and provide the
necessary information for interested parties to write terminal software
to access CYBIS systems, but also in their effort to produce a publically
available distribution of CYBIS that others who are interested may also
run their own CYBIS installation. IRATA.ONLINE is a direct result of the
public release of this distribution.

--------------------------
Connecting to IRATA.ONLINE
--------------------------

Once PLATOTERM is started, you can connect to CYBER1.ORG using your WIFI modem,
using a command such as:

```
ATDTIRATA.ONLINE:8005
```

------------------------
Connecting to CYBER1.ORG
------------------------

Once PLATOTERM is started, you can connect to CYBER1.ORG using your WIFI modem,
using a command such as:

```
ATDTCYBERSERV.ORG:8005
```

PLATO Keyboard
-------------------
The PLATO keyboard is mapped to the Atari keys, like so:

| PLATO KEY  	| Atari Key  	|
|---	|---	|
| ANS  	| CTRL-A  	|
| BACK  	| CTRL-B  	|
| SHIFT-BACK | CTRL- + (left arrow) |
| COPY | CTRL-C |
| SHIFT-COPY | CTRL- - (up arrow)  |
| DATA | CTRL-D ||
| SHIFT-DATA | SHIFT-CTRL-D |
| EDIT | CTRL-E |
| SHIFT-EDIT | SHIFT-CTRL-E |
| FONT | CTRL-F |
| &#247; | CTRL-G | 
| HELP | CTRL-I |
| SHIFT-HELP | SHIFT CTRL-H |
| LAB | CTRL-L |
| SHIFT-LAB | CTRL-= (down arrow) |
| SUPER | CTRL-P |
| SHIFT-SUPER | SHIFT CTRL-P |
| SQUARE | CTRL-Q | 
| ACCESS | SHIFT CTRL-Q |
| STOP | CTRL-S |
| SHIFT-STOP | SHIFT CTRL-S | 
| TERM | CTRL-T |
| &#215; | CTRL-X |
| SUB | CTRL-Y |
| SHIFT-SUB | SHIFT CTRL-Y |
| &#8656;   | ESC |
| CR and LF | Select RETURN |

MICRO Symbols
-------------

| PLATO KEY  | MICRO Key  |
|---         |---
|&alpha;    | A |
|&beta;     | B |
|&cedil;    | C |
|&delta;    | D |
|&aelig;    | G |
|&oslash;   | H |
|&aring;    | J |
|&auml;     | K |
|&lambda;   | L |
|&mu;       | M |
|&126;      | N |
|&deg;      | O |
|&pi;       | P |
|&DiacriticalGrave;| Q |
|&rho;      | R |
|&sigma;    | S |
|&Theta;    | T |
|&uml;      | U |
|&Hacek;    | V |
|&omega;    | W |
|&#8248;    | X |
|&ouml;     | Y |
|l-embed    | 0 |
|r-embed    | 1 |
|&#759;     | : |
|&updownarrow; | , |
|&ne;       | = |
|&ShortLeftArrow; | SHIFT A |
|&ShortDownArrow; | SHIFT X |
|&ShortRightArrow; | SHIFT D |
|&ShortUpArrow; | SHIFT W |
|&copy; | SHIFT C |
|&#11049; | SHIFT F |
|&Aelig;  | SHIFT G |
|&Oslash; | SHIFT H |
|&Aring;  | SHIFT J |
|&Auml;   | SHIFT K |
|&squ;    | SHIFT O |
|&Ouml;   | SHIFT Y |
|≤        | SHIFT < |
|≥        | SHIFT > |
|{        | SHIFT [ |
|}        | SHIFT ] |
|&#10761; | CTRL X  |
|≡        | SHIFT ) |
|Arrow    | 6       |

Credits
=======
* '''Thomas Cherryhomes''' - Terminal coding, sleepless nights.
* '''Steve Peltz''' - original PAD protocol decoder from MacPAD.
* '''Christian Groessler''' - multiply funcs for Atari, lots of testing
* '''Jon Halliday''' - Fast text output routines for Atari
* '''Ron Klein''' - Testing, testing, and more testing
' '''Sijmen Schouten''' - FAST I/O and R-Verter support! Testing, testing, and more testing.
* '''Michael Sternberg''' - Apple2 testing, showing off at Kansasfest 2018
* '''The.Doctor''' - Help tuning XON/XOFF parameters.
* '''John Buell''' - Testing
* '''John Manterola''' - Testing
* '''Jasmaz''' - Commodore 64 testing
* '''Paul Rickards''' - Commodore 64 testing
* '''Glenn Wiorek''' - Commodore 64 testing.
* '''Rory McMahon''' - Testing
