# Concepts: `rvalue` and `lvalue`

## References
- Eli Bendersky: Understanding lvalues and rvalues in C and C++: http://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c
- http://en.cppreference.com/w/cpp/language/value_category
- http://stackoverflow.com/questions/3601602/what-are-rvalues-lvalues-xvalues-glvalues-and-prvalues
- http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2010/n3055.pdf
- Scott Meyers: Effective Modern C++
- Bo Qian: Advanced C++: Understanding rvalue and lvalue, https://www.youtube.com/watch?v=UTUdhjzws5g


## Definitions

**Simplified definition:**

`lvalue` - represents an object that occupies some identifiable location in memory (i.e. has an
address)
`rvalue` - any object that is not an `lvalue`

**Definition 2:**

In concept (though not always in practice),
- `rvalues`: correspond to temporary objects returned from functions
- `lvalues`: correspond to objects you can refer to, either by name or by following a pointer or
  `lvalue` reference

**Definition 3:**

`lvalue`: logical address value
`rvalue`: register value

**From the point of view of `move` semantics:**

`rvalues` indicate objects eligible for move operations, while `lvalues` generally don't.

**Useful heurestic:**
To determine whether an expression is an `lvalue` is to ask if you can take its address. If you
can, it typically is. If you can't it's usually an `rvalue`.

## `lvalue` and `rvalue` of type `T`

Given a type `T`, you can have `lvalues` of type `T` as well as `rvalues` of type `T`.  It's
important to remember this when dealing with a parameter of `rvalue` reference type, because the
parameter itself is an `lvalue`.

Below `rhs` is an `lvalue`, though it has an `rvalue` reference type:

~~~~
class Widget{
public:
	Widget(Widget&& rhs);
	...
};
~~~~

## Examples:

~~~~
int i;         // i is an `lvalue`
int *p = &i;   // i's address is identifiable
i = 2;         // memory content can be modified

class dog;
dog d1;       // `lvalue` of user defined type (class)
~~~~

~~~~
int x  = 2;       // 2 is an `rvalue`
int x  = i+2;     // (i+2) is an `rvalue`
int *p = &(i+1);  // Error
i+2    = 4;       // Error
2      = i;       // Error

dof d1;
d1 = dog();  // dog() is an `rvalue` of user defined type (class)

int sum(int x, int y) {return x+y;}
int i = sum(3,4);                   // sum(3,4) is an `rvalue`, it is a temporary value
~~~~

Summary:

`rvalues`: 2, i+2, dog(), sum(3,4), x+y
`lvalues`: x, i, d1, p


Not all assignments to results of function calls are invalid.
Below `foo` returns a reference to `globalvar` which is an `lvalue` so it can be assigned to.

~~~~
int globalvar = 20;

int &foo()
{
	return globalvar;
}

int main()
{
	foo() = 10;
	return 0
}
~~~~

Another example with overloaded operators. `std::map::operator[]` returns a reference (`lvalue`)
that can be assigned to.  

~~~~
std::map<int, float> mymap:
mymap[10] = 5.6;
~~~~

Not all `lvalues` can be assigned to:

~~~~
cosnt int a = 10;   // 'a' is an `lvalue`
a = 12;             // but it can't be assigned.
~~~~

## Conversions between `lvalues` and `rvalues`

~~~~
int a = 1;      // a is an `lvalue`
int b = 1;      // b is an `lvalue`
int c = a + b;  // + needs `rvalues`, so a and
~~~~
