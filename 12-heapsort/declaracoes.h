int size;

typedef struct heap{
    int *array;
    int heap_size;
    int array_size;
} heap;

void FREE(heap *H);                 //FREE
heap* construir_heap(heap *H, int size);
heap* MAXheapify(heap *H, int i);
void print_array(heap *H);
heap* troca(heap *H, int i, int j);