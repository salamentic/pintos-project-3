#include <hash.h>
#include <random.h>

struct hash frametable;
struct frame
{
	void * faddr;
	void * paddr;
	struct hash_elem hash_elem;
};

unsigned 
frame_hash (const struct hash_elem *h, void * aux );

bool
frame_less (const struct hash_elem* a, const struct hash_elem* b, void * aux );

struct frame *
frame_lookup ( const void * address);

void
frame_init ();
