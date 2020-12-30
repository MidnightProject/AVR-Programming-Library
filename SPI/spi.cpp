#include <avr/io.h>
#include "spi.h"

SPI::SPI()
{
	
}

SPI::SPI(int8_t ch)
{
	#if defined( __AVR_ATmega328PB__ )
		if (ch >= 2)
		{
			return;
		}
	#endif
	
	#if defined( __AVR_ATmega328__ ) || defined( __AVR_ATmega328P__ )
		if (ch >= 1)
		{
			return;
		}
	#endif
		
	this->ch = ch;
	
	#if F_SPI0
		if (this->ch == 0)
		{
			setClock();
		}
	#endif
	
	#if F_SPI1
		if (this->ch == 1)
		{
			SPI.setClock();
		}
	#endif
}

SPI::SPI(int8_t ch, uint8_t mode, uint8_t bitOrder, uint8_t dataMode)
{
	#if defined( __AVR_ATmega328PB__ )
	if (ch >= 2)
	{
		return;
	}
	#endif
	
	#if defined( __AVR_ATmega328__ ) || defined( __AVR_ATmega328P__ )
		if (ch >= 1)
		{
			return;
		}
	#endif
	
	this->ch = ch;
	
	#if F_SPI0
	if (this->ch == 0)
	{
		setClock();
	}
	#endif
	
	#if F_SPI1
	if (this->ch == 1)
	{
		SPI.setClock();
	}
	#endif
	
	setMode(mode);
	setBitOrder(bitOrder);
	setDataMode(dataMode);
	
	enable();
}

SPI::SPI(int8_t ch, uint8_t mode, uint8_t dataMode, uint8_t bitOrder, uint32_t clock)
{	
	#if defined( __AVR_ATmega328PB__ )
		if (ch >= 2)
		{
			return;
		}
	#endif
	
	#if defined( __AVR_ATmega328__ ) || defined( __AVR_ATmega328P__ )
		if (ch >= 1)
		{
			return;
		}
	#endif
	
	this->ch = ch;
	
	setMode(mode);
	setBitOrder(bitOrder);
	setDataMode(dataMode);
	setClock(clock);
	
	enable();
}

void SPI::setChannel(int8_t ch)
{
	this->ch = ch;
}

void SPI::setMode(uint8_t mode)
{		
	if (mode == SPI_MASTER)
	{					
		switch (ch)
		{
			case  0:
				#ifndef SPI_MOSI0
					#define SPI_MOSI0	3
				#endif
				SPI_MOSI0_OUT();
			
				#ifndef SPI_SCK0
					#define SPI_SCK0	5
				#endif
				SPI_SCK0_OUT();
			
				#ifndef SPI_MISO0
					#define SPI_MISO0	4
				#endif
				SPI_MISO0_IN();
				
				#ifndef SPI_SS0
					#define SPI_SS0		2
				#endif
				SPI_SS0_OUT();
				break;
				
			#if defined( __AVR_ATmega328PB__ )
			case 1:
				#ifndef SPI_MOSI1
					#define SPI_MOSI1	3
				#endif
				SPI_MOSI1_OUT();
				
				#ifndef SPI_SCK1
					#define SPI_SCK1	1
				#endif
				SPI_SCK1_OUT();
				
				#ifndef SPI_MISO1
					#define SPI_MISO1	0
				#endif
				SPI_MISO1_IN();
				#ifndef SPI_SS1
					#define SPI_SS1		2
				#endif
				SPI_SS1_OUT();
				break;
			#endif
		}
		
		#if defined( __AVR_ATmega328PB__ )
			SPCR(ch) |= SPI_MASTER;
		#endif 
		
		#if defined( __AVR_ATmega328__ ) || defined( __AVR_ATmega328P__ )
			SPCR(ch) |= SPI_MASTER;
		#endif
	}
	else
	{
		return;
	}
}

void SPI::setDataMode(uint8_t dataMode)
{	
	#if defined( __AVR_ATmega328PB__ )	
		SPCR(ch) &= ~SPI_MODE_MASK;
		SPCR(ch) |= dataMode;
	#endif
	
	#if defined( __AVR_ATmega328__ ) || defined( __AVR_ATmega328P__ )
		SPCR(ch) &= ~SPI_MODE_MASK;
		SPCR(ch) |= dataMode;
	#endif
}

void SPI::setClock()
{		
	#if defined( __AVR_ATmega328PB__ )
		SPCR(ch) &= ~SPI_CLOCK_MASK;
		SPSR(ch) &= ~SPI_2XCLOCK_MASK;
	#endif
	
	#if defined( __AVR_ATmega328__ ) || defined( __AVR_ATmega328P__ )
		SPCR(ch) &= ~SPI_CLOCK_MASK;
		SPSR(ch) &= ~SPI_2XCLOCK_MASK;
	#endif
	
	#ifndef F_SPI0
		#define F_SPI0 0
	#endif
				
	#ifndef F_SPI1
		#define F_SPI1 0
	#endif

	#if defined( __AVR_ATmega328PB__ )
		volatile uint8_t clockDiv[] = {0, 0};
	#endif
	
	#if defined( __AVR_ATmega328__ ) || defined( __AVR_ATmega328P__ )
		volatile uint8_t clockDiv[] = {0};
	#endif
	
	#if F_SPI0 >= F_CPU / 2
	#elif F_SPI0 >= F_CPU / 4
		clockDiv[0] = 1;
	#elif F_SPI0 >= F_CPU / 8
		clockDiv[0] = 2;
	#elif F_SPI0 >= F_CPU / 16
		clockDiv[0] = 3;
	#elif F_SPI0 >= F_CPU / 32
		clockDiv[0] = 4;
	#elif F_SPI0 >= F_CPU / 64
		clockDiv[0] = 5;
	#else
		// Compensate for the duplicate fosc / 64
		clockDiv[0] = 7;
	#endif
	
	// Invert the SPI2X bit
	clockDiv[0] ^= 0x01;
	
	#if defined( __AVR_ATmega328PB__ )
	
		#if F_SPI1 >= F_CPU / 2
		#elif F_SPI1 >= F_CPU / 4
			clockDiv[1] = 1;
		#elif F_SPI1 >= F_CPU / 8
			clockDiv[1] = 2;
		#elif F_SPI1 >= F_CPU / 16
			clockDiv[1] = 3;
		#elif F_SPI1 >= F_CPU / 32
			clockDiv[1] = 4;
		#elif F_SPI1 >= F_CPU / 64
			clockDiv[1] = 5;
		#else
			// Compensate for the duplicate fosc / 64
			clockDiv[1] = 7;
		#endif
		
		// Invert the SPI2X bit
		clockDiv[1] ^= 0x01;

	#endif
	
	#if defined( __AVR_ATmega328PB__ )
		SPCR(ch) |= (clockDiv[ch] >> 1) & SPI_CLOCK_MASK;
		SPSR(ch) |= clockDiv[ch] & SPI_2XCLOCK_MASK;
	#endif
	
	#if defined( __AVR_ATmega328__ ) || defined( __AVR_ATmega328P__ )
		SPCR(ch) |= (clockDiv[ch] >> 1) & SPI_CLOCK_MASK;
		SPSR(ch) |= clockDiv[ch] & SPI_2XCLOCK_MASK;
	#endif
}

void SPI::setClock(uint32_t clock)
{
	#if defined( __AVR_ATmega328PB__ )
		SPCR(ch) &= ~SPI_CLOCK_MASK;
		SPSR(ch) &= ~SPI_2XCLOCK_MASK;
	#endif
	
	#if defined( __AVR_ATmega328__ ) || defined( __AVR_ATmega328P__ )
		SPCR(ch) &= ~SPI_CLOCK_MASK;
		SPSR(ch) &= ~SPI_2XCLOCK_MASK;
	#endif
	
	// div = 2 ^ (clockDiv + 1)
	
	// SPR1	SPR0 ~SPI2X fosc / div
	//   0    0     0   fosc / 2
	//   0    0     1   fosc / 4
	//   0    1     0   fosc / 8
	//   0    1     1   fosc / 16
	//   1    0     0   fosc / 32
	//   1    0     1   fosc / 64
	//   1    1     0   fosc / 64
	//   1    1     1   fosc / 128
	
	uint8_t clockDiv = 0;
	uint32_t clockSetting = F_CPU / 2;

	while (clockDiv < 6 && clock < clockSetting)
	{
		clockSetting /= 2;
		clockDiv++;
	}
	
	// Compensate for the duplicate fosc / 64
	if (clockDiv == 6)
	{
		clockDiv = 7;
	}
	
	// Invert the SPI2X bit
	clockDiv ^= 0x01;
	
	#if defined( __AVR_ATmega328PB__ )
		SPCR(ch) |= (clockDiv >> 1) & SPI_CLOCK_MASK;
		SPSR(ch) |= clockDiv & SPI_2XCLOCK_MASK;
	#endif
	
	#if defined( __AVR_ATmega328__ ) || defined( __AVR_ATmega328P__ )
		SPCR(ch) |= (clockDiv >> 1) & SPI_CLOCK_MASK;
		SPSR(ch) |= clockDiv & SPI_2XCLOCK_MASK;
	#endif
}

void SPI::setBitOrder(uint8_t bitOrder)
{
	#if defined( __AVR_ATmega328PB__ )
		(bitOrder == MSBFIRST) ? SPCR(ch) |= (1 << DORD) : SPCR(ch) &= ~(1 << DORD);
	#endif
	
	#if defined( __AVR_ATmega328__ ) || defined( __AVR_ATmega328P__ )
		(bitOrder == MSBFIRST) ? SPCR(ch) |= (1 << DORD) : SPCR(ch) &= ~(1 << DORD);
	#endif
}

void SPI::enable()
{	
	#if defined( __AVR_ATmega328PB__ )
		SPCR(ch) |= (1 << SPE);
	#endif
	
	#if defined( __AVR_ATmega328__ ) || defined( __AVR_ATmega328P__ )
		SPCR(ch) |= (1 << SPE);
	#endif
}

void SPI::disable()
{
	#if defined( __AVR_ATmega328PB__ )
		SPCR(ch) &= ~(1 << SPE);
	#endif
	
	#if defined( __AVR_ATmega328__ ) || defined( __AVR_ATmega328P__ )
		SPCR(ch) &= ~(1 << SPE);
	#endif
}

void SPI::sendByte( uint8_t data )
{
	SPDR(ch) = data;
	asm volatile("nop");
	
	while( !(SPSR(ch) & (1 << SPIF)) );		// wait SPIF = 1
}

uint8_t SPI::readByte()
{
	sendByte( 0xFF );
	return ( SPDR(ch) );
}