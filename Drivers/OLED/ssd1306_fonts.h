#ifndef __SSD1306_FONTS_H__
#define __SSD1306_FONTS_H__

#include <stddef.h>
#include <stdint.h>
#include <_ansi.h>


typedef struct {
	const uint8_t width;                /**< Font width in pixels */
	const uint8_t height;               /**< Font height in pixels */
	const uint16_t *const data;         /**< Pointer to font data array */
    const uint8_t *const char_width;    /**< Proportional character width in pixels (NULL for monospaced) */
} SSD1306_Font_t;

#ifdef SSD1306_INCLUDE_FONT_6x8
extern const SSD1306_Font_t Font_6x8;
#endif
#ifdef SSD1306_INCLUDE_FONT_7x10
extern const SSD1306_Font_t Font_7x10;
#endif
#ifdef SSD1306_INCLUDE_FONT_11x18
extern const SSD1306_Font_t Font_11x18;
#endif
#ifdef SSD1306_INCLUDE_FONT_16x26
extern const SSD1306_Font_t Font_16x26;
#endif
#ifdef SSD1306_INCLUDE_FONT_16x24
extern const SSD1306_Font_t Font_16x24;
#endif
#ifdef SSD1306_INCLUDE_FONT_16x15
/** Generated Roboto Thin 15 
 * @copyright Google https://github.com/googlefonts/roboto
 * @license This font is licensed under the Apache License, Version 2.0.
*/
extern const SSD1306_Font_t Font_16x15;
#endif

#endif // __SSD1306_FONTS_H__
