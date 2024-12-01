# Classes

- classes are user defined data type

```c
class Fruit {
  //by default private
  string name;
  string color;
};
```

```c++
class Fruit {
public:
  string name;
  string color;
};
```

<br>
<br>

# Objects

- objects are variables of type class

## Accessing variables of a class

```c++
int main() {
  Fruit apple;

  // Only accessible like this if they are public vars
  apple.name = "Apple";
  apple.color = "Red";
}
```

## Accessing variables using pointer

```c++
int main() {

  Fruit *mango = new Fruit();

  // Have to use arrow-> for object pointers
  mango->name = "Mango";
  mango->color = "Yellow";
}
```

<br>
<br>
<br>

# Constructor

- used to initialize an object
- This function is called when an object is created
- Have the same name as class name

### Constructor Types:

1. Default Constructor
2. Parameterized Constructor
3. Copy Constructor

```c++
class Rectangle {
public:
  int l;
  int b;

  // Default Constr.  - No arguments passed
  Rectangle() {
    l = 0;
    b = 0;
  }

  // Parameterised - arguments passed
  Rectangle(int x, int y) {
    l = x;
    b = y;
  }

  // Copy Constructor - Initialize an obj by another existing obj
  Rectangle(Rectangle& r){
    l = r.l;
    b = r.b;
  }
};

int main() {
  Rectangle r1;
  cout<<r1.l<<" "r1.b<<endl;

  Rectangle r2(3, 4);
  cout<<r2.l<<" "r2.b<<endl;

  Rectangle r3 = r2; // copying r2 into r3
  cout<<r3.l<<" "r3.b<<endl;
}
```

# Destructors

- Is a function called when an object is deleted
- Parameters can not be passed
- name: `~(class_name)`

```c++
class Rectangle {
public:
  int l;
  int b;
  Rectangle() {
    l = 0;
    b = 0;
  }
  Rectangle(int x, int y) {
    l = x;
    b = y;
  }
  Rectangle(Rectangle& r){
    l = r.l;
    b = r.b;
  }
  ~Rectangle() {
    cout<<"Destructor is called";
  }
};

int main() {
  Rectangle* r1 = new Rectangle();
  cout<<r1->l<<" "r1->b<<endl;
  delete r1;
  //destructor called here

  Rectangle r2(3, 4);
  cout<<r2.l<<" "r2.b<<endl;

  Rectangle r3 = r2;
  cout<<r3.l<<" "r3.b<<endl;

  return 0;
  // destructor called here for r2 and r3 as fun ended
}
```

<br>
<br>
<br>
<br>

# Encapsulation:

- Binding of methods and variables together.
- Data is only accessible from the class methods.
- Also leads to **_data abstraction_**.
  > Thats why classes are also called **_ADT (Abstract Data Type)_**

```c++
class ABC {
  // private by default
  int x;

  public:
    void set(int n) {
      x = n;
    }

    int get() {
      return x;
    }

int main() {
  ABC obj1;

  obj1.set(4);
  cout<<obj1.get()<<endl;
}
};

```

<br>
<br>
<br>

# Abstraction:

- Enables us to display only essential information.
- Implementation details are hidden from Us

<br>
<br>
<br>

# Inheritance:

- A class inherits the properties of another class.
- Inherited class is called - Parent/Super class
- Inheriting class is called - Child/Sub class.

### Access specifiers:

1.  Public ( Data and methods accessible from anywhere of the code )
2.  Private ( Data and methods accessible from **_Own_**, **_Parent_** & **_Child_** Classes )
3.  Protected ( Accessible only in **_Own_** class )

```c++
class Parent {
public:
  int x;

protected:
  int y;

private:
  int z;
};

// publicly inherited
class Child1: public Parent {
// x will remain public
// y will remain protected
// z will not be accessible
};

class Child2: private Parent {
// x will be private
// y will be private
// z will not be accessible
};

class Child3: protected Parent {
// x will be protected
// y will be protected
// z will be inaccessible
};

int main() {
  Parent p;
  p.x = 4;


}
```

<br>
<br>

### Inheritance Types:

**1. Single Inheritance**

- Class A inherits class B

```c++
class Parent{
public:
  Parent(){
    cout<<"Parent Class"<<endl;
  }
};

class Child: public Parent{
public:
  Child(){
    cout<<"Child Class"<<endl;
  }
};

int main() {
  Child c;

  return 0;
}
```

Output:

```bash
Parent Class
Child Class
```

**2. Multi-level Inheritance:**

- Class B inherits class A, Class C inherits Class B

```c++
class Parent{
public:
  Parent(){
    cout<<"Parent Class"<<endl;
  }
};

class Child: public Parent{
public:
  Child(){
    cout<<"Child Class"<<endl;
  }
};

class GrandChild: public Child{
  public:
  GrandChild(){
    cout<<"GrandChild Class"<<endl;
  }
};

int main() {
  GrandChild gc;

  return 0;
}
```

Output:

```bash
Parent Class
Child Class
GrandChild Class
```

**3. Multiple Inheritance:**

- Class C inherits Class A and Class B

```c++
class Parent1{
public:
  Parent1(){
    cout<<"Parent1 Class"<<endl;
  }
};

class Parent2{
public:
  Parent2(){
    cout<<"Parent2 Class"<<endl;
  }
};

class Child: public Parent1, public Parent2{
  public:
  Child(){
    cout<<"Child Class"<<endl;
  }
};

int main() {
  Child c;

  return 0;
}
```

Output:

```bash
Parent1 Class
Parent2 Class
Child Class
```

**4. Hierarchical Inheritance:**

- Multiple child class inherits a single class.

```c++
class Parent{
public:
  Parent(){
    cout<<"Parent Class"<<endl;
  }
};

class Child1: public Parent{
public:
  Child1(){
    cout<<"Child1 Class"<<endl;
  }
};

class Child2: public Parent1{
  public:
  Child2(){
    cout<<"Child2 Class"<<endl;
  }
};
```

**5. Hierarchical Inheritance:**

- Combination of multiple inheritance types.

```c++
/*
           Class-A
           /      \
          /        \
      Class-B    Class-C
                  |
                Class-D
*/
```

<br>
<br>

## Diamond Problem:

> Base class has multiple parent classes having a common ancestor.

```c++
/*
         Class-F
         /      \
        /        \
   Class-D      Class-E
      |            |
   Class-B      Class-C
       \          /
        \        /
         Class-A
*/
```

Output:

```bash
ClassF
ClassD
classB

ClassF
ClassE
classC

ClassA
```

<br>
<br>
<br>
<br>

# Polymorphism:

- Ability of objects/methods to take different forms.

### Two Types of Polymorphism:

1. Compile time
   - Function Overloading.
   - Operator Overloading.
2. Runtime

# Function Overloading (Compile time):

- Different functions with same function name.
- Functions Decided through:
  1. **How many** arguments passed.
  2. **Type** of the arguments.

```c++
class Sum{
public:

  void add(int x, int y) {
    int sum = x + y;
    cout<<sum<<endl;
  }

  void add(int x, int y, int z) {
    int sum = x + y + z;
    cout<<sum<<endl;
  }

  void add(float x, float y) {
    float sum = x + y;
    cout<<sum<<endl;
  }
};

int main() {
  Sum s;

  s.add(3, 4);
  s.add(3, 4, 5);
  s.add(2.5, 3.4);
}
```

<br>

## Operator Overloading:

```c++
class Complex{

public:
  int real;
  int imaginary;

  Complex(int x, int y){
    real = x;
    imaginary = y;
  }

  // Here Complex is the return type
  // c is an object passed
  // operator<op> - here op = +, -, *, / which we wanna overload
  Complex operator +(Complex &c){
    Complex ans(0, 0);
    ans.real = real + c.real; // real is real part of c1
    ans.imaginary = imaginary + c.imaginary; // imaginary is img. part of c2
    return ans;
  }
}

int main() {
  Complex c1(1, 2);
  Complex c2(1, 3);

  Complex c3 = c1 + c2; // compiler sees: c3 = c1.add(c2);
  cout<<c3.real<<" + "c3.imaginary<<"i"<<endl;
  return 0;
}
```

<br>
<br>
<br>

# Runtime Polymorphism: (Function Overriding)

- resolved at runtime

### Function overriding:

> When a child class defines a function of parent class.

```c++
class Parent{

public:
  // virtual keyword is for function overriding.
  // now it will be decided at runtime which fun to be called.
  virtual void print(){
    cout<<"Parent Class print."<<endl;
  }

  void show() {
    cout<<"Parent Class show."<<endl;
  }
};

class Child: public Parent{
public:
  void print(){
    cout<<"Child Class print."<<endl;
  }

  void show() {
    cout<<"Child Class show."<<endl;
  }
}

int main() {
  Parent *p;
  Child c;

  p = &c; // we are assigning child class to p at runtime.
  p->print();
  p->show();

  return 0;
}
```

Output:
```bash
Child Class print.
Parent Class show.
```
> `Parent class show.` because it was not virtual.



# Friend Function:
  - A non-member function that can access the private memebers of the class.

```c++
class A{
  int x;
public:
  A(int y){
    x = y;
  }

  friend void print(A &obj);
};

void print(A &obj){
  cout<<obj.x<<endl;
}

int main(){
  A a(5);
  print(a);
}
```