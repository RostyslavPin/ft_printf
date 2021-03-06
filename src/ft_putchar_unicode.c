#include "ft_printf.h"
#include <unistd.h>

void ft_putchar_unicode(unsigned int c)
{
	unsigned int v;
	unsigned int mask1 = 49280;
	unsigned int mask2= 14712960;
	unsigned int mask3= 4034953344;
	v = c;
	if(c > 0 && c <= 127)
		write(1, &c, 1);
	else if(c >= 128 && c <= 2047)
	{
		unsigned char o2 = (v << 26) >> 26; // Восстановление первых 6 бит 110xxxxx 10(xxxxxx)
		unsigned char o1 = ((v >> 6) << 27) >> 27; // Восстановление последних 5 бит 110(xxxxx) 10xxxxxx

		c = (mask1 >> 8) | o1; // Применение первой битовой маски ко первому байту
		write(1, &c, 1);
		c = ((mask1 << 24) >> 24) | o2; // Применение второй битовой маски ко второму байту
		write(1, &c, 1);
	}
	else if(c >= 2048 && c <= 65535)
	{
		unsigned char o3 = (v << 26) >> 26; // Восстановление первых 6 бит 1110xxxx 10xxxxxx 10(xxxxxx)
        unsigned char o2 = ((v >> 6) << 26) >> 26; // Восстановление вторых 6 бит 1110xxxx 10(xxxxxx) 10xxxxxx
        unsigned char o1 = ((v >> 12) << 28) >> 28; // Восстановление последних 4 бит 1110(xxxx) 10xxxxxx 10xxxxxx
 
        c = (mask2 >> 16) | o1; // Применение первой битовой маски ко первому байту
        write(1, &c, 1);
        c = ((mask2 << 16) >> 24) | o2; // Применение второй битовой маски ко второму байту
        write(1, &c, 1);
      	c = ((mask2 << 24) >> 24) | o3; // Применение третьей битовой маски ко третьему байту
        write(1, &c, 1);
	}
	else if (c >=65536 && c <= 1114111)
	{
		unsigned char o4 = (v << 26) >> 26; // Восстановление первых 6 11110xxx 10xxxxxx 10xxxxxx 10(xxxxxx)
		unsigned char o3 = ((v >> 6) << 26) >> 26; // Восстановление вторых 6 бит 11110xxx 10xxxxxx 10(xxxxxx) 10xxxxxx
		unsigned char o2 = ((v >> 12) << 26) >> 26;  // Восстановление третьих 6 бит bits 11110xxx 10(xxxxxx) 10xxxxxx 10xxxxxx
		unsigned char o1 = ((v >> 18) << 29) >> 29; // Восстановление последних 3 бита 11110(xxx) 10xxxxxx 10xxxxxx 10xxxxxx
       
		c = (mask3 >> 24) | o1; // Применение бит первого байта на первый байт маски
		write(1, &c, 1);
		c = ((mask3 << 8) >> 24) | o2; // Применение второй битовой маски ко второму байту
		write(1, &c, 1);
		c = ((mask3 << 16) >> 24) | o3; // Применение третьей битовой маски ко третьему байту
		write(1, &c, 1);
		c = ((mask3 << 24) >> 24) | o4; // Применение последней битовой маски ко последнему байту
		write(1, &c, 1);
	}
}