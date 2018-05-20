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

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

bool XYSprite::intersects(const XYSprite& other) const {
	int l = MAX(left(), other.left());
	int r = MIN(right(), other.right());
	if (r - l < 0)
		return false;
	int t = MAX(top(), other.top());
	int b = MIN(bottom(), other.bottom());
	if (b - t < 0)
		return false;

	for (int y = t; y <= b; y += 8) {
		for (int x = l; x <= r; ++x) {
			uint8_t r1 = 0, r2 = 0;
			sprite().render(Sprite::kOr, x - this->x(), y - this->y(), 1, &r1);
			other.sprite().render(Sprite::kOr, x - other.x(), y - other.y(), 1, &r2);
			if (r1 & r2)
				return true;
		}
	}

	return false;
}

