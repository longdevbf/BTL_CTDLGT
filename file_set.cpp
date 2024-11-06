#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Set{
	private:
		T* data;
		int size;
		int capacity;
	public:
		class Iterator {
		    private:
		        T* ptr;
		    public:
		        Iterator(T* p = nullptr) : ptr(p) {}
		
		        T& operator*() { return *ptr; }
		        Iterator& operator++() { 
		            ptr++; 
		            return *this; 
		        }
		        bool operator!=(const Iterator& other) const {
		            return ptr != other.ptr;
		        }
		    };
		Set(int capacity = 100);
		~Set();
		void insert_set(T value);
		bool remove_set(T value);
		bool contains_set(T value);
		void display_set();
		void clear_set();
		
		Iterator begin() {
			return Iterator(data);
		}
		Iterator end(){
			return Iterator(data + size);
		}
		Iterator find(const T& value);
	    template<typename Predicate>
	    void remove_if(Predicate pred);
};
template<typename T>
Set<T>::Set(int cap) : size(0), capacity(cap){
	data = new T[capacity];
}
template<typename T>
Set<T>::~Set(){
	delete[] data;
}
template<typename T>
void Set<T>::insert_set(T value){
	if(contains_set(value)){
		return ;
	}
	if(!contains_set(value) && size < capacity ){
		data[size++] = value;
	}
	sort(data, data + size);
}
template<typename T>
bool Set<T>::remove_set(T value){
	for(int i = 0; i < size; i++){
		if(data[i] == value){
			for(int j = i; j < size; j++){
				
		
			data[j] = data[j + 1];
				}
				size --;
			return true;
		}
	}
	return false;
	
}
template<typename T>
bool Set<T>::contains_set(T value){
	for(int i = 0; i < size; i++){
		if(data[i] == value){
			return true;
		}
	}
	return false;
}
template<typename T>
	void Set<T>::clear_set(){
		size = 0;
	}
template<typename T>
void Set<T>::display_set(){
	for(int i = 0; i < size; i++){
		cout<<data[i]<<" ";
	}
}
template<typename T>
typename Set<T>::Iterator Set<T>::find(const T& value) {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return Iterator(data + i);
        }
    }
    return end();
}

template<typename T>
template<typename Predicate>
void Set<T>::remove_if(Predicate pred) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (!pred(data[i])) {
            data[newSize++] = data[i];
        }
    }
    size = newSize;
}
//int main(){
//	int n;
//	cin>>n;
//	Set<int> v(n);
//	for(int i = 0; i < n; i++){
//		int tmp;cin>>tmp;
//		v.insert_set(tmp);
//	}
////	v.display();
////	if(v.contains(3)){
////	
////	v.remove(3);}
////	cout<<endl;
////	v.display();
//auto it = v.begin();
//cout<<*it;
//auto x = v.find(3);
//if(x != v.end()){
//	cout<<"tim thay"<<endl;
//}
//else{
//	cout<<"Khong tim thay"<<endl;
//}
//v.remove_if([](int k) {
//	return k % 2 == 0;
//});
//v.display_set();
//	
//	
//}