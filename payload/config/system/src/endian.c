/**
 *
 * @file    endian.c
 * @brief   Endianness utilities.
 *
 */

#include "endian.h"

/* Convert 16-bit number from host byte order to network byte order */
inline uint16_t hton16(uint16_t h16)
{
#if (BIG_ENDIAN)
    return h16;
#else
    return (((h16 & 0xff00) >> 8) |
            ((h16 & 0x00ff) << 8));
#endif
}

/* Convert 16-bit number from network byte order to host byte order */
inline uint16_t ntoh16(uint16_t n16)
{
    return hton16(n16);
}

/* Convert 32-bit number from host byte order to network byte order */
inline uint32_t hton32(uint32_t h32)
{
#if (BIG_ENDIAN)
    return h32;
#else
    return (((h32 & 0xff000000) >> 24) |
            ((h32 & 0x000000ff) << 24) |
            ((h32 & 0x0000ff00) << 8) |
            ((h32 & 0x00ff0000) >> 8));
#endif
}

/* Convert 32-bit number from network byte order to host byte order */
inline uint32_t ntoh32(uint32_t n32)
{
    return hton32(n32);
}

/* Convert 64-bit number from host byte order to network byte order */
inline uint64_t hton64(uint64_t h64)
{
#if (BIG_ENDIAN)
    return h64;
#else
    return (((h64 & 0xff00000000000000LL) >> 56) |
            ((h64 & 0x00000000000000ffLL) << 56) |
            ((h64 & 0x00ff000000000000LL) >> 40) |
            ((h64 & 0x000000000000ff00LL) << 40) |
            ((h64 & 0x0000ff0000000000LL) >> 24) |
            ((h64 & 0x0000000000ff0000LL) << 24) |
            ((h64 & 0x000000ff00000000LL) >> 8) |
            ((h64 & 0x00000000ff000000LL) << 8));
#endif
}

/* Convert 64-bit number from host byte order to network byte order */
inline uint64_t ntoh64(uint64_t n64)
{
    return hton64(n64);
}

/* Convert 16-bit number from host byte order to big endian byte order */
inline uint16_t htobe16(uint16_t h16)
{
    return hton16(h16);
}

/* Convert 16-bit number from host byte order to little endian byte order */
inline uint16_t htole16(uint16_t h16)
{
#if (LITTLE_ENDIAN)
    return h16;
#else
    return (((h16 & 0xff00) >> 8) |
            ((h16 & 0x00ff) << 8));
#endif
}

/* Convert 16-bit number from big endian byte order to little endian byte order */
inline uint16_t be16toh(uint16_t be16)
{
    return ntoh16(be16);
}

/* Convert 16-bit number from little endian byte order to host byte order */
inline uint16_t letoh16(uint16_t le16)
{
    return htole16(le16);
}

/* Convert 32-bit number from host byte order to big endian byte order */
inline uint32_t htobe32(uint32_t h32)
{
    return hton32(h32);
}

/* Convert 32-bit number from little endian byte order to host byte order */
inline uint32_t htole32(uint32_t h32)
{
#if (LITTLE_ENDIAN)
    return h32;
#else
    return (((h32 & 0xff000000) >> 24) |
            ((h32 & 0x000000ff) << 24) |
            ((h32 & 0x0000ff00) << 8) |
            ((h32 & 0x00ff0000) >> 8));
#endif
}

/* Convert 32-bit number from big endian byte order to host byte order */
inline uint32_t be32toh(uint32_t be32)
{
    return ntoh32(be32);
}

/* Convert 32-bit number from little endian byte order to host byte order */
inline uint32_t letoh32(uint32_t le32)
{
    return htole32(le32);
}

/* Convert 64-bit number from host byte order to big endian byte order */
inline uint64_t htobe64(uint64_t h64)
{
    return hton64(h64);
}

/* Convert 64-bit number from host byte order to little endian byte order */
inline uint64_t htole64(uint64_t h64)
{
#if (LITTLE_ENDIAN)
    return h64;
#else
    return (((h64 & 0xff00000000000000LL) >> 56) |
            ((h64 & 0x00000000000000ffLL) << 56) |
            ((h64 & 0x00ff000000000000LL) >> 40) |
            ((h64 & 0x000000000000ff00LL) << 40) |
            ((h64 & 0x0000ff0000000000LL) >> 24) |
            ((h64 & 0x0000000000ff0000LL) << 24) |
            ((h64 & 0x000000ff00000000LL) >> 8) |
            ((h64 & 0x00000000ff000000LL) << 8));
#endif
}

/* Convert 64-bit number from big endian byte order to host byte order */
inline uint64_t betoh64(uint64_t be64)
{
    return ntoh64(be64);
}

/* Convert 64-bit number from little endian byte order to host byte order */
inline uint64_t letoh64(uint64_t le64)
{
    return htole64(le64);
}

/* Convert float from host byte order to network byte order */
inline float htonflt(float f)
{
#if (BIG_ENDIAN)
    return f;
#else
    union v
    {
        float f;
        uint32_t i;
    };
    union v val;
    val.f = f;
    val.i = hton32(val.i);
    return val.f;
#endif
}

/* Convert float from host byte order to network byte order */
inline float ntohflt(float f)
{
    return htonflt(f);
}

/* Convert double from host byte order to network byte order */
inline double htondbl(double d)
{
#if (BIG_ENDIAN)
    return d;
#else
    union v
    {
        double d;
        uint64_t i;
    };
    union v val;
    val.d = d;
    val.i = hton64(val.i);
    return val.d;
#endif
}

/* Convert float from host byte order to network byte order */
inline double ntohdbl(double d)
{
    return htondbl(d);
}
