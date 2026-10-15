
#include <stdio.h>
#include <stdint.h>

// Initialize a deterministic lookup table
void init_table(uint32_t R[256])
{
    uint32_t x = 0x12345678u;

    for (int i = 0; i < 256; ++i) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        R[i] = x;
    }
}

// BUZ Hash function
uint32_t buz_hash(const char *str,
                  const uint32_t R[256],
                  uint32_t m)
{
    uint32_t h = 0;

    while (*str) {
        // Circular left shift by 1 bit
        h = (h << 1) | (h >> 31);

        // XOR with lookup table value
        h ^= R[(unsigned char)*str];

        str++;
    }

    return h % m;
}

int main(void)
{
    uint32_t R[256];
    init_table(R);

    const char *str = "hello";
    uint32_t m = 11;

    printf("Hash: %u\n", buz_hash(str, R, m));

    return 0;
}
