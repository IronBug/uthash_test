# uthash_test
uthash library bug test and possible patch

Looks like I found a bug in uthash library, in **HASH_ADD_KEYPTR_INORDER** function.
Here I made a test case for showing the bug and sketched a patch (for GCC only, since I don't have other compilers at hand, but easily extendable for other compilers.
I created an issue in uthash library github.
