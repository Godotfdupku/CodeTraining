template <typename T>
class smart_ptrs {
public:
	smart_ptrs();
	smart_ptrs(T*);
	smart_ptrs(smart_ptrs&);

	T* operator->();
	T* operator*();
	smart_ptrs& operator=(smart_ptrs&);
	~smart_ptrs();

private:
	int* counter;
	T* pointer;
	void decrease();
	void increase();
};

template<typename T>
smart_ptrs<T>::smart_ptrs():counter(0), pointer(0){}

template<typename T>
smart_ptrs<T>::smart_ptrs(T* p):counter(new int(1)), pointer(p){}

template<typename T>
smart_ptrs<T>::smart_ptrs(smart_ptrs& sp):counter(&(++*sp.counter),pointer(sp.pointer){}

template<typename T>
T* smart_ptrs<T>::operator->() { return pointer; }

template<typename T>
T& smart_ptrs<T>::operator*() { return *pointer; }

template<typename T>
smart_ptrs<T>& smart_ptrs<T>::operator=(smart_ptrs& sp)
{
	if (this != sp)
	{
		decrease()
		pointer = sp.pointer;
		counter = sp.counter;
		sp.incease();
	}
	return *this;
}

template<typename T>
smart_ptrs<T>::~smart_ptrs(){ decrease(); }

template<typename T>
void smart_ptrs<T>::decrease()
{
	if (counter && --*counter == 0 )
	{
		delete pointer;
		delete counter;
		pointer = 0;
		counter = 0;
	}
}

template<typename T>
void smart_ptrs<T>::increase()
{
	if (counter){ ++*counter }
}

smart_ptrs<int> p1;  // thread 1
// ...
smart_ptrs<int> p2 = p1;

smart_ptrs<int> p3 = p2; // thread 2
atomic<int> counter
