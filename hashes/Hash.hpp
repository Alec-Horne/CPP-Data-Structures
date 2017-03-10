#ifndef HASHES_HPP
#define HASHES_HPP

#include <vector>

class Hash {
private:
  std::vector<int> table;

  int count = 0;
public:
  // insert into the hash
  bool insert(const int&);

  // check if full
  bool isFull() { return count == table.size(); }
  bool retrieve(int&);
  void display();
 
  Hash(const int&);
  ~Hash() {};
};

void Hash::display() {
  for (int i = 0; i < table.size(); ++i)
    std::cout << "[" << table[i] << "]";
  std::cout << std::endl;
}

Hash::Hash(const int& size) {
  table.resize(size);
  //  for(auto i : table)
  //  i = -1;

  for (int i = 0; i < table.size(); ++i)
    table[i] = -1;
}

bool Hash::insert(const int& t) {
  if (isFull())
    return false;

  // we need to check if the hashed key is available 
  // if not
  // probe until one is

  int index = t % table.size();
  
  while (table[index] != -1) {
    index = (++index % table.size());
  }

  table[index] = t;
  ++count;
  return true;
}

#endif
