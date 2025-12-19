//
// Created by DigitalMelquiades on 12/19/25.
//
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() = default;
PriorityQueue::PriorityQueue(const int& capacity) : size(0), capacity(std::abs(capacity)) { heap.reserve(capacity); } // I use abs jus tin case some sneaky lad decided to enter negative capacity
PriorityQueue::~PriorityQueue() { for (const auto& employee : heap) delete employee; };
bool PriorityQueue::isEmpty() const { return size == 0; }
bool PriorityQueue::isFull() const { return size == this->capacity; }
void PriorityQueue::heapifyUp(int index) {
    if (index < 0 || index > capacity) throw std::invalid_argument("[Error] Nice try Diddy, you ain't foolin this code\n");
    while (index > 0) {
        int p = (index-1)/2;
        if (heap[index]->getSalary() > heap[p]->getSalary()) {
            std::swap(heap[index], heap[p]);
            index = p;
        } else break;
    }
}
void PriorityQueue::heapifyDown(int index) {
    if (index < 0 || index > capacity) throw std::invalid_argument("[Error] Nice try Diddy, you ain't foolin this code\n");
    while (true) {
        int left = (2 * index) + 1, right = (2 * index) + 2, largest = index;
        if (left < size && heap[left]->getSalary() > heap[largest]->getSalary()) largest = left;
        if (right < size && heap[right]->getSalary() > heap[largest]->getSalary()) largest = right;
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            index = largest;
        } else break;
    }
}
void PriorityQueue::enque(Employee* employee) {
    if (size == capacity) throw std::out_of_range("[Error] Queue full!\n");
    heap.push_back(employee);
    heapifyUp(size);
    size++;
}
Employee* PriorityQueue::deque() {
    if (heap.empty()) throw std::out_of_range("[Error] Whagwan? Queue is empty!");
    Employee* max = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    size--;
    if (size>0) heapifyDown(0);
    return max;
}
void PriorityQueue::print() const { for (const auto& employee:heap) if (employee) employee->print(); }