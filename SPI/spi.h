#ifndef SPI_H_
#define SPI_H_

#ifndef F_CPU
	#error "F_CPU is not defined for <spi>"
#endif

#ifndef LSBFIRST
#define LSBFIRST 0
#endif
#ifndef MSBFIRST
#define MSBFIRST 1
#endif

#define SPI_CLOCK_MASK			0x03
#define SPI_2XCLOCK_MASK		0x01
#define SPI_CLOCK_DIV2			0x04
#define SPI_CLOCK_DIV4			0x00
#define SPI_CLOCK_DIV8			0x05
#define SPI_CLOCK_DIV16			0x01
#define SPI_CLOCK_DIV32			0x06
#define SPI_CLOCK_DIV64			0x02
#define SPI_CLOCK_DIV128		0x03

#define SPI_MODE_MASK			0x0C
#define SPI_MODE0				0x00
#define SPI_MODE1				0x04
#define SPI_MODE2				0x08
#define SPI_MODE3				0x0C

#define SPI_MASTER				0x10
#define SPI_SLAVE				0x00

#if defined( __AVR_ATmega328PB__ )

	#undef SPCR
	#define SPCR(ch)				_SFR_MEM8(0x4C + (ch * 0x60))
	#undef SPSR
	#define SPSR(ch)				_SFR_MEM8(0x4D + (ch * 0x60))
	#undef SPDR
	#define SPDR(ch)				_SFR_MEM8(0x4E + (ch * 0x60))
	
	#define SPI_MISO0_BIT			4
	#define SPI_MISO0_PORT_DDR		DDRB
	#define SPI_MISO0_PORT			PORTB
	#define SPI_MISO0_PIN			PINB
	#define SPI_MISO0_OUT()			( SPI_MISO0_PORT_DDR |= ( 1 << SPI_MISO0_BIT ) )
	#define SPI_MISO0_IN()			( SPI_MISO0_PORT_DDR &= ~( 1 << SPI_MISO0_BIT ) )

	#define SPI_MOSI0_BIT			3
	#define SPI_MOSI0_PORT_DDR		DDRB
	#define SPI_MOSI0_PORT			PORTB
	#define SPI_MOSI0_PIN			PINB
	#define SPI_MOSI0_OUT()			( SPI_MOSI0_PORT_DDR |= ( 1 << SPI_MOSI0_BIT ) )
	#define SPI_MOSI0_IN()			( SPI_MOSI0_PORT_DDR &= ~( 1 << SPI_MOSI0_BIT ) )

	#define SPI_SCK0_BIT			5
	#define SPI_SCK0_PORT_DDR		DDRB
	#define SPI_SCK0_PORT			PORTB
	#define SPI_SCK0_PIN			PINB
	#define SPI_SCK0_OUT()			( SPI_SCK0_PORT_DDR |= ( 1 << SPI_SCK0_BIT ) )
	#define SPI_SCK0_IN()			( SPI_SCK0_PORT_DDR &= ~( 1 << SPI_SCK0_BIT ) )

	#define SPI_SS0_BIT				2
	#define SPI_SS0_PORT_DDR		DDRB
	#define SPI_SS0_PORT			PORTB
	#define SPI_SS0_PIN				PINB
	#define SPI_SS0_OUT()			( SPI_SS0_PORT_DDR |= ( 1 << SPI_SS0_BIT ) )
	#define SPI_SS0_IN()			( SPI_SS0_PORT_DDR &= ~( 1 << SPI_SS0_BIT ) )

	#define SPI_MISO1_BIT			0
	#define SPI_MISO1_PORT_DDR		DDRC
	#define SPI_MISO1_PORT			PORTC
	#define SPI_MISO1_PIN			PINC
	#define SPI_MISO1_OUT()			( SPI_MISO1_PORT_DDR |= ( 1 << SPI_MISO1_BIT ) )
	#define SPI_MISO1_IN()			( SPI_MISO1_PORT_DDR &= ~( 1 << SPI_MISO1_BIT ) )

	#define SPI_MOSI1_BIT			3
	#define SPI_MOSI1_PORT_DDR		DDRE
	#define SPI_MOSI1_PORT			PORTE
	#define SPI_MOSI1_PIN			PINE
	#define SPI_MOSI1_OUT()			( SPI_MOSI1_PORT_DDR |= ( 1 << SPI_MOSI1_BIT ) )
	#define SPI_MOSI1_IN()			( SPI_MOSI1_PORT_DDR &= ~( 1 << SPI_MOSI1_BIT ) )

	#define SPI_SCK1_BIT			1
	#define SPI_SCK1_PORT_DDR		DDRC
	#define SPI_SCK1_PORT			PORTC
	#define SPI_SCK1_PIN			PINC
	#define SPI_SCK1_OUT()			( SPI_SCK1_PORT_DDR |= ( 1 << SPI_SCK1_BIT ) )
	#define SPI_SCK1_IN()			( SPI_SCK1_PORT_DDR &= ~( 1 << SPI_SCK1_BIT ) )

	#define SPI_SS1_BIT				2
	#define SPI_SS1_PORT_DDR		DDRE
	#define SPI_SS1_PORT			PORTE
	#define SPI_SS1_PIN				PINE
	#define SPI_SS1_OUT()			( SPI_SS1_PORT_DDR |= ( 1 << SPI_SS1_BIT ) )
	#define SPI_SS1_IN()			( SPI_SS1_PORT_DDR &= ~( 1 << SPI_SS1_BIT ) )

#elif defined( __AVR_ATmega328__ ) || defined( __AVR_ATmega328P__ )

	 #undef SPCR
	 #define SPCR(ch)				_SFR_IO8(0x2C)
	 #undef SPSR
	 #define SPSR(ch)				_SFR_IO8(0x2D)
	 #undef SPDR
	 #define SPDR(ch)				_SFR_IO8(0x2E)
	 
	 #define SPI_MISO0_BIT			4
	 #define SPI_MISO0_PORT_DDR		DDRB
	 #define SPI_MISO0_PORT			PORTB
	 #define SPI_MISO0_PIN			PINB
	 #define SPI_MISO0_OUT()		( SPI_MISO0_PORT_DDR |= ( 1 << SPI_MISO0_BIT ) )
	 #define SPI_MISO0_IN()			( SPI_MISO0_PORT_DDR &= ~( 1 << SPI_MISO0_BIT ) )

	 #define SPI_MOSI0_BIT			3
	 #define SPI_MOSI0_PORT_DDR		DDRB
	 #define SPI_MOSI0_PORT			PORTB
	 #define SPI_MOSI0_PIN			PINB
	 #define SPI_MOSI0_OUT()			( SPI_MOSI0_PORT_DDR |= ( 1 << SPI_MOSI0_BIT ) )
	 #define SPI_MOSI0_IN()			( SPI_MOSI0_PORT_DDR &= ~( 1 << SPI_MOSI0_BIT ) )

	 #define SPI_SCK0_BIT			5
	 #define SPI_SCK0_PORT_DDR		DDRB
	 #define SPI_SCK0_PORT			PORTB
	 #define SPI_SCK0_PIN			PINB
	 #define SPI_SCK0_OUT()			( SPI_SCK0_PORT_DDR |= ( 1 << SPI_SCK0_BIT ) )
	 #define SPI_SCK0_IN()			( SPI_SCK0_PORT_DDR &= ~( 1 << SPI_SCK0_BIT ) )

	 #define SPI_SS0_BIT			2
	 #define SPI_SS0_PORT_DDR		DDRB
	 #define SPI_SS0_PORT			PORTB
	 #define SPI_SS0_PIN			PINB
	 #define SPI_SS0_OUT()			( SPI_SS0_PORT_DDR |= ( 1 << SPI_SS0_BIT ) )
	 #define SPI_SS0_IN()			( SPI_SS0_PORT_DDR &= ~( 1 << SPI_SS0_BIT ) )
#else
	#error "Defined processor is invalid for <spi>"
#endif

class SPI 
{
	private: int8_t ch;
	
	public: SPI(int8_t ch);
	public: SPI(int8_t ch, uint8_t mode, uint8_t bitOrder, uint8_t dataMode);
	public: SPI(int8_t ch, uint8_t mode, uint8_t bitOrder, uint8_t dataMode,  uint32_t clock);
	public: void setMode(uint8_t mode);
	public: void setDataMode(uint8_t dataMode);
	public: void setClock();
	public: void setClock(uint32_t clock);
	public: void setBitOrder(uint8_t bitOrder);
	public: void enable();
	public: void disable();
	public: void sendByte( uint8_t data );
	public: uint8_t readByte();
};

#endif /* SPI_H_ */