/* *~*~*
Implementation file for the Heap class: max-heap of integers
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
		/* Write your code here */
		int temp;
		int parent = _findParent(lastndx);

		while(lastndx && heapAry[lastndx] > heapAry[parent]) {
			temp = heapAry[parent];
			heapAry[parent] = heapAry[lastndx];
			heapAry[lastndx] = temp;

			lastndx = parent;
			parent = _findParent(lastndx);			
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
	if (left != -1) // if there's a left child
	{
		/* Write your code here */
		int temp;
		int index = rootdex;
		int right = _findRightChild(rootdex);
		if(right < count) {
			if(heapAry[left] > heapAry[right]) {
				if(heapAry[rootdex] < heapAry[left]) {
					temp = heapAry[left];
					heapAry[left] = heapAry[rootdex];
					heapAry[rootdex] = temp;

					_reHeapDown(left);
				}
			}
			else {
				if(heapAry[rootdex] < heapAry[right]) {
					temp = heapAry[right];
					heapAry[right] = heapAry[rootdex];
					heapAry[rootdex] = temp;

					_reHeapDown(right);
				}				
			}
		}
		else {
			if(heapAry[rootdex] < heapAry[left]) {
				temp = heapAry[left];
				heapAry[left] = heapAry[rootdex];
				heapAry[rootdex] = temp;

				_reHeapDown(left);
			}			
		}
	}

}
/* *~*~*
 The public member function insertHeap inserts a new item into a heap.
 It calls _reheapUp.
 *~**/
bool Heap::insertHeap(int newItem)
{
	if (isFull())
		return false;
		
	/* Write your code here */
	
	return true;
}

/* *~*~*
 The public member function deleteHeap deletes the root of the heap and
 passes back the root's data. It calls _reheapDown.
 *~**/
bool Heap::deleteHeap(int &returnItem)
{
	if (isEmpty())
		return false;
		
	/* Write your code here */
	return true;
}