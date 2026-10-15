//PJW Hash（Peter J. Weinberger Hash）

#include <stdio.h>
#include <stdint.h>

uint32_t pjw_hash(const char *str, uint32_t m)
{
    uint32_t h = 0;
    uint32_t g;

    while (*str) {
        // Shift left 4 bits and add character
        h = (h << 4) + (unsigned char)*str;

        // Extract highest 4 bits
        g = h & 0xF0000000u;

        if (g != 0) {
            h ^= (g >> 24); //將原本最高的 4 bits 混合到較低位元（第 4～7 bit）。
            h ^= g; //清除 h 原本最高的 4 bits。
        }

        str++;
    }

    return h % m;
}

int main(void)
{
    const char *str = "hello";
    uint32_t m = 11;

    printf("Hash: %u\n", pjw_hash(str, m));

    return 0;
}
