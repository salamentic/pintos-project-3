#include "vm/supptable.h"

unsigned 
page_hash (const struct hash_elem *h, void * aux )
{
  const struct page *f = hash_entry(h, struct page, hash_elem);
  return hash_bytes (&f->paddr, sizeof(f->paddr));
}

bool
page_less (const struct hash_elem* a, const struct hash_elem* b, void * aux )
{
  const struct page *num1 = hash_entry(a, struct page, hash_elem);
  const struct page *num2 = hash_entry(b, struct page, hash_elem);
  return num1->paddr < num2->paddr;
}

struct page *
page_lookup (struct hash * supptable,  const void * address)
{
  struct page h;
  struct hash_elem *e;
  h.paddr = address;
  e = hash_find(supptable, &h.hash_elem);
  return e != NULL ? hash_entry (e, struct page, hash_elem) : NULL;
}

bool
page_delete (struct hash * supptable,  const void * address)
{
  struct page h;
  struct hash_elem *e;
  h.paddr = address;
  e = hash_delete(supptable, &h.hash_elem);
  return e;
}

void
page_init (struct hash * supptable)
{
  hash_init(supptable, page_hash, page_less, NULL);
}
