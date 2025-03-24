< [back](cpp08_01_00_Container_Sequenziell.md) | [main](/) | [forward](cpp08_03_Container_unsort.md) >

---

# Associative Containers 

## std::set
- Storage in sorted order -> Binary search structure (Red-Black Tree)
- No duplicates allowed 
- Search, insertion, and deletion operations take `O(log(n))`

### Advantages 
- Suitable for unique numbers as well as set operations 
- Efficient searching 

### Disadvantages
- No access to elements via **index**
- Higher memory usage than `vector`

## std::multiset
- Same as `set`, but duplicates are allowed

### Advantages 
- Duplicates are allowed 

### Disadvantages 
- No unique storage 

## std::map
- Sorted in a tree structure like `set` 
- There is a key 
- A unique key value 

### Advantages 
- Keys are automatically sorted 
- No duplicates 
- Logarithmic time complexity `O(log(n))` for searches

### Disadvantages 
- High memory consumption and overhead
- Slow insertion operations 

## std::multimap
- Similar to `map`, but duplicates are allowed. 

### Advantages 
- Duplicates are allowed 

### Disadvantages 
- Greater overhead 

---
![Overview](../pic/assoziativ_containers.png)
