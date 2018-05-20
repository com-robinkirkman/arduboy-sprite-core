/*
 * XYSprite.cpp
 *
 *  Created on: May 13, 2018
 *      Author: robin
 */

#include <XYSprite.h>
#include <string.h>

XYSprite::XYSprite(int x, int y, Sprite::RenderMode mode, const Sprite sprite) :
mode_(mode), sprite_(sprite), x_(x), y_(y) {}

void XYSprite::render(int page_num, uint8_t *page) const {
	render(page_num, page, (Sprite::RenderMode) mode_);
}

void XYSprite::render(int page_num, uint8_t *page, Sprite::RenderMode mode) const {
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
	sprite_.render(mode, 0, page_y - y_, width, page + x_);
}

bool XYSprite::intersects(const XYSprite& other) const {
	// Naive implementation, does a whole display render first in OR and then in AND.
	uint8_t page1[128];
	uint8_t page2[128];
	for (int n = 0; n < 8; ++n) {
		memset(page1, 0, 128);
		memset(page2, 0, 128);
		render(n, page1, Sprite::kOr);
		other.render(n, page2, Sprite::kOr);
		for (int i = 0; i < 128; ++i) {
			if (page1[i] & page2[i])
				return true;
		}
	}
	return false;
}

