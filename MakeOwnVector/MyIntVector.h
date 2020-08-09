#include <cstdlib>

class MyIntVector
{
private:
	int *data;
	int _capacity = 0;
	int _size = 0;

public:
	MyIntVector(size_t init_capacity = 1);
	~MyIntVector();
	MyIntVector(const MyIntVector& v);
	MyIntVector& operator =(const MyIntVector & v);
	void operator +=(const MyIntVector & addend);
	int& operator [](int i); // reference ∏Æ≈œ 
	MyIntVector operator +(const MyIntVector & num);
	MyIntVector operator -(const MyIntVector & num);
	MyIntVector operator *(const MyIntVector & num);
	bool operator ==(const MyIntVector & v);
	MyIntVector operator -();
	MyIntVector operator ()(int const &num);
	void pop_back();
	void push_back(int x);
	size_t capacity() const;
	size_t size() const;
	void reserve(size_t new_capacity);
	bool isEmpty() const;
	void clear();
};
