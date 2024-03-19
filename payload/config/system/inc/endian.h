/*
Cubesat Space Protocol - A small network-layer protocol designed for Cubesats
Copyright (C) 2012 GomSpace ApS (http://www.gomspace.com)
Copyright (C) 2012 AAUSAT3 Project (http://aausat3.space.aau.dk)

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _ENDIAN_H_
#define _ENDIAN_H_

#include <stdint.h>

/**
   @file
   Endian support.
*/

#ifdef __cplusplus
extern "C"
{
#endif

    /**
       Convert from host order to network order.
    */
    uint16_t hton16(uint16_t h16);

    /**
       Convert from network order to host order.
    */
    uint16_t ntoh16(uint16_t n16);

    /**
       Convert from host order to network order.
    */
    uint32_t hton32(uint32_t h32);

    /**
       Convert from network order to host order.
    */
    uint32_t ntoh32(uint32_t n32);

    /**
       Convert from host order to network order.
    */
    uint64_t hton64(uint64_t h64);

    /**
       Convert from network order to host order.
    */
    uint64_t ntoh64(uint64_t n64);

    /**
       Convert from host order to big endian.
    */
    uint16_t htobe16(uint16_t h16);

    /**
       Convert from host order to little endian.
    */
    uint16_t htole16(uint16_t h16);

    /**
       Convert from big endian to host order.
    */
    uint16_t be16toh(uint16_t be16);

    /**
       Convert from little endian to host order.
    */
    uint16_t letoh16(uint16_t le16);

    /**
       Convert from host order to big endian.
     */
    uint32_t htobe32(uint32_t h32);

    /**
       Convert from host order to little endian.
    */
    uint32_t htole32(uint32_t h32);

    /**
       Convert from big endian to host order.
    */
    uint32_t be32toh(uint32_t be32);

    /**
       Convert from little endian to host order.
    */
    uint32_t letoh32(uint32_t le32);

    /**
       Convert from host order to big endian.
    */
    uint64_t htobe64(uint64_t h64);

    /**
       Convert from host order to little endian.
    */
    uint64_t tole64(uint64_t h64);

    /**
       Convert from big endian to host order.
    */
    uint64_t betoh64(uint64_t be64);

    /**
       Convert from little endian to host order.
    */
    uint64_t letoh64(uint64_t le64);

    /**
       Convert from host order to network order.
    */
    float htonflt(float f);

    /**
       Convert from network order to host order.
    */
    float ntohflt(float f);

    /**
       Convert from host order to network order.
    */
    double htondbl(double d);

    /**
       Convert from network order to host order.
    */
    double ntohdbl(double d);

#ifdef __cplusplus
}
#endif
#endif // _ENDIAN_H_
