/*
* @author Adrian Molofsky
* @version 11/14/23
*/

int atomicCAS(int* addr, int compare, int val) {
  int old = *addr;
  *addr = (old == compare) ? val : old;
  return old;
}

void atomic_min(int* addr, int x) {
  int old = *addr;
  int update = min(old, x);
  while (atomicCAS(addr, old, update) != old) {
    old = *addr;
    update = min(old, x);
  }
}
