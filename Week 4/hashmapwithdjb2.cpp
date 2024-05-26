#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <string>

// Define the hash map class
class HashMap {
private:
    // Each bucket contains a list of key-value pairs
    std::vector<std::list<std::pair<int, int>>> buckets;
    int numBuckets;
    int size;

    // DJB2 hash function
    int hashFunction(int key) {
        unsigned long hash = 5381;
        hash = ((hash << 5) + hash) + key; // hash * 33 + key
        return hash % numBuckets;
    }

public:
    HashMap(int numBuckets) : numBuckets(numBuckets), size(0) {
        buckets.resize(numBuckets);
    }

    void put(int key, int value) {
        int bucketIndex = hashFunction(key);
        auto& bucket = buckets[bucketIndex];

        for (auto& pair : bucket) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }

        bucket.emplace_back(key, value);
        size++;
    }

    bool get(int key, int& value) {
        int bucketIndex = hashFunction(key);
        auto& bucket = buckets[bucketIndex];

        for (const auto& pair : bucket) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }

        return false;
    }

    bool remove(int key) {
        int bucketIndex = hashFunction(key);
        auto& bucket = buckets[bucketIndex];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                size--;
                return true;
            }
        }

        return false;
    }

    int getSize() const {
        return size;
    }
};

// Driver code to test the HashMap
int main() {
    HashMap hashMap(10);

    // Insert key-value pairs
    hashMap.put(1, 100);
    hashMap.put(2, 200);
    hashMap.put(3, 300);
    hashMap.put(4, 400);

    // Retrieve values
    int value;
    if (hashMap.get(1, value)) {
        std::cout << "Key 1 has value " << value << std::endl;
    }
    else {
        std::cout << "Key 1 not found" << std::endl;
    }

    if (hashMap.get(2, value)) {
        std::cout << "Key 2 has value " << value << std::endl;
    }
    else {
        std::cout << "Key 2 not found" << std::endl;
    }

    if (hashMap.get(3, value)) {
        std::cout << "Key 3 has value " << value << std::endl;
    }
    else {
        std::cout << "Key 3 not found" << std::endl;
    }

    if (hashMap.get(5, value)) {
        std::cout << "Key 5 has value " << value << std::endl;
    }
    else {
        std::cout << "Key 5 not found" << std::endl;
    }

    // Remove a key-value pair
    if (hashMap.remove(2)) {
        std::cout << "Key 2 removed" << std::endl;
    }
    else {
        std::cout << "Key 2 not found" << std::endl;
    }

    if (hashMap.get(2, value)) {
        std::cout << "Key 2 has value " << value << std::endl;
    }
    else {
        std::cout << "Key 2 not found" << std::endl;
    }

    // Print the size of the hash map
    std::cout << "Size of the hash map: " << hashMap.getSize() << std::endl;

    return 0;
}
