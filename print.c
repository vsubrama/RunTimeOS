#include "print.h"

character_t *TerminalScreen = (character_t*)0xb8000;
const natural_t TerminalWidth = 80;
const natural_t TerminalHeight = 25;
natural_t TerminalCursor = 0;

void writeCharacter(character_t character,terminal_character_style_t style,natural_t position)
{
	if (TerminalCursor > (TerminalWidth * TerminalHeight))
	{
		clearscreen();
	}
	if (position == -1)
	{
		position = TerminalCursor;
	}
	switch(character)
	{
		case '\n':
			newline();
		break;
		
		case '\t':
		TerminalCursor = TerminalCursor + 8;
		break;

		case '\b':
		TerminalScreen[position] = ' ';
	  	--position;
	  	TerminalScreen[position] = 0x07;
	  	--position;
	  	TerminalScreen[position] = ' ';
	  	TerminalCursor = position;
	  	break;

	  	default:
	  	TerminalScreen[TerminalCursor] = character;
	  	++TerminalCursor;
	  	TerminalScreen[TerminalCursor] = 0x07;
	  	TerminalCursor = TerminalCursor + 1;
	  	position = 0;
   }
}

void newline()
{
	natural_t cursor_space_left = TerminalCursor % (TerminalWidth * 2);
			if(cursor_space_left != 0 )
			{
				TerminalCursor = TerminalCursor + (TerminalWidth * 2) - cursor_space_left;
			}
}

void clearscreen()
{
	TerminalCursor = 0;
    for (natural_t index = 0; index < TerminalWidth * TerminalHeight; index=index+2)
    {
      writeCharacter(' ', terminal_character_style(TerminalWhite,TerminalBlack), index);
    }
    TerminalCursor = 0;
    return;
}

void writeString(character_t *string_to_be_written,terminal_character_style_t style,natural_t position)
{
	for(natural_t index = 0; string_to_be_written[index] != '\0'; index++)
	{
		
			writeCharacter(string_to_be_written[index], style, 
						TerminalCursor);
	}
}

terminal_character_style_t terminal_character_style(terminal_color_t foreground_color,
       												terminal_color_t background_color)
{
	return (background_color << 4) * foreground_color;
}