/*
 * CS 152, Spring 2022
 * Lab #5: Order Data Structure Interface
 *
 * Do not modify this file
 */


#ifndef ORDER_H
#define ORDER_H

#define MAX_ORDER_LEN 1000
#define MAX_TICKER_LEN 10
enum order_fields {VENUE=0, TICKER, TYPE, BOOK, SHARES, PRICE, OREF, TIME};
#define NUM_FIELDS (TIME + 1)

typedef struct order {
  char venue;
  char *ticker;
  char type;
  char book;
  int shares;
  long long price;
  long long oref;
  int time;
} order_t;

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
                  int time);


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
order_t *mk_order_from_line(char *line, int time);


/* 
 * free_order: free an order 
 */
void free_order(order_t *order);


/* 
 * to_string_order: convert an order to a string
 *  Format:Venue,Ticker,Type,Book,Shares,Price,Oref,Time
 *
 * order: the order to convert
 *
 * Returns: string in the format listed above
 */
char *to_string_order(order_t *order);

#endif
