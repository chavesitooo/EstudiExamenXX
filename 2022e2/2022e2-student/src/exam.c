/**
 * 2022e2 Exam.
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

    struct sockaddr_in address1;

    memset(&address1, 0, sizeof(address1));

    address1.sin_family = AF_INET;
	// ...

    const int b1 = bind(s1, (struct sockaddr *) &address1, sizeof(address1));

    if (b1 < 0) {
        perror("bind1");
        return 1;
    }

    // ...

    // Listen at port 2345

    const int s2 = socket(AF_INET, SOCK_STREAM, 0);

    if (s2 < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in address2;

    memset(&address2, 0, sizeof(address2));

    address2.sin_family = AF_INET;
	// ...    

    const int b2 = bind(s2, (struct sockaddr *) &address2, sizeof(address2));

    if (b2 < 0) {
        perror("bind2");
        return 1;
    }

	// ...
	
    // Accept connections

    // ...

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

    const int c4 = close(s4);

    if (c4 < 0) {
        perror("close");
        return 1;
    }


	return 0;
}
