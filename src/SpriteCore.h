/*
 * SpriteCore.h
 *
 *  Created on: May 15, 2018
 *      Author: robin
 */

#ifndef SRC_SPRITECORE_H_
#define SRC_SPRITECORE_H_

#include <EEPROM.h>
#include <core/core.h>

#include "XYSprite.h"

class SpriteCore : public ArduboyCore {
public:
	static void begin();
	static void display(const XYSprite *sprites, int len);
	static void write(int x, int y, const char *text, XYSprite *sprites);
};

#endif /* SRC_SPRITECORE_H_ */
