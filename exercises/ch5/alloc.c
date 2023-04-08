#define MAX_ALLOC 1000

static char allocbuf[MAX_ALLOC];
static int allocn = 0;

/* [_ _ _ _ _]
 *    ^
 *    allocbuf+allocn
 *    user asks for n memory cells
 *    user gets a ptr == allocbuf+allocn
 *    allocn += n
 *    (if n == 2)
 *    [_ ----_ _]
 *           ^
 *           allocptr
 *    User has access to the ---- block
 *
 *    afree decrements allocn to point back where it
 *    did before the allocation
 */

/* ptr will be set to pointer to the start of allocated memory 
 * return value 1 indicates success, 0 means not enough memory available
 * */
char* alloc(int n){
    if(allocbuf + allocn + n >= allocbuf+MAX_ALLOC){
        return 0;
    }
    char *allocptr = allocbuf+allocn+n;
    allocn += n;
    return allocptr;
}

/* Frees the memory by relocating where the next block of free memory is */
void afree(char* ptr){
    if((ptr-allocbuf) > allocn && (ptr-allocbuf) < MAX_ALLOC){
        allocn = (ptr - allocbuf);
    }
}
