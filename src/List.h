/*
 * List.h
 *
 *  Created on: May 15, 2018
 *      Author: robin
 */

#ifndef SRC_LIST_H_
#define SRC_LIST_H_

#include <stddef.h>

template <typename T>
class List {
public:
	List(T *buf, size_t len) : buf_(buf), len_(len) {}
	size_t size() const { return len_; }
	inline T& operator[](int index) { return buf_[index]; }
	inline const T& operator[](int index) const { return buf_[index]; }

	T *buf_;
	size_t len_;
};

template<typename T, int LEN>
class ArrayList : public List<T> {
public:
	ArrayList() : List<T>(array_, LEN) {}

	T array_[LEN];
};

#endif /* SRC_LIST_H_ */
