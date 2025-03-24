#include "includes/MutantStack.hpp"


int test_subject()
{
    MutantStack<int>
    mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout<< "stack top " << mstack.top() << std::endl;
    mstack.pop();
    std::cout<< "stack top after pop " << mstack.top() << std::endl;
    std::cout << "stack size: "<< mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    // ++it;
    // ++it;
    // ++it;
    --it;
    while (it != ite)
    {
      std::cout << *it << std::endl;
      ++it;
    }

    std::cout << "-------------------Copie Constructor ------------------" << std::endl; 
    // copy constr
    std::stack<int> s(mstack);
    MutantStack<int>::iterator s_it = mstack.begin();
    MutantStack<int>::iterator s_ite = mstack.end();

    while (s_it != s_ite)
    {
      std::cout << *s_it << std::endl;
      ++s_it;
    }

    std::cout << "-------------------Copie Constructor 2 ------------------" << std::endl; 
    std::stack<int> c = s;
    MutantStack<int>::iterator c_it = mstack.begin();
    MutantStack<int>::iterator c_ite = mstack.end();

    while (c_it != c_ite)
    {
      std::cout << *c_it << std::endl;
      ++c_it;
    }
    return 0;
}


int test_stack_list()
{
  MutantStack<std::string, std::list<std::string> > st_lst;
  st_lst.printContainerType();

  std::cout <<  "Test empty Member" << std::endl;
  // Check empty member 
  if (st_lst.empty())
    std::cout <<  "Stack is empty!" << std::endl;
  
  st_lst.push("Guten ");
  st_lst.push("Morgen ");
  st_lst.push("es ");
  st_lst.push("ist ");
  st_lst.push("schon ");
  st_lst.push("9 Uhr ");
  
  std::cout <<  "Test size Member" << std::endl;
  std::cout <<  "Stack size: " << st_lst.size() << std::endl;
  
  MutantStack<std::string, std::list<std::string> >::iterator it = st_lst.begin();
  MutantStack<std::string, std::list<std::string> >::iterator ite = st_lst.end();

  std::cout << std::endl << "print list: " << std::endl;

  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }
  std::cout << std::endl;

  std::cout <<  "Test pop Member" << std::endl;
  std::cout <<  "top element befor pop: " << st_lst.top() << std::endl;
  st_lst.pop();
  std::cout <<  "top element after pop: " << st_lst.top() << std::endl;

  std::cout << std::endl << "print list: " << std::endl;
  it = st_lst.begin();
  ite = st_lst.end();
  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }
  std::cout << std::endl;

  return 0;
}

int test_stack_vector()
{
  MutantStack<std::string, std::vector<std::string> > st_vec;
  st_vec.printContainerType();

  std::cout <<  "Test empty Member" << std::endl;
  // Check empty member 
  if (st_vec.empty())
    std::cout <<  "Stack is empty!" << std::endl;
  
  st_vec.push("Guten ");
  st_vec.push("Morgen ");
  st_vec.push("es ");
  st_vec.push("ist ");
  st_vec.push("schon ");
  st_vec.push("9 Uhr ");
  
  std::cout <<  "Test size Member" << std::endl;
  std::cout <<  "Stack size: " << st_vec.size() << std::endl;
  
  MutantStack<std::string, std::vector<std::string> >::iterator it = st_vec.begin();
  MutantStack<std::string, std::vector<std::string> >::iterator ite = st_vec.end();

  std::cout << std::endl << "print vector: " << std::endl;

  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }
  std::cout << std::endl;

  std::cout <<  "Test pop Member" << std::endl;
  std::cout <<  "top element befor pop: " << st_vec.top() << std::endl;
  st_vec.pop();
  std::cout <<  "top element after pop: " << st_vec.top() << std::endl;

  std::cout << std::endl << "print vector: " << std::endl;
  it = st_vec.begin();
  ite = st_vec.end();
  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }
  std::cout << std::endl;

  return 0;
}

int main (void)
{
  test_subject();
  //test_stack_list();
  //test_stack_vector();
 
  return 0;
}

