#include"Bitset.h"
#include<cmath>


bitset::bitset() {
    for (int i = 0; i < N; i++){
    	a[i] = 0;
    }
        
}

void bitset::set(int pos) {
    if (!test(pos)) {
        if (pos % 32 == 31)
            a[pos / 32] -= pow(2, 31);
        else
            a[pos / 32] += pow(2, pos % 32);
    }
}

void bitset::reset(int pos) {
    if (test(pos)) {
        if (pos % 32 == 31)
            a[pos / 32] += pow(2, 31);
        else
            a[pos / 32] -= pow(2, pos % 32);
    }
}

int bitset::count() const {
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 32; j++)
            count += (a[i] & (1 << j)) ? 1 : 0;
    return count;
}

bool bitset::test(int pos) const {
    return (a[pos / 32] & (1 << pos % 32)) ? 1 : 0;
}

bool bitset::any() const {
    return (count()) ? 1 : 0;
}

bool bitset::none() const {
    return !any();
}

bool bitset::all() const {
    return (count() == 32 * N) ? 1 : 0;
}

bitset& bitset::operator&= (const bitset& b) {
    for (int i = 0; i < N; i++){
		a[i] &= b.a[i];
	} 
    return *this;
}
bitset& bitset::operator|= (const bitset& b) {
    for (int i = 0; i < N; i++){
    	a[i] |= b.a[i];
    }
    return *this;
}
bitset& bitset::operator^= (const bitset& b) {
    for (int i = 0; i < N; i++){
    	a[i] ^= b.a[i];
    }
        
    return *this;
}
bitset& bitset::operator= (const bitset& b) {
    for (int i = 0; i < N; i++){
    	a[i] = b.a[i];
    }
    return *this;
}
bitset& bitset::operator <<= (int pos) {
    *this = operator<<(pos);
    return *this;
}
bitset& bitset::operator >>= (int pos) {
    *this = operator>>(pos);
    return *this;
}
bitset bitset::operator~() const {
    bitset temp;
    for (int i = 0; i < N; i++){
    	temp.a[i] = ~a[i];
    }
    return temp;
}
bitset bitset::operator&(const bitset& b) const {
    bitset temp;
    for (int i = 0; i < N; i++){
    	temp.a[i] = a[i] & b.a[i];
    }
        
    return temp;
}
bitset bitset::operator|(const bitset& b) const {
    bitset temp;
    for (int i = 0; i < N; i++){
    	temp.a[i] = a[i] | b.a[i];
    }
        
    return temp;
}
bitset bitset::operator^(const bitset& b) const {
    bitset temp;
    for (int i = 0; i < N; i++){
    	temp.a[i] = a[i] ^ b.a[i];
    }
        
    return temp;
}
bitset bitset::operator<<(int pos) const {
    bitset temp;
    for (int i = 0; i < N; i++) {
        temp.a[i] = (a[i] << pos);
        if (i != 0)
            for (int j = 32 * i - 1; j >= 32 * i - pos; j--)
                if (test(j))
                    temp.set(j + pos);
    }//进位 
    return temp;
}

bitset bitset::operator>>(int pos) const {
    bitset temp;
    for (int i = N - 1; i >= 0; i--) {
        temp.a[i] = (a[i] >> pos);
        if (i != N - 1)
            for (int j = 32 * (i + 1); j < 32 * (i + 1) + pos; j++)
                test(j) ? temp.set(j - pos) : temp.reset(j - pos);
    }//退位 
    return temp;
}

bool bitset::operator== (const bitset& b) const {
    for (int i = 0; i < N; i++)
        if (a[i] != b.a[i])
            return 0;
    return 1;
}
bool bitset::operator!= (const bitset& b) const {
    return !operator==(b);
}
bool bitset::operator[] (int pos) const {
    return (a[pos / 32] & (1 << pos % 32)) ? 1 : 0;
}
