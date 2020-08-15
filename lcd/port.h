/******************************************************************************
MIT License

Copyright (c) 2020 MidnightProject

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#ifndef PORT_H_
#define PORT_H_

/******************************************************************************
WAVESHARE 320X240
******************************************************************************/

//#define LCD_HX8347D_CS				PA3
//#define LCD_HX8347D_CS_BIT			PA3
//#define LCD_HX8347D_CS_PORT_DDR		DDRA
//#define LCD_HX8347D_CS_PORT			PORTA
//#define LCD_HX8347D_CS_PIN			PINA
//#define LCD_HX8347D_CS_OUT()		( LCD_HX8347D_CS_PORT_DDR |= ( 1 << LCD_HX8347D_CS_BIT ) )
//#define LCD_HX8347D_CS_ENABLE()		( LCD_HX8347D_CS_PORT &= ~( 1 << LCD_HX8347D_CS_BIT ) )
//#define LCD_HX8347D_CS_DISABLE()	( LCD_HX8347D_CS_PORT |=  ( 1 << LCD_HX8347D_CS_BIT ) )

//#define LCD_HX8347D_DC				PA2
//#define LCD_HX8347D_DC_BIT			PA2
//#define LCD_HX8347D_DC_PORT_DDR		DDRA
//#define LCD_HX8347D_DC_PORT			PORTA
//#define LCD_HX8347D_DC_PIN			PINA
//#define LCD_HX8347D_DC_OUT()		( LCD_HX8347D_DC_PORT_DDR |= ( 1 << LCD_HX8347D_DC_BIT ) )
//#define LCD_HX8347D_DC_COMMAND()	( LCD_HX8347D_DC_PORT &= ~( 1 << LCD_HX8347D_DC_BIT ) )
//#define LCD_HX8347D_DC_DATA()		( LCD_HX8347D_DC_PORT |=  ( 1 << LCD_HX8347D_DC_BIT ) )

//#define LCD_WAVESHARE_320X240_BL			PL7
//#define LCD_WAVESHARE_320X240_BL_BIT		PL7
//#define LCD_WAVESHARE_320X240_BL_PORT_DDR	DDRL
//#define LCD_WAVESHARE_320X240_BL_PORT		PORTL
//#define LCD_WAVESHARE_320X240_BL_PIN		PINL
//#define LCD_WAVESHARE_320X240_BL_OUT()		( LCD_WAVESHARE_320X240_BL_PORT_DDR |=  ( 1 << LCD_WAVESHARE_320X240_BL_BIT ) )
//#define LCD_WAVESHARE_320X240_BL_OFF()		( LCD_WAVESHARE_320X240_BL_PORT &= ~( 1 << LCD_WAVESHARE_320X240_BL_BIT ) )
//#define LCD_WAVESHARE_320X240_BL_ON()		( LCD_WAVESHARE_320X240_BL_PORT |=  ( 1 << LCD_WAVESHARE_320X240_BL_BIT ) )

#endif /* PORT_H_ */