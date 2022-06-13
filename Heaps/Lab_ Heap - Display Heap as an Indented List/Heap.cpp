/* *~*~*
Implementation file for the Heap class: min-heap of integers
Written By: A. Student
Changed by: Pratyush Shanbhag
IDE: VSCode
*~**/

#include "Heap.h"

/* *~*~*
 The private member function _reHeapUp rearranges the heap after insert by moving the
 last item up to the correct location in the heap
 *~**/
void Heap::_reHeapUp(int lastndx)
{
	if (lastndx) // means lastndx != 0, i.e. newElement is not heap's root
	{
		int parent = _findParent(lastndx); // parent = parent of newElement
		// finish writing this recursive function
		/* Write  your code here */
		int temp;

		if(lastndx && heapAry[lastndx] < heapAry[parent]) {
			temp = heapAry[parent];
			heapAry[parent] = heapAry[lastndx];
			heapAry[lastndx] = temp;

			_reHeapUp(parent);
		}
	}
}

/* *~*~*
 The private member function _reHeapDown rearranges the heap after delete by moving the
 data in the root down to the correct location in the heap
 *~**/
void Heap::_reHeapDown(int rootdex)
{
	int left = _findLeftChild(rootdex);
	// finish writing this recursive function
	if (left != -1) // if there's a left child
	{
		/* Write  your code here */
		int right = _findRightChild(rootdex);
		int min = rootdex;

		if(left < count && heapAry[left] < heapAry[min]) {
			min = left;
		}
		
		if(right != -1 && right < count && heapAry[right] < heapAry[min]) {
			min = right;
		}

		if(min != rootdex) {
			int temp = heapAry[rootdex];
			heapAry[rootdex] = heapAry[min];
			heapAry[min] = temp;

			_reHeapDown(min);
		}
	}

}

/* *~*~*
 The private member function _printIndented (recursive)
 prints the heap as an indented tree (Right-Root-Left)
 *~**/
/* Write  your code here */
void Heap::_printIndented(int index, int level, void visit(int, int)) {
    if(index != -1  && index < count) {
        _printIndented(_findRightChild(index), level + 1, visit);
        visit(heapAry[index], level);
        _printIndented(_findLeftChild(index), level + 1, visit);
    }
}

/* *~*~*
 The public member function insertHeap inserts a new item into a heap.
 It calls _reheapUp.
 *~**/
bool Heap::insertHeap(int newItem)
{
	// finish writing this function
	if (isFull())
		return false;
    /* Write  your code here */
	heapAry[count] = newItem;
	_reHeapUp(count);
	count++;

   return true;
}

/* *~*~*
 The public member function deleteHeap deletes the root of the heap and
 passes back the root's data. It calls _reheapDown.
 *~**/
bool Heap::deleteHeap(int &returnItem)
{
	// finish writing this function
	if (isEmpty())
		return false;
	/* Write  your code here */
	returnItem = heapAry[0];
	count--;
	heapAry[0] = heapAry[count];
	_reHeapDown(0);
 
	return true;
}

/* *~*~*
 The public member function printIndented
 prints the heap as an indented tree (Right-Root-Left)
 It calls _printIndented.
 *~**/
/* Write  your code here */
void Heap::printIndented(void visit(int, int)) {
	_printIndented(0, 1, visit);
}