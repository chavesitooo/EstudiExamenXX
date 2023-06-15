/**
 * 2022e3 Exam.
 */

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {

    const int s1 = socket(AF_INET, SOCK_STREAM, 0);

    if (s1 < 0) {
        perror("socket");
        return 1;
    }

    const int s2 = socket(AF_INET, SOCK_STREAM, 0);

    if (s2 < 0) {
        perror("socket");
        return 1;
    }

    // Connect sockets

    // Main loop

    while(1) {
        const ssize_t t1 = recv(...);

        if (t1 < 0) {
            perror("recv");
            return 1;
        }

        const ssize_t t2 = send(...);

        if (t2 < 0) {
            perror("send");
            return 1;
        }
    }

    // Clean up

    const int d1 = close(s1);

    if (d1 < 0) {
        perror("close");
        return 1;
    }

    const int d2 = close(s2);

    if (d2 < 0) {
        perror("close");
        return 1;
    }



    return 0;
}
