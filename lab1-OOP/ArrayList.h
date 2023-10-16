#pragma once
#include <iostream>
#include <functional>

#include "List.h"

template <typename T>
class ArrayList : public List<T>
{
private:
	T* data;
	size_t length;

	void quickSort(int low, int high, bool (*sortingKey)(const T&, const T&))
	{
		if (low < high)
		{
			int m = partition(low, high, sortingKey);
			quickSort(low, m - 1, sortingKey);
			quickSort(m + 1, high, sortingKey);
		}
	}
	int partition(int low, int high, bool (*sortingKey)(const T&, const T&))
	{
		T pivot = data[high];
		int i = (low - 1);
		for (int j = low; j < high; j++)
		{
			if (sortingKey(data[j], pivot))
			{
				i++;
				std::swap(data[i], data[j]);
			}
		}
		std::swap(data[high], data[i + 1]);
		return (i + 1);
	}

	void mergeSort(int m, int w, bool (*sortingKey)(const T&, const T&))
	{
		if (m < w)
		{
			int d = m + (w - m) / 2;
			mergeSort(m, d, sortingKey);
			mergeSort(d + 1, w, sortingKey);
			merge(m, d, w, sortingKey);
		}
	}
	void merge(int left, int mid, int right, bool (*sortingKey)(const T&, const T&))
	{
		int subArrayOne = mid - left + 1;
		int subArrayTwo = right - mid;

		T* leftArray = new T[subArrayOne];
		T* rightArray = new T[subArrayTwo];

		for (int i = 0; i < subArrayOne; i++)
			leftArray[i] = data[left + i];
		for (int j = 0; j < subArrayTwo; j++)
			rightArray[j] = data[mid + 1 + j];

		int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
		int indexOfMergedArray = left;

		while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
		{
			if (sortingKey(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo]))
			{
				data[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
				indexOfSubArrayOne++;
			}
			else
			{
				data[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
				indexOfSubArrayTwo++;
			}
			indexOfMergedArray++;
		}

		while (indexOfSubArrayOne < subArrayOne)
		{
			data[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
			indexOfMergedArray++;
		}

		while (indexOfSubArrayTwo < subArrayTwo)
		{
			data[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
			indexOfMergedArray++;
		}
		delete[] leftArray;
		delete[] rightArray;
	}

public:
	ArrayList()
	{
		data = nullptr;
		length = 0;
	}

	void append(T value)
	{
		T* temp = new T[length + 1];
		for (size_t i = 0; i < length; i++)
			temp[i] = data[i];
		temp[length] = value;
		if (data)
			delete[] data;
		data = temp;
		length++;
	}
	void insert(size_t index, T value)
	{
		if (index > length)
			throw std::exception(LIST_INDEX_OUT_OF_RANGE);
		T* temp = new T[length + 1];
		for (size_t i = 0; i <= length; i++)
		{
			if (i < index)
				temp[i] = data[i];
			else if (i == index)
				temp[i] = value;
			else
				temp[i] = data[i - 1];
		}
		if (data)
			delete[] data;
		data = temp;
		length++;
	}

	T pop()
	{
		if (length == 0)
			throw std::exception(LIST_IS_EMPTY);
		T deletedElement = data[length - 1];
		if (length != 1)
		{
			T* temp = new T[length - 1];
			for (size_t i = 0; i < length - 1; i++)
				temp[i] = data[i];
			delete[] data;
			data = temp;
			length--;
		}
		else
		{
			delete[] data;
			length = 0;
		}
		return deletedElement;
	}
	void remove(T value)
	{
		size_t indexOfValue = -1;
		for (size_t i = 0; i < length; i++)
			if (data[i] == value && (indexOfValue = i))
				break;
		if (indexOfValue == -1)
			throw std::exception(LIST_DOES_NOT_CONTAIN_VALUE);
		if (length != 1)
		{
			T* temp = new T[length - 1];
			for (size_t i = 0; i < length; i++)
			{
				if (i < indexOfValue)
					temp[i] = data[i];
				else if (i > indexOfValue)
					temp[i - 1] = data[i];
			}
			delete[] data;
			data = temp;
			length--;
		}
		else
		{
			delete[] data;
			length = 0;
		}
	}

	size_t getLength()
	{
		return length;
	}

	void insertionSort(bool (*sortingKey)(const T&, const T&) = [](const T& first, const T& second) { return first < second; })
	{
		int i, j;
		T key;
		for (i = 1; i < length; i++)
		{
			key = data[i];
			j = i - 1;

			while (j >= 0 && !sortingKey(data[j], key))
			{
				data[j + 1] = data[j];
				j = j - 1;
			}
			data[j + 1] = key;
		}
	}
	void quickSort(bool (*sortingKey)(const T&, const T&) = [](const T& first, const T& second) { return first <= second; })
	{
		quickSort(0, length - 1, sortingKey);
	}
	void mergeSort(bool (*sortingKey)(const T&, const T&) = [](const T& first, const T& second) { return first <= second; })
	{
		mergeSort(0, length - 1, sortingKey);
	}
	void swapSort(bool (*sortingKey)(const T&, const T&) = [](const T& first, const T& second) { return first < second; })
	{
		bool swapped;
		for (int i = 0; i < length - 1; i++)
		{
			swapped = false;
			for (int j = 0; j < length - i - 1; j++)
			{
				if (!sortingKey(data[j], data[j + 1]))
				{
					std::swap(data[j], data[j + 1]);
					swapped = true;
				}
			}
			if (swapped == false)
				break;
		}
	}

	void customSort(void (*sort)(T*, int))
	{
		sort(data, length);
	}

	T& operator [](size_t index)
	{
		if (index >= length)
			throw std::exception(LIST_INDEX_OUT_OF_RANGE);
		return data[index];
	}
};

