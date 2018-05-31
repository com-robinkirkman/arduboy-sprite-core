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
#undef WIDTH
#undef HEIGHT

#include "XYSprite.h"
#include "List.h"

class SpriteCore : public ArduboyCore {
public:
	static constexpr int EEPROM_STORAGE_SPACE_START = 16;


	static void begin();
};

#endif /* SRC_SPRITECORE_H_ */
