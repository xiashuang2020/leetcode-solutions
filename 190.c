//
// Created by pyxisha on 2022/3/15.
//

#define uint32_t unsigned int

uint32_t reverseBits(uint32_t n) {
    uint32_t ret;

    ret = ((n & 0xffff) << 16) | ((n & 0xffff0000) >> 16);
    ret = ((ret & 0xff00ff) << 8) | ((ret & 0xff00ff00) >> 8);
    ret = ((ret & 0xf0f0f0f) << 4) | ((ret & 0xf0f0f0f0) >> 4);
    ret = ((ret & 0x33333333) << 2) | ((ret & 0xcccccccc) >> 2);
    ret = ((ret & 0x55555555) << 1) | ((ret & 0xaaaaaaaa) >> 1);


    return ret;
}

