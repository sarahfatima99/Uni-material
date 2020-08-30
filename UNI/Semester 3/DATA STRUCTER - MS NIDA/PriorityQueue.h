#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <algorithm>
#include <iostream>

template<typename T>
class PriorityQueue {

typedef unsigned long long ull;

private:

    T * data;
    ull size;
    ull rear;

    void max_heapify(int index);
    void min_heapify(int index);

public:

    PriorityQueue(int size);

    void enqueue(const T & s);
    void dequeue(void);
    void build_max_heap();
    void build_min_heap();
    T peek(void);
    void print(void);

    ~PriorityQueue();
};

template<typename T>
void PriorityQueue<T>::build_max_heap() {
    for( ull i = size / 2 ; i >= 1; --i ) this->max_heapify(i);
}

template<typename T>
void PriorityQueue<T>::build_min_heap() {
    for( ull i = size / 2 ; i >= 1; --i ) this->min_heapify(i);
}

template<typename T>
PriorityQueue<T>::PriorityQueue(int size)
    :   size(size), rear(1u) {
        data = new T[size];
}

template<typename T>
void PriorityQueue<T>::enqueue(const T & s) {
    if ( rear + 1 == size )
        std::cout << "Queue already full.\n";
    else {
        data[rear] = T(s);
        rear++;
    }
}

template<typename T>
void PriorityQueue<T>::dequeue(void) {
    if ( rear == 1 ) {
        std::cout << "Queue empty, cannot delete any further.\n";
    } else {
        swap(data[rear], data[1]);
        rear--;
    }
}

template<typename T>
void PriorityQueue<T>::max_heapify(int index) {

    int left = 2 * index, right = 2 * index + 1;

    int max = index;

    if ( left/right > this->size )
        return;

    if ( left <= this->size and data[max].CGPA < data[left].CGPA )
        max = left;
        
    if ( right <= this->size and data[max].CGPA < data[right].CGPA )
        max = right;

    if ( max != index ) {
        std::swap( data[max], data[index] );
        max_heapify(max);
    }
}

template<typename T>
void PriorityQueue<T>::min_heapify(int index) {
    
    int left = 2 * index, right = 2 * index + 1;

    if ( left/right > this->size )
        return;

    int min = index;

    if ( left <= this->size && data[min].CGPA > data[left].CGPA )
        min = left;
    if ( right <= this->size && data[min].CGPA > data[right].CGPA )
        min = right;

    if ( min != index ) {
        std::swap(data[min], data[index]);
        max_heapify(min);
    }
}

template<typename T>
T PriorityQueue<T>::peek(void) {
    return ( rear != 1 ? data[1] : T() ); 
}

template<typename T>
void PriorityQueue<T>::print(void) {
    for ( ull i = 0 ; i < size ; ++i ) { 
        std::cout << "( " << data[i].id << ", " << data[i].name << ", " << data[i].CGPA << " )";   
        std::cout << "\n";
    }
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
    delete[] data;
}

#endif