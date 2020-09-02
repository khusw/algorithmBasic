/*
    기본 해시 테이블 구현

    해시 테이블에는 
    key, value, bucket, hash function 
    4가지 요소가 있어야 하며
    hash function 은 key 값을 hash 로 바꾸는 역할을 한다는 점에 유의한다 (value 가 아니라)

    아래의 예제는 10칸짜리 배열이 있고 
    그 배열 안에 숫자를 어떻게 넣어서 매칭할것인지에 대한 내용이다.
*/

#include <bits/stdc++.h>

using namespace std;

template <typename K, typename V>

class HashNode {
   public:
    V value;
    K key;

    HashNode(K key, V value) {
        this->value = value;
        this->key = key;
    }
};

template <typename K, typename V>

class HashMap {
    HashNode<K, V> **arr;
    int capacity;
    int size;
    HashNode<K, V> *dummy;

   public:
    HashMap() {
        capacity = 20;
        size = 0;
        arr = new HashNode<K, V> *[capacity];

        for (int i = 0; i < capacity; i++) {
            arr[i] = NULL;
        }

        dummy = new HashNode<K, V>(-1, -1);
    }

    int hashCode(K key) {
        return key % capacity;
    }

    void insertNode(K key, V value) {
        HashNode<K, V> *temp = new HashNode<K, V>(key, value);

        int hashIndex = hashCode(key);

        while (arr[hashIndex] != NULL && arr[hashIndex]->key != key && arr[hashIndex]->key != -1) {
            hashIndex++;
            hashIndex %= capacity;
        }

        if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1) {
            size++;
        }
        arr[hashIndex] = temp;
    }

    V deleteNode(int key) {
        int hashIndex = hashCode(key);

        while (arr[hashIndex] != NULL) {
            if (arr[hashIndex]->key == key) {
                HashNode<K, V> *temp = arr[hashIndex];
                arr[hashIndex] = dummy;
                size--;
                return temp->value;
            }
            hashIndex++;
            hashIndex %= capacity;
        }
        return NULL;
    }

    V get(int key) {
        int hashIndex = hashCode(key);
        int counter = 0;
        while (arr[hashIndex] != NULL) {
            int counter = 0;
            if (counter++ > capacity) {
                return NULL;
            }
            if (arr[hashIndex]->key == key) {
                return arr[hashIndex]->value;
            }
            hashIndex++;
            hashIndex %= capacity;
        }
        return NULL;
    }

    int sizeOfMap() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            if (arr[i] != NULL && arr[i]->key != -1) {
                cout << "key = " << arr[i]->key << " value = " << arr[i]->value << '\n';
            }
        }
    }
};

int main() {
    HashMap<int, int> *h = new HashMap<int, int>;
    h->insertNode(1, 1);
    h->insertNode(2, 2);
    h->insertNode(2, 3);
    h->display();
    cout << h->sizeOfMap() << '\n';
    cout << h->deleteNode(2) << '\n';
    cout << h->sizeOfMap() << '\n';
    cout << h->isEmpty() << '\n';
    cout << h->get(2) << '\n';

    return 0;
}