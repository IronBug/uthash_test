#include <stdio.h>
#include <uthash.h>

struct item {
    /** Sort field */
	unsigned char *sort_field;
	/** Sort field length, in bytes */
	size_t	sort_field_len;
	/** Some user data */
	int some_user_data;
	/** Uthash service data */
	UT_hash_handle hh;
};

int sort_func(const struct item *a, const struct item *b)
{
    int va = *(int*)a->sort_field;
    int vb = *(int*)b->sort_field;
    if(va == vb) return 0;
    return (a<b)?-1:1;
}

int main()
{
    size_t i;
    struct item *p, *tmp;

    /** The sorted list */
    struct item *list = NULL;
    int counter = 0;

    /* fill in the sorted list */
    for(i=0; i<100; i++) {
        p = (struct item*)malloc(sizeof(struct item));

        p->sort_field_len = sizeof(int);
        p->sort_field = (unsigned char *)malloc(p->sort_field_len);
        *p->sort_field = counter++;

        /** This call causes segfault */
        HASH_ADD_KEYPTR_INORDER(hh, list, p->sort_field, p->sort_field_len, p, sort_func);
	}

    printf("filling in is ok\n");

	/* free resources */
    HASH_ITER(hh, list, p, tmp) {
        HASH_DEL(list, p);
        free(p);
    }

    printf("cleanup is ok\n");

    return 0;
}
