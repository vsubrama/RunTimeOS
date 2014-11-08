#include "print.h"

character_t *TerminalScreen = (character_t*)0xb8000;
const natural_t TerminalWidth = 80;
const natural_t TerminalHeight = 25;
natural_t TerminalCursor = 0;

void writeCharacter(character_t character,terminal_character_style_t style,natural_t position)
{
  TerminalScreen[position] = character;
  ++position;
  TerminalScreen[position] = 0x07;
  TerminalCursor = position + 1;
}

void clearscreen()
{
	TerminalCursor = 0;
    for (natural_t index = 0; index < TerminalWidth * TerminalHeight; index=index+2)
    {
      writeCharacter(' ', terminal_character_style(TerminalWhite,TerminalBlack), index);
    }
}

void writeString(character_t *string_to_be_written,terminal_character_style_t style,natural_t position)
{
	for(natural_t index = 0; string_to_be_written[index] != '\0'; index++)
	{
		if (string_to_be_written[index] == '\n')
		{
			natural_t cursor_space_left = TerminalCursor % (TerminalWidth * 2);
			if(cursor_space_left != 0 )
			{
				TerminalCursor = TerminalCursor + (TerminalWidth * 2) - cursor_space_left;
			}
		}
		else
		{
			writeCharacter(string_to_be_written[index], terminal_character_style(TerminalWhite,TerminalBlack), 
						TerminalCursor);	
		}
	}
}

terminal_character_style_t terminal_character_style(terminal_color_t foreground_color,
       												terminal_color_t background_color)
{
	return (background_color << 4) * foreground_color;
}