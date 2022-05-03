/*
 * CS 152, Spring 2022
 * Lab #5: Order Data Structure Implementation
 *
 * Name: add your name here
 *   YOU MUST FILL IN YOUR NAME AND THEN REMOVE THIS COMMENT.
 *
 * Sources used:
 *   YOU MUST COMPLETE THIS SECTION
 *
 * People consulted:
 *   YOU MUST COMPLETE THIS SECTION
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "util.h"
#include "order.h"

/*
 * mk_order: make an order from the parts
 *
 * venue: the venue the order is from
 * ticker: the ticker symbol for the company
 * typ: the type of order 
 * book: 'B' for buy or 'S' for sell
 * shares: the number of shares to be bought or sold
 * price: the desired price
 * oref: a unique identifier
 * time: the time the order was placed
 *
 * Returns: a pointer to an order struct.
 */
order_t *mk_order(char venue, char *ticker, char typ, char book, 
        		      int shares, long long price, long long oref, 
                  int time) {
    char *fn_name = "mk_order";
    order_t *o = (order_t*) ck_malloc(sizeof(order_t), fn_name);
    o->venue = venue;
    o->ticker = ck_strdup(ticker, fn_name);
    o->type = typ;
    o->book = book;
    o->shares = shares;
    o->price = price;
    o->oref = oref;
    o->time = time;
    return o;
}


/*

 * mk_order_from_line: constructs an order from an string describing
 *  the order and the time of the order.
 *
 * line: a string describing the order.  
 *  Format:Venue,Ticker,Type,Book,Shares,Price,Oref
 * time: the time the order was placed
 *
 * Returns: a pointer to an order struct. 
 */
order_t *mk_order_from_line(char *line, int time) {
    // YOUR CODE HERE
    // Replace NULL with an appropriate return value
    return NULL;
}


/* 
 * free_order: free an order 
 */
void free_order(order_t *order) {
    // order of the calls to free matters.
    free(order->ticker);
    free(order);
}


/* 
 * to_string_order: convert an order to a string
 *  Format:Venue,Ticker,Type,Book,Shares,Price,Oref,Time
 *
 * order: the order to convert
 *
 * Returns: string in the format listed above
 */
char *to_string_order(order_t *order) {
    // YOUR CODE HERE
    // Replace NULL with an appropriate return value
  return NULL;
}
