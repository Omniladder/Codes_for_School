// Specification file for the the IntegerList class.
#ifndef INTEGERLIST_H
#define INTEGERLIST_H

class IntegerList
{
  private:
    int *list;                 // Pointer to the array.
    int numElements;           // Number of elements.
    bool isValid(int) const;   // Validates subscripts.

  public:
    IntegerList(int);          // Constructor
    ~IntegerList();            // Destructor
    void setElement(int, int); // Sets an element to a value
    int getElement(int) const; // Returns an element
    void displayList() const;  // Display list
    IntegerList(const IntegerList &obj);
	const IntegerList operator=(const IntegerList &right);
	int& operator[](const int &sub);

  const IntegerList operator+(const IntegerList &right);
  void resize(int);
  const IntegerList sublist(int, int);
  const IntegerList sublist(int);
  const IntegerList sort();
};

#endif
