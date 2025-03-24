

[back](cpp05_00_learning.md) | [main](/) | [forward](cpp05_02_exceptions.md) >

---

# Nested Class

A nested class is a class that is defined within another class. The outer class is often referred to as the enclosing class, while the inner class is the nested class.

## Advantages
- **Logical Grouping:** When a class only makes sense in the context of another class or is only needed within that context.
- **Avoiding Name Collisions:** When a general name like `Node` is used.

### Example
```cpp
class LinkedList 
{
	public:
		class Node {};
};

class BinaryTree 
{
	public:
		class Node {};
};
```

## Example

```cpp
#include <iostream>
#include <string>

class Outer
{
	private:
		class InnerPrivate {
		public:
			void show() 
			{
				std::cout << "Inside the private nested class 'InnerPrivate'" << std::endl;
			}
		};

	public:
		class InnerPublic 
		{
			public:
				void show() 
				{
					std::cout << "Inside the public nested class 'InnerPublic'" << std::endl;
				}
				// Method that accesses the private InnerPrivate class through Outer
				void accessInnerPrivate(Outer& outerObj) 
				{
					outerObj.accessInnerPrivate(); // Call method of the outer class
				}
		};

		void show()
		{            
			std::cout << "Inside the public class 'Outer'" << std::endl; 
		}

		void accessInnerPrivate() 
		{
        	InnerPrivate obj1;
        	obj1.show(); 
    	}

};

int main() 
{
    // Outer::InnerPrivate obj1;  // Not allowed, since InnerPrivate is private
	Outer obi1;
    Outer::InnerPublic obj2;       // Allowed, since InnerPublic is public

	obi1.show();
	obi1.accessInnerPrivate();	
	obj2.show();
	obj2.accessInnerPrivate(obi1);	

    return 0;
}
```

