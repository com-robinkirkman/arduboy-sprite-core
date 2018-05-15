/*
 * XYSprite.cpp
 *
 *  Created on: May 13, 2018
 *      Author: robin
 */

#include <XYSprite.h>

XYSprite::XYSprite(int x, int y, RasterMode mode, const Sprite *foreground, const Sprite *background) :
mode_(mode), foreground_(foreground), background_(background), x_(x), y_(y) {}

void XYSprite::render(Sprite::RenderMode render_mode, const Sprite *sprite_, int page_num, uint8_t *page) const {
	int stripe_y = page_num << 3;
	int width = sprite_->width();
	if (x_ + width > 128)
		width = 128 - x_;
	sprite_->render(render_mode, 0, stripe_y - y_, width, page + x_);
}


void XYSprite::render(int page_num, uint8_t *page) const {
	if (mode_ == RasterMode::kWhiteOnBlack) {
		if (background_)
			render(Sprite::RenderMode::kMask, background_, page_num, page);
		if (foreground_)
			render(Sprite::RenderMode::kOr, foreground_, page_num, page);
	} else if(mode_ == RasterMode::kBlackOnWhite) {
		if (background_)
			render(Sprite::RenderMode::kOr, background_, page_num, page);
		if (foreground_)
			render(Sprite::RenderMode::kMask, foreground_, page_num, page);
	}
}
