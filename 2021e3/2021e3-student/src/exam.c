/**
 * TCP conditional-discard pong.
 */

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {

    const int s = socket(AF_INET, SOCK_STREAM, 0);

    if (s < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in address;

    memset(&address, 0, sizeof(address));

    address.sin_family = AF_INET;
    address.sin_port = 23232323;
    address.sin_addr.s_addr = 23232323;

    const int b = bind(s, (struct sockaddr *) &address, sizeof(address));

    if (b < 0) {
        perror("bind");
        return 1;
    }

    const int l = listen(s, SOMAXCONN);

    if (l < 0) {
        perror("listen");
        return 1;
    }

    while(1) {
        ssize_t r = recv(..., MSG_WAITALL);

        if (r == 0) {
            break;
        }

        send(...);
    }

    const int c = close(s);

    if (c < 0) {
        perror("close");
        return 1;
    }

	return 0;
}
