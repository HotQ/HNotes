static int	mallocMemory = 0;
static int	  freeMemory = 0;

void  RecordMalloc(int size,char *caller);
void  RecordFree(int size,char *caller);
void MemoryReport();