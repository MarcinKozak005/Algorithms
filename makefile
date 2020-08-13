# Sorting
bubblesort: Sorting/bubbleSort.cpp utils/utils.h
	g++ -o bubbleSort Sorting/bubbleSort.cpp utils/utils.h
	./bubbleSort
insertionSort: Sorting/insertionSort.cpp utils/utils.h
	g++ -o insertionSort Sorting/insertionSort.cpp utils/utils.h
	./insertionSort
selectionSort: Sorting/selectionSort.cpp utils/utils.h
	g++ -o selectionSort Sorting/selectionSort.cpp utils/utils.h
	./selectionSort
quickSort: Sorting/quickSort.cpp utils/utils.h
	g++ -o quickSort Sorting/quickSort.cpp utils/utils.h
	./quickSort
mergeSort: Sorting/mergeSort.cpp utils/utils.h
	g++ -o mergeSort Sorting/mergeSort.cpp utils/utils.h
	./mergeSort
heapSort: Sorting/heapSort.cpp utils/utils.h
	g++ -o heapSort Sorting/heapSort.cpp utils/utils.h
	./heapSort
# Graph
BFS: Graphs/BFS.cpp Graphs/Graph.cpp
	g++ -o BFS Graphs/BFS.cpp Graphs/Graph.cpp
	./BFS
DFS: Graphs/DFS.cpp Graphs/Graph.cpp
	g++ -o DFS Graphs/DFS.cpp Graphs/Graph.cpp
	./DFS
Dijkstra: Graphs/Dijkstra.cpp Graphs/Graph.cpp
	g++ -o Dijkstra Graphs/Dijkstra.cpp Graphs/Graph.cpp
	./Dijkstra
BellmanFord: Graphs/BellmanFord.cpp Graphs/Graph.cpp
	g++ -o BellmanFord Graphs/BellmanFord.cpp Graphs/Graph.cpp
	./BellmanFord
FloydWarshall: Graphs/FloydWarshall.cpp Graphs/Graph.cpp
	g++ -o FloydWarshall Graphs/FloydWarshall.cpp Graphs/Graph.cpp
	./FloydWarshall
AStar: Graphs/AStar.cpp Graphs/Graph.cpp utils/utils.h
	g++ -o AStar Graphs/AStar.cpp Graphs/Graph.cpp utils/utils.h
	./AStar
clean:
	rm -f bubbleSort insertionSort selectionSort quickSort mergeSort heapSort BFS DFS Dijkstra BellmanFord FloydWarshall AStar