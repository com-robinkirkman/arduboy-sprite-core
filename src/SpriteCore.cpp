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

void SpriteCore::display(XYSprite *sprites, size_t len) {
	List<XYSprite> list = {sprites, len };
	display(&list);
}

void SpriteCore::display(List<XYSprite>* sprites) {
	List<List<XYSprite>*> lists = { &sprites, 1 };
	display(&lists);
}
void SpriteCore::display(List<List<XYSprite>*>* sprites) {
	uint8_t page[WIDTH];
	for (int n = 0; n < HEIGHT / 8; ++n) {
		memset(page, 0, WIDTH);
		for (size_t i = 0; i < sprites->len; ++i) {
			const List<XYSprite>* list = sprites->data[i];
			for (size_t j = 0; j < list->len; ++j) {
				const XYSprite& sprite = list->data[j];
				sprite.render(n, page);
			}
		}
		SPI.transfer(page, WIDTH);
	}
}

void SpriteCore::write(int x, int y, const char *text, XYSprite *sprites) {
	uint8_t bg_raster[5];
	Sprite bg(5, 7, bg_raster);
	for (; *text; ++text, ++sprites, x += 6) {
		sprites->setX(x);
		sprites->setY(y);
		sprites->setForeground(Sprite(*text));
		sprites->setBackground(bg);
		sprites->setMode(XYSprite::RasterMode::kWhiteOnBlack);
	}
}
