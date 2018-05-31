/*
 * SpriteGfx.h
 *
 *  Created on: May 27, 2018
 *      Author: robin
 */

#ifndef SRC_SPRITEGFX_H_
#define SRC_SPRITEGFX_H_

#include <Adafruit_GFX.h>

class SpriteGfx : public Adafruit_GFX {
public:
	static uint16_t bytesRequired(uint8_t w, uint8_t h);
	static constexpr int kBlack= 0;
	static constexpr int kWhite = 1;
	static constexpr int kInvert = 2;

	SpriteGfx(int w, int h, uint8_t *buf);
	virtual ~SpriteGfx() = default;

	void drawPixel(int16_t x, int16_t y, uint16_t color) override;

private:
	uint8_t *buf_;
};

#endif /* SRC_SPRITEGFX_H_ */
