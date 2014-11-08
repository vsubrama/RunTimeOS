#include "print.h"

void kmain(void)
{
	char *tmp = "String to be written\n";
	char *tmp1 = "Halfhand string";
	char *tmp2 = "\nFull hand string";
	clearscreen();
	//writeChar();
	writeCharacter('A',terminal_character_style(TerminalWhite,TerminalBlack),0);
	writeString(&tmp[0],terminal_character_style(TerminalWhite,TerminalBlack),1);
	writeString(&tmp1[0],terminal_character_style(TerminalWhite,TerminalBlack),2);
	writeString(&tmp2[0],terminal_character_style(TerminalWhite,TerminalBlack),2);
	//int index = 0;
	//TerminalCursor = TerminalCursor + position;
	
}
