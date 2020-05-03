bool isOneBitCharacter(vector<int>& bits) {
    int len_bits = bits.size();
    if (bits[len_bits - 1]) return false;
    if (len_bits < 2) return bits[0] ? false:true;
    if (!bits[len_bits - 2]) return true;
    int num_1 = 0;
    for (int i = len_bits - 2; i >= 0 && bits[i]; --i)
    {
        ++num_1;
    }
    return num_1%2 ? false : true;
}
