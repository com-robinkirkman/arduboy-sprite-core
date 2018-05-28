/*
 * SpriteGfx.cpp
 *
 *  Created on: May 27, 2018
 *      Author: robin
 */

#include <SpriteGfx.h>

int SpriteGfx::bytesRequired(int w, int h) {
	int rows = h >> 3;
	if (h & 7) ++rows;
	return w * rows;
}

SpriteGfx::SpriteGfx(int w, int h, uint8_t *buf) : Adafruit_GFX(w, h), buf_(buf) {}

void SpriteGfx::drawPixel(int16_t x, int16_t y, uint16_t color) {
	int row = y >> 3;
	uint8_t *px = buf_ + row * width() + x;
	uint8_t mask = 1 << (y & 7);
	if (color == kInvert) color = (*px & mask) ? kBlack : kWhite;
	if (color == kBlack) *px &= ~mask;
	else if(color == kWhite) *px |= mask;
}
