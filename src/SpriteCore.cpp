/*
 * SpriteCore.cpp
 *
 *  Created on: May 15, 2018
 *      Author: robin
 */

#include <SpriteCore.h>

constexpr size_t kPageWidth = 128;
constexpr size_t kNumPages = 8;

void SpriteCore::begin() {
	ArduboyCore::boot();
}

void SpriteCore::display(const XYSprite *sprites, size_t len) {
	uint8_t page[kPageWidth];
	for (size_t n = 0; n < kNumPages; ++n) {
		memset(page, 0, kPageWidth);
		for (size_t i = 0; i < len; ++i)
			(*sprites++).render(n, page);
		SPI.transfer(page, kPageWidth);
	}
}

void SpriteCore::display(const List<XYSprite>& sprite_list) {
	uint8_t page[kPageWidth];
	for (size_t n = 0; n < kNumPages; ++n) {
		memset(page, 0, kPageWidth);
		const XYSprite *sprites = &sprite_list[0];
		for (size_t i = 0; i < sprite_list.size(); ++i) {
			(*sprites++).render(n, page);
		}
		SPI.transfer(page, kPageWidth);
	}
}

void SpriteCore::display(const List<List<XYSprite>*>& sprite_lists) {
	uint8_t page[kPageWidth];
	for (size_t n = 0; n < kNumPages; ++n) {
		memset(page, 0, kPageWidth);
		for (size_t i = 0; i < sprite_lists.size(); ++i) {
			const List<XYSprite> *sprite_list = sprite_lists[i];
			if (!sprite_list) continue;
			const XYSprite *sprites = &(*sprite_list)[0];
			for (size_t j = 0; j < sprite_list->size(); ++j) {
				(*sprites++).render(n, page);
			}
		}
		SPI.transfer(page, kPageWidth);
	}
}


void SpriteCore::write(int x, int y, const char *text, XYSprite *sprites) {
	uint8_t bg_raster[5];
	Sprite bg(5, 7, bg_raster);
	for (; *text; ++text, ++sprites, x += 6) {
		sprites->setX(x);
		sprites->setY(y);
		sprites->setSprite(Sprite(*text));
		sprites->setMode(Sprite::kOr);
	}
}
