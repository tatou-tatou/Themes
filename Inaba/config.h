// lemonboy's bar config.h

/* The height of the bar (in pixels) */
#define BAR_HEIGHT  18
/* The width of the bar. Set to -1 to fit screen */
#define BAR_WIDTH   -1
/* Offset from the left. Set to 0 to have no effect */
#define BAR_OFFSET 0
/* Choose between an underline or an overline */
#define BAR_UNDERLINE 1
/* The thickness of the underline (in pixels). Set to 0 to disable. */
#define BAR_UNDERLINE_HEIGHT 2
/* Default bar position, overwritten by '-b' switch */
#define BAR_BOTTOM 0
/* The fonts used for the bar, comma separated. Only the first 2 will be used. */
#define BAR_FONT       "-windows-montecarlo-medium-r-normal--11-110-72-72-c-60-microsoft-cp1252", "-windows-montecarlo-medium-r-normal--11-110-72-72-c-60-microsoft-cp1252"

/* Some fonts don't set the right width for some chars, pheex it */
#define BAR_FONT_FALLBACK_WIDTH 6
/* Define the opacity of the bar (requires a compositor such as compton) */
#define BAR_OPACITY 1.0 /* 0 is invisible, 1 is opaque */
/* Color palette */
#define BACKGROUND 0x1A1917
#define COLOR0 0x201f1d          // BG color of MUSIC, NOTIFICATIONS and CLOCK (dark grey)
#define COLOR1 0xA7402a          // BG color of TAGS and MAILS (red)
#define COLOR2 0x878438          // FG color of the date (green)
#define COLOR3 0x5C5541          // FG color of the squares before notifications, date and time (grey)
#define COLOR4 0x3D444E          // BG color of the notifications ICONS (blue)
#define COLOR5 0xded0b4          // FG color of NOTIFICATIONS, MUSIC and CLOCK (yellowish white)
#define COLOR6 0x302E26
#define COLOR7 0x302E26
#define COLOR8 0x5C5748
#define COLOR9 0xeddec9          // FG color of the TAGS and MAILS
#define FOREGROUND 0xded0b4
