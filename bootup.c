#include "print.h"
#include "keyboard.h"
#include "memory.h"

void kmain(void)
{
	char *tmp = "Booting up\n";
	char *tmp1 = "Welcome!";
	char *tmp2 = "\nRunning Savanth\n";
	clearscreen();
	writeCharacter('A',terminal_character_style(TerminalWhite,TerminalBlack),0);
	writeString(&tmp[0],terminal_character_style(TerminalWhite,TerminalBlack),1);
	writeString(&tmp1[0],terminal_character_style(TerminalWhite,TerminalBlack),2);
	writeString(&tmp2[0],terminal_character_style(TerminalWhite,TerminalBlack),2);
	
	idt_init();
	memory_init();
	integer32_t Savant_Return_Value = Kernel_main(5);
	char *Savant = Savant_Return_Value;
	writeCharacter(&Savant,terminal_character_style(TerminalWhite,TerminalBlack),2);
	/*char* tmp3 = (char*)malloc(400000);
	char* tmp4 = (char*)malloc(400000);
	tmp3[0] = 'a';
	tmp3[1] = 'b';
	tmp3[2] = '\n';
	writeString(&tmp3[0],terminal_character_style(TerminalWhite,TerminalBlack),2);
	tmp4[0] = 'a';
	tmp4[1] = 'b';
	tmp4[2] = '\n';
	writeString(&tmp4[0],terminal_character_style(TerminalWhite,TerminalBlack),2);*/
	while(1)
	{
		//keyboard_handler_main();
	}
}
