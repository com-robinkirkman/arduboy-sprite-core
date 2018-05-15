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

	XYSprite() : XYSprite(0, 0, kNone, nullptr, nullptr) {}
	XYSprite(int x, int y, RasterMode mode, const Sprite *foreground, const Sprite *background = nullptr);

	int x() const { return x_; }
	int y() const { return y_; }

	void setX(int x) { x_ = x; }
	void setY(int y) { y_ = y; }

	const Sprite *foreground() const { return foreground_; }
	const Sprite *background() const { return background_; }

	void setForeground(const Sprite* foreground) { foreground_ = foreground; }
	void setBackground(const Sprite* background) { background_ = background; }

	void render(int page_num, uint8_t *page) const;

private:
	inline void render(Sprite::RenderMode render_mode, const Sprite *sprite_, int page_num, uint8_t *page) const;


	uint8_t mode_;
	const Sprite *foreground_;
	const Sprite *background_;
	int x_;
	int y_;
};

#endif /* SRC_XYSPRITE_H_ */
