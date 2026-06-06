class DynamicArray {
private:
    int* arr;
    int length;
    int capacity;

public:

    DynamicArray(int capacity) {
        this->arr = new int[capacity];
        this->length = 0;
        this->capacity = capacity;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(length == capacity){
            resize();
        }
        arr[length] = n;
        length++;
    }

    int popback() {
        int end = arr[length-1];
        length--;
        return end;
    }

    void resize() {
        capacity = capacity * 2;
        int* temp = new int[capacity];
        for(int i = 0; i  < length; i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};
