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
	void begin();
	void display(const XYSprite *sprites, int len);
};

#endif /* SRC_SPRITECORE_H_ */
