#pragma once

#define LIST_INDEX_OUT_OF_RANGE "Index out of range!"
#define LIST_IS_EMPTY "List is empty!"
#define LIST_DOES_NOT_CONTAIN_VALUE "List does not contain the specified value!"

template <typename T>
class List
{
public:
	virtual void append(T) = 0;
	virtual void insert(size_t, T) = 0;
	virtual T pop() = 0;
	virtual void remove(T) = 0;
};
