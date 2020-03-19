#define MAX_SEQ 7
#define NR_BUFS (MAX_SEQ+1)/2

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct frame
{
	int seq;
	int ack;
	char data;
	char kind; // could be n/d/a
	bool no_nak;
};

bool between(int a,int b,int c)
{
	return((a<=b && b<c) || (c<a && a<=b) || (c<a && b<c));
}

void send_frame(struct frame f,int frame_expected,char *buffer)
{
    struct frame s;

    s.kind = f.kind;
    if(f.kind == 'd')
        s.data = buffer[f.seq % NR_BUFS];
    s.seq = f.seq;
    s.ack = (frame_expected + MAX_SEQ)%(MAX_SEQ + 1);
    if(f.kind == 'n')
        f.no_nak false;
    to_phy(&s);  // complete it
    if(f.kind == 'd')
        start_timer(f.seq % NR_BUFS)
    stop_ack_timer();
}
