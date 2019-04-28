#include "vm/frametable.h"

unsigned 
frame_hash (const struct hash_elem *h, void * aux )
{
  const struct frame *f = hash_entry(h, struct frame, hash_elem);
  return hash_bytes (&f->faddr, sizeof(f->faddr));
}

bool
frame_less (const struct hash_elem* a, const struct hash_elem* b, void * aux )
{
  const struct frame *num1 = hash_entry(a, struct frame, hash_elem);
  const struct frame *num2 = hash_entry(b, struct frame, hash_elem);
  return num1->faddr < num2->faddr;
}

struct frame *
frame_lookup ( const void * address)
{
  struct frame h;
  struct hash_elem *e;
  h.faddr = address;
  e = hash_find(&frametable, &h.hash_elem);
  return e != NULL ? hash_entry (e, struct frame, hash_elem) : NULL;
}

void
frame_init ()
{
  hash_init(&frametable, frame_hash, frame_less, NULL);
}
