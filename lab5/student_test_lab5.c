#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "util.h"
#include "order.h"
#include "order_list.h"

int main() {
    char *str = "I,AMGN,A,B,100,558000,1000";
    order_t *o = mk_order_from_line(str, 10);
    char *o_gen_str = to_string_order(o);
    if (o_gen_str) {
      printf("o: %s\n", o_gen_str);
      free(o_gen_str);
    }

    char *str1 = "I,AMGN,A,B,10,558500,1001";
    order_t *o1 = mk_order_from_line(str1, 10);
    char *o1_gen_str = to_string_order(o);
    if (o1_gen_str) {
      printf("o1: %s\n", o1_gen_str);
      free(o1_gen_str);
    }

    /* uncomment when ready to work on add_order

    order_list_t *lst = add_order_list(NULL, o);
    lst = add_order_list(lst, o1);
    // add an order that already exists
    lst = add_order_list(lst, o);

    for (order_list_t *tmp = lst; tmp != NULL; tmp=tmp->next) {
        char *order_str = to_string_order(tmp->order);
        printf("%s\n", order_str);
        free(order_str);
    }

    free_order_list(lst, false);
    */

    free_order(o);
    free_order(o1);    
}
