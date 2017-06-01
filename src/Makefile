SRC=BubbleSort.cpp  InsertionSort.cpp  MergeSort.cpp  SelectionSort.cpp  main.cpp QuickSort.cpp   HeapSort.cpp 
INCLUDE=Sorting.h
object=BubbleSort.o  InsertionSort.o  MergeSort.o  SelectionSort.o  main.o QuickSort.o   HeapSort.o 
sorting : $(object) 
	g++ -o sorting $(object)
	rm -f $(object)


object : $(SRC) $(INCLUDE)
	g++ -c $(SRC)

# use make clean after using make 
clean:
	rm -f $(object)
