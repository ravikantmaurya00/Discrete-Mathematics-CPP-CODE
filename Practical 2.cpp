#include <iostream>

using namespace std;

class RELATION {
public:
  int n;
  int** relation;

  RELATION(int n) {
    this->n = n;
    relation = new int*[n];
    for (int i = 0; i < n; i++) {
      relation[i] = new int[n];
      for (int j = 0; j < n; j++) {
        relation[i][j] = 0;
      }
    }
  }

  void set(int i, int j, int value) {
    relation[i][j] = value;
  }

  bool isReflexive() {
    for (int i = 0; i < n; i++) {
      if (relation[i][i] == 0) {
        return false;
      }
    }
    return true;
  }

  bool isSymmetric() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (relation[i][j] == 1 && relation[j][i] == 0) {
          return false;
        }
      }
    }
    return true;
  }

  bool isTransitive() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (relation[i][j] == 1 && relation[j][k] == 1 && relation[i][k] == 0) {
            return false;
          }
        }
      }
    }
    return true;
  }

  bool isAntiSymmetric() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (relation[i][j] == 1 && relation[j][i] == 1 && i != j) {
          return false;
        }
      }
    }
    return true;
  }

  void print() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << relation[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  RELATION relation(4);
  relation.set(0, 0, 1);
  relation.set(0, 1, 1);
  relation.set(1, 0, 1);
  relation.set(1, 1, 1);
  relation.set(2, 2, 1);
  relation.print();

  cout << "Is reflexive: " << relation.isReflexive() << endl;
  cout << "Is symmetric: " << relation.isSymmetric() << endl;
  cout << "Is transitive: " << relation.isTransitive() << endl;
  cout << "Is anti-symmetric: " << relation.isAntiSymmetric() << endl;

  return 0;
}
