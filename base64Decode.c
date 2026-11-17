#include <stdio.h>

int b64_val(int c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
    if (c == '+') return 62;
    if (c == '/') return 63;
    if (c == '=') return 0;
    return -1;
}

union Packer {
    struct {
        unsigned int c0 : 6;
        unsigned int c1 : 6;
        unsigned int c2 : 6;
        unsigned int c3 : 6;
    } f;
    unsigned char out[4];
};

int main(void) {
    union Packer p;
    unsigned char vals[4];
    unsigned char *ptr;
    int ch, idx = 0, pad = 0;

    while ((ch = getchar()) != EOF) {
        int val = b64_val(ch);
        if (val < 0) continue;

        ptr = vals + idx;
        *ptr = (unsigned char)val;
        if (ch == '=') pad++;
        idx++;

        if (idx == 4) {
            p.f.c0 = *(vals + 0);
            p.f.c1 = *(vals + 1);
            p.f.c2 = *(vals + 2);
            p.f.c3 = *(vals + 3);

            int out_bytes = 3 - pad;
            for (int i = 0; i < out_bytes; i++)
                putchar(p.out[i]);

            idx = 0;
            pad = 0;
            if (out_bytes < 3) break;
        }
    }
    return 0;
}
