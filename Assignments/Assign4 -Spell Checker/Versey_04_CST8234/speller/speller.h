#include "dictionary.c"
#include <sys/resource.h>
#include <sys/time.h>

#define VALID_ARGS 2
#define ARGS "STRING"
#define MAX_BUF 1024
#define DELIM "-1?][\",.:;\\/ \n"
#define MAX_WORD 45

typedef trie_node_t * speller;

/*prototypes*/
char* checkOptions(char *arguments);
double calculate (const struct rusage* b, const struct rusage* a);
double option_t(char *dict_name, char *file_name );
void option_n(char * dict_name, char * file_name );
void option_p(char * dict_name, char * file_name );
