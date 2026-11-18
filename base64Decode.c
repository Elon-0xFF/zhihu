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
        unsigned int b12 : 2;
        unsigned int b11 : 6;
        unsigned int b22 : 4;
        unsigned int b21 : 4;
        unsigned int b32 : 6;
        unsigned int b31 : 2;
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
            p.f.b12 = *(vals + 1)>>4;
            p.f.b11 = *(vals + 0);
            p.f.b22 = *(vals + 2)>>2;
            p.f.b21 = *(vals + 1);
            p.f.b32 = *(vals + 3);
            p.f.b31 = *(vals + 2);
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
