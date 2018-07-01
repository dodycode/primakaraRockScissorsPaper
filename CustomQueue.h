/* 
	CUSTOM QUEUE MADE BY WAHYU BUDI SAPUTRA
*/

#ifndef CUSTOMQUEUE_H
#define CUSTOMQUEUE_H

template <class T>
class CustomQueue {
	private:
		int mMaxSize;
		T* mQueue;
		int mHead;
		int mTail;
		
	public:
		CustomQueue(int maxSize) {
			mMaxSize = maxSize;
			mQueue = new T[mMaxSize];
			mHead = -1;
			mTail = -1;
		};
		bool isEmpty();
		bool isFull();
		void enqueue(T data);
		T dequeue();
		int size();
};

template <class T>
bool CustomQueue<T>::isEmpty() {
	if (mTail == -1) {
		return true;
	} else {
		return false;
	}
}

template <class T>
bool CustomQueue<T>::isFull() {
	if (mTail == mMaxSize - 1) {
		return true;
	} else {
		return false;
	}
}

template <class T>
void CustomQueue<T>::enqueue(T data) {
	if (isEmpty()) {
		mHead = 0;
		mTail = 0;
		mQueue[mTail] = data;
	} else {
		if (!isFull()) {
			mTail++;
			mQueue[mTail] = data;
		}
	}
}

template <class T>
T CustomQueue<T>::dequeue() {
	T data = mQueue[mHead];
	for (int i = mHead; i <= mTail - 1; i++) {
		mQueue[i] = mQueue[i + 1];
	}
	mTail--;
	return data;
}

template <class T>
int CustomQueue<T>::size() {
	return mTail + 1;
}

#endif 
