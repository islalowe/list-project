#include "object.h"
#include "list.h"
#include "vsarray.h"
#include "sstream"

// Implement ALL methods of VSArray class

/**
 * Constructor with capacity
 * Given a capacity the constructor allocates an array to Object*
 * this array will later hold pointers to the actual elements
 * that are being inserted into the list. The constructor also initializes
 * the elements of the array to nullptr
 * @param capacity the number of elements that the list is able to hold
 */
VSArray::VSArray(size_t capacity, double increasePercentage) {
    _capacity = capacity;
    double increaseAmount = _capacity * (increasePercentage / 100);
    _capacity += increaseAmount;
    _data = new Object*[_capacity];
    for (size_t i = 0; i < _capacity; i++) {
        _data[i] = nullptr;
    }
}

/**
 * Destructor
 * It frees the dynamic memory allocated for the list, it does so in
 * two steps:
 * 1. Traverses the list and releases the memory of each element. This in
 *    turn will call the destructor of each of the elements.
 * 2. Once the elements have been freed, then the array memory is released.
 */
VSArray::~VSArray() {
    // Step 1
    for (size_t i = 0; i < _size; i++) {
        delete _data[i];
    }
    // Step 2
    delete[] _data;
}

/**
 * Inserts an element into a given position.
 * This operation has the following steps:
 * 1. Check if the position is valid
 * 2. Check if there is enough space
 * 3. If the position is not the last, it needs to push the elements
 * 4. Insert the element in the given position
 * 5. Increase the size
 * @param element what the client wants to insert into the list
 * @param position the position where the element is to be inserted
 * @return true if it was possible to insert, false otherwise. It will not be able
 * to insert if the position is invalid or if the list is full.
 */
bool VSArray::Insert(Object* element, size_t position) {
    // Check if the position is valid
    if (position > _size) {
        return false;
    }
    // Check if there is enough space
    if (_size >= _capacity) {
        // Perform resizing if needed
        Object** newData = new Object*[_capacity, 100];
        // Copy existing elements to the new array
        for (size_t i = 0; i < _size; i++) {
            newData[i] = _data[i];
        }
        // Delete the old array and update pointers
        delete[] _data;
        _data = newData;
    }

    // Shift elements to the right
    for (size_t i = _size; i > position; i--) {
        _data[i] = _data[i - 1];
    }
    // Insert the new element
    _data[position] = element;
    _size++;
    return true;
}

/**
 * Searches for the position of an element in the list.
 * The method performs a linear search on the array for the given element.
 * If the element is found it returns the position, if it is not found it
 * returns -1.
 * @param element the object that the client is searching for.
 * @return the position of the element if found, -1 otherwise.
 */
int VSArray::IndexOf(const Object* element)const {
    for (size_t i = 0; i < _size; i++) {
        if (_data[i]->Equals(*element)){
            return i;
        }
    }
    return -1;
}

/**
 * Removes the element at position, when the position is valid. It returns
 * the pointer to the removed element. After removing the element, the rest of
 * the elements in the list will be pushed to cover the empty space, unless
 * the removed element is the last, in which case is just set to nullptr.
 * @param position the position of the element to be removed.
 * @return the pointer to the object in that position if the position was valid,
 * nullptr otherwise
 */
Object* VSArray::Remove(size_t position) {
    if (position >= _size){
        return nullptr;
    }
    Object* retVal = _data[position];
    //all of the elements after the removed one are scooting back one index
    for (size_t i = position; i < _size - 1; i++) {
        _data[i] = _data[i + 1];
    }
    _size--;
    return retVal;
}

/**
 * Element Access
 * Returns the element at a given position.
 * @param position the position of the element to retrieve.
 * @return a pointer to the element if the position is valid, nullptr otherwise
 */
Object* VSArray::Get(size_t position) const {
    if (position >= _size)
        return nullptr;
    else
        return _data[position];
}

/**
 * Creates a string representation of the list. This representation
 * will be the string representation of each of the elements, surrounding
 * the whole list with curly braces and separating the elements by comma.
 * Example: {2, 6, 8}
 * @return a string representation of the list
 */
string VSArray::ToString() const {
    std::stringstream retVal;
    retVal << "{";
    for (size_t i = 0; i < _size - 1; i++) {
        retVal << _data[i]->ToString() << ", ";
    }
    retVal << _data[_size - 1]->ToString() << "}";
    return retVal.str();
}

/**
 * Very similar to the destructor, this method releases all the elements
 * of the list, but it does not release the array to hold elements. It also
 * sets the size to zero. This method makes the list become empty.
 */
void VSArray::Clear() {
    for (size_t i = 0; i < _size; i++) {
        delete _data[i];
        _data[i] = nullptr;
    }
    _size = 0;
}

/**
 * Capacity accessor
 * @return the number of elements the list is able to hold
 */
size_t VSArray::GetCapacity() const {
    return _capacity;
}