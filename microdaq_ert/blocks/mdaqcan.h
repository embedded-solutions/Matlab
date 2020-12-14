#ifndef _MDAQCAN_H
#define _MDAQCAN_H

void mdaqcan_send(char *len, unsigned int *id, unsigned char data[]); 

void mdaqcan_recv(char *len, unsigned int *id, unsigned char data[]); 

void mdaqcan_conf(unsigned int rate);

#endif /* _MDAQCAN_H */
