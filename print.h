#include "types.h"

typedef natural8_t terminal_character_style_t;

typedef struct {
  character_t character;
  terminal_character_style_t style;
} terminal_character_t;

typedef enum {
  TerminalBlack = 0,
  TerminalBlue,
  TerminalGreen,
  TerminalCyan,
  TerminalRed,
  TerminalMagenta,
  TerminalBrown,
  TerminalLightGrey,
  TerminalDarkGrey,
  TerminalLightBlue,
  TerminalLightGreen,
  TerminalLightCyan,
  TerminalLightRed,
  TerminalLightMagenta,
  TerminalLightBrown,
  TerminalWhite
} terminal_color_t;

void writeCharacter(character_t character, terminal_character_style_t style,natural_t position);
void newline(void);
void clearscreen(void);
void writeString(character_t *character, terminal_character_style_t style,natural_t position);
terminal_character_style_t 
  terminal_character_style(terminal_color_t foreground_color,
       terminal_color_t background_color);