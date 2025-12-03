#include <cstring>
#include <iostream>

class Vector {
public:
  Vector(int n) : siz(n), count(0), data(new int[siz]){};
  int &operator[](int index) { return data[index]; };

  void push_back(int i) {
    if (count >= siz) {
      siz *= 2;
      int *dest[siz];
      memcpy(dest, data, siz);
    }
    count++;
    data[count] = i;
  }


  int at(int i) {
    if(i > count || i < 0) {
      return -1;
    }
    return data[i];
  }

  int erase(int i) {
    if(i > count || i < 0) {
      return -1;
    }

    //shift array
    for (int j = i; j < count; ++j) {
      data[j] = data[j + 1];
    }

    count--;
    return 0;
  }
  
  int capacity() { return siz; }
  int size() { return count; }

private:
  int siz;
  int count;
  int *data;
  const float WEIGHT{0.75};
};

int main() {
  Vector *v = new Vector(2);
  for (int i = 0; i < 10; i++) {
    v->push_back(i + 1);
    std::cout << "Capacity: " << v->capacity() << std::endl;
    std::cout << "Item count: " << v->size() << std::endl;
    std::cout << "-------------------\n" << std::endl;
  }

  std::cout << "Item at index (0): " << v->at(0) << std::endl;
  std::cout << "Item at index (6): " << v->at(6) << std::endl;
  std::cout << "Item at index (10): " << v->at(10) << std::endl;
  std::cout << "Item out of bounds: " << v->at(11) << std::endl;

    std::cout << "-------------------\n" << std::endl;
  v->erase(0);
  std::cout << "Item count after erase (0): " << v->size() << std::endl;
  std::cout << "Item at index (0): " << v->at(0) << std::endl;
  std::cout << "Item at index (6): " << v->at(6) << std::endl;
  std::cout << "Item at index (10): " << v->at(10) << std::endl;

  return 0;
}
