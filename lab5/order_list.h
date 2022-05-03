/*
 * CS 152, Spring 2022
 * Lab #5: Order List Data Structure Interface
 *
 * Do not modify this file
 */


#ifndef ORDER_LIST_H
#define ORDER_LIST_H

typedef struct order_list order_list_t;

struct order_list {
  order_t *order;
  order_list_t *next;
};

/*
 * find_before: find the list element BEFORE the one that matches
 *    the specified oref
 *
 * lst: a list of orders
 * oref: the oref of interest
 * found_match: an OUT parameter that is true if one of the orders on
 *  the list has the matching oref
 *
 * Returns: return NULL if no matching order is found in
 *   the list or if the matching order is the first order
 *   in the list.  Returns a pointer to the list node
 *   immediately before the node with the matching order.
 */
order_list_t *find_before(order_list_t *lst, long long oref,
			  bool *found_match);

/*
 * add_order_list: adds an order to the end of a list of orders if the
 *   order's oref is not already represented in the list.  If the
 *   order's oref is in the list, the original list is returned.
 *
 * lst: an order list
 * order: the order to add
 *
 * Returns: a pointer to the head of the list.
 */
order_list_t *add_order_list(order_list_t *lst, order_t *order);


/*
 * free_order_list: free the nodes of a list of orders and if requested,
 *  the orders themselves.
 *
 * lst: the list of orders
 * should_free_orders: true if the client also wants to have the
 *   orders themselves freed, false if not.
 */
void free_order_list(order_list_t *lst, bool should_free_orders);


/*
 * remove_order_by_oref: remove the order with the specified oref,
 *   if it resides in the list.  Return a pointer to the list.
 *
 * lst: a list of pointers to orders
 * oref: an oref
 * should_free_order: free the order as well as the list node, when true.
 *
 * Returns: a pointer to the head of the list or NULL, if the list is
 *  empty after removing the order.
 */
 order_list_t *remove_order_by_oref(order_list_t *lst, long long oref, 
                                    bool should_free_order);


#endif
