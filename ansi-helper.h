/* 
this is a utility I made because I was making something with heavy use of ansi escape codes
it is purely preprocesser directives, and allows easy writing of ansi codes for all common and some uncommon ansi codes
there is also a ansi cheet sheet right below this 

todo (never probably): 256 bit ansi codes

usage guide:

to set a text property (blold, faint, underline, blink, inverse, strike through [and potentially overline?]) use 
SANSI(property) so SANSI(FAINT) = "\e[2m" which sets future characters to be faint.

to set a full ansi code use ANSI(property,color) so ANSI(TNORMAL,TBLACK) "\e[0;30m" or ANSI(0,30) for the same result. the name schema is : T+COLOR (text color) B+COLOR (like BYELLOW, background). you can also have high intensity colors in most terminals with B/T + HI + COLOR (BHIYELLOW for high intensity background yellow);

colors  are : BLACK,RED,GREEN,YELLOW,BLUE,PURPLE,CYAN,WHITE

properties are what they are (BOLD) unset is U+PROPERTY (UBOLD) and high intensity to normal is BRIGHTNORMAL

(tnormal is no property, NULL also works,they are both 0)
properties are: TNORMAL BOLD FAINT ITALIC UNDERLINE BLINK INVERSE CROSSOUT/STRIKETHROUGH OVERLINE

special important codes get their own name 
reset all : ARESET (ansi reset)
clear : ACLEAR / ACLR (ansi clear etc)
u/d/l/r : AUP, ADOWN etc (move cursor)

to make text / bg use 256 color pallet  ANSI_256(T/B)(palletteNumber) so ANSI_256B(46) sets the background color to 46 (aka "\e[38;5;46m")

simmilar for true rgb ANSI_RGB(T/B)(R,G,B) so ANSI_RGBT(255,255,255) is max white text
*/



/* ansi codes (cheat sheet if you like typing it out, but I dont know why you want this header):
\e[0;30m - 0 is the state section 30m is the color section
30m - text black
31m - text red
32m - text green
33m - text yellow
34m - text blue
35m - text purple
36m - text cyan
37m - text white

40m - 47m same pattern but bg color
90m - 97m same pattern but hign intensity (non standard, common)
100m - 107m same pattern but high intensity bg (non standard, common)

there is also ansi fullcolor. or ansi pallete
not listing all 256 ansi pallet colors but the format is this: \e[38;5;nm (38 = settext [can be 48 for bg], 5 = color 5)

rbg ansi is \e[38(or 48);2;r;g;bm

\e[0m - reset
\e[2J - clear screen

\e[A up
\e[B Down
\e[C right
\e[D left

0 - normal
1 - bold
2 - faint (or light font weight )
3 - italics (rarely supported)
4 - underline (should exist, minimal fail)
5 - slow blink 
7 - inverse (invert background and foreground)
9 - strike though (usually supported)
53 - overlined

shutdowns
22 - normal intensity
23 - not italic
24 - not underlined
25 - stop blinking
27 - not reversed/inverted
29 - not crossed out
39 - default color (text)
49 - default color (back)
55 - not over lined */

#ifndef ANSI_HELPER
#define ANSI_HELPER


#define ARESET "\e[0m"
#define ACLR "\e[2J"
#define ACLEAR "\e[2J"

#define AUP "\e[A"
#define ADOWN "\e[B"
#define ARIGHT "\e[C"
#define ALEFT "\e[D"
//text black etc
#define TBLACK 30 
#define TRED 31 
#define TGREEN 32 
#define TYELLOW 33 
#define TBLUE 34 
#define TPURPLE 35 
#define TCYAN 36 
#define TWHITE 37 
//background black etc
#define BBLACK 40 
#define BRED 41 
#define BGREEN 42 
#define BYELLOW 43 
#define BBLUE 44 
#define BPURPLE 45 
#define BCYAN 46 
#define BWHITE 47 
//same but HI is for high intensity
#define THIBLACK 90 
#define THIRED 91 
#define THIGREEN 92 
#define THIYELLOW 93 
#define THIBLUE 94 
#define THIPURPLE 95 
#define THICYAN 96 
#define THIWHITE 97 

#define BHIBLACK 100 
#define BHIRED 101 
#define BHIGREEN 102 
#define BHIYELLOW 103 
#define BHIBLUE 104 
#define BHIPURPLE 105 
#define BHICYAN 106 
#define BHIWHITE 107 

#define TNORMAL 0 
#define BOLD 1
#define FAINT 2
#define ITALIC 3
#define UNDERLINE 4
#define BLINK 5// fast blink exists, but nobody supports it so not here
#define INVERSE 7
#define CROSSOUT 9 
#define STRIKETHROUGH 9 // some people like the full name, I dont but its here anyway
#define OVERLINE  53

// reset section U is not (so not inverse, not italic)
#define BRIGHTNORMAL 22 // same as setting 0 btw, not bold or faint 
#define UITALIC 23
#define UINVERSE 27
#define UCROSS 29
#define USTRIKETHROUGH 29
#define UCOLOR 39 // normal fg
#define UBACK 49 // normal bg
#define UOLINE 55 // not overlined
#define UULINE 24 // not underlined
#define UBLINK 25 // stop blinking


#define ANSI(type,value) "\e[" #type ";" #value "m" // long ansi, for full codes
#define SANSI(type) "\e[" #type "m" // short ansi for things like \e[2m text -> faint text 
#define ANSI_RGBT(r,g,b) "\e[38;2;" #r ";" #g ";" #b "m"  // only set color, but rgb (text)
#define ANSI_RGBB(r,g,b) "\e[48;2;" #r ";" #g ";" #b "m"
#define ANSI_256T(n) "\e[38;5;" #n "m" // pallette color n text
#define ANSI_256B(n) "\e[48;5;" #n "m"

#endif
