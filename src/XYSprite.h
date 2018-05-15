/*
 * XYSprite.h
 *
 *  Created on: May 13, 2018
 *      Author: robin
 */

#ifndef SRC_XYSPRITE_H_
#define SRC_XYSPRITE_H_

#include "Sprite.h"

class XYSprite {
public:
	enum RasterMode {
		kNone = 0,
		kWhiteOnBlack = 1,
		kBlackOnWhite = 2,
	};

	XYSprite() : XYSprite(0, 0, kNone, {}, {}) {}
	XYSprite(int x, int y, RasterMode mode, const Sprite& foreground, const Sprite& background);

	int x() const { return x_; }
	int y() const { return y_; }

	void setX(int x) { x_ = x; }
	void setY(int y) { y_ = y; }

	const Sprite& foreground() const { return foreground_; }
	const Sprite& background() const { return background_; }

	void setForeground(const Sprite foreground) { foreground_ = foreground; }
	void setBackground(const Sprite background) { background_ = background; }

	RasterMode mode() { return (RasterMode) mode_; }
	void setMode(RasterMode mode) { mode_ = mode; }

	void render(int page_num, uint8_t *page) const;

private:
	void render(Sprite::RenderMode render_mode, const Sprite& sprite, int page_num, uint8_t *page) const;

	uint8_t mode_;
	Sprite foreground_;
	Sprite background_;
	int x_;
	int y_;
};

#endif /* SRC_XYSPRITE_H_ */
