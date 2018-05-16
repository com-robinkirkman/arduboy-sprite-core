/*
 * XYSprite.cpp
 *
 *  Created on: May 13, 2018
 *      Author: robin
 */

#include <XYSprite.h>

XYSprite::XYSprite(int x, int y, Sprite::RenderMode mode, const Sprite sprite) :
mode_(mode), sprite_(sprite), x_(x), y_(y) {}

void XYSprite::render(int page_num, uint8_t *page) const {
	if (!sprite_.raster())
		return;
	int page_y = page_num << 3;
	if (y_ + sprite_.height() < page_y || y_ >= page_y + 8)
		return;
	if (x_ + sprite_.width() < 0 || x_ >= 128)
		return;
	int width = sprite_.width();
	if (x_ + width > 128)
		width = 128 - x_;
	sprite_.render((Sprite::RenderMode) mode_, 0, page_y - y_, width, page + x_);
}


