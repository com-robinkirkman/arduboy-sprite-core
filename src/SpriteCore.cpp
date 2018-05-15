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
	uint8_t page[WIDTH];
	for (int n = 0; n < HEIGHT / 8; ++n) {
		memset(page, 0, WIDTH);
		for (int i = 0; i < len; ++i)
			sprites[i].render(n, page);
		SPI.transfer(page, WIDTH);
	}
}

void SpriteCore::write(int x, int y, const char *text, XYSprite *sprites) {
	uint8_t bg_raster[5];
	Sprite bg(5, 7, bg_raster);
	for (; *text; ++text, ++sprites) {
		sprites->setX(x);
		sprites->setY(y);
		sprites->setForeground(Sprite(*text));
		sprites->setBackground(bg);
		sprites->setMode(XYSprite::RasterMode::kWhiteOnBlack);
	}
}
