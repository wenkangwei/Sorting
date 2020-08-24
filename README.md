

### Bubble sort (冒泡排序法)
#### Main idea
Bubble sort compares the array elements  $(n-1) + (n-2)+...+1  = \frac{n(n-1)}{2}$ times. At $k^{th}$ iteration, iterate (n-k) elements and swap two elements if previous one is larger than the next one in ascending sorting.
It guarantees that in each iteration, there must be at least one element sorted into the correct positions
__Example:__
in an array [5 1 4 2 8] with length = 5
__Begin:__
__$1^{st}$ iteration:__ iteration starts from arr[0] to arr[4] and swap two element if arr[i] > arr[i+1].
[5 1 4 2 8] $\to$ [__1 5__ 4 2 8] $\to$ [1 __4 5__ 2 8] $\to$ [1 4  __2 5__ 8] $\to$  [1 4  2 __5 8__]

__$2^{nd}$ iteration:__ iteration starts from arr[0] to arr[__3__] and swap two element if arr[i] > arr[i+1]. Process is similar to the first iteration.
The result is [1 4  2 __5 8__] $\to$ [1 2 4 5 8]

__$3^{rd}$ iteration:__ iteration starts from arr[0] to arr[__2__]. 
__$4^{rd}$ iteration:__ iteration starts from arr[0] to arr[__1__].
__End__

#### Process
1. Pesudo Code
    ~~~
    Loop through n-1 iteration:
        at the k^th iteration, loop through arr[0] to arr[n-1 - k] element:
            if arr[i]> arr[i+1]
                swap arr[i], arr[i+1]
    ~~~
2. Python Code
    ~~~Python
        def bubble_sort(array):
            n = len(array)
            for i in range(n-1):
                for j in range(n-1-i):
                if array[j] > array[j+1]:
                    array[j], array[j+1] = array[j+1], array[j]
            return array
    ~~~
#### Complexity
+ __Memory Complexity:__  O(1), since there is no memory used in algorithm
+ __Time Complexity:__ O(n^2), since there are two inner loops in function and need $\frac{n(n-1)}{2}$ comparison.


### Selection Sort (选择排序法)
#### Main Idea
Selection sort is to find the maximum value of current array and put it to the end of array and then exclude this sorted element to get the sub-array and repeat these two steps to sort the array. If find minimum value, need to put it to the beginning. 
#### Process
1. Pesudo Code
    ~~~
    Loop through n-1 iterations 
        at k^th iteration
        find max of array[0:n-1-k]
        put max into array[n-1-k]
    ~~~
2. Python Code
    ~~~Python
    def selection_sort(array):
        n = len(array)
        for i in range(n):
            max_v = 0
            for j in range(n-i):
                if array[max_v] < array[j]:
                    max_v = j
            array[n-i-1] , array[max_v] =array[max_v], array[n-i-1]
        return array
    ~~~
#### Complexity
+ __Memory Complexity:__ O(1) since in this code, we don't use additional memory
+ __Time Complexity:__: O(n^2), since selection sort use two loops to sort. One inner loop is used to find max value and the other loop is to sort the max values.

### Insertion sort (插入排序法)
#### Main Idea
Main idea of Insertion Sort is to compare the current element with elements before this element and then insert this element to the correct position by moving some elements backward.
1. Start from arr[1], i=1. Iterate elements arr[i] with index i from 1 to  N-1
2. For each element arr[i], compare arr[i] with the element arr[k] right before arr[i]. If we found element arr[k] > arr[i], swap arr[i] and arr[k].
3. Repeat Step 2 until the element arr[k] before arr[i] is less than or equal to arr[i]
__Example:__
Given an array arr = [4,3,2,10,12,1,5,6] with array length N= 8, initial index =0, we want to sort it in ascending order.
 __iteration 1:__  [__4,<span style="color:red">3</span>__,2,10,12,1,5,6] $\to$  [__<span style="color:red">3</span>,4__,2,10,12,1,5,6]
__iteration 2:__  [__3,4,<span style="color:red">2</span>__,10,12,1,5,6] $\to$  [__3,<span style="color:red">2</span>,4__,10,12,1,5,6] $\to$ [__<span style="color:red">2</span>,3,4__,10,12,1,5,6]
...

<img src=https://media.geeksforgeeks.org/wp-content/uploads/insertionsort.png>

#### Process
#### Pseudo code
~~~
Let i = 1
Loop until i ==N-1
    j= i-1
    // swap arr[i] and arr[j] if arr[j]>arr[i]
    while arr[i]< arr[j] and j>0:
        swap(arr[i], arr[j])
        j--
    i++
~~~

#### Complexity
1. Memory Complexity: O(1)
2. Speed Complexity: 
    + worst case: O(n^2)


#### Extension
1. Binary Search + Insertion sort. [Reference](https://www.geeksforgeeks.org/insertion-sort/)

<br>


### Quick sort (快速排序法)
#### Main Idea
In quick sort, the main idea is that
1. we first choose a pivot/key element used for comparison. Usually __we choose the last element in the partition/array as the pivot (we can also choose middle element or the first element as well)__ 
2. Move the __elements smaller than pivot__ to the __left__ to form a subarray/partition __P1__ containing all elements smaller than pivot. 
3. Move the __elements larger than pivot__ to the __right__ to form a subarraysubarray/partition __P2__ containing all elements larger than pivot
4. Move pivot to the position between  __P1__ and __P2__ such that elements ahead pivot are smaller than pivot, elements after pivot are after than pivot 
__Note: This structure is actually as same as binary search tree__, in which __elements on the left side of the parent node is smaller than parent as elements on the right side of the parent node is greater than parent__

5. Repeat steps 1~4 for each partition __recursively__ until subarray can not be partitioned (only one element)

<img src=https://www.geeksforgeeks.org/wp-content/uploads/gq/2014/01/QuickSort2.png>

#### Process
1. In Partition step
    + set the last element arr[len(arr)-1] to be pivot
    + set pointer pointing to values smaller than pivot: left_pt =0 and pointer pointing to values greater than pivot: right_pt = len(arr)-2
    + Loop until reaching terminal state: left_pt> right_pt
    + left_pt++ until it finds arr[left_pt]>pivot
    + right_pt-- until it finds arr[right_pt]< pivot
    + swap arr[left_pt] and arr[right_pt]
    + after reaching terminal, swap pivot and arr[left_pt] such that pivot is at the correct position.
    +  __Pseudo Code__
    ~~~
    partition(array, low, high):
        // check if input range is valid 
        if begin-end < 1:   return end
        
        pivot = array[high]
        left_pt = low
        right_pt = high-1
        //move left_pt to right, right_pt to left until  left_pt>right_pt
        //when left_pt>right_pt, we know array[left_pt] >= array[right_pt]
        //then we need to swap pivot with either array[left_pt] or array[right_pt]  to set the boundary

        Loop if left_pt<= right_pt:
            Loop if left_pt< len(array) and array[left_pt] <= pivot:
                left_pt++
            Loop if right_pt> 0 and array[right_pt]>= pivot:
                right_pt--
            
            if left_pt< right_pt:
                swap array[left_pt] and array[right_pt]
        if array[left_pt] > pivot
            swap array[left_pt], pivot
        return left_pt
    ~~~
    __Note:__
    + __array may have multiple values as same as pivot__. In order to iterate each element in position 0~n-1, need to use <= pivot, and >= pivot to avoid trapping at some positions that doesn't satisfy terminal condition
    eg.

        |arr[left_pt]|a[1]|arr[right_pt]|arr[pivot]|
        |--|--|--|--|
        |2|1|2|2|

    In this case, if we use  "< pivot" and ">pivot" rather than ">=","<=", then left_pt and right_pt won't check "1" in the array. 

    + __Need to compare array[left_pt] and pivot__, since when the input array has only 2 element, then left_pt = right_pt, it directly skips the loop and swap data without comparing the values, this could be wrong.
<br>

2. __Pseudo Code__

    ~~~
    QuickSort( array):
        return quicksort(array, 0, len(array)-1)
    ~~~

    ~~~
    quicksort(array, begin,end)
        //Check if array is empty or length >1
        if end-begin<1: return array
        
        // find the correct position of pivot
        mid = Partition(array, 0, len(array)-1)
        // sort the subarray with elements smaller than pivot
        array = quicksort(array, 0, mid-1)
        // sort the subarray with elements greater than pivot
        array =  quicksort(array, mid+1,len(array)-1)
        return array

    ~~~

3. __Python Code__
    ~~~Python
    class Solution(object):
        def quickSort(self, array):
            """
            input: int[] array
            return: int[]
            """
            # write your solution here
            return self.quick_sort(array, 0, len(array) - 1)

        def quick_sort(self, array, begin, end):
                    # check if input range is valid
            if end - begin < 1:
                return array
            mid = self.partition(array, begin, end)
            array = self.quick_sort(array, begin, mid - 1)
            array = self.quick_sort(array, mid + 1, end)
            return array

        def partition(self, array, begin, end):
                    # check if input range is valid
            if end - begin < 1:
                return end
            pivot = array[end]
            left_pt = begin
            right_pt = end - 1
            while left_pt < right_pt:
                while left_pt < end and array[left_pt] <= pivot:
                    left_pt += 1
                while right_pt > begin and array[right_pt] >= pivot:
                    right_pt -= 1
                if right_pt > left_pt:
                    array[left_pt], array[right_pt] = array[right_pt], array[left_pt]
            if array[end]< array[left_pt]:
            array[end], array[left_pt] = array[left_pt], array[end]

            return left_pt
    ~~~


#### Complexity
+ __Memory Complexity:__ O(1) if we don't consider the memory in stack. Otherwise,  O(n)
+ __Time Complexity:__   
    - best case/average case；O(nlogn)
    - worst case: O(n^2)
#### Note
+ __when it always picks the greatest/ smallest value as pivot or the array is already sorted, it comes to the worst case O(n^2)__ since the recursion tree becomes a __linked list data structure__ and take O(n) to iterate every node and O(n) to sort at each node. Then it comes to O(n*n) time complexity



### Merge sort （归并排序）
#### Main Idea：
Merge sort  is one of the divide and conquer algorithm like quicksort. Its main ideas is that
1. Find the middle of the array
2. Divide the array into two sub-array based on middle
3. Repeat step 1~2 recursively until only 1 element in the array
4. Merge left array and right array and return merged array recusively
5. Example:
    In the array below, we recurively divide the array  into left sub-array 2 and right sub-array 12, then sort the left array first by dividing it until step 4,5. We then merge two elements in step 6. After that, we go back to step 2 to sort the right sub-array. We do the same thing for the whole array.  
<img src=https://www.geeksforgeeks.org/wp-content/uploads/Merge-Sort-Tutorial.png>

#### Process
1. Pesudo Code
    ~~~
    MergeSort( array)
        check if array is valid array, if not ,return
        compute left , right boundary
        merge_subarray(array, left, right)
    
    merge_subarray(array, lef, right):
        check if left < right. If not, return array[left]

        compute middle = (left+right)//2
        // sort left array
        left_array = merge_subarray(array, left, middle)
        // sort right array
        right_array = merge_subarray(array, middle+1, right)
        // merge and sort left and right arrays
        sorted_array = merge(left_array, right_array)

        return sorted_array
    merge(left_array, right_array):
        use linear method to merge the left array and right array.
        // Note that since left_array and right array have 
        //been sorted, merging two sorted array actually 
        //lead to linear time complexity O(n) only
        create new array A
        left_index = 0
        right_index = 0
        while left_index >0 and right_index>0:
            add the min(left_array[left_index], right_array[right_index])
            index += 1
        Add the remaining elements in array to A
        return A
    ~~~
2. Python code
    ~~~Python
    class Solution(object):
        def merge_sort(self, array, left, right):
            if len(array)<2 or left>=right:
            return [array[left]]

            middle = left+ (right-left)//2
            left_array = self.merge_sort(array, left, middle)
            right_array = self.merge_sort(array, middle+1, right)
            sorted_array = self.merge(left_array, right_array)
            return sorted_array
        
        def merge(self, left_array, right_array):
            if left_array == None or len(left_array) <1:
            return right_array
            elif right_array == None or len(right_array) <1:
            return left_array
            
            l_index = 0
            r_index = 0
            merged_array = []
            while l_index < len(left_array) and r_index<len(right_array):
            if left_array[l_index] <  right_array[r_index]:
                merged_array.append(left_array[l_index])
                l_index += 1
            else:
                merged_array.append(right_array[r_index])
                r_index += 1
            if l_index < len(left_array):
            merged_array.extend(left_array[l_index:])
            elif r_index < len(right_array):
            merged_array.extend(right_array[r_index:])
            return merged_array

        def mergeSort(self, array):
            """
            input: int[] array
            return: int[]
            """
            # write your solution here
            if array == None or len(array) <2:
            return array
            
            return self.merge_sort(array, 0, len(array)-1)
    ~~~
#### Complexity
+ __Memory Complexity:__ if consider the memory used in stack during recursion, it is __O(n)__
+ __Time Complexity: O(nlogn)__. In each layer of recursion tree, it takes O(n) to merge and sort two sub-arrays at a level of the tree. Since merge sort uses division method, that is, Assume that are n elements to sort and take k steps (depth of the recursion tree) to sort. There are $2^0+2^1+...+2^k = n$ elements. When only consider the largest term, we have $2^k = n$, and $k = O(log_2n) or O(logn)$. Since each level of recursion tree take O(n) to sort array, then have $O(nlogn)$

#### Compared with quick sort
1. Both __merge sort and quick sort__ use __divide and conquer__ method (分治算法) to divide array and then solve each subset recursively. Hence both of them involve logn time complexity
2. __Merge sort__ involves linear sorting during merging two subarray and hence at each level of recursion tree, it takes O(n) to sort. __The total time complexity is O(nlogn)__
3. __Quicksort and merge sort are much more useful__ than  linear sorting(insertion, bubble, selection) due to its __O(nlogn)__ time complexity without increasing memory complexity

### Notes:
1. Usually, Recursion method is less optimal than iteration method (using while loop), since recursion method requires stack memory to store and return solved subset back to last sub-problem. __Hence memory complexity of recursion is usually O(n) unless there are no memory used in recursion function and reduce n to 1__
2. Recursion method is easy to implement, but usually costs more memory.
3. Selection sort can be viewed as a version of bubble sort with more explicit physic meaning, since it explicitly finds the min/max value and put them to the beginning/end of subarray.
4. __Insertion__ sort compares current element with __previous elements__ while __bubble/selection__ sort compare current element with the __next elements__
5. __In-place algorithm:__ an algorithm which transforms input using no auxiliary data structure. However a small amount of extra storage space is allowed for auxiliary variables. The input is usually overwritten by the output as the algorithm executes.

### Source code
For C++ source code, Please read my github repository [here](https://github.com/wenkangwei/Sorting/tree/master/src)


### Reference
[1] https://www.geeksforgeeks.org/bubble-sort/
[2] https://www.geeksforgeeks.org/insertion-sort/?ref=lbp
[3] https://www.geeksforgeeks.org/quick-sort/?ref=lbp
