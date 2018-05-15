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
	template <typename T> struct List {
		T *data;
		size_t len;
	};

	template <typename T, size_t N> struct StaticList {
		T data[N];
		List<T> list = { data, N };
	};

	static void begin();
	static void display(XYSprite* sprites, size_t len);
	static void display(List<XYSprite>& sprites);
	static void display(List<List<XYSprite>*>& sprites);
	static void write(int x, int y, const char *text, XYSprite *sprites);
};

#endif /* SRC_SPRITECORE_H_ */
