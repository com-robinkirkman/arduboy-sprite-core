/*
 * XYSprite.cpp
 *
 *  Created on: May 13, 2018
 *      Author: robin
 */

#include <XYSprite.h>

XYSprite::XYSprite(int x, int y, RasterMode mode, const Sprite& foreground, const Sprite& background) :
mode_(mode), foreground_(foreground), background_(background), x_(x), y_(y) {}

void XYSprite::render(Sprite::RenderMode render_mode, const Sprite& sprite, int page_num, uint8_t *page) const {
	if (!sprite.raster())
		return;
	int page_y = page_num << 3;
	if (y_ + sprite.height() < page_y || y_ >= page_y + 8)
		return;
	if (x_ + sprite.width() < 0 || x_ >= 128)
		return;
	int width = sprite.width();
	if (x_ + width > 128)
		width = 128 - x_;
	sprite.render(render_mode, 0, page_y - y_, width, page + x_);
}


void XYSprite::render(int page_num, uint8_t *page) const {
	if (mode_ == RasterMode::kWhiteOnBlack) {
		render(Sprite::RenderMode::kMask, background_, page_num, page);
		render(Sprite::RenderMode::kOr, foreground_, page_num, page);
	} else if(mode_ == RasterMode::kBlackOnWhite) {
		render(Sprite::RenderMode::kOr, background_, page_num, page);
		render(Sprite::RenderMode::kMask, foreground_, page_num, page);
	}
}
