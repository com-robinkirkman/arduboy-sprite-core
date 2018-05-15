/*
 * SpriteCore.cpp
 *
 *  Created on: May 15, 2018
 *      Author: robin
 */

#include <SpriteCore.h>

void SpriteCore::begin() {
	ArduboyCore::boot();
}

void SpriteCore::display(const XYSprite *sprites, int len) {
	uint8_t page[width()];
	for (int n = 0; n < height() / 8; ++n) {
		memset(page, 0, width());
		for (int i = 0; i < len; ++i)
			sprites[i].render(n, page);
		SPI.transfer(page, width());
	}
}

void SpriteCore::write(const char *text, uint8_t *raster) {
	for (; *text; text += 1, raster += 6) {
		Sprite::setFontRaster(*text, raster);
		raster[5] = 0;
	}
}
