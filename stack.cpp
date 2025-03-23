#include <iostream>
using namespace std;

#define MAX 4
int stack_arr[MAX];
int top = -1;

void push(int data) {
    if (top == MAX - 1) {
        cout << "Stack overflow\n";
        return;
    }
    stack_arr[++top] = data;
}

int pop() {
    if (top == -1) {
        cout << "Stack underflow\n";
        return -1; // Indicating stack is empty
    }
    return stack_arr[top--];
}

void print() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }
    for (int i = top; i >= 0; i--) {
        cout << stack_arr[i] << endl;
    }
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl;

    cout << "Stack elements:\n";
    print();

    return 0;
}
