# Input output
- little i/o optimization
```cpp
// Unlink cpp cin/cout from C stdin/stdout
ios_base::sync_with_stdio(0);
// Disable automatic flushing of cout when doing ops on cin
cin.tie(0); 
```
- multi line input
```cpp
int n;
cin>>n;
while(n--){
	//read line data here
}
```
- multi line input with unknown number of lines
```cpp
string line;
while (getline(cin, line)) {
    // Process each line
}
int n;
while (cin >> n) {
    // keep reading ints until there are no more
}
```
- if we try to use `cin>>str` here, it will be required twice in case line is 'str_a str_b' because of a whitespace between strings.
- invalid input handling
```cpp
int n;
if (!(cin >> n)) {
    cout << "Invalid input!" << endl;
    return 0;
}
```
- some special cases
```cpp
//removes leading whitespace "\t #2 test" is printed as "#2 test"
cin>>std::ws;
//setting floating point precision of output
cout << fixed << setprecision(2) << x << endl;
```
- stringstreams to manipulate strings as streams
```cpp
string a = "1+2i", b = "1+3i";
istringstream sin_a(a), sin_b(b);
ostringstream out;

int ra, ia, rb, ib;
char buff;

//reading from  input stream
sin_a >> ra >> buff >> ia >> buff;
sin_b >> rb >> buff >> ib >> buff;
//writing to output stream
out << ra*rb-ia*ib << '+' << ra*ib+ia*rb << 'i';
//string_stream to string
string result = out.str() 
```


## GCC built-ins

```cpp
int  __builtin_popcount(unsigned int x)//returns number of 1's in x

int  __builtin_parity(unsigned int x)//parity = (number of 1's) % 2

int  __builtin_clz(unsigned int x) //count leading zeros(put l or ll for long)

int  __builtin_ctz(unsigned int x) //count trailing zeros

int  __builtin_ffs(int x) //least significant 1 bit position + 1
```

## Lambdas

```cpp
[scope](params){body}
//scope is either empty, &(by reference) or =(by value)

vector<int> map_arr(vector<int> arr, function<int(int)> f){
    vector<int> ret(arr.size());
    for(int i=0; i<arr.size(); i++)
        ret[i] = f(arr[i]);
    return ret;
}

vector<int> arr{1,2,3,4,5,6,7,8,9,10};
auto square_arr = map_arr(arr, [](int i) -> int { return i*i; });

//by reference scope
int a = 10;
auto modifierLambda = [&](){
     a = 11;
};

//by value scope
auto readOnlyLambda = [=](){
     cout<<a<<' ';
};
```

- structured bindings

```cpp
auto [var1, var2] = make_tuple(1,2);//tuples,pairs,structs etc.
```

- constexpr for computing at compile time

```cpp
constexpr int cube (int a){return a * a * a;}
float gk[cube(3)]; // Valid since cpp11: variable 'gk' has 27 elements
```

## Literals

```cpp
auto raw_string = R"(Raw String\nx)"//will print: Raw String\nx
auto binary_num = 0b11
auto hex_num = 0x11
```

## References
| l-value reference | can be initialized with | can modify |
| --|--| --|
| modifiable l-values | Yes | Yes |
| non-modifiable l-values | No | No |
| r-values | No | No |

| l-value reference to const | can be initialized with | can modify |
| --|--| --|
| modifiable l-values | Yes | Yes |
| non-modifiable l-values | Yes | No |
| r-values | Yes | No |

| r-value reference | can be initialized with | can modify |
| --|--| --|
| modifiable l-values | No | No |
| non-modifiable l-values | No | No |
| r-values | Yes | Yes |

| r-value reference to const | can be initialized with | can modify |
| --|--| --|
| modifiable l-values | No | No |
| non-modifiable l-values | No | No |
| r-values | Yes | No |

```cpp
int& ref = x; //l-value ref
const int ref = x;//l-value ref to const
int&& ref = x; //r-value ref
const int&& ref = x;//r-value ref to const

string& s1 = "sdad";//will give error
const string& s2 = "sdad";//valid
string&& s3 = "sdad";//valid
string another_str = "dasda";
const string& s4 = another_str;//valid

void foo(int&& x) {
    std::cout << "x: " << x << std::endl;
}
foo(10); //ok
foo(a); //compile-time error
foo(std::move(a));//to make above line work

int&& ref{ 5 };
fun(ref);//will call fun(const int&) , not  fun(int&&); int&& ref is an lvalue of type int&&
fun(5);//will call fun(int&&)

```

- reference value can be assigned only once
- pointer to void, and null as value of pointer variable is possible; this is not possible for references
- r-value references extend the lifespan of the object they are initialized with to the lifespan of the r-value reference (l-value references to const objects can do this too).
- `std::move` can be used to cast to r-value; When you see std::move, it indicates that the value of the object should not be used afterwards, but you can still assign a new value and continue using it.
- by `auto&& var = <initializer>` you are saying: I will accept any initializer regardless of whether it is an lvalue or rvalue expression and I will preserve its constness. a forwarding reference, `auto&&` or `T&&`, will bind to anything

# STL related things

```cpp
//other covered in array algorithm
reverse(arr_begin, arr_end);
//descending sort or any other custom logic
// first paramter LESS_THAN second parameter will sort in increasing order
sort(arr_begin, arr_end, [](int a, int b){return a>b;})	

//both lower bound and upper bound require sorted array
//iterator to first element greater than or equal to value or arr_end; >=
lower_bound(arr_begin, arr_end, value);	

//iterator to first element greater than value or arr_end; >
upper_bound(arr_begin, arr_end, value);	
A.erase(A.begin() + 5,A.end());
random_shuffle(arr_begin, arr_end);

//effectively appends B to A
A.insert(A.end(), B.begin(), B.end());
```

- char related functions

```cpp
islower, isupper, isalpha, isdigit, isalnum etc.
```

- stack, queue, deque and priority_queue

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

deque<char> s; 
push_back,pop_back,
push_front,pop_front,
front,back,empty
```

- map/set and their muli and unordered variants

```cpp
s.insert(3); 
s.find(3); 
s.erase(3); 
s.lower_bound(3); //etc.
```
