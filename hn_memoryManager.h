#ifndef HN_MEMORYMANAGER_H_INCLUDED
#define HN_MEMORYMANAGER_H_INCLUDED

static int	mallocMemory = 0;
static int	  freeMemory = 0;

void  RecordMalloc(int size,char *caller);
void  RecordFree(int size,char *caller);
void MemoryReport();

#endif // HN_MEMORYMANAGER_H_INCLUDED
