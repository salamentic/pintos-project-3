#include <hash.h>
#include <random.h>
#include <inttypes.h>

//struct hash supptable;
struct page
{
	void * paddr;
	void * data;
	void * stack;
        int bytes;
        int zero;
        int offset;
        bool write;
	struct hash_elem hash_elem;
};

unsigned 
page_hash (const struct hash_elem *h, void * aux );

bool
page_less (const struct hash_elem* a, const struct hash_elem* b, void * aux );

struct page *
page_lookup (struct hash * supptable,  const void * address);

void
page_init (struct hash * supptable);

bool
page_delete (struct hash * supptable,  const void * address);
