/* 
	CUSTOM STACK MADE BY WAHYU BUDI SAPUTRA
	https://github.com/wahyubucil
*/

#ifndef CUSTOMSTACK_H
#define CUSTOMSTACK_H
#include <iostream>

using namespace std;

template <class T>
class CustomStack {
	private:
		T* mStack;
		int mMaxSize;
		int mTop;
		int mBottom;
	
	public:
		CustomStack(int maxSize) {
			mStack = new T[maxSize];
			mMaxSize = maxSize;
			mTop = -1;
			mBottom = 0;
		};
		void push(T);
		void pop();
		T getTop();
		int getTopPosition();
		T getBottom();
		int getBottomPosition();
		void increaseBottomPosition();
		int size();
		bool isEmpty();
		void reverseStack();
};

template <class T>
void CustomStack<T>::push(T value) {
	mTop++;
	mStack[mTop] = value;
}

template <class T>
void CustomStack<T>::pop() {
	mTop--;
}

template <class T>
T CustomStack<T>::getTop() {
	return mStack[mTop];
}

template <class T>
int CustomStack<T>::getTopPosition() {
	return mTop;
}

template <class T>
T CustomStack<T>::getBottom() {
	return mStack[mBottom];
}

template <class T>
int CustomStack<T>::getBottomPosition() {
	return mBottom;
}

template <class T>
void CustomStack<T>::increaseBottomPosition() {
	mBottom++;
}

template <class T>
int CustomStack<T>::size() {
	return mTop + 1;
}

template <class T>
bool CustomStack<T>::isEmpty() {
	return mTop == -1;
}

template <class T>
void CustomStack<T>::reverseStack() {
	T tempStack[size()];
	int sizeBeforePop = size();
	int i = 0;
	while (!isEmpty()) {
		T item = getTop();
		pop();
		tempStack[i] = item;
		i++;
	}
	
	for (int i = 0; i < sizeBeforePop; i++) {
		push(tempStack[i]);
	}
}

#endif 
