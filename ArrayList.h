#include <iostream>
using namespace std;

template <typename type>
struct ArrayList {
    type* array = new type[5];
    int nextIndex = 0;
    int length = 5;

    bool add(type element) {
        if (nextIndex >= length){
            type* newArr = new type[length+5];
            for (int i = 0; i < length; ++i)
                newArr[i] = array[i];
            delete[] array;
            array = newArr;
            length += 5;
        }
        array[nextIndex] = element;
        nextIndex++;
        return true;
    }

    bool insert(type element, int index){
        if (index < 0)
            return false;
        if (index >= length){
            int dist = index-length;
            dist++;
            type* newArr = new type[length+dist];
            for (int i = 0; i < length; ++i)
                newArr[i] = array[i];
            delete[] array;
            array = newArr;
            length += dist;
        }
        array[index] = element;
        return true;
    }

    type get(int index){
        if (length <= index || index < 0)
            return nullptr;
        return array[index];
    }

    bool remove(int index){
        if (index < 0 || index >= length)
            return false;
        type* newArr = new type[length-1];
        for (int i = 0; i < index; ++i) {
            newArr[i] = array[i];
        }
        for (int i = index; i < length-1; ++i) {
            newArr[i] = array[i+1];
        }
        delete[] array;
        array = newArr;
        length--;
        return true;
    }

    bool find(type element){
        for (int i = 0; i < length; ++i) {
            if (element == array[i])
                return true;
        }
        return false;
    }

    int size(){
        return length;
    }

    string toString(){
        string str = "[";
        for (int i = 0; i < length; ++i) {
            if (i+1 == length)
                str += array[i]+"]";
            else
                str += array[i]+", ";
        }
        return str;
    }
};