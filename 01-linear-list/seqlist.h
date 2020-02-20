#ifndef _SEQLIST_H_
#define _SEQLIST_H_
typedef struct {
    int* head;
    unsigned int length;
    unsigned int capacity;
} SeqList;


SeqList initSeqList(unsigned int capacity);
void displaySeqList(SeqList list);
SeqList add(SeqList list, int elem, int pos);
SeqList delete(SeqList list, int pos);
int search(SeqList list, int elem);
SeqList modify(SeqList list, int elem, int val);
#endif
