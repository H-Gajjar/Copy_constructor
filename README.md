# Copy_constructor

Copy constructor is a constructor used to create a new object as a copy of existing object.

## When copy constructor is called ?
Copy constructor called when we create a new object from existing object. For Example,
```
{
    A a;  // Default constructor called!
    A b = a; //Copy constructor called! As b is uninitialized and new object;
    A c;
    c = b; // No copy constructor called because  c & b both are already initialized.
    A d(c); //Explicit call of the copy constructor.
 }
 ```
Compiler defines the default copy constructor in each class. However, copy constructor define by
compile may not sufficient/useful in some scenario. For example, Class A & B both are
different classes and want to create object of class B from Class A object.
 
```
{
  A a
  B b = a; // here default copy constructor will not work, we have to rewrite copy constructor.
}
```
