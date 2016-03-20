//
//  main.c
//  patterns_c_strategy
//
//  Created by ursus on 20.03.16.
//  Copyright © 2016 Ursus Schneider. All rights reserved.
//

#include <stdio.h>

// just to make it easier later on
typedef double (* customerPriceStrategy) (double price, double shipping);

typedef struct _customer {
    char * name;
    customerPriceStrategy priceStratery;
} customer_t;
typedef struct _order {
    int orderNr;
    customer_t * customer;
} order_t;
// these are my actual strategies
double bronzeCustomer (double price, double shipping) {
    return (price * 0.9) + shipping;
}
double silverCustomer (double price, double shipping) {
    return (price * 0.8) + shipping;
}
double goldCustomer (double price, double shipping) {
    // plus free shipping
    return price * 0.7;
}



int main(int argc, const char * argv[]) {
    // create your customers
    customer_t cust_1;
    cust_1.name = "Jim";
    cust_1.priceStratery = &goldCustomer;
  
    customer_t cust_2;
    cust_2.name = "Ursus";
    cust_2.priceStratery = &bronzeCustomer;
    
    // create orders
    order_t order_1;
    order_1.customer = &cust_1;
    order_1.orderNr = 1;
    printf ("Customer: %s\t Order no: %i List price: %d\t Customer price: %f\n", order_1.customer->name, order_1.orderNr, 100, order_1.customer->priceStratery (100, 10));

    order_t order_2;
    order_2.customer = &cust_2;
    order_2.orderNr = 2;
    printf ("Customer: %s\t Order no: %i List price: %d\t Customer price: %f\n", order_2.customer->name, order_2.orderNr, 100, order_2.customer->priceStratery (100, 10));
    
    printf ("Customer: %s\t gets raised to silver status\n", order_2.customer->name);
    cust_2.priceStratery = &silverCustomer;
    printf ("Customer: %s\t Order no: %i List price: %d\t Customer price: %f\n", order_2.customer->name, order_2.orderNr, 100, order_2.customer->priceStratery (100, 10));
    
    

}
