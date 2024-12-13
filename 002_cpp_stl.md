# Sequence containers:
- array :  static contiguous array
- vector : dynamic contiguous array
- deque : double-ended queue(just like vector but (i) efficient insertion/deletion in the front and (ii) not guaranteed to store all its elements in contiguous storage)
- forward_list : singly-linked list
- list : doubly-linked list
- here mostly vector, deque are of use. Rest are better done manually
- ``push_back()``, ``pop_back()``, ``insert(iterator, element)``, ``erase(iterator)``,  ``front()``, ``back()``, `clear()`, brace initialization(`vector<int>a{1,3,4}`), and init with size constrctor(`vector<char>a(5,'a')`), iterators(`begin` and `end`) and reverse iterators(`rbegin`, `rend`), index access(`vec[2]` or `deq[2]`) work on both deque and vector
-  ``push_front()``,``pop_front()`` only work with deque

<br/>

# Container adaptors
- have an underlying sequence container but iterface is different(like providing insert to the end only)
- `stack<T,deque<T>>`, `queue<T,deque<T>>`
- priority queue implements heap;  `priority_queue<T,vector<T>,less<T>>` where `less<T>` is equivalent to `bool f(T a, T b) { return a<b; }`. using `less<T>` will keep the first element greatest and `greater<T>` will keep first element smallest.
```cpp
stack/priority_queue<int> s;
s.push('a'); 
s.pop(); 
s.empty(); 
s.top();


queue<char> s; 
s.push('a'); 
s.pop(); 
s.empty(); 
s.front(); s.back();
```
# Associative containers
- `set`, `map`, `unordered_set`, `unordered_map` are useful ones, their keys are unique
- `.size()`, `empty()`, iterators(`begin()` and `end()`), `count(key)`, `find(key)`, `insert`, `erase` are available for all. reverse iterators, `lower_bound`, `upper_bound` are not available for unordered ones
- `set<T,less<T>,>`
- `map<K,V,less<K>>`
- `unordered_set<T,hash<T>,equal_to<T>>`(hash is used for positioning and equal_to for keeping only unique elements/keys in set)
- `unordered_set<K,V,hash<K>,equal_to<K>>`
- by default, set and map sort in increasing order(like 1,2,3,4)

# Useful Algorithms related functions

```cpp
reverse(arr_begin, arr_end);
// less(f(a,b)=a<b) will sort in increasing order
sort(arr_begin, arr_end, less<int>())	

//both lower bound and upper bound require sorted array
//basic lower bound is like first >= element and upper bound like > element

//first itr where compare_function(*itr,value) is false
lower_bound(arr_begin, arr_end, value, less<int>());	
//first itr where compare_function(value,*itr) is true
upper_bound(arr_begin, arr_end, value, less<int>());	

random_shuffle(arr_begin, arr_end);
```

- char related functions
```cpp
islower, isupper, isalpha, isdigit, isalnum etc.
```
