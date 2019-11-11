int size;

typedef struct heap{
    int *array;
    int heap_size;
    int array_size;
} heap;

void FREE(heap *H);                 //FREE
void construir_heap(heap **H, int size);
void MAXheapify(heap *H, int i);
void print_array(heap *H);
void troca(heap *H, int i, int j);