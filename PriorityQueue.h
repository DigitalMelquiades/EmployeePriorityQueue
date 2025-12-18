//
// Created by DigitalMelquiades on 12/19/25.
//

#ifndef EMPLOYEE_PRIORITYQUEUE_H
#define EMPLOYEE_PRIORITYQUEUE_H
#include <vector>
#include "Employee.h"

class PriorityQueue {
    std::vector<Employee*> heap;
    int size, capacity;
public:
    PriorityQueue();
    PriorityQueue(const int& capacity);
    ~PriorityQueue();
    bool isEmpty() const;
    bool isFull() const;
    void heapifyUp(int index);
    void heapifyDown(int index);
    void enque(Employee* employee);
    Employee* deque();
    void print() const;
};

#endif //EMPLOYEE_PRIORITYQUEUE_H