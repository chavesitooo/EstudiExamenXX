/**
 * 2022e1 Exam.
 */

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {

    // Listen at port 1234

    const int s1 = socket(AF_INET, SOCK_STREAM, 0);

    if (s1 < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in address;

    memset(&address, 0, sizeof(address));

    address.sin_family = AF_INET;
    // ...

    const int b = bind(s1, (struct sockaddr *) &address, sizeof(address));

    if (b < 0) {
        perror("bind");
        return 1;
    }

    // ...

    // Connect to 127.0.0.1:2345

    const int s3 = socket(AF_INET, SOCK_STREAM, 0);

    if (s3 < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in address2;

    memset(&address2, 0, sizeof(address2));

    address2.sin_family = AF_INET;
    // ...

    // Main loop

    while(1) {
        const ssize_t r = recv(...);

        if (r < 0) {
            perror("recv");
            return 1;
        }

        const ssize_t s4 = send(...);

        if (s4 < 0) {
            perror("send");
            return 1;
        }
    }

    // Clean up

    const int c1 = close(s1);

    if (c1 < 0) {
        perror("close");
        return 1;
    }

    const int c2 = close(s2);

    if (c2 < 0) {
        perror("close");
        return 1;
    }

    const int c3 = close(s3);

    if (c3 < 0) {
        perror("close");
        return 1;
    }

	return 0;
}
