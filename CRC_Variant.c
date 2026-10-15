#include <stdio.h>
#include <stdint.h>

uint32_t crc_hash(const char *str, uint32_t m)
{
    uint32_t h = 0;

    while (*str) {
        // 32-bit circular left shift by 5
        h = (h << 5) | (h >> 27);

        // XOR with current character
        h ^= (unsigned char)*str;

        str++;
    }

    return h % m;
}

int main(void)
{
    const char *str = "hello";
    uint32_t m = 11;

    printf("Hash: %u\n", crc_hash(str, m));

    return 0;
}
