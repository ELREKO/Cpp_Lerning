--- 
[main](/) 

---

# Ford-Johnson algoritm 

The `Ford-Johnson algorithm`, also known as `Merge-Insertion Sort`, is an efficient comparison-based sorting algorithm developed in 1959 by L. R. Ford Jr. and Selmer M. Johnson. It is notable for achieving an optimal number of comparisons when sorting a list.
Key Features of the Ford-Johnson Algorithm (Merge-Insertion Sort)

## Purpose: Minimizes the number of comparisons required for sorting.

   ### Complexity:

- **Best-case:** `O(nlog⁡n)` 
- **Worst-case:** `O(nlog⁡n)`, but with a lower constant factor compared to other sorting algorithms like Quicksort or Merge Sort.
- **Exact number of comparisons:** Approaches the theoretical lower bound `log ⁡n!` given by the decision-tree model for comparison sorting.

**Advantage:** Uses fewer comparisons than traditional sorting algorithms like Merge Sort or QuickSort. However, it has a high overhead, making it impractical in most real-world applications.

## How It Works
1. The first few elements are sorted using `direct insertion`.
2. A special `merge-insertion` process is used to insert elements into a partially sorted list while minimizing the total number of comparisons.
3. The list is recursively merged until it is fully sorted.

## Practical Relevance

Theoretically optimal in terms of minimal number of comparisons, but rarely used in practice.
Algorithms like QuickSort, MergeSort, and TimSort are more practical because they are simpler to implement and have lower overhead.

## Links 
[Algoritmen -> p. 184](https://seriouscomputerist.atariverse.com/media/pdf/book/Art%20of%20Computer%20Programming%20-%20Volume%203%20(Sorting%20&%20Searching).pdf)
[better explanation](https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91)
