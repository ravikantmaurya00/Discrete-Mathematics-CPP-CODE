#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Set {
private:
    std::vector<int> elements;
public:
    bool isMember(int element) {
        for (int i = 0; i < elements.size(); ++i) {
            if (elements[i] == element) {
                return true;
            }
        }
        return false;
    }

    vector<vector<int>> powerSet() {
        vector<vector<int>> result;
        int setSize = elements.size();
        int powerSetSize = pow(2, setSize);

        for (int i = 0; i < powerSetSize; ++i) {
            vector<int> subset;
            for (int j = 0; j < setSize; ++j) {
                if ((i & (1 << j)) != 0) {
                    subset.push_back(elements[j]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }

    bool isSubset(Set otherSet) {
        for (int i = 0; i < otherSet.elements.size(); ++i) {
            if (!isMember(otherSet.elements[i])) {
                return false;
            }
        }
        return true;
    }

    Set setUnion(Set otherSet) {
        Set resultSet;
        resultSet.elements = elements;

        for (int i = 0; i < otherSet.elements.size(); ++i) {
            if (!resultSet.isMember(otherSet.elements[i])) {
                resultSet.elements.push_back(otherSet.elements[i]);
            }
        }
        return resultSet;
    }

    Set intersection(Set otherSet) {
        Set resultSet;
        for (int i = 0; i < elements.size(); ++i) {
            if (otherSet.isMember(elements[i])) {
                resultSet.elements.push_back(elements[i]);
            }
        }
        return resultSet;
    }

    Set complement(vector<int> universalSet) {
        Set resultSet;
        for (int i = 0; i < universalSet.size(); ++i) {
            if (!isMember(universalSet[i])) {
                resultSet.elements.push_back(universalSet[i]);
            }
        }
        return resultSet;
    }

    Set setDifference(Set otherSet) {
        Set resultSet;
        for (int i = 0; i < elements.size(); ++i) {
            if (!otherSet.isMember(elements[i])) {
                resultSet.elements.push_back(elements[i]);
            }
        }
        return resultSet;
    }

    Set symmetricDifference(Set otherSet) {
        Set resultSet;
        Set unionSet = setUnion(otherSet);
        Set intersectionSet = intersection(otherSet);

        resultSet = unionSet.setDifference(intersectionSet);
        return resultSet;
    }

    vector<pair<int, int>> cartesianProduct(Set otherSet) {
        vector<pair<int, int>> result;
        for (int i = 0; i < elements.size(); ++i) {
            for (int j = 0; j < otherSet.elements.size(); ++j) {
                result.push_back(make_pair(elements[i], otherSet.elements[j]));
            }
        }
        return result;
    }

    void addElement(int element) {
        if (!isMember(element)) {
            elements.push_back(element);
        }
    }

    void displaySet() {
        cout << "{ ";
        for (int i = 0; i < elements.size(); ++i) {
            cout << elements[i] << " ";
        }
        cout << "}" << endl;
    }
};

int main() {
    Set set1, set2;
    vector<int> universalSet;

    universalSet = {1, 2, 3, 4, 5};

    int choice, element;
    do {
        cout << "---------- Menu ----------" << endl;
        cout << "1. Add element to set" << endl;
        cout << "2. Check if an element is a member" << endl;
        cout << "3. Compute power set" << endl;
        cout << "4. Check if one set is a subset of the other" << endl;
        cout << "5. Compute union of two sets" << endl;
        cout << "6. Compute intersection of two sets" << endl;
        cout << "7. Compute complement of the set" << endl;
        cout << "8. Compute set difference between two sets" << endl;
        cout << "9. Compute symmetric difference between two sets" << endl;
        cout << "10. Compute cartesian product of two sets" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to add: ";
                cin >> element;
                set1.addElement(element);
                break;
            case 2:
                cout << "Enter the element to check: ";
                cin >> element;
                if (set1.isMember(element)) {
                    cout << element << " belongs to the set." << endl;
                } else {
                    cout << element << " does not belong to the set." << endl;
                }
                break;
            case 3:
                cout << "Power set: " << endl;
                vector<vector<int>> powerSet = set1.powerSet();
                for (int i = 0; i < powerSet.size(); ++i) {
                    cout << "{ ";
                    for (int j = 0; j < powerSet[i].size(); ++j) {
                        cout << powerSet[i][j] << " ";
                    }
                    cout << "}" << endl;
                }
                break;
            case 4:
                cout << "Enter the elements of the second set (-1 to stop): ";
                while (true) {
                    cin >> element;
                    if (element == -1) {
                        break;
                    }
                    set2.addElement(element);
                }
                if (set1.isSubset(set2)) {
                    cout << "Set 1 is a subset of Set 2." << endl;
                } else {
                    cout << "Set 1 is not a subset of Set 2." << endl;
                }
                break;
            case 5:
                cout << "Enter the elements of the second set (-1 to stop): ";
                while (true) {
                    cin >> element;
                    if (element == -1) {
                        break;
                    }
                    set2.addElement(element);
                }
                Set unionSet = set1.setUnion(set2);
                cout << "Union of Set 1 and Set 2: ";
                unionSet.displaySet();
                break;
            case 6:
                cout << "Enter the elements of the second set (-1 to stop): ";
                while (true) {
                    cin >> element;
                    if (element == -1) {
                        break;
                    }
                    set2.addElement(element);
                }
                Set intersectionSet = set1.intersection(set2);
                cout << "Intersection of Set 1 and Set 2: ";
                intersectionSet.displaySet();
                break;
            case 7:
                Set complementSet = set1.complement(universalSet);
                cout << "Complement of Set 1: ";
                complementSet.displaySet();
                break;
            case 8:
                cout << "Enter the elements of the second set (-1 to stop): ";
                while (true) {
                    cin >> element;
                    if (element == -1) {
                        break;
                    }
                    set2.addElement(element);
                }
                Set differenceSet = set1.setDifference(set2);
                cout << "Set difference of Set 1 and Set 2: ";
                differenceSet.displaySet();
                break;
            case 9:
                cout << "Enter the elements of the second set (-1 to stop): ";
                while (true) {
                    cin >> element;
                    if (element == -1) {
                        break;
                    }
                    set2.addElement(element);
                }
                Set symmetricDifferenceSet = set1.symmetricDifference(set2);
                cout << "Symmetric difference of Set 1 and Set 2: ";
                symmetricDifferenceSet.displaySet();
                break;
            case 10:
                cout << "Enter the elements of the second set (-1 to stop): ";
                while (true) {
                    cin >> element;
                    if (element == -1) {
                        break;
                    }
                    set2.addElement(element);
                }
                vector<pair<int, int>> product = set1.cartesianProduct(set2);
                cout << "Cartesian product of Set 1 and Set 2: ";
                for (int i = 0; i < product.size(); ++i) {
                    cout << "(" << product[i].first << ", " << product[i].second << ") ";
                }
                cout << endl;
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}


