class DynamicArray {
private:
    int *arr;
    int size;
    int capacity;
public:

    DynamicArray(int n) {
        arr = (int*)malloc(sizeof(int)*n);
        capacity = n;
        size = 0;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(size == capacity) resize();
        arr[size] = n;
        size++;
    }

    int popback() {
        size--;
        return arr[size];
    }

    void resize() {
        capacity *= 2;
        int *cpy = (int*)malloc(sizeof(int)*capacity);
        for(int i = 0; i < size; i++) cpy[i] = arr[i];
        free(arr);
        arr = cpy;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
