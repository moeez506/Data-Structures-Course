#include <iostream>
#include <stdexcept>
#include <memory>
#include <cmath>

class AdvancedDynamicArray {
private:
    std::unique_ptr<int[]> array;
    int count; // 2
    int capacity; // 4

    static constexpr double GrowthFactor = 2; // 2 // 1.6


    static constexpr int InitialCapacity = 4;


    static constexpr int LinearGrowthThreshold = 20000;
    static constexpr int LinearGrowthAmount = 1000;

    //5
    void ensureCapacity(int minCapacity) {

        // 5 > 4
        if (minCapacity > capacity) {
            int newCapacity;

            if (capacity < LinearGrowthThreshold) {
                // Exponential growth
                //  8                           4       * 2
                newCapacity = static_cast<int>(capacity * GrowthFactor);
            }
            else {
                // Linear growth
                newCapacity = capacity + LinearGrowthAmount;
            }
            std::unique_ptr<int[]> newArray = std::make_unique<int[]>(newCapacity);
            for (int i = 0; i < count; ++i) {
                newArray[i] = array[i];
            }
            array = std::move(newArray);
            capacity = newCapacity;
        }
    }

    void shrinkCapacity() {
        if (count < capacity / 4 && capacity > InitialCapacity) {
            int newCapacity = capacity / 2;
            if (newCapacity < InitialCapacity) {
                newCapacity = InitialCapacity;
            }
            std::unique_ptr<int[]> newArray = std::make_unique<int[]>(newCapacity);
            for (int i = 0; i < count; ++i) {
                newArray[i] = array[i];
            }
            array = std::move(newArray);
            capacity = newCapacity;
        }
    }

public:
    AdvancedDynamicArray(int initCapacity = InitialCapacity)
        : array(std::make_unique<int[]>(initCapacity)), count(0), capacity(initCapacity) {}

    AdvancedDynamicArray(int initCapacity = InitialCapacity, int threshold = LinearGrowthThreshold, int growbynumber = LinearGrowthAmount)
        : array(std::make_unique<int[]>(initCapacity)), count(0), capacity(initCapacity) {
    
    }

    int size() const {
        return count;
    }

    int getCapacity() const {
        return capacity;
    }

    int& operator[](int index) {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    void add(int item) {
        ensureCapacity(count + 1);

        // count  > 0 > index = 0
        //0 > 1

        array[count++] = item;
    }
    //5
    void insert(int index, int item) {
        if (index < 0 || index > count) {
            throw std::out_of_range("Index out of range");
        }
        ensureCapacity(count + 1);
        for (int i = count; i > index; --i) {
            array[i] = array[i - 1];
        }
        array[index] = item;
        ++count;
    }

    void removeAt(int index) {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = index; i < count - 1; ++i) {
            array[i] = array[i + 1];
        }
        array[--count] = 0; // Clear the last element
        shrinkCapacity();
    }

    void clear() {
        array = std::make_unique<int[]>(InitialCapacity);
        count = 0;
        capacity = InitialCapacity;
    }
};

int main() {
    try {
        AdvancedDynamicArray arr;

        arr.add(10);
        arr.add(20);
        arr.add(30);
        arr.insert(1, 15);
        arr.removeAt(2);

        for (int i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Current size: " << arr.size() << std::endl;
        std::cout << "Current capacity: " << arr.getCapacity() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
