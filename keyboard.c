#include "keyboard.h"
#include "keyboard_map.h"
#include "print.h"
#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define IDT_SIZE 256
#define INTERRUPT_GATE 0x8e
#define KERNEL_CODE_SEGMENT_OFFSET 0x08

extern unsigned char keyboard_map[128];
extern void keyboard_handler(void);

void idt_init(void)
{
	unsigned long keyboard_address;
	unsigned long idt_address;
	unsigned long idt_ptr[2];

	struct IDT_entry{
	   unsigned short int offset_lowerbits;
	   unsigned short int selector;
	   unsigned char zero;
	   unsigned char type_attr;
	   unsigned short int offset_higherbits;
	};

	struct IDT_entry IDT[IDT_SIZE];

	/* populate IDT entry of keyboard's interrupt */
	keyboard_address = (unsigned long)keyboard_handler; 
	IDT[0x21].offset_lowerbits = keyboard_address & 0xffff;
	IDT[0x21].selector = KERNEL_CODE_SEGMENT_OFFSET;
	IDT[0x21].zero = 0;
	IDT[0x21].type_attr = INTERRUPT_GATE;
	IDT[0x21].offset_higherbits = (keyboard_address & 0xffff0000) >> 16;
	

	/*     Ports
	*	 PIC1	PIC2
	*Command 0x20	0xA0
	*Data	 0x21	0xA1
	*/

	/* ICW1 - begin initialization */
	write_port(0x20 , 0x11);
	write_port(0xA0 , 0x11);

	/* ICW2 - remap offset address of IDT */
	/*
	* In x86 protected mode, we have to remap the PICs beyond 0x20 because
	* Intel have designated the first 32 interrupts as "reserved" for cpu exceptions
	*/
	write_port(0x21 , 0x20);
	write_port(0xA1 , 0x28);

	/* ICW3 - setup cascading */
	write_port(0x21 , 0x00);  
	write_port(0xA1 , 0x00);  

	/* ICW4 - environment info */
	write_port(0x21 , 0x01);
	write_port(0xA1 , 0x01);
	/* Initialization finished */

	/* mask interrupts */
	write_port(0x21 , 0xff);
	write_port(0xA1 , 0xff);

	/* fill the IDT descriptor */
	idt_address = (unsigned long)IDT ;
	idt_ptr[0] = (sizeof (struct IDT_entry) * IDT_SIZE) + ((idt_address & 0xffff) << 16);
	idt_ptr[1] = idt_address >> 16 ;

	load_idt(idt_ptr);
	write_port(0x21 , 0xFD);
}
void keyboard_handler_main(void)
{
	unsigned char bufferstatus;
	bufferstatus = read_port(KEYBOARD_STATUS_PORT);

	if (bufferstatus & 0x80)
	{
		return;
	}
	else
	{
		natural_t data = read_port(KEYBOARD_DATA_PORT);
		if (data > 2 && data < 53)
		{
			character_t keyboard_data = keyboard_map[data];
			writeCharacter(keyboard_data,terminal_character_style(TerminalWhite,TerminalBlack),-1);
		}
	}
	write_port(0x20,0x20);
}